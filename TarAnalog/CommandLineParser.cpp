#include "stdafx.h"
#include "CommandLineParser.h"

CommandLineParser::CommandLineParser(int argc, const char* argv[])
{
	int argCounter = 1;

	while (argCounter < argc)
	{
		std::string argValue = argv[argCounter];
		if (IsKey(argValue))
		{
			ParamValue paramValue;
			paramValue.KeyName = argValue;

			int keyValuesCount = FindParamByKey(argValue)->ValuesCount;

			int i = 0;
			for (i = argCounter + 1; i < std::min(argCounter + keyValuesCount + 1, argc); ++i)
			{
				std::string currentArgValue(argv[i]);
				if (IsKey(currentArgValue))
				{
					break;
				}

				paramValue.Values.push_back(currentArgValue);

			}
			argCounter = i;
			mParamValues.push_back(paramValue);
		}
		else
		{
			++argCounter;
		}
	}
}

const CommandLineParser::ParamArguments& CommandLineParser::operator[](const std::string paramName)
{
	auto paramIt = std::find_if(mParamValues.begin(), mParamValues.end(), [&](const ParamValue& paramValue)
	{
		return paramName == paramValue.KeyName;
	});

	if (paramIt != mParamValues.end())
	{
		return paramIt->Values;
	}

	throw std::runtime_error("Can't find a such param value!");
}

CommandLineParser::ParamInfoArray::const_iterator CommandLineParser::FindParamByKey(const std::string& keyName)
{
	return std::find_if(kParamInfos.begin(), kParamInfos.end(), [&](const ParamInfo& paramInfo)
	{
		return paramInfo.KeyName == keyName;
	});
}

bool CommandLineParser::IsKey(const std::string& keyName)
{
	return FindParamByKey(keyName) != kParamInfos.end();
}

const CommandLineParser::ParamInfoArray CommandLineParser::kParamInfos
{ {
	{ "-i", ~0 },
	{ "-o", 1 },
	{ "-a", 0 },
	{ "-x", 0 },
	{ "-l", 0 }
	} };