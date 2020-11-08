#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
class StringParser
{
public:

	static std::vector<std::string> parser(std::string string, std::string delimiter)
	{
		std::vector<std::string> result;
		size_t pos = 0;
		std::string token;
		while ((pos = string.find(delimiter)) != std::string::npos) {
			token = string.substr(0, pos);
			result.push_back(token);
			string.erase(0, pos + delimiter.length());
		}
		if(string != "")
		result.push_back(string);

		return result;
	}

	static std::string toLower(std::string string)
	{
		std::transform(string.begin(), string.end(), string.begin(), ::tolower);
		return string;
	}
};