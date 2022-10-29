#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n;
	cin >> n;
	vector<string>names(n);
	vector<string>nums(n);

	for (int i = 0; i < n; i++)
	{
		cin >> names[i];
		cin >> nums[i];
	}
	int max = 0;
	vector<string>maxnames;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < nums[i].size()-2; j++)
		{
			if (nums[i].size() < 3)break;
			if (nums[i][j] == 's' && nums[i][j + 1] == 'o' && nums[i][j + 2] == 's')
				count++;
		}
		if (count > max)
		{
			maxnames = { names[i] };
			max = count;
		}
		else if (count == max)
		{
			maxnames.push_back(names[i]);
		}

	}
	for (int i = 0; i < maxnames.size(); i++)
	{
		cout << maxnames[i] << " ";
	}
	cout << endl;
	cout << max << endl;



	system("pause");
	return 0;

}