/*
** EPITECH PROJECT, 2018
** untitled
** File description:
** started at 5/5/18
*/
#ifndef UNTITLED_PARSER_HPP
#define UNTITLED_PARSER_HPP

#include <vector>
#include <string>
#include <commands_enum.hpp>
#include <plazza_manager.hpp>

class Parser {
	public:
	Parser();
	std::vector<std::string> split(const std::string &test, char sep);
	Information isEnum(const std::string &cmd);
	void execCmd(Information info, const std::vector<std::string> &files, PlazzaManager *plazzaManager);
	bool cmdParser(const std::string &cmd, PlazzaManager *plazzaManager);
};

#endif //UNTITLED_PARSER_HPP
