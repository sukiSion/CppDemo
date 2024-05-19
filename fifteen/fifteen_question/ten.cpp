#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <memory>

using namespace std;

struct Review{
    string title;
    int rating;
    double price;
};


shared_ptr<Review> CreateReview(){
    return shared_ptr<Review>(new Review);
}

bool FillReview(const shared_ptr<Review> & spr){
    cout << "Enter book title(quit to quit): ";
    getline(cin , spr->title);
    if(spr->title == "quit"){
        return false;
    }
    cout << "Enter book rating: ";
    cin >> spr->rating;
    if(!cin){
        return false;
    }
    cout << "Enter book price: ";
    cin >> spr->price;
    if(!cin){
        return false;
    }
    while(cin.get() != '\n');
    return true;
}

bool operator<(const shared_ptr<Review> & spr1 , const shared_ptr<Review> & spr2){
    if(spr1->title < spr2->title){
        return true;
    }else if(spr1->title == spr2->title && spr1->rating < spr2->rating){
        return true;
    }else if(spr1->title == spr2->title && spr1->rating == spr2->rating && spr1->price < spr2->price){
        return true;
    }else{
        return false;
    }
}

bool RatingAscend(const shared_ptr<Review> & spr1 , const shared_ptr<Review> & spr2){
    return spr1->rating < spr2-> rating;
}

bool RatingDescend(const shared_ptr<Review> & spr1 , const shared_ptr<Review> & spr2){
    return spr1->rating > spr2-> rating;
}

bool PriceAscend(const shared_ptr<Review> & spr1 , const shared_ptr<Review> & spr2){
    return spr1->price < spr2-> price;
}

bool PriceDescend(const shared_ptr<Review> & spr1 , const shared_ptr<Review> & spr2){
    return spr1-> price > spr2-> price;
}

void ShowReview(const shared_ptr<Review> & spr){
     cout << spr->rating << "\t" << spr->price << "\t" << spr->title << endl;
}

int main(int argc, char const *argv[])
{
    vector<shared_ptr<Review>> original_books;
    shared_ptr<Review> book = CreateReview();
    while (FillReview(book))
    {
        original_books.push_back(book);
        book = CreateReview();
    }
    if (original_books.size() > 0){
        vector<shared_ptr<Review>> sorted_books(original_books);
        cout << "Tnank you. You entered the following:" << endl;
        cout << "Rating\tPrice\tBook" << endl;
        for_each(original_books.begin() , original_books.end() , ShowReview);
        char ch;
        cout << "Menu:" << endl;
        cout << "o: show original books" << endl;
        cout << "a: show books by title" << endl;
        cout << "u: show books by up rating" << endl;
        cout << "d: show books by down rating" << endl;
        cout << "p: show books by up price" << endl;
        cout << "k: show books by down price" << endl;
        cout << "q: quit" << endl;
        cout << "input: ";
        while (cin >> ch &&  tolower(ch) != 'q'){
        switch (ch)
            {
                case 'o':
                {
                    cout << "Original books:\nRating\tPrice\tBook\n";
                    for_each(original_books.begin(), original_books.end(), ShowReview);
                    break;
                }
                case 'a':
                {
                    sort(sorted_books.begin(), sorted_books.end());
                    cout << "Sorted by title:\nRating\tPrice\tBook\n";
                    for_each(sorted_books.begin(), sorted_books.end(), ShowReview);
                    break;
                }
                case 'u':
                {
                    sort(sorted_books.begin(), sorted_books.end(), RatingAscend);
                    cout << "Sorted by up rating:\nRating\tPrice\tBook\n";
                    for_each(sorted_books.begin(), sorted_books.end(), ShowReview);
                    break;
                }
                case 'd':
                {
                    sort(sorted_books.begin(), sorted_books.end(), RatingDescend);
                    cout << "Sorted by down rating:\nRating\tPrice\tBook\n";
                    for_each(sorted_books.begin(), sorted_books.end(), ShowReview);
                    break;
                }
                case 'p':
                {
                    sort(sorted_books.begin(), sorted_books.end(), PriceAscend);
                    cout << "Sorted by up price:\nRating\tPrice\tBook\n";
                    for_each(sorted_books.begin(), sorted_books.end(), ShowReview);
                    break;
                }
                case 'k':
                {
                    sort(sorted_books.begin(), sorted_books.end(), PriceDescend);
                    cout << "Sorted by down price:\nRating\tPrice\tBook\n";
                    for_each(sorted_books.begin(), sorted_books.end(), ShowReview);
                    break;
                }
                default:
                {
                    cout << "Wrong input! Please enter again!" << endl;
                    break;
                }
            }
            cout << "\nMenu:" << endl;
            cout << "o: show original books" << endl;
            cout << "a: show books by title" << endl;
            cout << "u: show books by up rating" << endl;
            cout << "d: show books by down rating" << endl;
            cout << "p: show books by up price" << endl;
            cout << "k: show books by down price" << endl;
            cout << "q: quit" << endl;
            cout << "input: ";
        }
    }else{
        cout << "No entries. ";
    }
    cout << "Bye.\n";
    return 0;
}
