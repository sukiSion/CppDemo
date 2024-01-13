#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
int main()
{
	char words[50];
	int yuanyin = 0, NO_yuanyin = 0, others = 0;
	cout << "Enter words(q to quit): " << endl;
	cin >> words;
	while (strcmp(words, "q"))
	{
		if (!isalpha(words[0]))
		{
			others++;//统计非字母开头的单词
		}
		else
		{
			switch (words[0])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				yuanyin++; break;//统计元音开头的单词
			default:NO_yuanyin++;
			}
		}
		cin >> words;
	}
	cout << yuanyin << " words beginning with yuanyin " << endl;
	cout << NO_yuanyin << " words beginning with consonants " << endl;
	cout << others << " others" << endl;
}