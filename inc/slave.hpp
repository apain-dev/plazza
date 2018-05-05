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

class Slave {
	public:
	Slave();

	bool getDisponibility() const;

	void setDisponibility(bool _disponibility);

	SlaveManager *getSlaveManager() const;

	void setSlaveManager(SlaveManager *slaveManager);

	void updateDisponibility(bool disponibility);

	bool applyCmd(const std::string &cmd);

	private:
	bool _disponibility;
	SlaveManager *_slaveManager;
};

#endif //UNTITLED_SLAVE_HPP
