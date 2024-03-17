#include "dma.h"
#include<iostream>
static const int DMA = 3;

int main(int argc, char const *argv[])
{
    using namespace std;
    abcDMA * p_dmas[DMA];
    char tempLabel[50];
    char tempColor[50];
    char tempStyle[50];
    int tempRating;
    char kind;
    for(int i = 0 ; i < DMA ; i++){
        cout << "Enter dma's label: ";
        cin.get(tempLabel , 50);
        cout  << "Enter dma's rating: ";
        cin  >> tempRating;
        cout << "Enter 1 for baseDMA or 2 for lacksDMA or 3 for hasDMA: ";
        while(cin >> kind && (kind != '1' && kind != '2' && kind != '3')){
            cout << "Enter either 1 or 2 or 3: ";
        }
        
        if(kind == '1'){
            p_dmas[i] = new baseDMA(tempLabel , tempRating);
        }else if(kind == '2'){
            cout  << "Enter lacksdma's color: ";
            while (cin.get() != '\n');
            cin.get(tempColor , 50);
            p_dmas[i] = new lacksDMA(tempColor , tempLabel , tempRating);
        }else if(kind == '3'){
            cout  << "Enter hasdma's style: ";
            while (cin.get() != '\n');
            cin.get(tempStyle , 50);
            p_dmas[i] = new hasDMA(tempStyle , tempLabel , tempRating);
        }
        while (cin.get() != '\n');
    }
    for(int i = 0 ; i < DMA ; i++){
        p_dmas[i]->View();
    }
    for(int i = 0 ; i < DMA ; i++){
        delete p_dmas[i];
    }
    cout << "Done." << endl;
    return 0;
}
