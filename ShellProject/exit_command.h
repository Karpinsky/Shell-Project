#pragma once

#ifndef SHELLPROJECT_EXIT_COMMAND_H_
#define SHELLPROJECT_EXIT_COMMAND_H_

#include "shell_command.h"

// Forward declared dependencies
class Shell;

class ExitCommand : public ShellCommand
{
public:
	ExitCommand(std::string commandKeyword, Shell* shell);
	virtual ~ExitCommand();

	void DisplayShortCommandDescription();
	void InitializeAdditionalCommandTriggers();

	bool Execute(std::vector<std::string>& options);

private:
	Shell* shell_;
};

#endif // !SHELLPROJECT_EXIT_COMMAND_H_

