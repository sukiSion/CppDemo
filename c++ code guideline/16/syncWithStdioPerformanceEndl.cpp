#include<chrono>
#include<fstream>
#include<iostream>
#include<random>
#include<sstream>
#include<string>

/**
 * 从这个程序可以看出使用'\n'来作为换行符比使用std::endl作为换行符快了大约10%到20%
 */
constexpr int iterations = 500;
std::ifstream openFile(const std::string& myFile){
    std::ifstream file(myFile , std::ios::in);
    if(!file){
        std::cerr << "Can't open file " + myFile << "!" << '\n';
        exit(EXIT_FAILURE);
    }
    return file;
}

std::string readFile(std::ifstream file){
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

template <typename End>
auto writeToConsole(const std::string& fileContent , End end){
    auto start = std::chrono::steady_clock::now();
    for(auto c: fileContent){
        std::cout << c << end;
    }
    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - start;
    return dur;
}

template<typename Function>
auto measureTime(std::size_t iter , Function&& f){
    std::chrono::duration<double> dur{};
    for(int i = 0 ; i < iter ; ++i){
        dur += f();
    }
    return dur / iter;
}

int main(int argc, char const *argv[])
{
    std::cout << '\n';

    std::string myFile;
    if(!(std::cin >> myFile)){
        std::cerr << "Filename missing !" << '\n';
        exit(EXIT_FAILURE);
    }
    std::ifstream file = openFile(myFile);
    std::string fileContent = readFile(std::move(file));
    // 计算500次使用endl对字符串中每个字符换行的平均时间
    auto averageWithFlush = measureTime(iterations  ,[&fileContent]{
        return writeToConsole(fileContent , std::endl<char , std::char_traits<char>>);   
    });
    // 计算500次使用'\n'对字符串中每个字符换行的平均时间
    auto averageWithoutFlush = measureTime(iterations , [&fileContent]{
        return writeToConsole(fileContent , std::endl<char , std::char_traits<char>>);   
    });
    std::cout << '\n';

    std::cout << "With flush(std::endl) " << averageWithFlush.count() << " seconds" << '\n';
    std::cout << "With flush(\\n) " << averageWithoutFlush.count() << " seconds" << '\n';

    std::cout << "With Flush/Without Flush: " << averageWithFlush/averageWithoutFlush << '\n';

    std::cout << '\n';
    return 0;
}
