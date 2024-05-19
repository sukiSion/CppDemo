#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Review{
    string title;
    int rating;
};

bool FillReview(Review & rr){
    cout << "Enter book title(quit to quit): ";
    getline(cin , rr.title);
    if(rr.title == "quit"){
        return false;
    }
    cout << "Enter book rating: ";
    cin >> rr.rating;
    if(!cin){
        return false;
    }
    while(cin.get() != '\n');
    return true;
}

void showReview(const Review & rr){
    cout << rr.rating << "\t" << rr.title << endl;
}

int main(int argc, char const *argv[])
{
    vector<Review> books;
    Review temp;
    while(FillReview(temp)){
        books.push_back(temp);
    }
    int num = books.size();
    if(num > 0){
        cout << "Tnank you. You entered the following:" << endl;
        cout << "Rating\tBook" << endl;
        for(int i = 0 ; i < num ; i++){
            showReview(books[i]);
        }
        cout << "Reprising:" << endl;
        cout << "Rating\tBook" << endl;
        vector<Review>::iterator pr;
        for(pr = books.begin() ; pr != books.end() ; pr++){
            showReview(*pr);
        }
        vector<Review> oldlist(books);
        if(num > 3){
            books.erase(books.begin() + 1 , books.begin() + 3);
            cout << "After erasure: " << endl;
            for(pr = books.begin() ; pr != books.end() ; pr++){
                showReview(*pr);
            }
            books.insert(books.begin() , oldlist.begin() + 1, oldlist.begin() + 2);
            cout << "After insertion:" << endl;
            for(pr = books.begin() ; pr != books.end() ; pr++){
                showReview(*pr);
            }
        }
        books.swap(oldlist);
        cout << "Swapping oldlist with books:" << endl;
        for(pr = books.begin() ; pr != books.end() ; pr++){
             showReview(*pr);
        }
    }else{
        cout << "Nothing entered , nothing gained." << endl;
    }
    return 0;
}
