/*
  Author: NguyenTienLinh-20191924
*/ 

#include <iostream>
#include <string>
#include"Dictionary.h"
using namespace std;
// Hàm dùng để chuyển chuỗi text hợp lệ sang đoạn mã Morse tuong ứng.
// Đầu vào là  chuỗi string được copy ra từ file text. 
// Đầu ra: là  đoạn mã Morse tương ứng 
string Textmorse(string text){
    string code = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
        {
            code += Char2Morse(text[i]) + ' ';
        }
        else 
        {
            code += '/';
            code += ' ';
        }
    }
    code[code.length() - 1] = '\0';
    return code;
}

