/*
 * ReadFiles.hpp
 *
 *  Created on: Feb 22, 2016
 *      Author: Piyush
 */

#ifndef READFILES_HPP_
#define READFILES_HPP_
#include <string>

class ReadFiles
{
public:
	std::string inpfilename;
	std::string outfilename;
	//std::string logfilename;
	bool readFile(const std::string,const std::string);	/*open and read the input file*/
	void setFileName(const std::string,const std::string);
	std::string getInpFileName();
	std::string getOutFileName();

};
#endif /* READFILES_HPP_ */
