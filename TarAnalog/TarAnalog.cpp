// TarAnalog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

void filecopy(std::ifstream &in, std::ofstream &out)
{
	char ch;
	while (in.get(ch))        
		out.put(ch);
}
int _tmain(int argc, _TCHAR* argv[])
{

	std::ifstream first("D:\\1.bin", std::ios::binary);
	std::ifstream second("D:\\2.bin", std::ios::binary);
	std::ofstream outfile("D:\\3.bin", std::ios::app | std::ios::binary);
	if (first) filecopy(first, outfile);
	if (second) filecopy(second, outfile);

	return 0;
}

