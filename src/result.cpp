/*
** EPITECH PROJECT, 2018
** plazza
** File description:
**  result.cpp - jibs (CLion)
*/

#include <thread>
#include "result.hpp"

Result::Result(int sock) : _sock(sock)
{
	_finished = false;
	std::thread thread(&Result::listen, this);
	thread.detach();
}

Result::~Result()
{
}

bool Result::getFinished() const
{
	return _finished;
}

std::vector<std::string> Result::getResults() const
{
	return _results;
}

int Result::readData()
{
	ssize_t ret = 0;
	char buffer[256];

	memset(buffer, '\0', 256);
	ret = read(_sock, buffer, 257);
	if (-1 == ret)
		return 1;
	if (buffer[0] == 0)
		return 0;
	for (ssize_t i = 0; i < ret; i++) {
		if (buffer[i] == '\n')
			buffer[i] = '\0';
	}
	if (strcmp(buffer, "END") == 0)
		return 1;
	_results.emplace_back(std::string(buffer));
	return 0;
}

void Result::listen()
{
	struct timeval time_val;
	int fd;
	fd_set fs;

	FD_ZERO(&fs);
	FD_SET(_sock, &fs);
	time_val.tv_sec = 3000;
	time_val.tv_usec = 0;
	while (1) {
		fd = select(_sock + 1, &fs, NULL, NULL, &time_val);
		if (fd < 1)
			close(_sock);
		else {
			if (1 == readData()) {
				close(_sock);
				break;
			}
		}
	}
	_finished = true;
	close(_sock);
}