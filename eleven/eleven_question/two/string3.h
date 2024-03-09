#ifndef STRING3_H_
#define STRING3_H_

#include<iostream>
using std::ostream;
using std::istream;

class String{
    private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
    public:
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length() const {return len;}
    void stringlow();
    void stringup();
    int has(const char c);
    String & operator=(const String &);
    String & operator=(const char *);
    String operator+(const String & st) const;
    String operator+(const char * s) const;
    char & operator[](int i);
    const char & operator[](int i)const;
    friend String operator+(const char * s , const String & st);
    friend bool operator<(const String & st, const String & st2);
    friend bool operator>(const String & st, const String & st2);
    friend bool operator==(const String & st, const String & st2);
    friend ostream & operator<<(ostream & os , const String & st);
    friend istream & operator>>(istream & is , String & st);
    static int HowMany();
};

#endif