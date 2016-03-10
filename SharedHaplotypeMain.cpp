//============================================================================
// Name        : SharedHaplotypeMatching.cpp
// Author      : Piyush
// Version     :
// Copyright   :
// Description : Main Program. Entry gate.
//============================================================================
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include "ReadFiles.hpp"
#include "Part.hpp"

int main(int argc,char *argv[]) {
clock_t begin = clock();

ReadFiles inpfile;
std::string INPFILENAME="";
//std::string OUTPUTFILENAME="";
std::string LOGFILENAME="";


for (int i=0;i<argc;i++)
{
	if(strcmp(argv[i],"--in")==0)
	{
		INPFILENAME=argv[++i];
	}
	if (strcmp(argv[i],"--log")==0)
	{
		LOGFILENAME=argv[++i];
	}
}
//std::cout<<INPFILENAME<<std::endl;
//std::cout<<LOGFILENAME<<std::endl;

//exit(0);
/*ERROR CHECKING*/
if(strcmp(INPFILENAME.c_str(),"") ==0)
{
	std::cerr<<"--in <filename> not provided"<<std::endl;
	exit(0);
}
if (INPFILENAME.find(".int")!=std::string::npos)
{
	
}
else
{
	std::cerr<<"--in <filename> not provided"<<std::endl;
	exit(0);
		
}

if (strcmp(LOGFILENAME.c_str(),"") == 0)
{
	std::cerr<<"--log <filename> not provided"<<std::endl;
	exit(0);	
}

if(!inpfile.readFile(INPFILENAME))
{
	std::cerr<<"Couldn't open file "<<INPFILENAME<<" program is exiting"<<std::endl;
	exit(0);
}
part ind1(inpfile);
part ind2(inpfile);
part compute;
//compute.quickSort_hapindex(ind1);
compute.computation_haplotype(ind1,ind2);
clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

std::ofstream f_writelog;
f_writelog.open(LOGFILENAME.c_str());
if(!f_writelog.is_open())
		{
			std::cerr<<LOGFILENAME<<" Cannot be opened! Please verify "<<std::endl;
			exit(0);
		}
else
{

	f_writelog<<"The elapsed time is "<<elapsed_secs<<" seconds";
}
f_writelog.close();

return 0;
}
