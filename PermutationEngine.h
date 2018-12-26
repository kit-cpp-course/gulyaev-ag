#pragma once
#include <array>
#include "HalfBlock.h"

using BlockPart = std::bitset<4>;
using PermutationTable = std::array<std::array<uint8_t, 16>, 8>;

/*
 * �����, ����������� ������ � �������� ������������.
 * The class that implements the work with the permutation table.
 */

class PermutationEngine
{
private:
	/*
	 * ������� ������������.
	 * Permutation table.
	 */
	const PermutationTable _permutationTable;
	
	std::array<BlockPart, 8> ToBlockParts(const HalfBlockData& data) const;
	
	HalfBlockData FromBlockParts(const std::array<BlockPart, 8>& data) const;
	
	std::array<BlockPart, 8> Permutate(const std::array<BlockPart, 8>& data) const;
public:
	/*
	 * ����������� ������, ����������� ��������� ������� ������������.
	 * A class constructor accepting the permutation table created.
	 */
	PermutationEngine(const PermutationTable& table);
	/*
	 * �����, ����������� ������������ ��� ����������� �����.
	 * The method that performs the permutation for the passed block.
	 */
	HalfBlockData Permutate(const HalfBlockData& data) const;
};
