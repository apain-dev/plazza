/*
** EPITECH PROJECT, 2018
** plazza
** File description:
**  result.hpp - jibs (CLion)
*/

#ifndef PLAZZA_RESULT_HPP
# define PLAZZA_RESULT_HPP

#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <cstring>

class Result {
	public:
	Result(int sock);
	virtual ~Result();
	void listen();
	int readData();
	bool getFinished() const;
	std::vector<std::string> getResults() const;

	private:
	int _sock;
	bool _finished;
	std::string _threadId;
	std::vector<std::string> _results;
};

#endif /* PLAZZA_RESULT_HPP */
