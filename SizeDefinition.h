#pragma once

/*
 * Класс, содержащий константы, используемые в программе.
 * A class containing constants used in the program.
 */

class SizeDefinition
{
public:
	/* 
	 * Размер части блока - 4 байта.
	 * The size part of the block - 4 bytes.
	 */
	static const uint16_t BlockPart = 4;
	/*
	 * Размер половины блока - 32 байта.
	 * Half block size - 32 bytes.
	 */
	static const uint16_t HalfBlock = 32;
	/*
	 * Размер блока - 64 байта.
	 * The size of the block - 64 bytes.
	 */
	static const uint16_t Block = 64;
	/*
	 * Размер ключа - 256 байт.
	 * The size part of the block - 256 bytes.
	 */
	static const uint16_t Key = 256;
};
