Guidelines支持库（GSL）是一个小型库，用于支持C++ Core Guideline的规则
GSL是由视图、所有权指针、断言、实用工具和概念（C++20）等组件组成

# 视图
视图从来不是对象的所有者。gsl::span<T>代表一段无所有权的连续内存范围
这个无所有权的范围可以是数组，也可以是指针加上大小，或者是一个std::vector；这同样适用于gsl::string_span<T>或者以零结尾的C字符串：gsl::czstring或者gsl::wzstring。
gsl::span<T>存在的主要原因是为了防止普通的数组在传递给函数时退化成指针————此时大小信息会丢失
gsl::span<T>会自动推断出纯数组或std::vector大小，所使用指针则需额外提供大小
gsl::span<T>和std::span<T>类似（C++20）

# 所有权指针
gsl::unique_ptr和gsl::shared_ptr使得可以在不支持C++11的编译器上使用智能指针
gsl::owner<T*>是一个拥有被引用对象的所有权的指针，如果无法使用智能指针或容器等资源句柄则应该使用gsl::owner<T*>。关键是必须明确释放资源。
在C++ Core Guidelines中，没有被标记为gsl::owner<T*>的原始指针被认位是无所有权的，所以无需释放资源
1) gsl::dyn_array<T>是一个堆分配的数组，由固定数量的元素，在运行期指定。
2) gsl::stack_array<T>是一个栈分配的数组，由固定数量的元素，在运行期指定。

# 断言
1) Expects()：为函数陈述前置条件
2) Ensures()：为函数陈述后置条件
目前必须将其放在函数体中，在即将到来的实现这些将会被移到函数声明中，这两个函数是契约的一部分，当函数的调用破坏了前置条件Expects或后置条件Ensures程序会终止

# 实用工具
1) gsl::narrow_cast<T>：是一个static_cast<T>，并表达出了意图：一个窄化转型可能会发生
2) gsl::narrow：也是一个static_cast<T>：如果static_cast<T>(x) != x发生，就会抛出narrowing_error异常
3) gsl::not_null<T*>：永远不应为空的指针。若设置为空指针会得到一个编译错误。甚至可以将智能指针放到gsl::not_null<T*>中。和引用之间的差别是：可以重新绑定gsl::not_null<T*>对象但不能重新绑定引用。可以将其用于函数参数和返回类型，这样就不必检查指针是不是一个空指针了
4) finally允许注册一个可调用对象，他会在作用域结束时运行。
```cpp
void f(int n){
    void* p = malloc(n);
    // 在函数f最后lambda函数[p]{free(p);}会被自动调用
    auto _ = finally([p]{
        free(p);
    });
}
```
**应该把finally当作最后的手段————仅在不能使用适当的资源管理方案时，比如不能使用智能指针和STL容器时使用**
