/*
 * main.cpp
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */
#include <iostream>
#include "JobShop.h"
#include <fstream>

int main(int argc, char **argv) {
	std::string aFile;

	std::cin >> aFile;

	JobShop js1(aFile);
	js1.run();
}

