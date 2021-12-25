#include "Dictionary.h"
#include <iostream>
#include <string>

using namespace std;

string Textmorse(string text){
    string code = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
        {
            code += Char2Morse(text[i]) + ' ';
        }
        else code += '/';
    }
    return code;
}

