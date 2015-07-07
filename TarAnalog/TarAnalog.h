#pragma once
#ifndef TARANALOG_H
#define TARANALOG_H

#include <vector>
#include <string>

class TarAnalog
{
private:
	const char* archfilename;
	std::vector<const char*> files;
public:
	TarAnalog();
	TarAnalog(const char* name);
	~TarAnalog();

	void addFile(const char* filename) { files.push_back(filename); }
	void deleteFile(const char* filename);
	void writeInArch(const char* filename);
	void writeAllInArch();
};
#endif
