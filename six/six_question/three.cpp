#include<iostream>
using namespace std;
struct box
{
    // 大意是不能将字符串常量赋值给字符数组 , 除非在定义的时候赋值
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_box(const box);
void calculate_volume(box *);

void show_box(const box b){
    cout << "maker: " << b.maker << endl;
    cout << "height: " << b.height << endl;
    cout << "width: " << b.width << endl;
    cout << "length: " << b.length << endl;
    cout << "volume: " << b.volume << endl;
}

void calculate_volume(box *pb){
    pb -> volume = pb->height * pb->width * pb->length;
}

int main(int argc, char const *argv[])
{
    box b{
        "Sion",
        12.0,
        14.0,
        16.0,
        0.0
    };
    calculate_volume(&b);
    show_box(b);
    return 0;
}

