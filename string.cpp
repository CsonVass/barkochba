#include <iostream>
#include <cstring>

#include "string.h"


using std::cin;
using std::ios_base;

///Konstruktor C stringből
String::String(const char* t){
    len = strlen(t);
    text = new char[len+1];
    strcpy(text, t);
}

/// Konstruktor egy karakterből
String::String(char ch){
    len = 1;
    text = new char[len+1];
    text[0] = ch;
    text[1] = '\0';
}

/// Másoló konstruktor
String::String(const String& s){
    len = s.len;
    text = new char[len+1];
    strcpy(text, s.text);
}

String String::operator+(const String& s) const{
    String temp;
    temp.len = len + s.len;
    delete[] temp.text;
    temp.text = new char[temp.len+1];
    strcpy(temp.text, text);
    strcat(temp.text, s.text);
    return temp;
}

/// Értékadó operátor.
String& String::operator=(const String& s){
    if(this != &s){
        delete[] text;
        len = s.len;
        text = new char[len+1];
        strcpy(text, s.text);
    }
    return *this;
}

/// Kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s){
    os<<s.c_str();
    return os;
}

/// Beolvas egy stringbe.
std::istream& operator>>(std::istream& is, String& s){
    unsigned char ch;
    s = String("");
    std::ios_base::fmtflags f1 = is.flags();
    is.setf(ios_base::skipws);
    while(is >> ch && !is.eof()) {
        is.unsetf(ios_base::skipws);
        if(ch == '\n' || ch == '\r'){
            is.putback(ch);
            break;
        }else{
            s = s + ch;
        }
    }
    is.setf(f1);
    return is;
}

///Egyenlő operátor
bool operator==(const String& s0, const char* s1){
    return (strcmp(s0.c_str(), s1)==0);
}

bool operator==(const String& s0, const String& s1){
    return (strcmp(s0.c_str(), s1.c_str())==0);
}

///Nem egyenlő operátor
bool operator!=(const String& s0, const char* s1){
    return (strcmp(s0.c_str(), s1)!=0);
}
