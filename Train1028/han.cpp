#include<iostream>
using namespace std;
#include<vector>
#include<stack>
int i = 1;
void move(char x, char y)
{
	cout << "STEP" << i << "£º" << x << "->" << y << endl;
	i++;
}

void hanoi(int n, char a, char b, char c)
{
	if (n == 1)move(a, c);
	else
	{
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);

	}


}


int main()
{
	int n;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');






	system("pause");
	return 0;

}