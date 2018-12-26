#pragma once
#include "IBlockProvider.h"

/*
 * Класс, реализующий интерфейс IBlockProvider: работает с данными, сохраненными в файле.
 * Class that implements the IBlockProvider interface: works with data stored in a file.
 */

class FileBlockProvider : public IBlockProvider
{
private:
	const std::string _sourceFileName;
	const std::string _destFileName;
public:
	/*
	 * Конструктор принимает имена файлов для обработки данных.
	 * The constructor accepts file names for data processing.
	 */
	FileBlockProvider(const std::string& source, const std::string& dest);
	/*
	 * Возвращает данные для обработки из файла.
	 * Returns data to be processed from a file.
	 */
	std::vector<Block> GetBlocks() const override;
	/*
	 * Сохраняет обработанные данные в файл.
	 * Saves the processed data to a file.
	 */
	void PutBlocks(const std::vector<Block>& blocks) const override;
};
