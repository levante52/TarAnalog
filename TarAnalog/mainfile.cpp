#include "stdafx.h"
#include "TarAnalog.h"

int _tmain(int argc, _TCHAR* argv[])
{
	TarAnalog Arch;
	/*std::vector<const char*> files;
	files.push_back("file1.bin");
	files.push_back("file2.bin");*/
	Arch.AddFile("file1.bin");
	Arch.AddFile("file2.bin");
	Arch.DeleteFile("file1.bin");

	Arch.WriteAllInArch();
	//Arch.writeInArch("Started.pdf");
	return 0;
}