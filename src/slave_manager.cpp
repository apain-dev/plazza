/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** started at 5/5/18
*/

#include <iostream>
#include "plazza_manager.hpp"
#include "slave_manager.hpp"
#include "slave.hpp"

/**
  *  @brief  Constructor of SlaveManager
  *  @param nbSlaves int number of slave
  */

SlaveManager::SlaveManager(int nbSlaves) : _nbSlaves(nbSlaves)
{
	for (int i = 0; i < _nbSlaves; i++) {
		auto newSlave = new Slave();
		newSlave->setSlaveManager(this);
		_slaves.emplace(_slaves.begin(), newSlave);
	}
	_disponibility = _nbSlaves;
	std::cout << "[DEBUG] " << _nbSlaves << " slaves created: "
		<< _disponibility << " dispo " << std::endl;
}

/**
  *  @brief  try to run cmd by finding a free slave
  *  @param cmd  string contening cmd
  *  @return  bool success or not
  */

bool SlaveManager::sendCmd(const std::string &cmd)
{
	Slave *freeSlave = findFreeSlave();

	if (!freeSlave)
		return (false);
	freeSlave->applyCmd(cmd);
	return (true);
}

/**
  *  @brief  try to find a free slave
  *  @return  Slave* | nullptr free slave
  */

Slave *SlaveManager::findFreeSlave()
{
	for (auto &_slave : _slaves) {
		if (_slave->getDisponibility())
			return _slave;
	}
	std::cout << "cannot find" << std::endl;
	return nullptr;
}

/*
 * Getter & setter
 */

void SlaveManager::increaseDisponibility()
{
	_disponibility++;
}

void SlaveManager::decreaseDisponibility()
{
	_disponibility--;
}

const std::vector<Slave *> &SlaveManager::getSlaves() const
{
	return _slaves;
}

void SlaveManager::setSlaves(const std::vector<Slave *> &slaves)
{
	_slaves = slaves;
}

PlazzaManager *SlaveManager::getPlazzaManager() const
{
	return _plazzaManager;
}

void SlaveManager::setPlazzaManager(PlazzaManager *plazzaManager)
{
	_plazzaManager = plazzaManager;
}

int SlaveManager::getDisponibility() const
{
	return _disponibility;
}

void SlaveManager::setDisponibility(int disponibility)
{
	_disponibility = disponibility;
}

int SlaveManager::getNbSlaves() const
{
	return _nbSlaves;
}

void SlaveManager::setNbSlaves(int nbSlaves)
{
	_nbSlaves = nbSlaves;
}

