#include "change_directory_command.h"



ChangeDirectoryCommand::ChangeDirectoryCommand(std::string commandKeyword) : ShellCommand(commandKeyword)
{

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
