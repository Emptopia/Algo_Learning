#include <iostream>

using namespace std;

double x1 = 0.61, x2 = -0.05, x3 = 0.88;
double e = 0.0005;
int cnt = 0;
const double eps = 1e-8;

void gs(double& x1, double& x2, double& x3)
{
	x1 = (3.0 - x2) / 5.0;
	x2 = (1.0 - x1 - x3) / 10.0;
	x3 = (7.0 - x2) / 8.0;
	cnt++;
	cout << "µÚ" << cnt << "´Î: x = " << x1 << " " << x2 << " " << x3 << endl;
}


int main()
{
	
	int cnn = 0;
	double e1 = 0.0004, e2 = 1.0, e3 = 1.0;
	while (e1  > e  && cnt < 10)
	{
		gs(x1, x2, x3);
		double e1 = abs(5.0 * x1 + x2 - 3.0);
		double e2 = abs(x1 + 10.0 * x2 + x3 - 1.0);
		double e3 = abs(x2 + 8.0 * x3 - 7.0);
		cout << "e = " << e1 << " " << e2 << " " << e3 << endl;


	}


	return 0;

}