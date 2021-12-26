//quan


#ifndef _ERRORCHECKING_H_
#define _ERRORCHECKING_H_

#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

bool check_open(char a[]);  //check if input file can open
bool check_exist_out(char a[]);// check if output file  exists 
bool check_type(string a);//check if input file is text or morse
void check_text(string s);//check error characters in file text
void check_morse(string s);//check error characters in file morse

#include "ErrorChecking.cpp"

#endif