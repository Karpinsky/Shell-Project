#include "list_command.h"



ListCommand::ListCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options) : ShellCommand<ListCommand>(commandKeyword, conditional_minimal_number_of_options)
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

void ListCommand::InitializeOptionalActionCommands(ListCommand* child)
{
	ShellCommand<ListCommand>::InitializeOptionalActionCommands(child);
}

CommandExecutionResult ListCommand::Execute(std::vector<std::string>& options)
{
	return CommandExecutionResult::EXEC_FAIL;
}
