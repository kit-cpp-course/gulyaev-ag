#pragma once
#include <bitset>
#include <vector>
#include "Block.h"

/*
 * ���������, ������� �� ���������� ��� �������� ������ ������ ��� ���������� � ������������.
 * The interface that we use as a source of data blocks for encryption and decryption.
 */

class IBlockProvider
{
public:
	/*
	 * ���������� ������ ��� ���������.
	 * Returns data to be processed.
	 */
	virtual std::vector<Block> GetBlocks() const = 0;
	/*
	 * ��������� ������������ ������.
	 * Saves the processed data.
	 */
	virtual void PutBlocks(const std::vector<Block>& blocks) const = 0;
	/*
	 * ���������� ������.
	 * Destructor class.
	 */
	~IBlockProvider() = default;
};
