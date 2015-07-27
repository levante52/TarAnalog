#include "stdafx.h"
#include "TarAnalog.h"
#include "CommandLineParser.h"

// IZ: по кодстайлу настоятельно следовать этому https://docs.unrealengine.com/latest/INT/Programming/Development/CodingStandard/index.html
// и упаси тебя боже использовать пробелы вместо табуляции



int _tmain(int argc, _TCHAR* argv[])
{
	const char* params[] =
	{
		"tar.exe",
		"-i",
		"1.bin",
		"2.bin",
		"3.bin",
		"-o",
		"koryukina.rar",
		"-a"
	};

	CommandLineParser commandLineParser(sizeof(params) / sizeof(char*), params);

	bool flagPack = false;
	bool flagUnpack = false;
	bool flagFiles = false;
	TarAnalog Arch;

	if (argc <= 1)
	{
		std::cout << "Input arguments";
	}

	else
	{
		if (!_tcscmp(argv[1], _T("-pack")))
		{
			flagPack = true;
			std::cout << "Files packed" << std::endl;
		}
		if (!_tcscmp(argv[1], _T("-unpack")))
		{
			flagUnpack = true;
			std::cout << "Files unpacked" << std::endl;
		}
		if (!_tcscmp(argv[2], _T("-files")))
		{
			flagFiles = true;
		}
		for (int i = 3; i < argc; i++)
		{
			if (flagFiles)
			{
				Arch.AddFile(argv[i]);
			}
		}
	}
	if (flagPack)
	{
		Arch.Pack();
	}
	if(flagUnpack)
	{
		Arch.Unpack();
	}
	return 0;
}