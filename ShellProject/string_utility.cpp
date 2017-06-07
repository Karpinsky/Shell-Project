#include "string_utility.h"
#include <iostream>


std::vector<std::string> StringUtility::Split(std::string & stringValue, std::string & delimiter)
{
	std::vector<std::string> splitedStringVector;

	size_t last = 0;
	size_t next = 0;
	size_t delimiter_size = delimiter.size();
	while ((next = stringValue.find(delimiter, last)) != std::string::npos)
	{
		if (last != next)
		{
			splitedStringVector.push_back(stringValue.substr(last, next - last));
		}
		last = next + delimiter_size;
	}
	
	if (last < stringValue.size())
	{
		splitedStringVector.push_back(stringValue.substr(last));
	}

	return splitedStringVector;
}

void StringUtility::Split(std::string & stringValue, std::string & delimiter, std::vector<std::string>& splitedStringVector)
{
}
