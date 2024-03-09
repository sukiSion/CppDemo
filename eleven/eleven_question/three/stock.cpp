#include "stock.h"
#include<cstring>

Stock::Stock(){
    // std::cout << "Default constructor called.\n";
    char no_name[] = "no name";
    company = new char[strlen(no_name) + 1];
    strcpy(company , no_name);
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co , long n , double pr ){
    // std::cout << "Constructor using " << co << " called.\n";
    company = new char[strlen(co) + 1];
    strcpy(company , co);
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::Stock(const Stock & st){
    company = new char[strlen(st.company) + 1];
    strcpy(company , st.company);
    shares = st.shares;
    share_val = st.share_val;
    total_val = st.total_val;
}

Stock::~Stock(){
    // std::cout << "Bye, " << company << "!\n";
    delete [] company;
}

Stock & Stock::operator=(const Stock & st){
    if(this == &st){
        return *this;
    }
    delete [] company;
    company = new char[strlen(st.company) + 1];
    strcpy(company , st.company);
    shares = st.shares;
    share_val = st.share_val;
    total_val = st.total_val;
    return *this;
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}


const Stock & Stock::topval(const Stock & s) const
{
    if(s.total_val > total_val){
        return s;
    }else{
        return *this;
    }
}

std::ostream & operator<<(std::ostream & os , const Stock & st){
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed , ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "Company: " << st.company
              << " Shares: " << st.shares << '\n'
              << " Share Price: $" << st.share_val;
    cout.precision(2);
    cout << " Total Worth: $" << st.total_val << '\n';
    cout.setf(orig , ios_base::floatfield);
    cout.precision(prec);
    return os;
}