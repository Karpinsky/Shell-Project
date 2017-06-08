#include "list_command.h"



ListCommand::ListCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options) : ShellCommand(commandKeyword, conditional_minimal_number_of_options)
{

}


ListCommand::~ListCommand()
{

}

void ListCommand::DisplayShortCommandDescription()
{

}

void ListCommand::InitializeAdditionalCommandTriggers()
{
}

CommandExecutionResult ListCommand::Execute(std::vector<std::string>& options)
{
	return CommandExecutionResult::EXEC_FAIL;
}
