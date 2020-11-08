#include "NumberConverter.hpp"
#include "StringParser.hpp"
#include <cmath>

NumberConverter::NumberConverter()
{	
	mUnits = {"zero", "one", "two", "three", "four", "five", "six", "seven", 
		"eight", "nine", "ten","eleven", "twelve", "thirteen", "fourteen", 
		"fifteen","sixteen", "seventeen", "eighteen", "nineteen"};

	mTens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	mScales = {"hundred", "thousand", "million", "billion"};

    mWordNumbers["and"] = { 1, 0 };

	for (int i = 0; i < mUnits.size(); i++)
	{
        mWordNumbers[mUnits[i]] = {1, i};
	}

	for (int i = 1; i < mTens.size(); i++)
	{
        mWordNumbers[mTens[i]] = { 1, i*10 };
	}

	for (int i = 0; i < mScales.size(); i++)
	{
		if (i == 0)
            mWordNumbers[mScales[i]] = { 100, 0 };
		else
            mWordNumbers[mScales[i]] = { static_cast<int>(std::pow(10, (i * 3))), 0 };
	}
}

std::string NumberConverter::convert(std::string text)
{
    int result = 0;
	int current = 0;
	bool isNumber = false;
    bool isLastWordAUnit = false;
    bool isLastWordAScale = false;

	std::string currentString;

    for (auto& word : StringParser::parser(text, " "))
    {
       auto lowerCaseWord = StringParser::toLower(word);

        if (!isWordANumber(lowerCaseWord) || (lowerCaseWord == "and" && !isLastWordAScale))
        {
            if (isNumber) currentString += std::to_string(result + current) + " ";

            currentString += word + " ";
            result = 0;
            current = 0;
            isNumber = false;
        }
        else 
        {
            auto scale = mWordNumbers[lowerCaseWord].first;
            auto increment = mWordNumbers[lowerCaseWord].second;

            if (isLastWordAUnit && !isWordInScales(lowerCaseWord))
            {
                currentString += std::to_string(result + current) + " ";
                result = 0;
                current = 0;
            }
            if (scale > 1) current = std::max(1, current);

            current = current * scale + increment;

            if (scale > 100)
            {
                result += current;
                current = 0;
            }
            isNumber = true;
        }
        isLastWordAScale = isWordInScales(lowerCaseWord);
        isLastWordAUnit = isWordInUnits(lowerCaseWord);
    }
    if (isNumber) currentString += std::to_string(result + current);
    if (currentString[currentString.size() - 1] == ' ') currentString.resize(currentString.size() - 1);
    return currentString;
}

bool NumberConverter::isWordInUnits(std::string word)
{
    return std::find(mUnits.begin(), mUnits.end(), word) != mUnits.end();
}

bool NumberConverter::isWordInScales(std::string word)
{
    return std::find(mScales.begin(), mScales.end(), word) != mScales.end();
}

bool NumberConverter::isWordANumber(std::string word)
{
    return mWordNumbers.find(word) != mWordNumbers.end();
}
