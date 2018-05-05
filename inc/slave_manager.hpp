/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** started at 5/5/18
*/

#ifndef UNTITLED_SLAVE_MANAGER_HPP
#define UNTITLED_SLAVE_MANAGER_HPP

#include <vector>
#include <string>

class Slave;

#include "plazza_manager.hpp"

class SlaveManager {
	private:
	std::vector<Slave *> _slaves;
	PlazzaManager *_plazzaManager;
	int _disponibility;
	int _nbSlaves;

	public:
	explicit SlaveManager(int _nbSlaves);

	void increaseDisponibility();

	void decreaseDisponibility();

	const std::vector<Slave *> &getSlaves() const;

	void setSlaves(const std::vector<Slave *> &_slaves);

	PlazzaManager *getPlazzaManager() const;

	void setPlazzaManager(PlazzaManager *_plazzaManager);

	int getDisponibility() const;

	void setDisponibility(int _disponibility);

	int getNbSlaves() const;

	void setNbSlaves(int _nbSlaves);

	bool sendCmd(const std::string &);

	Slave *findFreeSlave();
};

#endif //UNTITLED_SLAVE_MANAGER_HPP
