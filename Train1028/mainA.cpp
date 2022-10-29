#include<iostream>
using namespace std;
#include<vector>
#include<string>
int main()
{
	string s;
	cin >> s;
	int count = 0;
	string t = "chuanzhi";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == t[0])
		{
			int same = 1;
			for (int j = 1; j < 7; j++)
			{
				if ((i + j) >= s.size())
				{
					cout << count << endl;
					return 0;
				}
				if (s[i + j] != t[j])same = 0;
			}
			if (same == 1)count++;
		}
	}
	cout << count << endl;


	system("pause");
	return 0;

}