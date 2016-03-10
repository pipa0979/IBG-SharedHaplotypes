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
	std::string fName;
	bool readFile(const std::string);	/*open and read the input file*/
	void setFileName(const std::string);
	std::string getFileName();
};
#endif /* READFILES_HPP_ */
