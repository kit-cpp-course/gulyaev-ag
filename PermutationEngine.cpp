#include "PermutationEngine.h"

std::array<BlockPart, 8> PermutationEngine::ToBlockParts(const HalfBlockData& data) const
{
	std::array<uint8_t, 8> coeff = {
		0, 4, 8, 12, 16, 20, 24, 28
	};

	std::array<BlockPart, 8> result{};
	for (int i = 0; i < 8; i++)
	{
		result[i] = data.to_ulong() >> coeff[i];
	}
	return result;
}

HalfBlockData PermutationEngine::FromBlockParts(const std::array<BlockPart, 8>& data) const
{
	std::array<uint8_t, 8> coeff = { 0, 4, 8, 12, 16, 20, 24, 28 };
	uint32_t temp{};
	for (int i = 0; i < 8; i++)
	{
		temp += data[i].to_ulong() << coeff[i];
	}
	return HalfBlockData(temp);
}

std::array<BlockPart, 8> PermutationEngine::Permutate(const std::array<BlockPart, 8>& data) const
{
	std::array<BlockPart, 8> after{};
	for (int i = 0; i < 8; i++)
	{
		const uint8_t from = data[i].to_ulong();
		const uint8_t to = _permutationTable[i][from];
		after[i] = BlockPart(to);
	}
	return after;
}

PermutationEngine::PermutationEngine(const PermutationTable& table) : _permutationTable(table)
{
}

HalfBlockData PermutationEngine::Permutate(const HalfBlockData& data) const
{
	std::array<BlockPart, 8> temp = ToBlockParts(data);
	temp = Permutate(temp);
	return FromBlockParts(temp);
}
