#pragma once
#include "IBlockProvider.h"

/*
 * �����, ����������� ��������� IBlockProvider: �������� � �������, ������������ � �����.
 * Class that implements the IBlockProvider interface: works with data stored in a file.
 */

class FileBlockProvider : public IBlockProvider
{
private:
	const std::string _sourceFileName;
	const std::string _destFileName;
public:
	/*
	 * ����������� ��������� ����� ������ ��� ��������� ������.
	 * The constructor accepts file names for data processing.
	 */
	FileBlockProvider(const std::string& source, const std::string& dest);
	/*
	 * ���������� ������ ��� ��������� �� �����.
	 * Returns data to be processed from a file.
	 */
	std::vector<Block> GetBlocks() const override;
	/*
	 * ��������� ������������ ������ � ����.
	 * Saves the processed data to a file.
	 */
	void PutBlocks(const std::vector<Block>& blocks) const override;
};
