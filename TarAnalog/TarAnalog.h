#pragma once // � ���� ��� ���� #pragma once, ��� ��� ������ #ifndef �� ����� ������

class TarAnalog
{
public:
	TarAnalog();
	TarAnalog(const std::string& name);
	~TarAnalog();

	void AddFile(const std::string& filename);
	void DeleteFile(const std::string& filename);
	void WriteInArch(const std::string& filename);
	void WriteAllInArch();

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
	std::string					mArchFilename;
	std::vector<std::string>	mFiles;
};
