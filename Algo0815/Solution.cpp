#include "Solution.h"

void Solution::printUmap(unordered_map<int, int>m)
{
	for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << ":" << it->second << endl;
	}
}






int Solution::strStr(string haystack, string needle)
{
	bool res = true;
	for (int i = 0; i < haystack.size(); i++)
	{
		if (needle[0] == haystack[i])
		{
			for (int j = 0; j < needle.size(); j++)
			{
				res = true;
				if (needle[j] != haystack[i + j])
				{
					res = false;
					break;
				}
			}
			if(res == true)
				return i;
		}
	}
	return -1;
}


string Solution::countAndSay(int n)
{
	string res = "1";
	for (int i = 0; i < n-1; i++)
	{
		int count = 0;
		int num = res[0] - '0';
		string tempRes = "";
		for (int j = 0; j < res.size(); j++)
		{
			if (num == res[j]-'0')
				count++;
			else
			{
				tempRes += (to_string(count) + to_string(num));
				num = res[j] - '0';
				count = 1;
			}
		}
		tempRes += (to_string(count) + to_string(num));
		res = tempRes;
	}
	return res;
}