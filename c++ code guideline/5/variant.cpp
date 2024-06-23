#include <variant>
#include <string>

int main(int argc, char const *argv[])
{
    std::variant<int , float> v;
    std::variant<int , float> w;

    int i = std::get<int>(v); // 获取初始值
    v = 12;
    int j = std::get<int>(v);

    // 类型和索引必须是有效的，否则得到std::bad_variant_access异常
    w = std::get<int>(v);   // 根据变体中对应类型获取
    w = std::get<0>(v);  // 根据变体中对应索引获取
    w = v; // 由于变体v中只持有int，所以v将对应int值赋给变体w

    // 错误：[int,float]里没有double
    // std::get<double>(v);
    // 错误：有效索引值只有0和1
    // std::get<3>(v);

    try{
        // w包含int而非float，从w中获取float会抛出异常
        std::get<float>(w);
    }catch(std::bad_variant_access){}
    v = 5.5f;
    v = 5;

    // 如果构造函数调用和赋值调用没有二义性，转换可以发生
    std::variant<std::string> v2("abc");
    v2 = "def";
    return 0;
}
