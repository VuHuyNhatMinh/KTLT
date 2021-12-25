/*
    Author: 
*/

#include <iostream>
#include "Dictionary.h"
// #include "ErrorChecking.h"
#include "Morse2String.h"
#include "String2Morse.h"

using namespace std;

int main(int argc, char* argv[])
{
    string s;
    cin >> s;
    string* res = decrypt(&s);
    cout << *res << endl;
}