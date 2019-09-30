/*
 * Main.cpp
 *
 *  Created on: 23 Sep 2019
 *      Author: yvbakker
 */

#include <iostream>
#include "Task.h"
#include "Job.h"
#include "JobShop.h"
#include "test.h"
#include <vector>
#include <fstream>
#include <regex>


int main(int argc, char **argv) {

	std::ifstream in("test.txt");
	std::string stringFile((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

	JobShop js1(stringFile);
	js1.run();
}
