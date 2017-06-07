#include "make_directory_command.h"

MakeDirectoryCommand::MakeDirectoryCommand(std::string commandKeyword) : ShellCommand(commandKeyword)
{
}


MakeDirectoryCommand::~MakeDirectoryCommand()
{
}

void MakeDirectoryCommand::DisplayShortCommandDescription()
{
	std::cout << " ~ mkdir [-h|--help] <dirname> _ creates directory with a given name\n"
		" ~ !-> name of already created directory\n"
		" ~ Examples:\n"
		// " ~ mkdir -h\n"
		// " ~ mkdir --help"
		" ~ mkdir My directory !-> My directory\n"
		" ~ mkdir My -h directory !-> My -h directory\n";
}

void MakeDirectoryCommand::InitializeAdditionalCommandTriggers()
{
}

// You can call mkdir followed by name of the directory, if first parameter after mkdir isn't -h or --help, 
// then even if you write 'name of -h my directory' the folder with the name 'name of -h my directory' will be created
// As in many shells - anything you write after -h or --help commands is disregarded
bool MakeDirectoryCommand::Execute(std::vector<std::string>& options)
{
	if (options.size() < this->minimal_number_of_options)
	{
		return false;
	}
	else if (this->optional_action_commands_.find(options[1]) != this->optional_action_commands_.end())
	{
		this->optional_action_commands_[options[1]]->Invoke();
		return true;
	}

	std::string directory_name = options[1];

	for (std::vector<std::string>::iterator it = options.begin() + 2; it != options.end(); ++it)
	{
		directory_name.append(" " + *it);
	}

	if (bfs::create_directory(bfs::path { directory_name }))
	{
		return true;
	}

	perror("Could not create a directory at current path");
	return false;
}
