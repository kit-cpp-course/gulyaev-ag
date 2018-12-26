#include "HalfBlock.h"
#include "PermutationEngine.h"

HalfBlock::HalfBlock(const HalfBlockData& data) : _data(data)
{
}

HalfBlock::HalfBlock(const uint32_t value) : _data(value)
{
}

uint32_t HalfBlock::ToUint32() const
{
	return _data.to_ulong();
}

HalfBlock HalfBlock::LeftShift(int shift) const
{
	HalfBlockData result = _data;
	for (int i = 0; i < shift; i++)
	{
		const auto temp = result.test(31);
		result <<= 1;
		result.set(i, temp);
	}
	return HalfBlock(result);
}

HalfBlock HalfBlock::operator^(const HalfBlock& other) const
{
	HalfBlockData result{};
	for (int i = 0; i < 32; i++)
	{
		result.set(i, _data.test(i) ^ other._data.test(i));
	}
	return HalfBlock(result);
}

HalfBlock HalfBlock::operator+(const HalfBlock& other) const
{
	const uint32_t temp = static_cast<uint32_t>(_data.to_ullong() + other._data.to_ullong());
	return HalfBlock(temp);
}

HalfBlock HalfBlock::Permutate(const PermutationEngine& engine) const
{
	auto dataAfter = engine.Permutate(_data);
	return HalfBlock(dataAfter);
}
