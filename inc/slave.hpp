/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** started at 5/5/18
*/

#ifndef UNTITLED_SLAVE_HPP
#define UNTITLED_SLAVE_HPP

class SlaveManager;

#include <string>
#include <thread>
#include "operation.hpp"

class Slave {
	public:
	Slave();

	bool getDisponibility() const;

	void setDisponibility(bool _disponibility);

	SlaveManager *getSlaveManager() const;

	void setSlaveManager(SlaveManager *slaveManager);

	void updateDisponibility(bool disponibility);

	bool applyCmd(const std::string &cmd, Information info);

	int connectSocket();

	void launchThread(const std::string &cmd, Information info);

	void sendThreadId();

	void sendData(std::string const &s);

	private:
	bool _disponibility;
	SlaveManager *_slaveManager;
	std::thread::id _thread;
	Operation *_op;
	int _sock;
};

#endif //UNTITLED_SLAVE_HPP
