#include "shell_command.h"



ShellCommand::ShellCommand(std::string commandKeyword)
{
	this->command_keyword_ = commandKeyword;

	Action<ShellCommand>* optional_action_command = new Action<ShellCommand>();
	optional_action_command->AddAction(&ShellCommand::DisplayShortCommandDescription);
	this->optional_action_commands_.insert({"-h", optional_action_command});
	this->optional_action_commands_.insert({"--help", optional_action_command });
}

ShellCommand::~ShellCommand()
{
}

std::string ShellCommand::GetCommandKeyword()
{
	return this->command_keyword_;
}
