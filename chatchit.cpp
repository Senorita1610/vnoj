#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	str.insert(0," ");
	str.insert(str.size()," ");
	for(int i=1;i<str.size();i++)
	{
		if (str[i] == 'k' && str[i-1] == ' ' && str[i+1] == ' ')
			str.replace(i, 1 , "khong");
		if (str[i] == 'k' && str[i-1] == ' ' && str[i+1] == 'o' && str[i+2] == ' ')
			str.replace(i, 2 , "khong");
		if (str[i] == 'n' && str[i-1] == ' ' && str[i+1] == ' ')
			str.replace(i, 1 , "nhieu");
		if (str[i] == 'n' && str[i-1] == ' ' && str[i+1] == 'g' && str[i+2] == ' ')
			str.replace(i, 2 , "nguoi");
		if (str[i] == 'd' && str[i-1] == ' ' && str[i+1] == 'c' && str[i+2] == ' ')
			str.replace(i, 2 , "duoc");
		if (str[i] == 'h' && str[i-1] == ' ' && str[i+1] == 'o' && str[i+2] == 'k' && str[i+3] == ' ')
			str.replace(i, 3 , "khong");
		if (str[i] == 'n' && str[i-1] == ' ' && str[i+1] == 't' && str[i+2] == 'n' && str[i+3] == ' ')
			str.replace(i, 3 , "nhu the nao");
		if (str[i] == 'k' && str[i-1] == ' ' && str[i+1] == 'q' && str[i+2] == ' ')
			str.replace(i, 2 , "ket qua");
		if (str[i] == 'j')
			str.replace(i, 1 , "gi");
		if (str[i] == 'w')
			str.replace(i, 1 , "qu");
		if (str[i] == 'f')
			str.replace(i, 1 , "ph");
		if (str[i] == 'd' && str[i+1] == 'z')
			str.replace(i, 2 , "d");
		if (str[i] == 'z')
			str.replace(i, 1 , "d");
	}
	for(int i=1;i<str.size();i++)
	cout << str[i];
}

