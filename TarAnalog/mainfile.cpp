#include "stdafx.h"
#include "TarAnalog.h"

// IZ: по кодстайлу настоятельно следовать этому https://docs.unrealengine.com/latest/INT/Programming/Development/CodingStandard/index.html
// и упаси тебя боже использовать пробелы вместо табуляции

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