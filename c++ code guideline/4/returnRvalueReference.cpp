int && returnRvalueReference(){
    return int{};
}

int main(int argc, char const *argv[])
{
    auto myInt = returnRvalueReference();
    return 0;
}
