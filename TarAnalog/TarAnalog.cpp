// TarAnalog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>



int _tmain(int argc, _TCHAR* argv[])
{

	char byte[1];  // буфер для считывания одного байта

	FILE *archFile; // файл - архив
	FILE *file;   // файл для архивирования
	errno_t err1, err2;

	err1 = fopen_s(&archFile, "archFile.bin", "wb");
	err2 = fopen_s(&file, "curFile.bin","rb");
	// переписываем информацию в архив
	if (err1 == 0 && err2 == 0)
	{
		while (!feof(file))
		{
			if (fread(byte, 1, 1, file) == 1)
				fwrite(byte, 1, 1, archFile);
		}
	}

	fclose(file);
	fclose(archFile);

	return 0;
}

