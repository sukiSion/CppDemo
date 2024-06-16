#include<iostream>
#include<set>
#include<tuple>

int main(int argc, char const *argv[])
{
    std::cout << '\n';
    std::set<int> mySet;
    std::set<int>::iterator iter;
    bool inserted = false;
    std::tie(iter , inserted) = mySet.insert(2011);
    if(inserted) std::cout << "2011 was inserted successfullly\n";
    auto [iter2 , inserted2] = mySet.insert(2017);
    if(inserted2) std::cout << "2017 was inserted successfullly\n";
    std::cout << '\n';
    return 0;
}
