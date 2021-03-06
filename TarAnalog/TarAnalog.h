#pragma once // � ���� ��� ���� #pragma once, ��� ��� ������ #ifndef �� ����� ������

class TarAnalog
{
public:
	TarAnalog();
	TarAnalog(const std::string& name);
	// IZ: ���������� ���� ����� �� �����, ������ ��� � ������������ �� ������ �� ��������� � �� ������ ������� ������� �� ����� ���������
	// ������� ��� Rule of three https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)

	void Pack();
	void Unpack();
	void AddFile(const std::string& filename);

/*
IZ: ��������� ������ � ���� ������ ������� ����, ����� ������� ������� �����, �� ������ �������
��������� ������. ������, �������� �������������� ����� ���:

- public ������
- public ����
- protected ������
- protected ����
- private ������
- private ����
*/

private:
	void WriteInArch(const std::string& filename);
	void DeleteFile(const std::string& filename);
	void WriteInfo();
	void ReadInfo();

	std::string					mArchFilename; // IZ: ��������� STL, �� ��. ��� ��� const char* - �������� ���� ����� � ������, C++, ��� ��� �� C
	std::string					mInfoFile;
	std::vector<std::string>	mFiles;
	std::vector<std::size_t>	mSizeOfFiles;
	FILE* mArchFile = nullptr;	// ���� - ����� IZ: ��, � C++11 ����� ������ � ���, � ��� ����� ��������� � ���� ����������, �� ��� ������ C++11 � ����
};
