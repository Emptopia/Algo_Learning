#include<iostream>
using namespace std;
#include<vector>
#include<iomanip>

vector<vector<int>>res = {};
vector<int>now = {};

void dfs(vector<int>now, int n, int r,int num)
{
	now.push_back(num);
	vector<int>temp = now;
	if (now.size() == r)
	{
		res.push_back(now);
		return;
	}
	for (int i = now[now.size()-1]+1; i <= n; i++)
	{
		dfs(now, n, r, i);
	}


}


int main()
{
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= n; i++)
	{
		dfs(now, n, r, i);

	}
	
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
		{
			cout << setw(3) << res[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;

}