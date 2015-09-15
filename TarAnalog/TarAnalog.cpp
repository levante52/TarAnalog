// TarAnalog.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "TarAnalog.h"

TarAnalog::TarAnalog()
{
	mArchFilename = "archFile.bin";
	mInfoFile = "info.txt";
}

TarAnalog::TarAnalog(const std::string& name) :
	mArchFilename(name) // IZ: на одной строке не круто, вот так получше
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
	char readBuffer[kBufferSize];  
				   // IZ: считывать по одному байту очень долго, буфер должен быть хотя бы на 4 килобайта,
				   // это ускорит в разы

	// IZ: никогда не оставляй переменные непроинициализированными, особенно указатели
	// и не пиши int *x - это не труъ, int* x круче, потому что если тебе надо найти в коде потом все указатели на int,
	// это получится сделать проще, а то у некоторых есть такие штуки: int          *x
	FILE* file = nullptr;   // файл для архивирования
	errno_t errorCode = fopen_s(&file, filename.c_str(), "rb");

	// переписываем информацию в архив
	if (errorCode == 0)
	{
		while (!feof(file))
		{
			// IZ: переделано на считывание сразу кучи байтов
			size_t bytesRead = fread(readBuffer, 1, kBufferSize, file);
			fwrite(readBuffer, 1, bytesRead, mArchFile);
		}
	}
	if (file != NULL)
	{	
		fseek(file, 0, SEEK_END);
		mSizeOfFiles.push_back(ftell(file));
		fclose(file);
		file = nullptr;
	}
	
}
void TarAnalog::WriteInfo() // пишем информацию по заархивированным файлам
{
	std::ofstream f;
	f.open(mInfoFile.c_str(), std::ios::out);
	for (int i = 0; i < mFiles.size(); i++)
	{
		f << mFiles[i] << "\t" << mSizeOfFiles[i] << std::endl;
	}

	//закрытие потока
	f.close();

}

void TarAnalog::Pack()
{
	errno_t errorCode = fopen_s(&mArchFile, mArchFilename.c_str(), "wb+"); // IZ: файл архива не надо открывать каждый раз, когда ты в него пишешь, это бьет по перфомансу
	if (errorCode != 0)
	{
		return;
	}

	for (const std::string& filename : mFiles) // IZ: range based for твой друг
	{
		WriteInArch(filename);
	}
	fclose(mArchFile);
	WriteInfo();
}
void TarAnalog::Unpack()
{
	FILE* file = nullptr;
	const size_t kBufferSize = 4096;
	char readBuffer[kBufferSize];
	size_t sizeOfFile;
	size_t bytesRead;


	errno_t errorCode = fopen_s(&mArchFile, mArchFilename.c_str(), "rb+"); 
	if (errorCode != 0)
	{
		return;
	}
	int i = 0;
	for (const std::string& filename : mFiles) 
	{
		errno_t errorCode = fopen_s(&file, filename.c_str(), "wb+");
		if (errorCode != 0)
		{
			return;
		}
		bytesRead = 0;
		bytesRead = fread(readBuffer, 1, mSizeOfFiles[i], mArchFile);
		fwrite(readBuffer, 1, bytesRead, file);
		std::cout << bytesRead << std::endl;
		
		fclose(file);
		i++;
	}
	fclose(mArchFile);
	
}
