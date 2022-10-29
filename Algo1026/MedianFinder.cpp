#include "MedianFinder.h"
MedianFinder::MedianFinder()
{

}


void MedianFinder::addNum(int num)
{
	if (A.size() != B.size())
	{
		A.push(num);
		B.push(A.top());
		A.pop();
	}
	else
	{
		B.push(num);
		A.push(B.top());
		B.pop();
	}


}

double MedianFinder::findMedian()
{
	if (A.size() != B.size())return A.top();
	else return (A.top() + B.top()) / 2.0;
}