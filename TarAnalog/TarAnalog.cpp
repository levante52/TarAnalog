// TarAnalog.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "TarAnalog.h"

TarAnalog::TarAnalog()
{
	mArchFilename = "archFile.bin";
}

TarAnalog::TarAnalog(const std::string& name) :
	mArchFilename(name) // IZ: на одной строке не круто, вот так получше
{
}

TarAnalog::~TarAnalog()
{
}

void TarAnalog::AddFile(const std::string& filename)
{
	mFiles.push_back(filename);
}

void TarAnalog::DeleteFile(const std::string& filename)
{
	mFiles.erase(std::remove(mFiles.begin(), mFiles.end(), filename), mFiles.end() );
}

void TarAnalog::WriteInArch(const std::string& filename) // функция записи одного файла в архив
{
	const size_t kBufferSize = 4096;
	char readBuffer[kBufferSize];  // буфер для считывания одного байта 
				   // IZ: считывать по одному байту очень долго, буфер должен быть хотя бы на 4 килобайта,
				   // это ускорит в разы

	// IZ: никогда не оставляй переменные непроинициализированными, особенно указатели
	// и не пиши int *x - это не труъ, int* x круче, потому что если тебе надо найти в коде потом все указатели на int,
	// это получится сделать проще, а то у некоторых есть такие штуки: int          *x
	FILE* archFile = nullptr; // файл - архив
	FILE* file = nullptr;   // файл для архивирования
	errno_t err1, err2;

	err1 = fopen_s(&archFile, mArchFilename.c_str(), "a+");
	err2 = fopen_s(&file, filename.c_str(), "rb");
	// переписываем информацию в архив
	if (err1 == 0 && err2 == 0)
	{
		while (!feof(file))
		{
			// IZ: переделано на считывание сразу кучи байтов
			size_t bytesRead = fread(readBuffer, 1, kBufferSize, file);
			fwrite(readBuffer, 1, bytesRead, archFile);
		}
	}

	fclose(file);
	fclose(archFile);
}

// IZ: пустая строка не помешает
void TarAnalog::WriteAllInArch()// функция записи списка файлов в архив
{
	remove(mArchFilename.c_str()); // удаляем всё что было раньше	
	for (const std::string& filename : mFiles) // IZ: range based for твой друг
	{
		WriteInArch(filename);
	}

}
