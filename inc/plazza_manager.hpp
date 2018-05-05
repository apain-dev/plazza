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

class SlaveManager;

class PlazzaManager {
	public:
	PlazzaManager(int _nbSlaves);

	void readUserInput();

	int getNbNotFreeSlave();

	int getNbFreeSlave();

	bool runCmd(const std::string &cmd);

	SlaveManager *findFreeSlaveManager();

	SlaveManager *createSlaveManager();

	private:
	std::vector<SlaveManager *> _slaveManagers;
	std::string _cmd;
	int _nbSlaves;
};

#endif //UNTITLED_PLAZZA_MANAGER_HPP
