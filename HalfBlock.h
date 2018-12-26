#pragma once
#include <bitset>
#include "SizeDefinition.h"

class PermutationEngine;
using HalfBlockData = std::bitset<SizeDefinition::HalfBlock>;

/*
 * ��������������� ����� ��� ���������� � ������������ �����: ��������� ������������ ��� ���������� � ������������ ��������� ��������.
 * Helper class for block encryption and decryption: implements bit-by-bit operations used for encryption and decryption.
 */

class HalfBlock
{
private:
	HalfBlockData _data;
public:
	/*
	 * �����������, ��������� �������� ����� �� ������ ���������� ������.
	 * A constructor that creates a half block based on the received data.
	 */
	explicit HalfBlock(const HalfBlockData& data);
	/*
	 * �����������, ��������� �������� ����� �� 4-��������� ������ �����.
	 * A constructor that creates a half block of an 4-byte integer.
	 */
	explicit HalfBlock(const uint32_t value);

	/*
	 * ���������� ������������� ����� � ���� ������ 4-��������� �����.
	 * Returns the block representation as an 4-byte integer.
	 */
	uint32_t ToUint32() const;
	/*
	 * �������� ������������ ���������� ������ �� 11 �������� �����.
	 * The operation of cyclic bitwise shift 11 bits to the left.
	 */
	HalfBlock LeftShift(int shift = 11) const;
	/*
	 * ����� �� ������ 2.
	 * Sum modulo 2.
	 */
	HalfBlock operator ^(const HalfBlock& other) const;
	/*
	 * ����� �� ������ 32.
	 * Sum modulo 32.
	 */
	HalfBlock operator +(const HalfBlock& other) const;
	/*
	 * �������� ������������ ������ ����� � �������������� ������� ������������.
	 * Permutation inside block using permutation table.
	 */
	HalfBlock Permutate(const PermutationEngine& engine) const;
};
