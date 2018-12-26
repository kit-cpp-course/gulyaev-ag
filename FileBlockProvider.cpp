#include "FileBlockProvider.h"
#include <fstream>

FileBlockProvider::FileBlockProvider(const std::string& source, const std::string& dest)
	: _sourceFileName(source), _destFileName(dest)
{
}

std::vector<Block> FileBlockProvider::GetBlocks() const
{
	std::ifstream source(_sourceFileName, std::ios_base::binary);
	std::vector<BlockData> blocks{};

	while (!source.eof())
	{
		auto temp = uint64_t{};
		source.read(reinterpret_cast<char*>(&temp), 8);
		blocks.push_back(temp);
	}
	return std::vector<Block>(blocks.begin(), blocks.end());
}

void FileBlockProvider::PutBlocks(const std::vector<Block>& blocks) const
{
	auto dest = std::ofstream(_destFileName, std::ios_base::binary);
	for (int i = 0; i < blocks.size(); i++)
	{
		auto temp = blocks[i].ToUint64();
		dest.write(reinterpret_cast<char*>(&temp), 8);
	}
}
