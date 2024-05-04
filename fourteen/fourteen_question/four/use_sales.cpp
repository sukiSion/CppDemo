#include "sales.h"
#include<iostream>

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::cin;
    using std::endl;
    double vals1[12] = {
        1220 , 1100 , 1122 , 2212 , 1232 , 2234 ,
        2884 , 2393 , 3302 , 2922 , 3002 , 3544 ,
    };
    double vals2[12] = {
        12 , 11 , 22 , 21 , 32 , 34 , 
        28 , 29 , 33 , 29 , 32 , 35
    };
    Sales sales1(2011 , vals1 , 12);
    LabeledSales sales2("Blogstar" , 2012 , vals2 , 12);
    cout << "First try block:" << endl;
    LabeledSales::nbad_index * nbad;
    try{
        int i;
        cout << "year = " << sales1.Year() << endl;
        for(i = 0 ; i < 12 ; i++){
            cout << sales1[i] << ' ';
            if(i % 6 == 5){
                cout << endl;
            }
        }
        cout << "Year = " << sales2.Year() << endl;
        cout << "Label = " << sales2.Label() << endl;
        for(i = 0 ; i <= 12 ; i++){
            cout << sales2[i] << ' ';
            if(i % 6 == 5){
                cout << endl;
            }
        }
        cout << "End of try block 1." << endl;
    }catch(Sales::bad_index & bad){
        cout << bad.what();
        if(nbad = dynamic_cast<LabeledSales::nbad_index *>(&bad)){
            cout << "Company: " << nbad->label_val() << endl;
        }
        cout << "bad index:" << bad.bi_val() << endl;
    }
    cout << endl << "Next try block: " << endl;
    try{
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "End of try block 2." << endl;
    }catch(Sales::bad_index & bad){
        cout << bad.what();
        if(nbad = dynamic_cast<LabeledSales::nbad_index *>(&bad)){
            cout << "Company: " << nbad->label_val() << endl;
        }
        cout << "bad index:" << bad.bi_val() << endl;
    }
    cout << "done" << endl;
    return 0;
}
