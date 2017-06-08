#pragma once

#include "shell_command.h"

class ListCommand : public ShellCommand
{
public:
	ListCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options);
	virtual ~ListCommand();

	void DisplayShortCommandDescription();
	void InitializeAdditionalCommandTriggers();

	CommandExecutionResult Execute(std::vector<std::string>& options);
};

