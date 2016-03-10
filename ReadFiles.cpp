/*
 * ReadFiles.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: Piyush
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "ReadFiles.hpp"
bool ReadFiles::readFile(const std::string filename)
{
	setFileName(filename);
	bool flag;
	std::string each;
	std::ifstream fname(filename.c_str());
	if(!fname.is_open())
		{
			std::cerr<<filename<<" Cannot be opened! Please verify "<<std::endl;
			exit(0);
		}
	else
		getline(fname,each);
	if (!strcmp("h_ID chr hap st en hap_index root_pop",each.c_str()))	/*Correct .int file is opened*/
		{
			flag=true;
			fname.close();
		}
	else
		{
			std::cerr<<"Bad File / Files headings not correct. "
					<<"Please check the file heading's is in this following format"<<std::endl
					<<"h_ID chr hap st en hap_index root_pop"<<std::endl;
			exit(0);
		}
return flag;
}
std::string ReadFiles::getFileName()
{
	return fName;
}
void ReadFiles::setFileName(const std::string filename)
{
	fName=filename;
}
