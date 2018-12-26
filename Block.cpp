#include "Block.h"
#include "HalfBlock.h"

Block::Block(const BlockData& data) : _data(data)
{
}

Block::Block(const uint64_t value) : _data(value)
{
}

Block::Block(const HalfBlock& left, const HalfBlock& right)
{
	const uint64_t value = (static_cast<uint64_t>(left.ToUint32()) << 32) + right.ToUint32();
	_data = BlockData(value);
}

uint64_t Block::ToUint64() const
{
	return _data.to_ullong();
}

HalfBlock Block::GetPart(Side side) const
{
	uint64_t temp = _data.to_ullong();
	if (side == Side::Left)
		temp >>= 32;
	return HalfBlock(temp);
}
