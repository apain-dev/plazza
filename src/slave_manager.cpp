//
// Created by arthur on 5/4/18.
//

#include "slave_manager.hpp"

SlaveManager::SlaveManager(int _nbSlaves) : _nbSlaves(_nbSlaves),
	_disponibility(0)
{
}

const std::vector<Slave> &SlaveManager::get_slaves() const
{
	return _slaves;
}

void SlaveManager::set_slaves(const std::vector<Slave> &_slaves)
{
	SlaveManager::_slaves = _slaves;
}

PlazzaManager *SlaveManager::get_plazzaManager() const
{
	return _plazzaManager;
}

void SlaveManager::set_plazzaManager(PlazzaManager *_plazzaManager)
{
	SlaveManager::_plazzaManager = _plazzaManager;
}

int SlaveManager::get_disponibility() const
{
	return _disponibility;
}

void SlaveManager::set_disponibility(int _disponibility)
{
	SlaveManager::_disponibility = _disponibility;
}

int SlaveManager::get_nbSlaves() const
{
	return _nbSlaves;
}

void SlaveManager::set_nbSlaves(int _nbSlaves)
{
	SlaveManager::_nbSlaves = _nbSlaves;
}
