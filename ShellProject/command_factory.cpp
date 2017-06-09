#include "command_factory.h"



ChangeDirectoryCommand* CommandFactory::CreateChangeDirectoryCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell * shell)
{
	ChangeDirectoryCommand* command = new ChangeDirectoryCommand(commandKeyword, conditional_minimal_number_of_options, shell);
	command->InitializeAdditionalCommandTriggers();
	command->InitializeOptionalActionCommands(command);
	return command;
}

ExitCommand* CommandFactory::CreateExitCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell * shell)
{
	ExitCommand* command = new ExitCommand(commandKeyword, conditional_minimal_number_of_options, shell);
	command->InitializeAdditionalCommandTriggers();
	command->InitializeOptionalActionCommands(command);
	return command;
}

ListCommand* CommandFactory::CreateListCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options)
{
	ListCommand* command = new ListCommand(commandKeyword, conditional_minimal_number_of_options);
	command->InitializeAdditionalCommandTriggers();
	command->InitializeOptionalActionCommands(command);
	return command;
}

MakeDirectoryCommand* CommandFactory::CreateMakeDirectoryCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options)
{
	MakeDirectoryCommand* command = new MakeDirectoryCommand(commandKeyword, conditional_minimal_number_of_options);
	command->InitializeAdditionalCommandTriggers();
	command->InitializeOptionalActionCommands(command);
	return command;
}

CommandFactory::CommandFactory()
{
}