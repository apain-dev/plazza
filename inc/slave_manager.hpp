//
// Created by arthur on 5/4/18.
//

#ifndef UNTITLED_SLAVE_MANAGER_HPP
#define UNTITLED_SLAVE_MANAGER_HPP

#include <vector>
class Slave;
#include "slave.hpp"
#include "plazza_manager.hpp"

class SlaveManager {
	public:
	explicit SlaveManager(int _nbSlaves);

	void increase_disponibility();

	void decrease_disponibility();

	const std::vector<Slave> &get_slaves() const;

	void set_slaves(const std::vector<Slave> &_slaves);

	PlazzaManager *get_plazzaManager() const;

	void set_plazzaManager(PlazzaManager *_plazzaManager);

	int get_disponibility() const;

	void set_disponibility(int _disponibility);

	int get_nbSlaves() const;

	void set_nbSlaves(int _nbSlaves);

	bool sendCmd(const std::string &);

	Slave find_free_slave();

	private:
	std::vector<Slave> _slaves;
	PlazzaManager *_plazzaManager;
	int _disponibility;
	int _nbSlaves;


};

#endif //UNTITLED_SLAVE_MANAGER_HPP
