#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

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

bool operator<(const Review & r1 , const Review & r2){
    if(r1.title < r2.title){
        return true;
    }else if(r1.title == r2.title && r1.rating < r2.rating){
        return true;
    }else{
        return false;
    }
}


bool worseThan(const Review & r1 , const Review & r2){
    if(r1.rating < r2.rating){
        return true;
    }else{
        return false;
    }
}


int main(int argc, char const *argv[])
{
    vector<Review> books;
    Review temp;
    while(FillReview(temp)){
        books.push_back(temp);
    }
    if(books.size() > 0){
        cout << "Tnank you. You entered the following:" << endl;
        cout << "Rating\tBook" << endl;
        for_each(books.begin() , books.end() , showReview);
        sort(books.begin() , books.end());
        cout << "Sorted by title:"<< endl;
        cout << "Rating\tBook" << endl;
        for_each(books.begin() , books.end() , showReview);

        sort(books.begin() , books.end() , worseThan);
        cout << "Sorted by rating:"<< endl;
        cout << "Rating\tBook" << endl;
        for_each(books.begin() , books.end() , showReview);

        random_shuffle(books.begin() , books.end());
        cout << "After shuffling:"<< endl;
        cout << "Rating\tBook" << endl;
        for_each(books.begin() , books.end() , showReview);
    }else{
        cout << "No entries. " << endl;
    }
    cout << "Bye." << endl;
    return 0;
}
