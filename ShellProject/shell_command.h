#pragma once

#ifndef SHELLPROJECT_SHELL_COMMAND_H_
#define	SHELLPROJECT_SHELL_COMMAND_H_

#ifdef linux
#include <unistd.h>
#endif

#include <unordered_map>
#include <boost/filesystem.hpp>

#include "interface_command.h"
#include "action.h"

namespace bfs = boost::filesystem;

template<class Child>
class ShellCommand : public ICommand
{
public:
	ShellCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options);
	virtual ~ShellCommand();

	virtual void DisplayShortCommandDescription() = 0;

	virtual CommandExecutionResult Execute(std::vector<std::string>& options);

	std::string GetCommandKeyword();

protected:
	std::string command_keyword_;
	std::unordered_map<std::string, int> additional_command_triggers_;
	std::unordered_map<std::string, Action<Child>*> optional_action_commands_;

	size_t conditional_minimal_number_of_options_;

	virtual void InitializeAdditionalCommandTriggers() = 0;
	virtual void InitializeOptionalActionCommands(Child* child);
};

#endif // !SHELLPROJECT_SHELL_COMMAND_H_

template<class Child>
inline ShellCommand<Child>::ShellCommand(std::string commandKeyword, size_t conditional_minimal_number_of_options)
{
	this->command_keyword_ = commandKeyword;
	this->conditional_minimal_number_of_options_ = conditional_minimal_number_of_options;
}

template<class Child>
inline ShellCommand<Child>::~ShellCommand()
{
	for (std::unordered_map<std::string, Action<Child>*>::iterator it = this->optional_action_commands_.begin(); it != this->optional_action_commands_.end(); ++it)
	{
		delete it->second;
	}
}

template<class Child>
inline CommandExecutionResult ShellCommand<Child>::Execute(std::vector<std::string>& options)
{
	if (options.size() >= 2 && this->optional_action_commands_.find(options[1]) != this->optional_action_commands_.end())
	{
		this->optional_action_commands_[options[1]]->Invoke();
		return CommandExecutionResult::EXEC_COMMAND;
	}
	else if (options.size() >= this->conditional_minimal_number_of_options_)
	{
		return CommandExecutionResult::EXEC_SIZE;
	}
	return CommandExecutionResult::EXEC_FAIL;
}

template<class Child>
inline std::string ShellCommand<Child>::GetCommandKeyword()
{
	return this->command_keyword_;
}

template<class Child>
inline void ShellCommand<Child>::InitializeOptionalActionCommands(Child* child)
{
	Action<Child>* optional_action_command = new Action<Child>();
	optional_action_command->AddAction(child, &Child::DisplayShortCommandDescription);
	this->optional_action_commands_.insert({ "-h", optional_action_command });
	this->optional_action_commands_.insert({ "--help", optional_action_command });
}
