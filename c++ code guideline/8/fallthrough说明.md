在C++17中，引入了一个新的属性标识符 `[[fallthrough]]`，用于明确标识在 `switch` 语句中的意图，表明在一个 `case` 分支之后没有 `break` 语句是有意为之的，而不是由于疏忽或错误。

### 作用

`[[fallthrough]]` 的主要作用是提高代码的可读性和可维护性，同时避免潜在的警告或错误。它向编译器和阅读代码的人明确表明：某个 `case` 分支的执行会故意地“贯穿”到下一个 `case` 分支。

### 使用示例

以下是一个简单的示例，展示如何使用 `[[fallthrough]]`：

```cpp
#include <iostream>

void process(int n) {
    switch (n) {
        case 1:
            std::cout << "Case 1" << std::endl;
            // fallthrough to case 2 intentionally
            [[fallthrough]];
        case 2:
            std::cout << "Case 2" << std::endl;
            break;
        case 3:
            std::cout << "Case 3" << std::endl;
            break;
        default:
            std::cout << "Default case" << std::endl;
            break;
    }
}

int main() {
    process(1); // Outputs: Case 1 \n Case 2
    process(2); // Outputs: Case 2
    process(3); // Outputs: Case 3
    process(4); // Outputs: Default case
    return 0;
}
```

### 解释

- 当 `process(1)` 被调用时，程序执行 `case 1`，打印 "Case 1"，然后遇到 `[[fallthrough]]` 属性，继续执行 `case 2`，打印 "Case 2"。
- 当 `process(2)` 被调用时，程序直接执行 `case 2`，打印 "Case 2"。
- 当 `process(3)` 被调用时，程序执行 `case 3`，打印 "Case 3"。
- 当 `process(4)` 被调用时，程序执行 `default` 分支，打印 "Default case"。

### 好处

1. **提高代码可读性**：明确标识出意图，让阅读代码的人更容易理解代码逻辑。
2. **减少错误**：避免因为忘记写 `break` 语句而导致的错误。
3. **帮助编译器分析**：有些编译器在检测到 `case` 分支没有 `break` 语句时会发出警告，使用 `[[fallthrough]]` 可以抑制这些警告，因为它明确了意图。

### 注意事项

- `[[fallthrough]]` 必须紧跟在要贯穿的 `case` 分支后面的代码，并且不能在它之后有任何代码（除了注释）。
- `[[fallthrough]]` 仅适用于 `switch` 语句中的 `case` 分支，不能用于其他地方。

### 总结

C++17 引入的 `[[fallthrough]]` 属性是为了增强代码的可读性和可维护性，它明确标识 `switch` 语句中的有意贯穿行为，从而帮助程序员避免潜在的错误和误解。通过使用 `[[fallthrough]]`，代码变得更清晰，编译器也能更好地理解开发者的意图。