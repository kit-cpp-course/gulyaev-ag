#pragma once
#include <bitset>
#include "SizeDefinition.h"

using BlockData = std::bitset<SizeDefinition::Block>;

class HalfBlock;

/*
 * Block - ������������ ������� ������ ��� ���������� � ������������.
 * Block - is an elementary data unit for encryption and decryption.
 */

class Block
{
private:
	BlockData _data;

public:
	/*
	 * ����� ����� ����� - ����� (������� ���� �����) ��� ������ (������� ���� �����).
	 * The selection of a block part is left (the high bits of the block) or right (the low bits of the block).
	 */
	enum class Side { Left, Right };
	/*
	 * �����������, ��������� ���� �� ������ ���������� ������.
	 * A constructor that creates a block based on the received data.
	 */
	explicit Block(const BlockData& data);
	/*
	 * �����������, ��������� ���� �� 8-��������� ������ �����.
	 * A constructor that creates a block of an 8-byte integer.
	 */
	explicit Block(const uint64_t value);
	/*
	 * �����������, ������������ 2 ����� � ����.
	 * A constructor uniting 2 blocks in one.
	 */
	Block(const HalfBlock& left, const HalfBlock& right);
	/*
	 * ���������� ������������� ����� � ���� ������ 8-��������� �����.
	 * Returns the block representation as an 8-byte integer.
	 */
	uint64_t ToUint64() const;
	/*
	 * ���������� ����� �����.
	 * Returns part (left or right) of a block.
	 */
	HalfBlock GetPart(Side side) const;
};
