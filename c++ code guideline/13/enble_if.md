`std::enable_if` 是 C++ 中类型特征库的一部分，用于实现 SFINAE（Substitution Failure Is Not An Error）。它通常用于模板元编程，来选择性地启用或禁用某些模板函数或类的实例化。`std::enable_if` 可以根据编译期条件启用或禁用模板特化或重载，从而使代码更灵活和类型安全。

### `std::enable_if` 语法

`std::enable_if` 的基本形式如下：

```cpp
template<bool B, class T = void>
struct enable_if { };

template<class T>
struct enable_if<true, T> { typedef T type; };
```

- **B**：布尔常量表达式。如果 `B` 为 `true`，则 `enable_if::type` 定义为类型 `T`，否则没有定义。
- **T**：可选的类型参数，默认为 `void`。

`std::enable_if` 也有一个别名模板：

```cpp
template<bool B, class T = void>
using enable_if_t = typename enable_if<B, T>::type;
```

### 使用场景

- **函数模板的启用或禁用**：可以基于模板参数的属性启用或禁用特定的函数模板。
- **类模板的部分特化**：可以基于模板参数的属性选择性地定义类模板的部分特化。

### 示例

#### 示例 1：启用或禁用函数模板

假设我们有一个函数模板，只希望它在模板参数是整型时才有效。

```cpp
#include <iostream>
#include <type_traits>

// 函数模板，仅当 T 是整型时启用
template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
foo(T t) {
    std::cout << "foo() called with integral type: " << t << std::endl;
    return t;
}

// 函数模板，仅当 T 不是整型时启用
template<typename T>
typename std::enable_if<!std::is_integral<T>::value, T>::type
foo(T t) {
    std::cout << "foo() called with non-integral type: " << t << std::endl;
    return t;
}

int main() {
    foo(10);       // 调用第一个 foo()，因为 10 是整型
    foo(3.14);     // 调用第二个 foo()，因为 3.14 不是整型

    return 0;
}
```

在这个示例中，`foo` 函数模板有两个重载，一个用于整型，一个用于非整型。通过 `std::enable_if`，我们可以根据 `T` 是否是整型来选择性地启用相应的重载。

#### 示例 2：在类模板中使用 `enable_if`

假设我们有一个类模板，只希望它在模板参数是指针类型时才有效。

```cpp
#include <iostream>
#include <type_traits>

template<typename T, typename Enable = void>
class MyClass;

// 特化 MyClass，仅当 T 是指针类型时启用
template<typename T>
class MyClass<T, typename std::enable_if<std::is_pointer<T>::value>::type> {
public:
    void print() {
        std::cout << "MyClass instantiated with pointer type." << std::endl;
    }
};

// 特化 MyClass，仅当 T 不是指针类型时启用
template<typename T>
class MyClass<T, typename std::enable_if<!std::is_pointer<T>::value>::type> {
public:
    void print() {
        std::cout << "MyClass instantiated with non-pointer type." << std::endl;
    }
};

int main() {
    MyClass<int*> ptrInstance;  // 实例化指针类型
    ptrInstance.print();

    MyClass<int> nonPtrInstance;  // 实例化非指针类型
    nonPtrInstance.print();

    return 0;
}
```

在这个示例中，`MyClass` 类模板有两个特化，一个用于指针类型，一个用于非指针类型。通过 `std::enable_if`，我们可以选择性地实例化相应的特化版本。

#### 示例 3：结合 `enable_if_t`

使用 `enable_if_t` 别名模板可以使代码更加简洁。

```cpp
#include <iostream>
#include <type_traits>

template<typename T>
std::enable_if_t<std::is_integral<T>::value, T>
bar(T t) {
    std::cout << "bar() called with integral type: " << t << std::endl;
    return t;
}

template<typename T>
std::enable_if_t<!std::is_integral<T>::value, T>
bar(T t) {
    std::cout << "bar() called with non-integral type: " << t << std::endl;
    return t;
}

int main() {
    bar(42);       // 调用第一个 bar()，因为 42 是整型
    bar(3.14);     // 调用第二个 bar()，因为 3.14 不是整型

    return 0;
}
```

在这个示例中，使用 `std::enable_if_t` 使函数模板的定义更简洁。

### 总结

- **`std::enable_if`**：用于模板元编程，选择性地启用或禁用模板实例化。
- **参数**：`bool B` 和可选的类型 `T`（默认是 `void`）。
- **应用**：可以用于函数模板和类模板的部分特化，根据编译期条件进行选择。
- **优势**：使模板元编程更灵活和类型安全，避免不必要的模板实例化错误。