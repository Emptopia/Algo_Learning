#include "Solution.h"

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