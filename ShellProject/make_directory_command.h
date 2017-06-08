#pragma once // This one should exclude the need of ifndef and define, but I don't know it for sure, so I still use both.

#ifndef SHELLPROJECT_MAKE_DIRECTORY_COMMAND_H_
#define SHELLPROJECT_MAKE_DIRECTORY_COMMAND_H_


#include "shell_command.h"

class MakeDirectoryCommand : public ShellCommand
{
public:
	MakeDirectoryCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options);
	virtual ~MakeDirectoryCommand();

	void DisplayShortCommandDescription();
	void InitializeAdditionalCommandTriggers();

	CommandExecutionResult Execute(std::vector<std::string>& options);
};

#endif // !SHELLPROJECT_MAKE_DIRECTORY_COMMAND_H_