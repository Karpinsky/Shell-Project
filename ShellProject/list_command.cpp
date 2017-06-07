#include "list_command.h"



ListCommand::ListCommand(std::string commandKeyword) : ShellCommand(commandKeyword)
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

bool ListCommand::Execute(std::vector<std::string>& options)
{
	// List items in directory
	std::cout << "Hello !" << std::endl;
	return false;
}
