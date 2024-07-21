`std::lock_guard` 是 C++11 引入的一个类模板，用于管理互斥锁的生命周期。它通过构造函数获取锁，并在析构函数中释放锁，从而确保锁在作用域结束时自动释放，无需显式解锁。这种机制有助于防止因异常或早期返回而导致的锁泄漏问题。

### 基本用法

以下是 `std::lock_guard` 的基本用法示例：

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_thread_id(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    // 这里的代码在锁保护下运行
    std::cout << "Thread " << id << '\n';
    // lock 在此范围结束时自动释放
}

int main() {
    std::thread threads[10];
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(print_thread_id, i);
    }

    for (auto& th : threads) th.join();

    return 0;
}
```

### 详细说明

1. **构造函数**：
   当创建 `std::lock_guard` 对象时，构造函数会尝试获取互斥锁。通常，这意味着调用 `mutex::lock` 方法。

2. **析构函数**：
   当 `std::lock_guard` 对象超出作用域时，析构函数会自动释放互斥锁，通常调用 `mutex::unlock` 方法。

### 原理

`std::lock_guard` 的实现非常简单，通常类似于以下代码：

```cpp
template <typename Mutex>
class lock_guard {
public:
    explicit lock_guard(Mutex& m) : mtx(m) {
        mtx.lock();
    }

    ~lock_guard() {
        mtx.unlock();
    }

    // 禁用拷贝和赋值
    lock_guard(const lock_guard&) = delete;
    lock_guard& operator=(const lock_guard&) = delete;

private:
    Mutex& mtx;
};
```

### 优点

- **简单性**：使用 `std::lock_guard` 可以简化代码，减少手动锁定和解锁的可能错误。
- **异常安全**：在异常发生时，`std::lock_guard` 会确保互斥锁被正确释放，防止死锁。
- **作用域管理**：通过 RAII（资源获取即初始化）模式，`std::lock_guard` 确保锁的生命周期与其作用域绑定，从而更好地管理资源。

### 进阶用法

如果需要在单个作用域中锁定多个互斥锁，可以使用 `std::scoped_lock` 或 `std::lock` 结合多个 `std::lock_guard`。

### 示例：多个锁

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1, mtx2;

void thread_function() {
    // 使用 std::lock 同时锁定多个互斥锁，避免死锁
    std::lock(mtx1, mtx2);

    // 使用 std::lock_guard 进行管理
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);

    // 这里的代码在两个锁保护下运行
    std::cout << "Thread function running\n";
    // lock1 和 lock2 在此范围结束时自动释放
}

int main() {
    std::thread t1(thread_function);
    std::thread t2(thread_function);

    t1.join();
    t2.join();

    return 0;
}
```

在这个示例中，`std::lock` 函数同时锁定多个互斥锁，并使用 `std::lock_guard` 结合 `std::adopt_lock` 标签来接管锁。

### 总结

`std::lock_guard` 是一个简单且有效的工具，用于管理互斥锁的生命周期，确保在作用域结束时自动释放锁。它通过RAII模式提高代码的安全性和可维护性，适用于需要互斥锁保护的临界区。