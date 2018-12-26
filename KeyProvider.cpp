#include "KeyProvider.h"
#include <sstream>

KeyProvider::KeyProvider(const std::array<HalfBlock, 8>& data) : _data(data)
{
}

HalfBlock KeyProvider::GetIterKeyToEncrypt(int i) const
{
	if (i < 24)
		return _data[i % 8];
	return _data[7 - i % 8];
}

HalfBlock KeyProvider::GetIterKeyToDecrypt(int i) const
{
	if (i < 8)
		return _data[i];
	return _data[7 - i % 8];
}
