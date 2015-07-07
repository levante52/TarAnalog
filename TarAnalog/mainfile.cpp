#include "stdafx.h"
#include "TarAnalog.h"

int _tmain(int argc, _TCHAR* argv[])
{
	TarAnalog Arch;
	/*std::vector<const char*> files;
	files.push_back("file1.bin");
	files.push_back("file2.bin");*/
	Arch.addFile("file1.bin");
	Arch.addFile("file2.bin");
	Arch.deleteFile("file1.bin");

	Arch.writeAllInArch();
	//Arch.writeInArch("Started.pdf");
	return 0;
}