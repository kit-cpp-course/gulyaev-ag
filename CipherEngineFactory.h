#pragma once
#pragma once
#include <string>
#include <fstream>
#include "KeyProvider.h"
#include "PermutationEngine.h"
#include "MagmaEngine.h"

/*
 * Класс, предназначенный для создания экземпляров класса MagmaEngine.
 * A class designed to create instances of the MagmaEngine class.
 */

class CipherEngineFactory
{
private:
	const std::string _keyFilename;
	const std::string _permutationTableFilename;

	KeyProvider MakeKeyProvider() const;

	PermutationEngine MakePermutationEngine() const;
public:
	/*
	 * Конструктор принимает название файла, содержащий ключ, и название файла, содержащий таблицу перестановок.
	 * The constructor accepts the name of the file containing the key and the name of the file containing the permutation table.
	 */
	CipherEngineFactory(const std::string& keyFilename, const std::string& tableFilename);
	/*
	 * Возвращает указатель на экземпляр класса MagmaEngineBase, который готов выполнить требуемое действие.
	 * Returns a pointer to an instance of the MagmaEngineBase class that is ready to perform the requested action.
	 */
	MagmaEngineBase * Build(MagmaEngineBase::EngineAction action) const;
};
