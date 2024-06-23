有实参依赖查找（Argument-Dependent Lookup，简称 ADL），也称为柯尼希查找（Koenig Lookup），是 C++ 中的一种名称查找机制，用于在调用函数时，根据函数参数的命名空间来查找函数。这种查找机制使得在某些情况下，可以更方便地调用特定命名空间中的函数，而无需显式指定命名空间。

### 详细解释

在 C++ 中，当调用一个函数时，编译器需要确定该函数的定义位置。通常情况下，编译器会在调用上下文中查找函数名称。然而，当使用 ADL 时，编译器不仅会在调用上下文中查找函数名称，还会在函数参数所属的命名空间中查找。

### 例子

假设我们有一个自定义的命名空间 `MyNamespace` 和一个自定义类型 `MyType`：

```cpp
#include <iostream>

namespace MyNamespace {
    class MyType {};

    void myFunction(MyType) {
        std::cout << "MyNamespace::myFunction called" << std::endl;
    }
}

void myFunction(int) {
    std::cout << "Global myFunction called" << std::endl;
}

int main() {
    MyNamespace::MyType obj;
    myFunction(obj); // 这将调用 MyNamespace::myFunction
    myFunction(10);  // 这将调用全局的 myFunction
    return 0;
}
```

### 解释

1. **全局命名空间**：我们定义了一个全局函数 `myFunction`，它接受一个 `int` 参数。
2. **自定义命名空间**：在 `MyNamespace` 命名空间中，我们定义了一个类 `MyType` 和一个接受 `MyType` 参数的函数 `myFunction`。
3. **ADL 机制**：在 `main` 函数中，当我们调用 `myFunction(obj)` 时，编译器会查找 `obj` 的类型 `MyNamespace::MyType` 所属的命名空间 `MyNamespace`，并找到 `MyNamespace::myFunction`。因此，即使我们没有显式指定命名空间 `MyNamespace`，编译器仍然能够找到并调用正确的函数。
4. **全局查找**：当我们调用 `myFunction(10)` 时，参数 `10` 是一个 `int` 类型，编译器只会在全局命名空间中查找，因此调用的是全局的 `myFunction`。

### ADL 的好处和应用

1. **简化代码**：ADL 允许我们在调用命名空间中的函数时省略命名空间前缀，使代码更简洁。
2. **增强可读性**：通过减少冗长的命名空间前缀，ADL 提高了代码的可读性。
3. **常见应用**：ADL 常用于重载运算符和通用算法。例如，标准库中的 `std::swap` 函数就是利用 ADL 机制，使得用户可以定义自定义类型的 `swap` 函数，而 `std::swap` 可以正确调用自定义类型的 `swap` 实现。

#### 自定义 `swap` 函数示例

```cpp
#include <iostream>
#include <algorithm>

namespace MyNamespace {
    class MyType {
    public:
        int value;
        MyType(int val) : value(val) {}
    };

    void swap(MyType& a, MyType& b) {
        std::cout << "MyNamespace::swap called" << std::endl;
        std::swap(a.value, b.value);
    }
}

int main() {
    MyNamespace::MyType a(1), b(2);
    using std::swap;
    swap(a, b); // 这将调用 MyNamespace::swap
    std::cout << "a.value = " << a.value << ", b.value = " << b.value << std::endl;
    return 0;
}
```

### 解释

1. **自定义 `swap` 函数**：在 `MyNamespace` 命名空间中，我们定义了一个自定义类型 `MyType` 和对应的 `swap` 函数。
2. **ADL 机制**：在 `main` 函数中，当我们调用 `swap(a, b)` 时，编译器会通过 ADL 查找 `a` 和 `b` 的类型 `MyNamespace::MyType` 所属的命名空间，并找到 `MyNamespace::swap` 函数。
3. **标准库中的 `swap`**：通过 `using std::swap`，我们可以确保标准库中的 `swap` 也在查找范围内。如果没有自定义的 `swap` 函数，那么将会调用标准库的 `swap`。

### 总结

有实参依赖查找（ADL）是一种有用的 C++ 机制，通过在参数所属的命名空间中查找函数名称，使得代码更简洁和可读。ADL 主要用于函数重载和模板库中，通过保持参数的命名空间信息，实现更灵活和高效的函数调用。