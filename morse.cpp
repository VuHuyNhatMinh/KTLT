/*
    Author: 
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"
#include "ErrorChecking.h"
#include "Morse2String.h"
#include "String2Morse.h"

using namespace std;

int main(int argc, char* argv[])
{
    /* 
        Check whether open file data or not 
    */
    if (!check_open(argv[1]))
    {
        return 1;
    }

    /*
        Check whether file result exsit or not 
        If does, overwrite or not
    */
    if (!check_exist_out(argv[2]))
    {
        return 1;
    }

    /*
        Open file data to perform decrypt
    */
    fstream fdata;
    fdata.open(argv[1], ios::in);
    // An object string data to store all text in data file
    string data;    
    getline(fdata, data, '\0');
    fdata.close();
   
    /*
        Check the file type
    */
    // An object string res to store decryption data
    string res;
    if (check_type(data))
    {
        // Check error in morse file
        check_morse(data);

        cout << "This is morse file" << endl;

        // Decrypt to text file
        string* input = &data;
        string* english = decrypt(input);
        res = *english;
        delete english;
    }
    else
    {
        // Check error in text file
        check_text(data);

        cout << "This is txt file" << endl;

        // Decrypt to morse file
        res = Textmorse(data);
    }
    // cout << res << endl;

    /*
        Open file result to write result
    */
    fstream fresult;
    fresult.open(argv[2], ios::out);
    fresult << res << endl;
    fresult.close(); 
}