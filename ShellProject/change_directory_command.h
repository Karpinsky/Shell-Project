#pragma once

#include "shell_command.h"

// Forward declared dependencies
class Shell;

class ChangeDirectoryCommand : public ShellCommand<ChangeDirectoryCommand>
{
public:
	ChangeDirectoryCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell* shell);
	virtual ~ChangeDirectoryCommand();

	void UpdateCurrentDirectory();
	void GoToParentDirectory();

	void DisplayShortCommandDescription();
	virtual void InitializeAdditionalCommandTriggers();
	virtual void InitializeOptionalActionCommands(ChangeDirectoryCommand* child);

	CommandExecutionResult Execute(std::vector<std::string>& options);

private:
	Shell* shell_;
};

