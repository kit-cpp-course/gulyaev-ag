#pragma once
#include "HalfBlock.h"
#include "KeyProvider.h"
#include "PermutationEngine.h"
#include "IBlockProvider.h"

/* 
 * ������� ����� ��� ���������� ���������� � ������������.
 * Base class to perform encryption and decryption.
 */

class MagmaEngineBase
{
private:
	HalfBlock function(const HalfBlock& block, const HalfBlock& key) const;

protected:
	const PermutationEngine _permutationEngine;

	const KeyProvider _keyProvider;

	virtual HalfBlock GetIterKey(const int i) const = 0;

public:
	/*
	 * ����� �������� - ���������� ��� ������������.
	 * The choice of action is encryption or decryption.
	 */
	enum class EngineAction { Encrypt, Decrypt };
	/*
	 * �����������, ����������� ����������� ��� ������ ������ ���������.
	 * A constructor that accepts the parameters necessary for the class to work.
	 */
	MagmaEngineBase(const PermutationEngine& engine, const KeyProvider& keyProvider);
	/*
	 * ������ �������� ��������� ������� ������.
	 * Start processing input data.
	 */
	void Proceed(const IBlockProvider& provider) const;
};

class MagmaEncrypt : public MagmaEngineBase
{
protected:
	HalfBlock GetIterKey(const int i) const override;

public:
	/*
	 * ���������� MagmaEngineBase ��� ���������� �������� ����������.
	 * An implementation of MagmaEngineBase for performing an encryption operation.
	 */
	MagmaEncrypt(const PermutationEngine& engine, const KeyProvider& keyProvider);
};

class MagmaDecrypt : public MagmaEngineBase
{
public:
	/*
	 * ���������� MagmaEngineBase ��� ���������� �������� ������������.
	 * An implementation of MagmaEngineBase for performing a decryption operation.
	 */
	MagmaDecrypt(const PermutationEngine& engine, const KeyProvider& keyProvider);

protected:
	HalfBlock GetIterKey(const int i) const override;
};
