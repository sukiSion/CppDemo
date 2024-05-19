#include<iostream>
#include<ctime>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>

using namespace std;

void test_sort(int n){
    int i ;
    vector<int> vi0;
    for(i = 0; i < n ; i++){
        vi0.push_back(rand());
    }
    vector<int> vi(vi0);
    list<int> li(vi0.size());
    copy(vi0.begin() , vi0.end() , li.begin());

    cout << "Test sorting " << n << " elements:" << endl;

    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "Sort vi: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s." << endl;

    start = clock();
    li.sort();
    end = clock();
    cout << "Sort li: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s." << endl;
    
    sort(vi0.begin() , vi0.end());
    copy(vi0.begin() , vi0.end() , li.begin());

    start = clock();
    copy(li.begin() , li.end() ,vi.begin());
    sort(vi.begin() , vi.end());
    copy(vi.begin() , vi.end() , li.begin());

    end = clock();
    cout << "Sort vi and copy to li: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s." << endl;

}

const long big[3] = {100000, 1000000, 10000000};

int main(int argc, char const *argv[])
{
    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        test_sort(big[i]);
    }
    cout << "Done." << endl;
    return 0;
}


