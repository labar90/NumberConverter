
#include <iostream>
#include <NumberConverter.hpp>
#include <map>

int main()
{
	//test : [test case] {sentece, expected}
	std::map< std::string, std::pair < std::string, std::string >> tests;

	tests["Number in the middle of a sentence"] = { "I have one hundred and thirty one apples", "I have 131 apples" };
	tests["Number in a sentece"] = { "one hundred and one", "101"};
	tests["mix 'and'"] = { "ten and one hundred or one hundred and ten ", "10 and 100 or 110" };
	tests["two continous numbers"] = { "three forty five", "3 45" };
	tests["two numbers with and in the middle"] = { "three and forty five", "3 and 45" };
	tests["two diffrent numbers in the middle of a sentece"] = { "I have one hundred and thirty one apples and two bananas", "I have 131 apples and 2 bananas" };
	tests["same begin number and end number"] = { "one hundred one thousand one hundred", "101100" };
	tests["two different number in the begining and in the end"] ={ "twenty years or thirty one", "20 years or 31" };
	tests["simple nummber"] = { "one hundred one thousand", "101000" };
	tests["Use of 'and' in a number"] = { "hundred and six", "106" };
	tests["Uppercase number"] = { "Twenty years or thirty one", "20 years or 31" };
	tests["Number in the middle of a sentence 2"] = { "I am thirty years old and i have fifty thousand euros", "I am 30 years old and i have 50000 euros" };
	tests["minimum number"] = { "Zero", "0" };
	tests["limit number"] = { "nine hundred ninety nine million nine hundred ninety nine thousand nine hundred and ninety nine", "999999999" };
	tests["maximum number"] = { "billion", "1000000000" };
	tests["same two simple numbers continous"] ={ "forty five forty five", "45 45" };
	tests["omit one"] ={ "hundred", "100" };
	tests["two continous numbers 2"] = { "One hundred forty five thousand six hundred and seven twenty two", "145607 22" };
	tests["complex number"] = { "four hundred million one thousand five hundred and eight", "400001508" };
	tests["one"] = { "one", "1" };

	NumberConverter converter;

	int passedTest = 0;
	int failedTest = 0;
	int totalTest = 0;
	for (auto& test : tests)
	{
		totalTest++;

		std::cout << "TEST CASE: " << totalTest << " " << test.first <<std::endl;
		std::cout << "Sentece: " << test.second.first << std::endl;

		std::cout << "Expected: " << test.second.second;
		std::cout << " - Result: " << converter.convert(test.second.first) << std::endl;
		if (test.second.second == converter.convert(test.second.first))
		{
			std::cout << "PASSED" << std::endl;
			passedTest++;
		}
		else
		{
			std::cout << "FAILED" << std::endl;
			failedTest++;
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;

	std::cout << "TOTAL TEST: " << totalTest << std::endl;
	std::cout << "FAILED TEST: " << failedTest << std::endl;
	std::cout << "PASSED TEST: " << passedTest << std::endl;


	return 0;
}
