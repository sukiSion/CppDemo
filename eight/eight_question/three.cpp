#include<iostream>
#include<new>
#include<cstring>
using namespace std;
struct chaff
{
    char dross[20];
    int slag;
};
const int LEN = 512;
const int N = 2;
char buff[LEN];
void getchaffs(chaff chaffs[]){
    for(int i = 0 ; i < N ; i++){
        cout << "Enter dross: ";
        cin.get(chaffs[i].dross , 20);
        while(cin.get() != '\n');
        cout << "Enter slag: ";
        (cin >> chaffs[i].slag).get();
        if(!cin){
            break;
        }
    }
}

void showchaffs(const chaff chaffs[]){
    for(int i = 0 ; i < N ; i++){
      cout << "dross: " << chaffs[i].dross << ", slag: " <<  chaffs[i].slag << endl;
    }
}

int main(int argc, char const *argv[])
{
    chaff * pc1 = new chaff[N];
    chaff * pc2 = new (buff) chaff[N];
    getchaffs(pc2);
    for(int i = 0 ; i < N ; i++){
        pc1[i].slag = pc2[i].slag;
        strcpy(pc1[i].dross , pc2[i].dross);
    }
    showchaffs(pc1);
    showchaffs(pc2);
    delete [] pc1;
    return 0;
}
