/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** started at 5/5/18
*/

#include <iostream>
#include "plazza_manager.hpp"
#include "parser.hpp"

int main(int ac, char **av)
{
	if (ac == 2) {
		auto plazzaManager = new PlazzaManager(std::atoi(av[1]));
		plazzaManager->readUserInput();
	} else {
		std::cout << "./plazza nbSlave" << std::endl
			<< "nbSlave (int): number of slave" << std::endl;
	}
}