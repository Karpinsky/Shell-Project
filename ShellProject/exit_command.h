#pragma once

#ifndef SHELLPROJECT_EXIT_COMMAND_H_
#define SHELLPROJECT_EXIT_COMMAND_H_

#include "shell_command.h"

// Forward declared dependencies
class Shell;

class ExitCommand : public ShellCommand<ExitCommand>
{
public:
	ExitCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell* shell);
	virtual ~ExitCommand();

	void DisplayShortCommandDescription();
	virtual void InitializeAdditionalCommandTriggers();
	virtual void InitializeOptionalActionCommands(ExitCommand* child);

	CommandExecutionResult Execute(std::vector<std::string>& options);

private:
	Shell* shell_;
};

#endif // !SHELLPROJECT_EXIT_COMMAND_H_

