/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** started at 5/5/18
*/

#include <iostream>
#include "slave_manager.hpp"
#include "slave.hpp"

/**
  *  @brief  Constructor of Slave
  */

Slave::Slave() : _disponibility(true)
{
}

/**
  *  @brief  update disponibility of slave & SlaveManager
  *  @param disponibility  bool slave status
  *  @return  void
  */

void Slave::updateDisponibility(bool disponibility)
{
	if (!disponibility) {
		_slaveManager->decreaseDisponibility();
	} else {
		_slaveManager->increaseDisponibility();
	}
}

/**
  *  @brief  try to run cmd
  *  @param cmd  string contening cmd
  *  @return  bool success or not
  */

bool Slave::applyCmd(const std::string &cmd)
{
	bool ret = true;
	setDisponibility(false);

	std::cout << cmd << " is working" << std::endl;
	// TODO Launch real action

	return ret;
}

/*
 *	Getter & setter
 *
 */

bool Slave::getDisponibility() const
{
	return _disponibility;
}

void Slave::setDisponibility(bool disponibility)
{
	_disponibility = disponibility;
	updateDisponibility(disponibility);
}

SlaveManager *Slave::getSlaveManager() const
{
	return _slaveManager;
}

void Slave::setSlaveManager(SlaveManager *slaveManager)
{
	_slaveManager = slaveManager;
}
