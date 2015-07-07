// TarAnalog.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "TarAnalog.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>


TarAnalog::TarAnalog()
{
	archfilename = "archFile.bin";
}

TarAnalog::TarAnalog(const char* name) : archfilename(name)
{
}

TarAnalog::~TarAnalog()
{
}

void TarAnalog::deleteFile(const char* filename)
{
	files.erase(std::remove(files.begin(), files.end(), filename), files.end() );
}
void TarAnalog::writeInArch(const char* filename) // функция записи одного файла в архив
{

	char byte[1];  // буфер для считывания одного байта
	FILE *archFile; // файл - архив
	FILE *file;   // файл для архивирования
	errno_t err1, err2;

	err1 = fopen_s(&archFile, archfilename, "a+");
	err2 = fopen_s(&file, filename, "rb");
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
}
void TarAnalog::writeAllInArch()// функция записи списка файлов в архив
{
	remove(archfilename); // удаляем всё что было раньше
	for (std::vector<const char*>::iterator itr = files.begin(); itr != files.end(); ++itr)
	{
		writeInArch(*itr);
	}

}
