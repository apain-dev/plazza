/*
** EPITECH PROJECT, 2018
** untitled
** File description:
** started at 5/5/18
*/
#include <iostream>
#include "plazza_manager.hpp"
#include "parser.hpp"

/**
 * @param text line to split
 * @param sep separator char
 * @return array of string
 */

std::vector<std::string> Parser::split(const std::string &text, char sep)
{
	std::vector<std::string> tokens;
	std::size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != std::string::npos) {
		if (end != start) {
			tokens.push_back(text.substr(start, end - start));
		}
		start = end + 1;
	}
	if (end != start) {
		tokens.push_back(text.substr(start));
	}
	return tokens;
}

/**
 *
 * @param cmd string to test
 * @return enum version of value
 */

Information Parser::isEnum(const std::string &cmd)
{
	if (cmd.find("EMAIL_ADDRESS") != std::string::npos)
		return (EMAIL_ADDRESS);
	else if (cmd.find("PHONE_NUMBER") != std::string::npos)
		return (PHONE_NUMBER);
	else if (cmd.find("IP_ADDRESS") != std::string::npos)
		return (IP_ADDRESS);
	else
		return (UNDEFINED);
}

/**
 *
 * @param info information to search
 * @param files list of files to read
 * @param plazzaManager instance of plazza
 */

void Parser::execCmd(Information info, const std::vector<std::string> &files,
	PlazzaManager *plazzaManager
)
{
	for (auto &i: files) {
		plazzaManager->runCmd(i, info);
	}
}

/**
 *
 * @param cmd input command argument
 * @param plazzaManager instance of plazzaManager
 * @return success || error
 */

bool Parser::cmdParser(const std::string &cmd, PlazzaManager *plazzaManager)
{
	auto vector = split(cmd, ';');
	std::vector<std::string> t;
	std::vector<std::string> files;
	Information info;

	for (auto &i : vector) {
		t = split(i, ' ');
		for (auto &v: t) {
			info = isEnum(v);
			if (info != UNDEFINED) {
				execCmd(info, files, plazzaManager);
				files.clear();
				t.clear();
				break;
			} else {
				files.emplace_back(v);
			}
		}
	}
	return true;

}

Parser::Parser()
{
}
