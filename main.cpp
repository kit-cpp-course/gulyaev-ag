#include "FileBlockProvider.h"
#include "MagmaEngine.h"
#include "CipherEngineFactory.h"

int main()
{
	const auto& rawProvider = FileBlockProvider("text.txt", "encrypt.txt");
	const auto& encryptedProvider = FileBlockProvider("encrypt.txt", "back.txt");
	const auto& builder = CipherEngineFactory("key.data", "table.data");

	const MagmaEngineBase * encrypter = builder.Build(MagmaEngineBase::EngineAction::Encrypt);
	const MagmaEngineBase * decrypter = builder.Build(MagmaEngineBase::EngineAction::Decrypt);

	encrypter->Proceed(rawProvider);
	decrypter->Proceed(encryptedProvider);

	delete encrypter;
	delete decrypter;
}
