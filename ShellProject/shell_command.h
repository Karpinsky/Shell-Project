#pragma once

#ifndef SHELLPROJECT_SHELL_COMMAND_H_
#define	SHELLPROJECT_SHELL_COMMAND_H_

#ifdef linux
#include <unistd.h>
#endif

#include <unordered_map>
#include <string>
#include <boost/filesystem.hpp>

#include "interface_command.h"
#include "action.h"

namespace bfs = boost::filesystem;

class ShellCommand : public ICommand
{
public:
	ShellCommand(std::string commandKeyword);
	virtual ~ShellCommand();

	virtual void DisplayShortCommandDescription() = 0;
	

	std::string GetCommandKeyword();

protected:
	std::string command_keyword_;
	std::unordered_map<std::string, int> additional_command_triggers_;
	std::unordered_map<std::string, Action<ShellCommand>*> optional_action_commands_;

	const size_t minimal_number_of_options = 2;

	virtual void InitializeAdditionalCommandTriggers() = 0;
};

#endif // !SHELLPROJECT_SHELL_COMMAND_H_