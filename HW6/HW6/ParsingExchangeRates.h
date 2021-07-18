
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>  
#include <cstdio> 


const std::string DOLLAR = "USD";
const std::string EURO = "EUR";

void parsing();
void copyFile(std::ifstream& fin, std::ofstream& fout, size_t lineDelete, size_t nPosition);
void findWord(std::string word, std::string fileName);

