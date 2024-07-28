#include<algorithm>
#include<cctype>
#include<iostream>
#include<string>
#include<vector>

struct Rec{
    std::string name;
    std::string addr;
    int id;
};

bool compare_insensitive(const std::string& a , const std::string& b){
    if(a.size() != b.size() )return false;
        for(std::string::size_type i = 0 ; i < a.size() ; ++i){
            if(std::tolower(a[i]) != std::tolower(b[i])){
                return false;
            }
        }
        return true;
};

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::vector<Rec> vr{
        {"Grimm" , "Minich" , 1},
        {"huber" , "Stuttgart" , 2},
        {"Smith" , "Rottenburg" , 3},
        {"black" , "Hanover" , 4}
    };

    std::string name = "smith";
    // 由于这个谓词比较普遍，因此可以将其抽出来
    // auto res = std::find_if(vr.begin() , vr.end() , [&name](const Rec& r){
    //     if(r.name.size() != name.size() )return false;
    //     for(std::string::size_type i = 0 ; i < r.name.size() ; ++i){
    //         if(std::tolower(r.name[i]) != std::tolower(name[i])){
    //             return false;
    //         }
    //     }
    //     return true;
    // });
    auto res = std::find_if(vr.begin() , vr.end() , [&name](const Rec& r){
        return compare_insensitive(r.name , name);
    });

    if(res != vr.end()){
        std::cout << res->name << " , " << res->addr << " , " << res->id << '\n';
    }

    std::vector<std::string> vs{
        "Grimm" , "huber" , "Smith" , "black"
    };
    // 可以在合适的场合下重复使用该谓词函数
    auto res2 = std::find_if(vs.begin() , vs.end() , [&name](const std::string& s){
        return compare_insensitive(s , name);
    });

    std::cout << '\n';
    return 0;
}
