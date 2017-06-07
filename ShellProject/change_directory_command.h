#pragma once

#include "shell_command.h"

class ChangeDirectoryCommand : public ShellCommand
{
public:
	ChangeDirectoryCommand(std::string commandKeyword, Shell* shell);
	virtual ~ChangeDirectoryCommand();

	void DisplayShortCommandDescription();
	void InitializeAdditionalCommandTriggers();

	bool Execute(std::vector<std::string>& options);

private:
	Shell* shell_;
};

