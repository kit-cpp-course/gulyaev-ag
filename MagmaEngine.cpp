#include "Block.h"
#include "IBlockProvider.h"
#include "PermutationEngine.h"
#include "KeyProvider.h"
#include "MagmaEngine.h"

MagmaEngineBase::MagmaEngineBase(const PermutationEngine& engine, const KeyProvider& keyProvider)
	: _permutationEngine(engine), _keyProvider(keyProvider)
{
}

HalfBlock MagmaEngineBase::function(const HalfBlock& block, const HalfBlock& key) const
{
	auto result = block + key;
	result = result.Permutate(_permutationEngine);
	return result.LeftShift(11);
}

void MagmaEngineBase::Proceed(const IBlockProvider& provider) const
{
	auto blocks = provider.GetBlocks();

	for (auto& currentBlock : blocks)
	{
		auto left = currentBlock.GetPart(Block::Side::Left);
		auto right = currentBlock.GetPart(Block::Side::Right);
		for (int j = 0; j < 32; j++)
		{
			const auto temp = right;
			right = left ^ function(right, GetIterKey(j));
			left = temp;
		}
		const auto encryptedBlock = Block(right, left);
		currentBlock = encryptedBlock;
	}

	provider.PutBlocks(blocks);
}

MagmaEncrypt::MagmaEncrypt(const PermutationEngine& engine, const KeyProvider& keyProvider) : MagmaEngineBase(
	engine, keyProvider)
{
}

MagmaDecrypt::MagmaDecrypt(const PermutationEngine& engine, const KeyProvider& keyProvider) : MagmaEngineBase(
	engine, keyProvider)
{
}

HalfBlock MagmaEncrypt::GetIterKey(const int i) const
{
	return _keyProvider.GetIterKeyToEncrypt(i);
}

HalfBlock MagmaDecrypt::GetIterKey(const int i) const
{
	return _keyProvider.GetIterKeyToDecrypt(i);
}
