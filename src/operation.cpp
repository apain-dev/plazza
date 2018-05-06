/*
** EPITECH PROJECT, 2018
** plazza
** File description:
**  operation.cpp - jibs (CLion)
*/

#include <unistd.h>
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

bool Operation::executeCommand(enum Information information, int sock)
{
	switch (information) {
	case PHONE_NUMBER:
		findPhoneNumber(sock);
		break;
	case EMAIL_ADDRESS:
		break;
	case IP_ADDRESS:
		findIPAdress(sock);
		break;
	default:
		return true;
	}
	return false;
}

int Operation::findPhoneNumber(int sock)
{
	std::string line;
	std::regex phone_regex("[\\d\\s]{11,}");
	std::smatch phone_match;
	std::smatch m;
	std::string s;

	while (getline(_fileStream, line)) {
		while (std::regex_search(line, m, phone_regex)) {
			for (auto &item: m) {
				std::stringstream ss;
				ss << item;
				s = ss.str();
				write(sock, s.c_str(), s.size());
			}
			line = m.suffix();
		}
	}
}

int Operation::findIPAdress(int sock)
{
	std::string line;
	std::regex ip_regex(
		"(\\d{1,3})[.](\\d{1,3})[.](\\d{1,3})[.](\\d{1,3})");
	std::smatch phone_match;
	std::smatch m;
	std::string s;

	while (getline(_fileStream, line)) {
		while (std::regex_search(line, m, ip_regex)) {
			std::stringstream ss;
			ss << m[0];
			s = ss.str();
			write(sock, s.c_str(), s.size());
			line = m.suffix();
		}
	}
}
