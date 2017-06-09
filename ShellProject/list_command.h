#pragma once

#include "shell_command.h"

class ListCommand : public ShellCommand<ListCommand>
{
public:
	ListCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options);
	virtual ~ListCommand();

	void DisplayShortCommandDescription();
	virtual void InitializeAdditionalCommandTriggers();
	virtual void InitializeOptionalActionCommands(ListCommand* child);

	CommandExecutionResult Execute(std::vector<std::string>& options);
};

