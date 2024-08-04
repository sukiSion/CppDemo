template<typename T>
auto getValue(T x){
    if(x < 0){
        return -1; // int
    }else if()x > 0){
        return 1.0; // double
    }else{
        return 0.0f; // float
    }
}

int main(int argc, char const *argv[])
{
    getValue(5.5);
    return 0;
}
