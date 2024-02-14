1、使用函数的三个步骤： 定义函数、提供原型、调用函数
2、创建对应的函数原型：
(1) igor()没有参数，且没有返回值：void igor(void);
(2) tofu()接受一个int参数，并返回一个float：float tofu(int);
(3) mpg()接受两个double参数，并返回一个double：double mpg(double , double);
(4) summation()将long数组名和数组长度作为参数，并返回一个long值：long(long [] , int);
(5) dector()接受一个字符串参数（不能修改该字符串），并返回一个double值：double dector(const char []);
(6) ofcourse()将boss结构作为参数，不返回值：void ofcourse(boss);
(7) plot()将map结构的指针作为参数，并返回一个字符串：char * plot(map *);
3、三个参数函数：int数组名、数组长度和int值，将数组所有元素设置为int值
void set_array(int arr[], int size, int value)
{ 
    for (int i = 0; i < size; i++) 
    arr[i] = value; 
} 
4、三个参数函数：数组第一个元素指针，数组最后一个元素后面的指针和int值，将数组所有元素设置为int值
void set_array(int * begin, int * end, int value)
{ 
    for (int * pt = begin; pt < end; pt++) 
    pt* = value; 
}
5、将double数组名和数组长度作为参数，返回数组最大值，不能修改函数内容
double biggest(const double foot[], int size){
    double max; 
    for(int i = 0 ; i < size; i++){
        max = max >= foot[i] ? max : foot[i];
    }
    return max;
}
6、不对基本类型的函数参数使用const限定符：将 const 限定符用于指针，以防止指向的原始数据被修改。程序传递基本类型（如 int 或 double）时，它将按值传递，以便函数使用副本。这样，原始数据将得到保护。
7、C++可以使用的C风格字符串格式有：字符串可以存储在 char 数组中，可以用带双引号的字符串来表示，也可以用指向字符串第一个字符的指针来表示。
8、函数原型：int replace(char * str , char c1 , char c2); 
函数定义：
int replace(char * str , char c1 , char c2){
    int count;
    while(*str){
        if(*str == c1){
            *str = c2;
            count++;
        }
        str++;
    }
    return cout;
}
9、表达式*"pizza"含义：由于 C++将“pizza”解释为其第一个元素的地址，因此使用*运算符将得到第一个元素的值，即字符 p
表达式"taco"[2]含义：由于 C++将“taco”解释为第一个元素的地址，因此它将“taco”[2]解释为第二个元素的值，即字符c。换句话来说，字符串常量的行为与数组名相同。
10、glitz是结构：
(1) 按值传：传递结构名 glitz 
(2) 按地址传：使用地址运算符 &glitz
按值传递将自动保护原始数据，但这是以时间和内存为代价的。按地址传递可节省时间和内存，但不能保护原始数据，除非对函数参数使用了 const 限定符。另外，按值传递意味着可以使用常规的结构成员表示法，但传递指针则必须使用间接成员运算符。
11、函数judge()返回值：int，参数：将const char 指针作为参数返回int值的函数指针
int judge(int (*)(const char *))
12、有结构：
struct application{
    char name[30];
    int credit_ratings[3];
}
(1) 将结构作为参数，显示结构内容
void display(application ap){
    cout << ap.name << endl;
    for (int i = 0; i < 3; i++) {
        cout << ap.credit_ratings[i] << endl;
    }
}
(2) 将结构地址作为参数，显示地址指向结构的内容
void display(const application * pa){
    cout << pa->name << endl; 
    for (int i = 0; i < 3; i++) {
        cout << pa->credit_ratings[i] << endl; 
    }
}
13、f1(): void f1(application * a);
f2(): const char * f2(const application * a1, const application * a2);
void (*p1)(application * a) = &f1;
const char * (*p2)(const application * a1, const application * a2) = &f2;
void (*ap[5])(application * a)
const char * (*(*p2)[10])(const application * a1, const application * a2)
14、
typedef void (*p_f1)(application *);
p_f1 p1 = f1;
typedef const char * (*p_f2)(const applicant *, const applicant *);
p_f2 p2 = f2; 
p_f1 ap[5];
p_f2 (*ap)[10];