#pragma once

#include <vector>
#include <string>

enum class CommandExecutionResult {
	EXEC_FAIL,
	EXEC_SIZE,
	EXEC_COMMAND
};

class ICommand
{
public:
	virtual ~ICommand() = 0 {}
	virtual CommandExecutionResult Execute(std::vector<std::string>& options) = 0;
};