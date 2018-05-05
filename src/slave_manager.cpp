/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** started at 5/5/18
*/

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
	std::thread t(&SlaveManager::initSocket, this);
	t.detach();
	_server = t.get_id();
}

/**
  *  @brief  try to run cmd by finding a free slave
  *  @param cmd  string contening cmd
  *  @return  bool success or not
  */

bool SlaveManager::sendCmd(const std::string &cmd)
{
	std::string delimiter = ";";
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

void SlaveManager::initSocket()
{
	struct sockaddr_in in;
	struct sockaddr_in in_client;
	int sock;
	int sock_client;
	int c;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("socket");
		return;
	}
	in.sin_family = AF_INET;
	in.sin_addr.s_addr = INADDR_ANY;
	in.sin_port = htons(8888);
	if (bind(sock, (struct sockaddr *)&in, sizeof(in)) < 0) {
		perror("bind");
		return;
	}
	listen(sock, this->_nbSlaves);
	c = sizeof(struct sockaddr_in);
	while (42) {
		sock_client = accept(sock, (struct sockaddr *)&in_client,
			(socklen_t *)&c);
		if (sock_client < 0)
			return;
	}
}
