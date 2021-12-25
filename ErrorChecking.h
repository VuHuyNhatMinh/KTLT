//quan


#ifndef _ERRORCHECKING_H_
#define _ERRORCHECKING_H_

#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

bool check_open(char a[]);  //check file vào
char check_exist_out(char a[]);//hàm check xem file đầu ra có exist hay không, return ký tự (y hoặc n) nếu đã tồn tại, return NULL nếu chưa tồn tại
bool check_type(string a);//check if a is text or morse
void check_text(string s);//check error characters in file text
void check_morse(string s);//check error character in file morse

#include "ErrorChecking.cpp"

#endif