#include "Dictionary.h"
#include <iostream>
#include <string>

using namespace std;

// Vì đô dài chuỗi đọc được mình không biết là bao nhiêu nên xử lí như thế này hơi mạo hiểm
// có thể độ dài chuỗi chúng ta không dùng hết nhưng xử lí tốt nhất là decrypt từng kí tự một

// function for decrypting. Input: Adress of the message (string*). Output: Adress of the text.
string* decrypt(string* input){
    *input += " "; //extra space added at the end to access the last morse code
    string* output = new string; 
    if (!output)
    {
        return NULL;
    }
    string temp;
    for (int i = 0; i < input->length(); i++)
    {
        if (input->at(i) != ' ' && input->at(i) != '/' && input->at(i) != '\n'){ // Check space, "new line" (\n) and slash.
            temp += input->at(i); //storing morse code of a single character
        }
        else if (input->at(i) == '/'){//in case of forward-slash
            *output += ' '; // append ' ' to the output string.
        }        
        else if(input->at(i) == ' ' || input->at(i) == '\n'){ //in case of space or '\n'       
            *output += Morse2Char(temp); // search the dictionary for matching character.
            temp.clear(); // clear the temporary variable.
            if(input->at(i) == '\n'){*output += '\n';} // in case of '\n' append '\n' to output.
        }
    }
    return output;
}

// Decrypt no dynamic mem
string Decrypt(string input){
    input += " "; //extra space added at the end to access the last morse code
    string output ; 
    string temp;
    for (int i = 0; i < input.length(); i++)
    {
        if (input.at(i) != ' ' && input[i] != '/' && input[i] != '\n'){ // Check space, "new line" (\n) and slash.
            temp += input[i]; //storing morse code of a single character
        }
        else if (input[i] == '/'){//in case of forward-slash
            output += ' '; // append ' ' to the output string.
        }        
        else if(input[i] == ' ' || input[i] == '\n'){ //in case of space or '\n'       
            output += Morse2Char(temp); // search the dictionary for matching character.
            temp.clear(); // clear the temporary variable.
            if(input[i] == '\n'){output += '\n';} // in case of '\n' append '\n' to output.
        }
    }
    return output;
}
