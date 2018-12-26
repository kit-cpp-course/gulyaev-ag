#pragma once

/*
 * �����, ���������� ���������, ������������ � ���������.
 * A class containing constants used in the program.
 */

class SizeDefinition
{
public:
	/* 
	 * ������ ����� ����� - 4 �����.
	 * The size part of the block - 4 bytes.
	 */
	static const uint16_t BlockPart = 4;
	/*
	 * ������ �������� ����� - 32 �����.
	 * Half block size - 32 bytes.
	 */
	static const uint16_t HalfBlock = 32;
	/*
	 * ������ ����� - 64 �����.
	 * The size of the block - 64 bytes.
	 */
	static const uint16_t Block = 64;
	/*
	 * ������ ����� - 256 ����.
	 * The size part of the block - 256 bytes.
	 */
	static const uint16_t Key = 256;
};
