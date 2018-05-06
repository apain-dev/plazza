/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** started at 5/5/18
*/

#include <iostream>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "slave_manager.hpp"
#include "slave.hpp"


/**
  *  @brief  Constructor of Slave
  */

Slave::Slave() : _disponibility(true), _op(new Operation())
{
	_sock = -1;
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
  *  @param info Enum type de recherche
  *  @return  bool success or not
  */

bool Slave::applyCmd(const std::string &cmd, Information info)
{
	bool ret = true;
	setDisponibility(false);

	std::thread t(&Slave::launchThread, this, cmd, info);
	t.detach();
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

int Slave::connectSocket()
{
	struct sockaddr_in sock_addr;
	struct protoent *proto_ent;
	int sock;

	proto_ent = getprotobyname("TCP");
	if (NULL == proto_ent)
		return (-1);
	sock = socket(AF_INET, SOCK_STREAM,
		proto_ent->p_proto);
	if (-1 == sock)
		return (-1);
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sock_addr.sin_port = htons((unsigned short int)8888);
	if (1 == connect(sock,
		(struct sockaddr *)&sock_addr,
		sizeof(sock_addr)))
		return (-1);
	return (sock);
}

void Slave::sendThreadId()
{
	std::stringstream ss;
	std::string s;

	ss << _thread << std::endl;
	s = ss.str();
	write(_sock, s.c_str(), s.size());
}

void Slave::sendData(std::string const &s)
{
	usleep(10);
	write(_sock, s.c_str(), s.size());
}

void Slave::launchThread(const std::string &cmd, Information info)
{
	_sock = connectSocket();
	_thread = std::this_thread::get_id();
	if (-1 == _sock) {
		std::cerr << "Unable to connect to manager" << std::endl;
		return;
	}
	sendThreadId();
	if (_op->openFile(cmd)) {
		std::cerr << "Cannot open file" << std::endl;
		updateDisponibility(true);
		close(_sock);
		_sock = -1;
		return;
	}
	if (_op->executeCommand(info, _sock)) {
		std::cerr << "Cannot find info" << std::endl;
		updateDisponibility(true);
		close(_sock);
		_sock = -1;
		return;
	}
	sendData("END");
	updateDisponibility(true);
	close(_sock);
	_sock = -1;
}