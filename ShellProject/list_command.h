#pragma once

#include "shell_command.h"

class ListCommand : public ShellCommand
{
public:
	ListCommand(std::string commandKeyword);
	virtual ~ListCommand();

	void DisplayShortCommandDescription();
	void InitializeAdditionalCommandTriggers();

	bool Execute(std::vector<std::string>& options);
};

