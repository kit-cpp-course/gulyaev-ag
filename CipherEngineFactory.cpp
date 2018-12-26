#include "CipherEngineFactory.h"

KeyProvider CipherEngineFactory::MakeKeyProvider() const
{
	auto keyData = KeyData{};
	auto keySource = std::ifstream(_keyFilename, std::ios_base::binary);
	keySource.read(reinterpret_cast<char*>(&keyData), 32);

	std::array<HalfBlockData, 8> data{};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			data[i].set(j, keyData.test(i * 32 + j));
		}
	}
	return KeyProvider(
		std::array<HalfBlock, 8>{
		HalfBlock(data[0]), HalfBlock(data[1]), HalfBlock(data[2]), HalfBlock(data[3]),
			HalfBlock(data[4]), HalfBlock(data[5]), HalfBlock(data[6]), HalfBlock(data[7])
	});
}

PermutationEngine CipherEngineFactory::MakePermutationEngine() const
{
	auto table = PermutationTable{};
	auto tableSource = std::ifstream(_permutationTableFilename);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			tableSource >> table[i][j];
		}
		tableSource.ignore();
	}

	return PermutationEngine(table);
}

CipherEngineFactory::CipherEngineFactory(const std::string& keyFilename, const std::string& tableFilename)
	: _keyFilename(keyFilename), _permutationTableFilename(tableFilename)
{
}

MagmaEngineBase* CipherEngineFactory::Build(MagmaEngineBase::EngineAction action) const
{
	const auto key = MakeKeyProvider();
	const auto permutationEngine = MakePermutationEngine();

	if (action == MagmaEngineBase::EngineAction::Encrypt)
	{
		return new MagmaEncrypt(permutationEngine, key);
	}
	return new MagmaDecrypt(permutationEngine, key);
}
