#pragma once
#include <bitset>
#include <vector>
#include "Block.h"

/*
 * Интерфейс, который мы используем как источник блоков данных для шифрования и дешифрования.
 * The interface that we use as a source of data blocks for encryption and decryption.
 */

class IBlockProvider
{
public:
	/*
	 * Возвращает данные для обработки.
	 * Returns data to be processed.
	 */
	virtual std::vector<Block> GetBlocks() const = 0;
	/*
	 * Сохраняет обработанные данные.
	 * Saves the processed data.
	 */
	virtual void PutBlocks(const std::vector<Block>& blocks) const = 0;
	/*
	 * Деструктор класса.
	 * Destructor class.
	 */
	~IBlockProvider() = default;
};
