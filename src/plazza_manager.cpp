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
  *  @brief  Constructor of PlazzaManager
  *  @param nbSlaves int number of slave
  */

PlazzaManager::PlazzaManager(int nbSlaves) : _nbSlaves(nbSlaves)
{
	_slaveManagers.emplace(_slaveManagers.begin(), createSlaveManager());
}


/**
  *  @brief  create new SlaveManager and give it PlazzaManager instance
  *  @return  SlaveManager* new slave
  */

SlaveManager *PlazzaManager::createSlaveManager()
{
	std::cout << "[DEBUG] SlaveManager created" << std::endl;
	auto newSlaveManager = new SlaveManager(_nbSlaves);
	newSlaveManager->setPlazzaManager(this);

	return (newSlaveManager);
}

/**
  *  @brief  calculate number of slaves who are free
  *  @return  int not free slaves
  */

SlaveManager *PlazzaManager::findFreeSlaveManager()
{
	for (auto &slaveManager: _slaveManagers) {
		if (slaveManager->getDisponibility() > 0)
			return slaveManager;
	}
	_slaveManagers.emplace(_slaveManagers.begin(), createSlaveManager());
	return (_slaveManagers[0]);
}

/**
  *  @brief  calculate number of slaves who are free
  *  @return  int free slaves
  */


int PlazzaManager::getNbFreeSlave()
{
	int count = 0;

	for (auto &slaveManager: _slaveManagers) {
		count += slaveManager->getDisponibility();
	}
	return count;
}

/**
  *  @brief  calculate number of slaves who aren't free
  *  @return  int not free slaves
  */


int PlazzaManager::getNbNotFreeSlave()
{
	int count = getNbFreeSlave();

	return static_cast<int>(_slaveManagers.size() * _nbSlaves - count);
}

/**
  *  @brief  read user input and exec appropriate cmd
  */


void PlazzaManager::readUserInput()
{
	std::string cmd;
	bool running = true;

	while (running) {
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (cmd.find("nbNotFreeSlave") != std::string::npos) {
			std::cout << "Slave who processed: "
				<< getNbNotFreeSlave() << std::endl;
		} else if (cmd.find("fuckOff") != std::string::npos) {
			std::cout << "ByeBye" << std::endl;
			running = false;
		} else if (cmd.find("nbFreeSlave") != std::string::npos) {
			std::cout << "Slaves who are jerking themself: "
				<< getNbFreeSlave() << std::endl;
		} else {
			runCmd(cmd);
		}
		cmd.clear();
	}
}

/**
  *  @brief  try to run cmd by finding a free slave
  *  @param cmd  string contening cmd
  *  @return  bool success or not
  */

bool PlazzaManager::runCmd(const std::string &cmd)
{
	auto slave = findFreeSlaveManager();
	if (!slave)
		return false;
	slave->sendCmd(cmd);
	return true;
}
