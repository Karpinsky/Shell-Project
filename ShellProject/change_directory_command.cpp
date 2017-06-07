#include "shell.h"



ChangeDirectoryCommand::ChangeDirectoryCommand(std::string commandKeyword, Shell* shell) : ShellCommand(commandKeyword)
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

bool ChangeDirectoryCommand::Execute(std::vector<std::string>& options)
{
	return false;
}
