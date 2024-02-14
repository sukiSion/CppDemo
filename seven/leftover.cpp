#include<iostream>
const int ArSize = 80;
char * left(const char * str , int n = 1);
unsigned long left(unsigned long num , unsigned int ct);
char * left(const char * str , int n){
    if(n < 0){
        n = 0;
    }
    char * p = new char[n + 1];
    int i;
    for(i = 0 ; i < n && str[i] ; i++){
        p[i] = str[i];
    }
    p[i] = '\0';
    return p;
}

unsigned long left(unsigned long num , unsigned int ct){
    unsigned digits = 1;
    unsigned long n = num;
    if(ct == 0 || num == 0){
        return 0;
    }
    while (n /= 10)
    {
        digits ++;
    }
    if(digits > ct){
        ct = digits - ct;
        while (ct--)
        {
            num /= 10;
        }
        return num;
        
    }else{
        return num;
    }
    
}

int main(int argc, char const *argv[])
{
    using namespace std;
    char trip[] = "Hawaii!!";   // test value
    unsigned long n = 12345678; // test value
    int i ;
    char * temp;

    for (i = 1; i < 10; i++)
    {
        cout << left(n, i) << endl;
        temp = left(trip,i);
        cout << temp << endl;
        delete [] temp; // point to temporary storage
    }
    return 0;
}
