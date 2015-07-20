#include "stdafx.h"
#include "TarAnalog.h"

// IZ: �� ��������� ������������ ��������� ����� https://docs.unrealengine.com/latest/INT/Programming/Development/CodingStandard/index.html
// � ����� ���� ���� ������������ ������� ������ ���������

int _tmain(int argc, _TCHAR* argv[])
{
	bool flagPack = false;
	bool flagUnpack = false;
	bool flagFiles = false;
	TarAnalog Arch;
	//Arch.AddFile("file1.bin");
	//Arch.AddFile("file2.bin");
	//Arch.WriteAllInArch();
	if (argc <= 1)
	{
		std::cout << "Input arguments";
	}

	else
	{
		if (!_tcscmp(argv[2], _T("-pack")))
		{
			flagPack = true;
			std::cout << "Files packed" << std::endl;
		}
		if (!_tcscmp(argv[2], _T("-unpack")))
		{
			flagUnpack = true;
			std::cout << "Files unpacked" << std::endl;
		}
		/*if (!_tcscmp(argv[3], _T("-files")))
		{
			flagFiles = true;
			std::cout << "Choosed -files" << std::endl;
		}
		for (int i = 4; i < argc; i++)
		{
			if (flagFiles)
			{
				Arch.AddFile(argv[i]);
			}
		}*/
	}
	return 0;
}