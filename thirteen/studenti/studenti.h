#ifndef STUDENTI_H_
#define STUDENTI_H_
#include<iostream>
#include<string>
#include<valarray>
using std::string;
using std::valarray;
class Student: private string , private valarray<double>{
    private:
    typedef std::valarray<double> ArrayDb;
    std::ostream & arr_out(std::ostream & os) const;
    public:
    Student(): string("Null Student"), ArrayDb(){}
    explicit Student(const std::string & s): string(s) , ArrayDb(){}
    explicit Student(int n): string("Nully") , ArrayDb(n){}
    Student(const std::string & s , int n): string(s) , ArrayDb(n){}
    Student(const std::string & s , const ArrayDb & a): string(s) , ArrayDb(a){}
    Student(const char * s , const double * pd , int n): string(s) , ArrayDb(pd , n){}
    ~Student(){}
    double Average() const;
    const std::string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;
    friend std::istream & operator>>(std::istream & is , Student & stu);
    friend std::istream & getline(std::istream & is , Student & stu);
    friend std::ostream & operator<<(std::ostream & os , const Student & stu); 
};

#endif