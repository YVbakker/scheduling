/*
 * Main.cpp
 *
 *  Created on: 24 Sep 2019
 *      Author: yvbakker
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Task.h"
#include "Job.h"
#include "Jobshop.h"
#include "vector"


int main(int argc, char **argv) {

	if(argc == 2){
		std::ifstream file;
		file.open(argv[1]);
		char c;
		std::string data;
		while(file >> c){data += c;};
		JobShop js(data);
		std::cout<<js.calc()<<std::endl;
	}
	else{
		std::cout<<"(1 argument expected) Please input exacly one text file containing configuration."<<std::endl;
	}
}
