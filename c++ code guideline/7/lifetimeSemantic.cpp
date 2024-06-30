#include<iostream>
#include<memory>

using std::cout;

void asSmartPointerGood(std::shared_ptr<int> &shr){
    cout << "asSmartPointerGood \n";
    cout << "    shr.use_count(): " << shr.use_count() << '\n';
    shr.reset(new int(2011));
    cout << "    shr.use_count(): " << shr.use_count() << '\n';
    cout << "asSmartPointerGood \n";
}


// 由于该函数只使用了智能指针的底层资源
// 参数应该是原始指针或者引用
// 而使用了这样参数表明需要在函数中重装指针，但是实际上并没有这么做
void asSmartPointerBad(std::shared_ptr<int> & shr){
    cout << "asSmartPointerBad(sharedPtr2) \n";
    *shr += 19;
}

int main(int argc, char const *argv[])
{
    auto sharedPtr1 = std::make_shared<int>(1998);
    // 由于sharePtr2对sharePtr1进行了拷贝，所以此时引用计数为2
    auto sharedPtr2 = sharedPtr1;

    cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << '\n';
    cout << '\n';

    // 由于sharedPtr1在该函数中指向了新的资源
    // 所以此时sharedPtr1和sharedPtr2成为了不同资源的所有者
    asSmartPointerGood(sharedPtr1);

    cout << '\n';

    cout << "*sharedPtr1: " << *sharedPtr1 << '\n';
    cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << '\n';
    cout << '\n';

    cout << "*sharedPtr2: " << *sharedPtr2 << '\n';
    cout << "sharedPtr2.use_count(): " << sharedPtr2.use_count() << '\n';
    cout << '\n';

    asSmartPointerBad(sharedPtr2);
    cout << "*sharePtr2: " << *sharedPtr2 << '\n';
    return 0;
}
