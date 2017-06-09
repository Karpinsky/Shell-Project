#include "make_directory_command.h"

MakeDirectoryCommand::MakeDirectoryCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options) : ShellCommand<MakeDirectoryCommand>(commandKeyword, conditional_minimal_number_of_options)
{
}


MakeDirectoryCommand::~MakeDirectoryCommand()
{
}

void MakeDirectoryCommand::DisplayShortCommandDescription()
{
	std::cout << " ~ mkdir [-h|--help] <dirname> _ creates directory with a given name\n"
		" ~ !-> execution result\n"
		" ~ Examples:\n"
		// " ~ mkdir -h\n"
		// " ~ mkdir --help"
		" ~ mkdir My directory !-> My directory\n"
		" ~ mkdir My -h directory !-> My -h directory\n";
}

void MakeDirectoryCommand::InitializeAdditionalCommandTriggers()
{
}

void MakeDirectoryCommand::InitializeOptionalActionCommands(MakeDirectoryCommand* child)
{
	ShellCommand<MakeDirectoryCommand>::InitializeOptionalActionCommands(child);
}

// You can call mkdir followed by name of the directory, if first parameter after mkdir isn't -h or --help, 
// then even if you write 'name of -h my directory' the folder with the name 'name of -h my directory' will be created
// As in many shells - anything you write after -h or --help commands is disregarded
CommandExecutionResult MakeDirectoryCommand::Execute(std::vector<std::string>& options)
{
	std::string directory_name;
	switch (ShellCommand<MakeDirectoryCommand>::Execute(options))
	{
	case CommandExecutionResult::EXEC_COMMAND:
		return CommandExecutionResult::EXEC_COMMAND;

		break;
	case CommandExecutionResult::EXEC_SIZE:
		directory_name = options[1];

		for (std::vector<std::string>::iterator it = options.begin() + 2; it != options.end(); ++it)
		{
			directory_name.append(" " + *it);
		}

		try
		{
			if (bfs::create_directory(bfs::path{ directory_name }))
			{
				return CommandExecutionResult::EXEC_COMMAND;
			}
		}
		catch (bfs::filesystem_error err)
		{
			std::cout << "Inappropriate filename " << err.what() << std::endl;
		}

		perror("Could not create a directory at current path");

		break;
	}

	return CommandExecutionResult::EXEC_FAIL;
}
