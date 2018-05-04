//
// Created by arthur on 5/4/18.
//

#include "slave.hpp"

Slave::Slave()
{
}

bool Slave::get_disponibility() const
{
	return _disponibility;
}

void Slave::set_disponibility(bool _disponibility)
{
	Slave::_disponibility = _disponibility;
}

SlaveManager *Slave::get_slaveManager() const
{
	return _slaveManager;
}

void Slave::set_slaveManager(SlaveManager *_slaveManager)
{
	Slave::_slaveManager = _slaveManager;
}