#pragma once
#include <array>
#include <bitset>
#include <string>
#include "SizeDefinition.h"
#include "HalfBlock.h"

using KeyData = std::bitset<SizeDefinition::Key>;

/*
 * �����, ����������� ������ � ������ ����������.
 * The class that implements the work with the encryption key.
 */

class KeyProvider
{
private:
	const std::array<HalfBlock, 8> _data;

public:
	/*
	 * �����������, ����������� ������ ��� �������� ����� � ������.
	 * A constructor that accepts data for storing a key in memory.
	 */
	KeyProvider(const std::array<HalfBlock, 8>& data);
	/*
	 * ���������� i-� ���� ��� ����������.
	 * Returns the i-th key when encrypting.
	 */
	HalfBlock GetIterKeyToEncrypt(int i) const;
	/*
	 * ���������� i-� ���� ��� ������������.
	 * Returns the i-th key when decrypting.
	 */
	HalfBlock GetIterKeyToDecrypt(int i) const;
};

