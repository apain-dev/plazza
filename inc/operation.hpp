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
	bool openFile(const std::string &file);
	int closeFile();
	bool executeCommand(enum Information information, int sock);
	int findPhoneNumber(int sock);
	int findEmailAdress(int sock);
	int findIPAdress(int sock);

};

#endif /* PLAZZA_OPERATION_HPP */
