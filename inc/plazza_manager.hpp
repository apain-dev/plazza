/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** started at 5/5/18
*/


#ifndef UNTITLED_PLAZZA_MANAGER_HPP
#define UNTITLED_PLAZZA_MANAGER_HPP

#include <vector>
#include <string>
#include "commands_enum.hpp"

class SlaveManager;
class Result;

class PlazzaManager {
	public:
	PlazzaManager(int _nbSlaves);

	void readUserInput();

	int getNbNotFreeSlave();

	int getNbFreeSlave();

	bool runCmd(const std::string &cmd, Information info);

	SlaveManager *findFreeSlaveManager();

	SlaveManager *createSlaveManager();

	void initSocket();
	void listenClient();

	void readResult();

	private:
	std::vector<SlaveManager *> _slaveManagers;
	std::vector<Result *> _results;
	std::string _cmd;
	int _nbSlaves;
	int _sock;
};

#endif //UNTITLED_PLAZZA_MANAGER_HPP
