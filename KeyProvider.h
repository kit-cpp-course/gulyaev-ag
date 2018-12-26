#pragma once
#include <array>
#include <bitset>
#include <string>
#include "SizeDefinition.h"
#include "HalfBlock.h"

using KeyData = std::bitset<SizeDefinition::Key>;

/*
 * Класс, реализующий работу с ключом шифрования.
 * The class that implements the work with the encryption key.
 */

class KeyProvider
{
private:
	const std::array<HalfBlock, 8> _data;

public:
	/*
	 * Конструктор, принимающий данные для хранения ключа в памяти.
	 * A constructor that accepts data for storing a key in memory.
	 */
	KeyProvider(const std::array<HalfBlock, 8>& data);
	/*
	 * Возвращает i-й ключ при шифровании.
	 * Returns the i-th key when encrypting.
	 */
	HalfBlock GetIterKeyToEncrypt(int i) const;
	/*
	 * Возвращает i-й ключ при дешифровании.
	 * Returns the i-th key when decrypting.
	 */
	HalfBlock GetIterKeyToDecrypt(int i) const;
};

