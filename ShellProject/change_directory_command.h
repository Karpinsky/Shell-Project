#pragma once

#include "shell_command.h"

class ChangeDirectoryCommand : public ShellCommand
{
public:
	ChangeDirectoryCommand(std::string commandKeyword);
	virtual ~ChangeDirectoryCommand();

	void DisplayShortCommandDescription();
	void InitializeAdditionalCommandTriggers();

	bool Execute(std::vector<std::string>& options);
};

