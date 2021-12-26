#include "Dictionary.h"
#include <iostream>
#include <string>

using namespace std;

// Hàm dùng để chuyển chuỗi text hợp lệ sang đoạn mã Morse tuong ứng.
// Đầu vào là con trỏ tới chuỗi string được copy ra từ file text. 
// Đầu ra: là một con trỏ tới vùng nhớ động được cấp phát có chứa đoạn mã Morse đã được dịch ra. (Cần xóa vùng bộ nhớ động được cấp phát sau khi dùng. )
string* Textmorse(string* text){
    string* code = new string;
    for (int i = 0; i < text->length(); i++)
    {
        if (text->at(i) != ' ')
        {
            *code += Char2Morse(text->at(i)) + ' ';
        }
        else *code += '/ ';
    }
    return code;
}

