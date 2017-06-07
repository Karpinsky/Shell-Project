#pragma once

#include <vector>
#include <string>

class ICommand
{
public:
	virtual ~ICommand() = 0 {}
	virtual bool Execute(std::vector<std::string>& options) = 0;
};