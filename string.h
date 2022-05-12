#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>

class String{
    char *text;
    int len;
public:

    const char* c_str() const {return text;}
    int getlen() {return len;}

    ///Konstruktor C stringből
    String(const char* t = "");

    /// Konstruktor egy karakterből
    String(char ch);

    /// Másoló konstruktor
    String(const String& s);

    String operator+(const String& s) const;

    /// Sztrinhez karaktert összefűz
    String operator+(char ch) const { return *this + String(ch);}

    /// Értékadó operátor.
    String& operator=(const String& s);

    ///Felszabaditas
    void torol() {delete[] text;}

    /// Destruktor
    ~String() {this->torol();}


};
/// Kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s);

/// Beolvas string-be.
std::istream& operator>>(std::istream& is, String& s);

///Egyenlő operátor
bool operator==(const String&, const char*);

bool operator==(const String&, const String&);

///Nem egyenlő operátor
bool operator!=(const String&, const char*);


#endif // STRING_H_INCLUDED
