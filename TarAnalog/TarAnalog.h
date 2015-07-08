#pragma once // у тебя уже есть #pragma once, все эти убогие #ifndef не нужны больше

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
IZ: приватные методы и поля всегда спускай вниз, когда человек смотрит класс, он обычно смотрит
публичные методы. Вообще, старайся структуировать класс так:

- public методы
- public поля
- protected методы
- protected поля
- private методы
- private поля
*/

private:
	std::string					mArchFilename;
	std::vector<std::string>	mFiles;
};
