/*
** EPITECH PROJECT, 2018
** plazza
** File description:
**  operation.hpp - jibs (CLion)
*/

#ifndef PLAZZA_OPERATION_HPP
# define PLAZZA_OPERATION_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include "commands_enum.hpp"

class Operation
{
	private:
	std::ifstream _fileStream;

	public:
	Operation();
	virtual ~Operation();
	int openFile(const std::string &file);
	int closeFile();
	int executeCommand(enum Information information);
	int findPhoneNumber();
};

#endif /* PLAZZA_OPERATION_HPP */
