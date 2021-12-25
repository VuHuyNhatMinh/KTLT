//quan


#ifndef _ERRORCHECKING_CPP_
#define _ERRORCHECKING_CPP_

#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

//check file open, nếu mở được return true, ko thì return false
bool check_open(char a[])
{
    ifstream fin(a);                             
    if(!fin.is_open())  
	{
		cout<<"Error: "<<a<<" could not be opened.";
        return false;
	}
    else
    {
        fin.close();
        return true;
    }
}


//hàm check xem file đầu ra có exist hay không, return ký tự (y hoặc n) nếu đã tồn tại, return NULL nếu chưa tồn tại
char check_exist_out(char a[])     //input là mảng một chiều kí tự chứa một string
{                                  //output là wanrning nếu file đã tồn tại, là NULL nếu file chưa tồn tại
    char c;
    ifstream fs(a);
    if (fs.is_open()) {
        fs.close();
        cout <<"Warning: "<<a<<" already exists. Do you wish to overwrite (y,n)? ";
        
        cin>>c;
        while(c!='y'&&c!='n')
        {
            cout<<"Enter only y or n";
        }
        if (c == 'y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

//check if a is text or morse
bool check_type(string a)       //input là một string data 
{                               //output là true nếu là morse, là false nếu là text 
    for( int i=0;i<a.size();i++)        //duyệt qua tất cả các kí tự trong string, 
    {                                   //chỉ cần gặp một kí tự khác '.', '-', '/' hoặc ' ' thôi thì sẽ là file text
        if(a[i]!='.'&& a[i]!='-' && a[i]!='/'&&a[i]!=' ')  
        {
            return false;
        }
    }
    return true;
}

//check error characters in file text
void check_text(string s)   //input: a string       
{                           //output: show error characters and their locations on screen  
    char text[42] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' , 'j', 'k', 'l', 'm', 'n', 'o', 'p' , 'q', 'r', 's', 't',
                'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8' ,'9', '.', '?', '-', ',', ':', '#'};
    int new_line = 1;
    for( int i=0;i<s.size();i++)    //duyệt tất cả các kí tự trong string
    {
        if(s[i]!=' '&&s[i]!='\n')   //nếu kí tự không phải là kí tự dấu cách hoặc kí tự xuống dòng thì kiểm tra
        {
            bool check = false;
            for(int j=0;j<42;j++)   //nếu kí tự ko có trong bảng kí tự bên trên thì check = false, có thì là true
            {
                if(s[i]==text[j])
                {
                    check = true;
                    break;
                }
            }
            if(check == false)
            {
                cout<<"Error: Unrecognised character "<<s[i]<<" on line "<<new_line<<endl;      
            }
        }
        if(s[i]=='\n')
        {
            new_line++;  // gặp kí tự xuống dòng thì new_line (dòng đang xét) + thêm 1
        }
    }
    
}


//check error character in file morse
void check_morse(string s)  //input is a string
{                           //output: show error characters and their locations on screen
    string morse[42] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.---", "--..", "-----", ".----", "..---", 
                "...---", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "..--..", "-....-", "--..--", "---...", "........"};
    char a[100] = {'\0'};           //mảng để lưu một từ morse
    int index = 0;
    int new_line =1;
    for( int i=0;i<s.size();i++)        //duyệt tất cả các data trong string
    {
        if(s[i]!=' '&&s[i]!='\n'&&s[i]!='/')    //nếu khác dấu cách, xuống dòng hoặc '/' thì thêm kí tự vào mảng a
        {
            a[index] = s[i];
            index++;
        }
        if(s[i]==' '||s[i]=='\n'||s[i]=='/')       //nếu kí tự là dấu cách hoặc xuống dòng hoặc '/' nghĩa là a đã là một từ morse
        {
            if(s[i]=='/')continue;                  // nếu là kí tự '/' thì nghĩa là trước đó là kí tự dấu cách, nên bỏ qua
            if(s[i]==' '&&s[i-1]=='/')continue;     //nếu là kí tự dấu cách và trước đó là kí tự '/' thì bỏ qua 
            bool check = false;                     //còn lại là trường hợp dấu cách kết thúc một từ morse
            a[index] ='\0';                         //thêm kí tự NULL để a thành string
            for(int j=0;j<42;j++)                   //xét xem từ morse có trong bảng morse kia không, nếu có thì check =true, không thì false
            {
                if(a==morse[j])
                {
                    check = true;
                    break;
                }
            }
            if(check == false)
            {
                cout<<"Invalid Morse code "<<a<<" on line  "<<new_line<<endl;
            }
            if(s[i]=='\n')
            {
                new_line++;                 // gặp kí tự xuống dòng thì new_line (dòng đang xét) + 1
            }
            index=0;

            int k=0;        // clear  array a
            while(a[k]!='\0')
            {
                a[k] = '\0';
                k++;
            }                        
        }

        if(i==s.size()-1)           //nếu gặp kí tự cuối cùng trong file thì nghĩa là hết một từ morse cuối cùng, 
        {                           // check từ morse đó         
            bool check = true;
            a[index] ='\0';
            for(int j=0;j<42;j++)
            {
                if(a==morse[j])
                {
                    check = false;
                }
                if(check == false)break;
            }
            if(check == true)
            {
                cout<<"Invalid Morse code "<<a<<" on line  "<<new_line<<endl;
            }
        }
    }
}

#endif