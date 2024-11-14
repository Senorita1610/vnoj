#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

double polynominal(int d, double* ci, double x)
{
	double result = 0.0;
	for (int i = 0; i < d + 1; ++i)
		result += ci[i] * pow(x, i);
	return result;
}

int main()
{
	FASTIO();

	int d;
	double coefi[12];

	cin >> d;
	for (int i = 0; i < d + 1; ++i)
		cin >> coefi[i];

	double x = -1e+6;
	double dx = 1e+6;

	while (dx > 1e-8)
	{
		double y = polynominal(d, coefi, x + dx);
		if (y * coefi[d] <= 0.0)
			x += dx;
		dx *= 0.5;
	}

	cout << (int)(x * 1e+3) << endl;
	return 0;
}

