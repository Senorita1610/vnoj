#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int M = 1e6 + 5;

int n;
char a[N];
int id[4];
int f[4][M], tot;
int f3[M], tot3;
int cnt;

void change() { swap (id[1], id[2]); }

void times(int x)
{
	f[id[2]][0] = f[id[1]][0];
	int add = 0;
	for (int i = 1; i <= f[id[2]][0]; i ++)
	{
		f[id[2]][i] = f[id[1]][i] * x + add;
		add = f[id[2]][i] / 10;
		f[id[2]][i] %= 10;
	}
	if (add) f[id[2]][++ f[id[2]][0]] = add;
}

void times3 ()
{
	int add = 0;
	for (int i = 1; i <= tot3; i ++)
	{
		f3[i] = f3[i] * 3 + add;
		add = f3[i] / 10;
		f3[i] %= 10;
	}
	if (add) f3[++ tot3] = add;
}

void add ()
{
	int add = 0;
	f[id[2]][0] = max (f[id[2]][0], tot3);
	for (int i = 1; i <= f[id[2]][0]; i ++)
	{
		f[id[2]][i] += f3[i] + add;
		add = f[id[2]][i] / 10;
		f[id[2]][i] %= 10;
	}
	if (add) f[id[2]][++ f[id[2]][0]] = add;
}

int main()
{
	id[1] = 1, id[2] = 2;
	f3[1] = 1, tot3 = 1;
	f[id[1]][0] = 1;
	f[id[1]][1] = 1;
	scanf ("%s", (a + 1));
	n = strlen(a + 1);
	for (int i = 1; i <= n; i ++)
	{
		if (a[i] == 'L') times(2);
		else if (a[i] == 'R') times(2), add();
		else if (a[i] == '*') times(5), add(), times3();
		else times (1);
		change ();
	}
	for (int i = f[id[1]][0]; i >= 1; i --) printf ("%d", f[id[1]][i]);
	return 0;
}

