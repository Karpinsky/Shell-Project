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
	std::unordered_map<std::string, Action<ShellCommand>*> optional_action_commands_;

	size_t conditional_minimal_number_of_options_;

	virtual void InitializeAdditionalCommandTriggers() = 0;
};

#endif // !SHELLPROJECT_SHELL_COMMAND_H_