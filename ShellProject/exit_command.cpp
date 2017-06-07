#include "shell.h"



ExitCommand::ExitCommand(std::string commandKeyword, Shell* shell) : ShellCommand(commandKeyword)
{	
	this->shell_ = shell;
}


ExitCommand::~ExitCommand()
{
}

void ExitCommand::DisplayShortCommandDescription()
{
}

void ExitCommand::InitializeAdditionalCommandTriggers()
{
}

bool ExitCommand::Execute(std::vector<std::string>& options)
{
	this->shell_->Stop();
	return true;
}
