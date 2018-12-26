#pragma once
#include <bitset>
#include "SizeDefinition.h"

class PermutationEngine;
using HalfBlockData = std::bitset<SizeDefinition::HalfBlock>;

/*
 * Вспомогательный класс для шифрования и дешифрования блока: реализует используемые при шифровании и дешифровании побитовые операции.
 * Helper class for block encryption and decryption: implements bit-by-bit operations used for encryption and decryption.
 */

class HalfBlock
{
private:
	HalfBlockData _data;
public:
	/*
	 * Конструктор, создающий половину блока на основе полученных данных.
	 * A constructor that creates a half block based on the received data.
	 */
	explicit HalfBlock(const HalfBlockData& data);
	/*
	 * Конструктор, создающий половину блока из 4-байтового целого числа.
	 * A constructor that creates a half block of an 4-byte integer.
	 */
	explicit HalfBlock(const uint32_t value);

	/*
	 * Возвращает представление блока в виде целого 4-байтового числа.
	 * Returns the block representation as an 4-byte integer.
	 */
	uint32_t ToUint32() const;
	/*
	 * Операция циклического побитового сдвига на 11 разрядов влево.
	 * The operation of cyclic bitwise shift 11 bits to the left.
	 */
	HalfBlock LeftShift(int shift = 11) const;
	/*
	 * Сумма по модулю 2.
	 * Sum modulo 2.
	 */
	HalfBlock operator ^(const HalfBlock& other) const;
	/*
	 * Сумма по модулю 32.
	 * Sum modulo 32.
	 */
	HalfBlock operator +(const HalfBlock& other) const;
	/*
	 * Операция перестановки внутри блока с использованием таблицы перестановок.
	 * Permutation inside block using permutation table.
	 */
	HalfBlock Permutate(const PermutationEngine& engine) const;
};
