#include "shell.h"



ChangeDirectoryCommand::ChangeDirectoryCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell* shell) : ShellCommand(commandKeyword, conditional_minimal_number_of_options)
{
	this->shell_ = shell;
}


ChangeDirectoryCommand::~ChangeDirectoryCommand()
{
}

void ChangeDirectoryCommand::DisplayShortCommandDescription()
{
}

void ChangeDirectoryCommand::InitializeAdditionalCommandTriggers()
{
}

CommandExecutionResult ChangeDirectoryCommand::Execute(std::vector<std::string>& options)
{

	return CommandExecutionResult::EXEC_FAIL;
}
