/*
 * main.cpp
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */
#include <iostream>
#include <fstream>

#include "JobShop.h"

int main(int argc, char **argv) {
	std::string aFile;
	if(argc == 2)
	{
		aFile = argv[1];
	}
	else{
		std::cin >> aFile;
	}
	JobShop js1(aFile);
	js1.run();
}

