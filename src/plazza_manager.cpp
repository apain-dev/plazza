/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** started at 5/5/18
*/

#include <iostream>

#include "plazza_manager.hpp"
#include "parser.hpp"

#include "slave_manager.hpp"
#include "result.hpp"
#include "slave.hpp"

/**
  *  @brief  Constructor of PlazzaManager
  *  @param nbSlaves int number of slave
  */

PlazzaManager::PlazzaManager(int nbSlaves) : _nbSlaves(nbSlaves)
{
	_parser = new Parser();
	_slaveManagers.emplace(_slaveManagers.begin(), createSlaveManager());
	std::thread t(&PlazzaManager::initSocket, this);
	t.detach();
	std::thread t2(&PlazzaManager::readResult, this);
	t2.detach();
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
	std::cout << ">";
	while (std::getline(std::cin, cmd)) {
		if (cmd.find("nbNotFreeSlave") != std::string::npos) {
			std::cout << "Slave who processed: "
				<< getNbNotFreeSlave() << std::endl;
		} else if (cmd.find("fuckOff") != std::string::npos) {
			std::cout << "ByeBye" << std::endl;
		} else if (cmd.find("nbFreeSlave") != std::string::npos) {
			std::cout << "Slaves who are jerking themself: "
				<< getNbFreeSlave() << std::endl;
		} else {
			_parser->cmdParser(cmd, this);
		}
		cmd.clear();
		std::cout << std::endl << "> ";
	}
}

/**
  *  @brief  try to run cmd by finding a free slave
  *  @param cmd  string contening cmd
  *  @return  bool success or not
  */

bool PlazzaManager::runCmd(const std::string &cmd, Information information)
{
	auto slave = findFreeSlaveManager();
	if (!slave)
		return false;
	slave->sendCmd(cmd, information);
	return true;
}

void PlazzaManager::initSocket()
{
	struct sockaddr_in in;
	int option = 1;

	_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_sock == -1) {
		perror("socket");
		return;
	}
	setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
	in.sin_family = AF_INET;
	in.sin_addr.s_addr = INADDR_ANY;
	in.sin_port = htons(8888);
	if (bind(_sock, (struct sockaddr *)&in, sizeof(in)) < 0) {
		perror("bind");
		return;
	}
	listen(_sock, this->_nbSlaves);
	listenClient();
}

void PlazzaManager::listenClient()
{
	struct sockaddr_in in_client;
	int sock_client;
	int c;
	Result *result;

	c = sizeof(struct sockaddr_in);
	while (42) {
		sock_client = accept(_sock, (struct sockaddr *)&in_client,
			(socklen_t *)&c);
		if (sock_client < 0)
			return;
		result = new Result(sock_client);
		_results.emplace_back(result);
	}
	close(_sock);
}

void PlazzaManager::readResult()
{
	for (auto it = _results.begin(); it != _results.end(); ++it) {
		Result *res = dynamic_cast<Result *>(*it);
		if (res->getFinished()) {

			for (auto &i: res->getResults()) {
				if (res->getResults()[0] == i) {
					std::cout << "Slave " << i
						<< " finished with results :"
						<< std::endl;
				} else
					std::cout << i << std::endl;
			}
			delete (*it);
			_results.erase(it);
			break;
		}
	}
	sleep(1);
	readResult();
}