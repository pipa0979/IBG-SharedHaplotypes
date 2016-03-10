/*
 * SortFile.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Piyush
 */
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string.h>
#include "SortFile.hpp"

namespace std
{
	ostream &operator<<(ostream &os, SortFile const &p)
	{
		return os << p.A() << " " << p.B() << " " << 	p.C()<< " "<<	p.D()<< " "<<p.X() << " " << p.Y() << " " << p.Z();
	}
}
struct byY
{
    bool operator()(SortFile const &a, SortFile const &b)
		{
			return a.Y() < b.Y();
		}
};
std::string SortFile::ComputeSorting(part ind)
{
	std::string filename=ind.fileName;
	std::ifstream file_old(filename.c_str());
	std::string sorted_file_name=filename.substr(0,filename.find(".int"))+ "_sorted"+".int";
	std::ofstream fileSorted(sorted_file_name.c_str());
	if(fileSorted.is_open())
		fileSorted<<"h_ID chr hap st en hap_index root_pop"<<"\n";
	else
	{
		std::cerr<<" Error Opening Sorted File "<<sorted_file_name<<std::endl;
		exit(0);
	}
    std::vector<SortFile> columns;
    std::string every;
    int count=0;
    while(getline(file_old,every))
		{
			std::stringstream ss;
			if (!strcmp("h_ID chr hap st en hap_index root_pop",every.c_str()))	/*Correct .int file is opened*/
					continue;
			ss<<every;
			ss>>ind.h_ID;	/*get the h_ID i..e the name of the individual from .int file*/
			ss>>ind.chr;
			ss>>ind.hap;
			ss>>ind.st;
			ss>>ind.en;
			ss>>ind.hap_index;
			ss>>ind.root_pop;
			ss.str("");
			ss.clear();	/*Clear state flags*/
			//std::cout<<ind.h_ID<<"	" <<ind.chr<<"	"<<ind.hap<<"	"<<ind.st<<"	"<<ind.en<<"	"<<ind.hap_index<<"	"<<ind.root_pop<<std::endl;
			columns.push_back(SortFile(ind.h_ID, ind.chr, ind.hap,ind.st,ind.en,ind.hap_index,ind.root_pop));
			//getchar();
		}
    std::sort(columns.begin(), columns.end(), byY());
    for(std::vector<SortFile>::iterator it = columns.begin(); it != columns.end(); ++it)
    	fileSorted<<*it<<"\n";
    file_old.close();
    fileSorted.close();
    return sorted_file_name;
}



