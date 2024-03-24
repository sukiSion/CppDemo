#include "studenti.h"
using std::endl;
using std::istream;
using std::string;
using std::ostream;

std::ostream & Student::arr_out(std::ostream & os) const{
    int i;
    int lim = ArrayDb::size();
    if(lim > 0){
        for(i = 0 ; i < lim ; i++){
            os << ArrayDb::operator[](i) << " ";
            if(i % 5 == 4){
                os << endl;
            }
        }
        if(i % 5 != 0){
            os << endl;
        }
    }else{
        os << " empty array ";
    }
    return os;
}

double Student::Average() const{
    if(ArrayDb::size() > 0){
        return ArrayDb::sum() / ArrayDb::size();
    }else{
        return 0;
    }
}

const std::string & Student::Name() const{
    return static_cast<const string &>(*this);
}

double & Student::operator[](int i){
    return ArrayDb::operator[](i);
}

double Student::operator[](int i) const{
    return ArrayDb::operator[](i);
}

std::istream & operator>>(std::istream & is , Student & stu){
    is >> static_cast<string &>(stu);
    return is;
}

std::istream & getline(std::istream & is , Student & stu){
    std::getline(is , static_cast<string &>(stu));
    return is;
}

std::ostream & operator<<(std::ostream & os , const Student & stu){
    os << "Scores for " << static_cast<const string &>(stu) << ":" << endl;
    stu.arr_out(os);
    return os;
}