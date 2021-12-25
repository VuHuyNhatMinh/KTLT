<<<<<<< HEAD
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

    // Open file data to perform decrypt
    ifstream fdata;
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
        // If it is morse file
        string *input = &data;
        string* english = decrypt(input);
        cout << *english << '\n';

    }
    else
    {
        // If it is text file
        // check_text(data);

        // Decrypt to morse file
        res = Textmorse(data);
    }
    cout << res << endl;
    system("pause>0");
=======
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

    // Open file data to perform decrypt
    ifstream fdata;
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
        // If it is morse file
        string *input = &data;
        string* english = decrypt(input);
        cout << *english << '\n';

    }
    else
    {
        // If it is text file
        // check_text(data);

        // Decrypt to morse file
        res = Textmorse(data);
    }
    cout << res << endl;
    system("pause>0");
>>>>>>> 629e16b67dcab567b0c05d4748845f5ec6a7f7ce
}