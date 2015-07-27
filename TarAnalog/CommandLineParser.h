#pragma once
#include "stdafx.h"

class CommandLineParser
{
public:
	using ParamArguments = std::vector<std::string>;

	class ParamValue
	{
	public:
		std::string KeyName;
		ParamArguments Values;
	};

	CommandLineParser(int argc, const char* argv[]);

	const ParamArguments& operator[](const std::string paramName);

private:
	enum
	{
		kMaximumParams = 9000
	};

	std::vector<ParamValue>	mParamValues;

	class ParamInfo
	{
	public:
		std::string KeyName;
		uint8_t	ValuesCount; // 2^n - 1 ������, ��� ��������� �������� �� ��� ���, ���� �� �������� ���������, ���� ���� �� ���������� ������ ��������, ���, ������� ��� ���� ������ ��� ������ - ����� ����� ����������
	};


	using ParamInfoArray = std::array<ParamInfo, 5>;
	static const ParamInfoArray	kParamInfos;

	ParamInfoArray::const_iterator FindParamByKey(const std::string& keyName);

	bool IsKey(const std::string& keyName);
};