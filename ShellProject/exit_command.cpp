#include "shell.h"



ExitCommand::ExitCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell* shell) : ShellCommand<ExitCommand>(commandKeyword, conditional_minimal_number_of_options)
{	
	this->shell_ = shell;
}


ExitCommand::~ExitCommand()
{
}

void ExitCommand::DisplayShortCommandDescription()
{
	std::cout << " ~ exit [-h|--help] [exit code] _ exits shell\n"
		" ~ !-> execution result\n"
		" ~ Examples:\n"
		// " ~ exit -h\n"
		// " ~ exit --help"
		" ~ exit !-> Shell execution stopped with code: 1\n"
		" ~ exit 371 !-> Shell execution stopped with code: 371\n";
}

void ExitCommand::InitializeAdditionalCommandTriggers()
{
}

void ExitCommand::InitializeOptionalActionCommands(ExitCommand* child)
{
	ShellCommand<ExitCommand>::InitializeOptionalActionCommands(child);
}

CommandExecutionResult ExitCommand::Execute(std::vector<std::string>& options)
{
	switch (ShellCommand<ExitCommand>::Execute(options))
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
		return CommandExecutionResult::EXEC_COMMAND;

		break;
	}

	return CommandExecutionResult::EXEC_FAIL;
}
