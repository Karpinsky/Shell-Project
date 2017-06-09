#include "shell.h"
#include "change_directory_command.h"



ChangeDirectoryCommand::ChangeDirectoryCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options, Shell* shell) : ShellCommand<ChangeDirectoryCommand>(commandKeyword, conditional_minimal_number_of_options)
{
	this->shell_ = shell;
}

ChangeDirectoryCommand::~ChangeDirectoryCommand()
{

}



void ChangeDirectoryCommand::UpdateCurrentDirectory()
{
	this->shell_->SetPath(bfs::current_path());
}

void ChangeDirectoryCommand::GoToParentDirectory()
{
	this->shell_->SetPath(this->shell_->GetPath().remove_filename());
}

void ChangeDirectoryCommand::DisplayShortCommandDescription()
{
	std::cout << " ~ cd [-h|--help] <path> _ change current directory to <path>\n"
		" ~ !-> execution result\n"
		" ~ Examples:\n"
		// " ~ cd -h\n"
		// " ~ cd --help"
		" ~ cd C:\\ !-> current path: C:\\ \n"
		" ~ cd F:\\Projects\\Say NO To War !-> current path: F:\\Projects\\Say NO To War\n";
}

void ChangeDirectoryCommand::InitializeAdditionalCommandTriggers()
{
}

void ChangeDirectoryCommand::InitializeOptionalActionCommands(ChangeDirectoryCommand* child)
{
	ShellCommand<ChangeDirectoryCommand>::InitializeOptionalActionCommands(child);

	// Update directory
	Action<ChangeDirectoryCommand>* optional_action_command = new Action<ChangeDirectoryCommand>();
	optional_action_command->AddAction(this, &ChangeDirectoryCommand::UpdateCurrentDirectory);
	this->optional_action_commands_.insert({".", optional_action_command});

	// Go to parent directory
	optional_action_command = new Action<ChangeDirectoryCommand>();
	optional_action_command->AddAction(this, &ChangeDirectoryCommand::GoToParentDirectory);
	this->optional_action_commands_.insert({ "..", optional_action_command });
}

CommandExecutionResult ChangeDirectoryCommand::Execute(std::vector<std::string>& options)
{
	switch (ShellCommand<ChangeDirectoryCommand>::Execute(options))
	{
	case CommandExecutionResult::EXEC_COMMAND:
		return CommandExecutionResult::EXEC_COMMAND;

		break;
	case CommandExecutionResult::EXEC_SIZE:
		this->shell_->SetPath(bfs::path{ options[1] });
		return CommandExecutionResult::EXEC_COMMAND;

		break;
	case CommandExecutionResult::EXEC_FAIL:
		std::cout << " ~ cd [-h|--help] <path>\n";

		break;
	}
	return CommandExecutionResult::EXEC_FAIL;
}
