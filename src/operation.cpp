/*
** EPITECH PROJECT, 2018
** plazza
** File description:
**  operation.cpp - jibs (CLion)
*/

#include "operation.hpp"

Operation::Operation()
{
}

Operation::~Operation()
{
}

int Operation::openFile(const std::string &file)
{

	_fileStream.open(file);
	if (!_fileStream.good())
		return 1;
	return 0;
}

int Operation::closeFile()
{
	_fileStream.close();
	return 0;
}

int Operation::executeCommand(enum Information information)
{
	switch (information) {
	case PHONE_NUMBER:
		findPhoneNumber();
		break;
	case EMAIL_ADDRESS:
		break;
	case IP_ADDRESS:
		break;
	default:
		break;
	}
}

int Operation::findPhoneNumber()
{
	std::string line;
	std::regex phone_regex("(?:[a-z0-9_-]+(?:\\.[a-z0-9!_-]+)*|\"(?:[\\x01-\\x08\\x0b\\x0c\\x0e-\\x1f\\x21\\x23-\\x5b\\x5d-\\x7f]|\\\\[\\x01-\\x09\\x0b\\x0c\\x0e-\\x7f])*\")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\\x01-\\x08\\x0b\\x0c\\x0e-\\x1f\\x21-\\x5a\\x53-\\x7f]|\\\\[\\x01-\\x09\\x0b\\x0c\\x0e-\\x7f])+)\\])");
	std::smatch phone_match;
	std::smatch m;

	while (getline(_fileStream, line)) {
		//std::cout << line << std::endl;
		if (std::regex_search(line.cbegin(), line.cend() ,m, phone_regex)) {
			for (auto x:m)
				std::cout << x << " ";
			std::cout << std::endl;
		}
	}
}