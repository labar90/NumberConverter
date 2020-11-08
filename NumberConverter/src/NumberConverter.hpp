
#ifndef NUMBERCONVERSOR2_H
#define NUMBERCONVERSOR2_H

#include <vector>
#include <string>
#include <map>

class NumberConverter
{
public:
	NumberConverter();

	std::string convert(std::string text);
private:

	bool isWordInUnits(std::string word);
	bool isWordInScales(std::string word);

	bool isWordANumber(std::string word);

	std::vector<std::string> mUnits;
	std::vector<std::string> mTens;
	std::vector<std::string> mScales;

	std::map<std::string, std::pair<int,int>> mWordNumbers;

};

#endif
