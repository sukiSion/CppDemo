#include "person.h"

int main(int argc, char const *argv[])
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy" , "Sam");
    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();
    return 0;
}
