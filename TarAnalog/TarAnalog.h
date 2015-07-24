#pragma once // у тебя уже есть #pragma once, все эти убогие #ifndef не нужны больше

class TarAnalog
{
public:
	TarAnalog();
	TarAnalog(const std::string& name);
	// IZ: деструктор тебе здесь не нужен, потому что в конструкторе ты ничего не выделяешь и не должна никакие ресурсы за собой подчищать
	// почитай про Rule of three https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)

	void Pack();
	void Unpack();
	void AddFile(const std::string& filename);

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
	void WriteInArch(const std::string& filename);
	void DeleteFile(const std::string& filename);
	void WriteAllInArch();

	std::string					mArchFilename; // IZ: используй STL, че ты. Все эти const char* - источник кучи багов и ошибок, C++, это вам не C
	std::vector<std::string>	mFiles;
	FILE* mArchFile = nullptr;	// файл - архив IZ: да, в C++11 можно делать и так, я так везде использую и тебе рекомендую, но это только C++11 и выше
};
