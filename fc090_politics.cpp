#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct despicable {
	int s, a, b;
};

int main()
{
	int n, help, s, a, b;
	double asghar[1000012], mohseni[1000012], shit = 0, Oops = 0;
	cin >> n;
	despicable ArreyOne[10000];

	for (int j = 0; j < n; j++)
	{
		cin >> ArreyOne[j].s >> ArreyOne[j].a >> ArreyOne[j].b;
	}

	help = n - 1, mohseni[1000011] = 0, asghar[1000011] = 0;

	for (int i = 1000000; i > 0; i--)
	{
		asghar[i] = asghar[i + 1];
		for (; help >= 0 && ArreyOne[help].s == i;)
		{
			int mashdosein(ArreyOne[help].a), gholom(ArreyOne[help].b);

			shit = (mohseni[min(i + mashdosein, 1000011)] - mohseni[min(i + gholom + 1, 1000011)]) / (gholom - mashdosein + 1);
			Oops = shit + 1;
			asghar[i] = max(asghar[i], Oops);
			help--;
		}
		mohseni[i] = asghar[i] + mohseni[i + 1];
	}

	cout << fixed;
	cout << setprecision(8);
	cout << asghar[1] << endl;

	return 0;
}

