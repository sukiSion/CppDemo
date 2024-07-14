#include<iostream>

enum class Message{
    information,
    warning,
    error,
    fatal
};

void writeMessage(){
    std::cout << "message" << '\n';
}

void writeWarning(){
    std::cout << "warning" << '\n';
}

void writeUnexpected(){
    std::cout << "unexpected" << '\n';
}

// 使用了Default处理处除information和waring之外的“默认情况”，可以
void withDefault(Message message){
    switch(message){
        case Message::information: {
            writeMessage();
            break;
        }
        case Message::warning: {
            writeWarning();
            break;
        }
        default:{
            writeUnexpected();
            break;
        }
    }
}

// 可以通过注释了解到这个switch语句没有默认情况
void withoutDefaultGood(Message message){
    switch(message){
        case Message::information: {
            writeMessage();
            break;
        }
        case Message::warning: {
            writeWarning();
            break;
        }
        default:{
            // 没什么可做的
            break;
        }
    }
}

// 是否忘记添加了默认情况？还是说Message::error和Message::fatal是后来才添加的？
void withoutDefaultBad(Message message){
    switch(message){
        case Message::information: {
            writeMessage();
            break;
        }
        case Message::warning: {
            writeWarning();
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    withDefault(Message::fatal);
    withoutDefaultGood(Message::information);
    withoutDefaultBad(Message::warning);
    return 0;
}
