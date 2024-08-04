#include<iostream>
#include<string>

// 编译器会负责资源的释放
class Device{
    public:
    Device(const std::string& res): resource(res){
        std::cout << "\nINIT: " << resource << ".\n";
    }
    void work() const{
        std::cout << "WORKING: " << resource << ".\n";
    }
    ~Device(){
        std::cout << "SHUT DOWN: " << resource << ".\n\n";
    }
    private:
    const std::string resource;
};

int main(int argc, char const *argv[])
{
    Device resGuard1{"DEVICE 1"};
    resGuard1.work();
    {
        Device resGuard2{"DEVICE 2"};
        resGuard2.work();
    }
    resGuard1.work();
    return 0;
}
