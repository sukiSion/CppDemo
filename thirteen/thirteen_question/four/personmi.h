#ifndef PERSON_H_
#define PERSON_H_
#include<string>
using std::string;

class Person{
    private:
    string fname;
    string lname;
    protected: 
    virtual void Data() const;
    virtual void Get();
    public:
    Person(const char * fn = "no", const char * ln = "one"): fname(fn) , lname(ln){}
    virtual ~Person() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Gunslinger: virtual public Person{
    private:
    int nicks;
    protected: 
    void Data() const;
    void Get();
    public:
    Gunslinger() : Person(), nicks(0) {}
    Gunslinger(const char * fn , const char * ln , int n) : Person(fn, ln), nicks(n) {}
    Gunslinger(const Person &p, int n = 0) : Person(p), nicks(n) {}
    void Set();
    void Show() const;
    double Draw() const; 
};

class PokerPlayer: virtual public Person{
    protected:
    void Data() const; 
    public:
    PokerPlayer() : Person() {}
    PokerPlayer(const char * fn , const char * ln) : Person(fn, ln) {}
    PokerPlayer(const Person &p) : Person(p) {}
    void Set();
    void Show() const;
    int Draw() const; 
};

class BadDude: public Gunslinger , public PokerPlayer{
    protected:
    void Data() const; 
    void Get();
    public:
    BadDude() {}
    BadDude(const char * fn , const char * ln, int n) : Person(fn, ln), Gunslinger(fn, ln, n), PokerPlayer(fn, ln) {}
    BadDude(const Person &p, int n = 0) : Person(p), Gunslinger(p, n), PokerPlayer(p) {}
    BadDude(const Gunslinger &g) : Person(g), Gunslinger(g), PokerPlayer(g) {}
    BadDude(const PokerPlayer &p , int n = 0) : Person(p), Gunslinger(p , n), PokerPlayer(p) {}
    void Set();
    void Show() const;
    double Gdraw() const; 
    int Cdraw() const;  
};

#endif