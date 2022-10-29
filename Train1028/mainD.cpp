#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>
bool cmp(int& a, int& b)
{
	return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}
//当a+b更大，返回1(a排到前面)
int main()
{
	int n;
	cin >> n;
	vector<int>nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	string link;
	sort(nums.begin(), nums.end(), cmp);
	for (int i = 0; i < nums.size(); i++)
	{
		link.append(to_string(nums[i]));
	}
	cout << link << endl;

	system("pause");
	return 0;

}