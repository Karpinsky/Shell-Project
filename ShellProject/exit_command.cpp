#include "shell.h"



ExitCommand::ExitCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell* shell) : ShellCommand(commandKeyword, conditional_minimal_number_of_options)
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

CommandExecutionResult ExitCommand::Execute(std::vector<std::string>& options)
{
	switch (ShellCommand::Execute(options))
	{
	case CommandExecutionResult::EXEC_COMMAND:
		return CommandExecutionResult::EXEC_COMMAND;

		break;
	case CommandExecutionResult::EXEC_SIZE:
		try 
		{
			this->shell_->Stop(std::stoi(options[1]));
		}
		catch (std::invalid_argument err)
		{
			perror("Invalid exit code. Program execution eded with default code.\n");
			this->shell_->Stop();
		}
		return CommandExecutionResult::EXEC_COMMAND;
		
		break;
	case CommandExecutionResult::EXEC_FAIL:
		this->shell_->Stop();

		break;
	}
}
