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

bool Operation::openFile(const std::string &file)
{

	_fileStream.open(file);
	return (!_fileStream.good());
}

int Operation::closeFile()
{
	_fileStream.close();
	return 0;
}

bool Operation::executeCommand(enum Information information)
{
	switch (information) {
	case PHONE_NUMBER:
		findPhoneNumber();
		break;
	case EMAIL_ADDRESS:
		break;
	case IP_ADDRESS:
		findIPAdress();
		break;
	default:
		return true;
	}
	return false;
}



int Operation::findPhoneNumber()
{
	std::string line;
	std::regex phone_regex("[\\d\\s]{11,}");
	std::smatch phone_match;
	std::smatch m;

	while (getline(_fileStream, line)) {
		while (std::regex_search(line, m, phone_regex)) {
			for (auto &item: m)
				std::cerr << "Found: " << item << std::endl;
			line = m.suffix();
		}
	}
}

int Operation::findIPAdress()
{
	std::string line;
	std::regex ip_regex("(\\d{1,3})[.](\\d{1,3})[.](\\d{1,3})[.](\\d{1,3})");
	std::smatch phone_match;
	std::smatch m;

	while (getline(_fileStream, line)) {
		while (std::regex_search(line, m, ip_regex)) {
				std::cerr << "Found: " << m[0] << std::endl;
			line = m.suffix();
		}
	}
}
