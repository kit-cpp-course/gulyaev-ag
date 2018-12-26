#pragma once
#include <bitset>
#include "SizeDefinition.h"

using BlockData = std::bitset<SizeDefinition::Block>;

class HalfBlock;

/*
 * Block - элементарная единица данных для шифрования и дешифрования.
 * Block - is an elementary data unit for encryption and decryption.
 */

class Block
{
private:
	BlockData _data;

public:
	/*
	 * Выбор части блока - левая (старшие биты блока) или правая (младшие биты блока).
	 * The selection of a block part is left (the high bits of the block) or right (the low bits of the block).
	 */
	enum class Side { Left, Right };
	/*
	 * Конструктор, создающий блок на основе полученных данных.
	 * A constructor that creates a block based on the received data.
	 */
	explicit Block(const BlockData& data);
	/*
	 * Конструктор, создающий блок из 8-байтового целого числа.
	 * A constructor that creates a block of an 8-byte integer.
	 */
	explicit Block(const uint64_t value);
	/*
	 * Конструктор, объединяющий 2 блока в один.
	 * A constructor uniting 2 blocks in one.
	 */
	Block(const HalfBlock& left, const HalfBlock& right);
	/*
	 * Возвращает представление блока в виде целого 8-байтового числа.
	 * Returns the block representation as an 8-byte integer.
	 */
	uint64_t ToUint64() const;
	/*
	 * Возвращает часть блока.
	 * Returns part (left or right) of a block.
	 */
	HalfBlock GetPart(Side side) const;
};
