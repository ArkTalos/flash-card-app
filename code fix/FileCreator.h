#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileCreator
{
private:
	std::vector<std::string> fileName;
	std::string fileExtension;
public:
	FileCreator();
	~FileCreator();
	void setFileName(std::string fileName);
	void setFileExtension(std::string fileExtension);
	void createFile();
};

