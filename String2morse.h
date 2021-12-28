/*
    Author: NguyenTienLinh_20191924
*/
#include "Dictionary.h"
#include <iostream>
#include <string>

using namespace std;

// Hàm dùng để chuyển chuỗi text hợp lệ sang đoạn mã Morse tương ứng.
// Đầu vào là chuỗi string được copy ra từ file text. 
// Đầu ra: là đoạn mã Morse đã được dịch ra.
string Textmorse(string text){
    string code;
    for (int i = 0; i < text.length(); i++) 
    {
        if (text.at(i) != ' ') // kiểm tra dấu cách
        {
            if (i < text.length() - 1) 
            {
                code += Char2Morse(text.at(i)) + ' ';
            }
            else
            {
                code += Char2Morse(text.at(i));
            }
        }
        else 
        {
            code += '/';
            code += ' ';
        }
    }
    return code;
}