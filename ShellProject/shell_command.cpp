#include "shell_command.h"



ShellCommand::ShellCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options)
{
	this->command_keyword_ = commandKeyword;
	this->conditional_minimal_number_of_options_ = conditional_minimal_number_of_options;

	Action<ShellCommand>* optional_action_command = new Action<ShellCommand>();
	optional_action_command->AddAction(&ShellCommand::DisplayShortCommandDescription);
	this->optional_action_commands_.insert({"-h", optional_action_command});
	this->optional_action_commands_.insert({"--help", optional_action_command });
}

ShellCommand::~ShellCommand()
{
}

CommandExecutionResult ShellCommand::Execute(std::vector<std::string>& options)
{
	if (options.size() >= 2 && this->optional_action_commands_.find(options[1]) != this->optional_action_commands_.end())
	{
		this->optional_action_commands_[options[1]]->Invoke();
		return CommandExecutionResult::EXEC_COMMAND;
	}
	else if (options.size() >= this->conditional_minimal_number_of_options_)
	{
		return CommandExecutionResult::EXEC_SIZE;
	}
	return CommandExecutionResult::EXEC_FAIL;
}

std::string ShellCommand::GetCommandKeyword()
{
	return this->command_keyword_;
}
