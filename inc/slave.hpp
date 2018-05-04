//
// Created by arthur on 5/4/18.
//

#ifndef UNTITLED_SLAVE_HPP
#define UNTITLED_SLAVE_HPP

#include <string>
#include "slave_manager.hpp"

class Slave {
	public:
	Slave();

	bool get_disponibility() const;

	void set_disponibility(bool _disponibility);

	SlaveManager *get_slaveManager() const;

	void set_slaveManager(SlaveManager *_slaveManager);

	void update_disponibility(bool);

	bool apply_cmd(const std::string &);




	private:
	bool _disponibility;
	SlaveManager *_slaveManager;
};

#endif //UNTITLED_SLAVE_HPP
