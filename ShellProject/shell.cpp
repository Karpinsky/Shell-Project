#include "shell.h"

using namespace std;


Shell::Shell()
{
	this->is_running_ = false;
	this->current_path_ = bfs::current_path();

	this->InitializeCommands();
}

Shell::Shell(bfs::path& startupPath) : Shell()
{
	bfs::current_path(startupPath);
	this->current_path_ = startupPath;
}

Shell::~Shell()
{
	for (auto it = this->inner_commands_.begin(); it != this->inner_commands_.end(); ++it)
	{
		delete it->second;
	}
}

void Shell::Run()
{
	if (this->is_running_)
	{
		cout << "The shell is already running";
		throw -1;
	}
	this->is_running_ = true;

	char user_command_input[1024];

	while (this->is_running_)
	{
		cout << this->current_path_.string() << ":~ ^_^ ";
		cin.getline(user_command_input, 1024);

		std::string delimiter = " ";
		std::vector<std::string> additional_options = StringUtility::Split(std::string(user_command_input), delimiter);

		if (this->inner_commands_.find(additional_options[0]) != this->inner_commands_.end())
		{
			this->inner_commands_[additional_options[0]]->Execute(additional_options);
		}
		else if (this->outer_commands_.find(additional_options[0]) != this->outer_commands_.end())
		{
#ifdef linux
			pid_t pid = fork();
			if (!pid)
			{
				this->outer_commands_[additional_options[0]]->Execute(additional_options);
				break;
			}
			else if (pid == -1)
			{
				perror("Could not fork the process");
			}
#else
			this->outer_commands_[additional_options[0]]->Execute(additional_options);
#endif
		}
		else
		{
			cout << "Unrecognised command. Notice me Senpai!" << endl;
		}
	}
}

void Shell::Stop() 
{
	this->is_running_ = false;
}

bool Shell::IsRunning()
{
	return this->is_running_;
}

void Shell::SetPath(bfs::path& newPath)
{
	bfs::current_path(newPath);
	this->current_path_ = newPath;
}

void Shell::InitializeCommands()
{
	std::string exit_command_keyword = "exit";
	this->inner_commands_.insert({ exit_command_keyword, new ExitCommand(exit_command_keyword, this) });

	std::string change_directory_command_keyword = "cd";
	this->inner_commands_.insert({ change_directory_command_keyword, new ChangeDirectoryCommand(change_directory_command_keyword) });

	std::string make_directory_command_keyword = "mkdir";
	this->outer_commands_.insert({ make_directory_command_keyword, new MakeDirectoryCommand(make_directory_command_keyword) });

	std::string list_command_keyword = "ls";
	this->outer_commands_.insert({ list_command_keyword, new ListCommand(list_command_keyword) });

	// std::string print_working_directory_command_keyword = "pwd";
	// this->inner_commands.insert({ print_working_directory_command_keyword, new PrintWorkingDirectoryCommand(print_working_directory_command_keyword) });

	// Your try

	// Im going to add string split() to shell in this cpp file after you initialize those new commands in here because of merge on git
	// So you can leave additional options to be additional_options.push_back("-h"); for now, without adding additional options fucntional to commands
}
