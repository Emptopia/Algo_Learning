#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
int main()
{
	int n, w, h;
	cin >> n >> w >> h;
	vector<int>nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	double len = sqrt(w * w + h * h);
	for (int i = 0; i < n; i++)
	{
		if (len >= nums[i])cout << "DA" << endl;
		else cout << "NE" << endl;
	}




	system("pause");
	return 0;

}