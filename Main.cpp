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

	std::ifstream in(aFile);
	std::string stringFile((std::istreambuf_iterator<char>(in)),
			std::istreambuf_iterator<char>());

	JobShop js1(stringFile);
	js1.run();
}

