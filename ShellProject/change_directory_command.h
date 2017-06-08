#pragma once

#include "shell_command.h"

// Forward declared dependencies
class Shell;

class ChangeDirectoryCommand : public ShellCommand
{
public:
	ChangeDirectoryCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell* shell);
	virtual ~ChangeDirectoryCommand();

	void DisplayShortCommandDescription();
	void InitializeAdditionalCommandTriggers();

	CommandExecutionResult Execute(std::vector<std::string>& options);

private:
	Shell* shell_;
};

