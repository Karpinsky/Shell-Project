#pragma once

#ifndef SHELLPROJECT_SHELL_H_
#define SHELLPROJECT_SHELL_H_

#include "exit_command.h"
#include "change_directory_command.h"
#include "make_directory_command.h"
#include "list_command.h"
#include "print_working_directory_command.h"
#include "string_utility.h"

class Shell
{
public:
	Shell();
	Shell(bfs::path& startupPath);
	~Shell();

	void Run();
	void Stop(int exitCode = 1);
	bool IsRunning();

	bfs::path GetPath();
	void SetPath(bfs::path newPath);

private:
	bool is_running_;
	std::unordered_map<std::string, ICommand*> inner_commands_;
	std::unordered_map<std::string, ICommand*> outer_commands_;
	bfs::path current_path_;

	void InitializeCommands();
};

#endif  // SHELLPROJECT_SHELL_H_