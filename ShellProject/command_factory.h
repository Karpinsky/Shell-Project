#pragma once
#include "change_directory_command.h"
#include "exit_command.h"
#include "list_command.h"
#include "make_directory_command.h"


class CommandFactory
{
public:
	
	static ChangeDirectoryCommand* CreateChangeDirectoryCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell* shell);
	static ExitCommand* CreateExitCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell* shell);
	static ListCommand* CreateListCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options);
	static MakeDirectoryCommand* CreateMakeDirectoryCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options);

private:
	CommandFactory();
};

