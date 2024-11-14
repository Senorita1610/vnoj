#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
 
const int N = 1e5 + 10 , inf = 1e9 , Lg = 17;
 
int n , a[N] , rmxq[N][Lg] , rmnq[N][Lg] , lg2[N] , nexL[N] , nexR[N] , las;
int b[N] , psum[N] , m , mvR[N][Lg] , mvL[N][Lg];
vector <pair<int ,int>> all;
 
int mn_pos(int aa , int bb)
{
	if(a[aa] < a[bb])
		return aa;
	return bb;
}
 
int mx_pos(int aa , int bb)
{
	if(a[aa] > a[bb])
		return aa;
	return bb;
}
 
int Get_mx(int l , int r)
{
	r++;
	int sz = (r - l);  sz = lg2[sz];
	return mx_pos(rmxq[l][sz] , rmxq[r - (1 << sz)][sz]);
}
 
int Get_mn(int l , int r)
{
	r++;
	int sz = (r - l);  sz = lg2[sz];
	return mn_pos(rmnq[l][sz] , rmnq[r - (1 << sz)][sz]);
}
 
struct SEG{
	vector <int> vec[N << 2];
	int mn[N << 2] , mx[N << 2];
	void Build(int node = 1 , int nl = 0 , int nr = m)
	{
		if(nr - nl == 1)
		{
			vec[node].push_back(all[nl].S);
			mn[node] = all[nl].F;
			mx[node] = all[nl].F;
			return;
		}
		int mid = (nl + nr) >> 1 , lc = node << 1 , rc = lc | 1;
		Build(lc , nl , mid);  Build(rc , mid , nr);
		vec[node] = vec[lc];
		for(auto u : vec[rc])
			vec[node].push_back(u);
		sort(vec[node].begin() , vec[node].end());
		mn[node] = min(mn[lc] , mn[rc]);
		mx[node] = max(mx[lc] , mx[rc]);
	}
	int Get(int val , int l , int r , int node = 1 , int nl = 0 , int nr = m)
	{
		if(mx[node] < val)
			return 0;
		if(mn[node] >= val)
		{
			return upper_bound(vec[node].begin() , vec[node].end() , r) - lower_bound(vec[node].begin() , vec[node].end() , l);
		}
		int mid = (nl + nr) >> 1 , lc = node << 1 , rc = lc | 1;
		return Get(val , l , r , lc , nl , mid) + Get(val , l , r , rc , mid , nr);
	}
} seg;
 
void Build()
{
	lg2[1] = 0;
	for(int i = 2 ; i < N ; i++)
		lg2[i] = lg2[i / 2] + 1;
	for(int i = 0 ; i < n ; i++)
		rmnq[i][0] = rmxq[i][0] = i;
	for(int j = 1 ; j < Lg ; j++)
	{
		int len = (1 << j);
		for(int i = 0 ; i + len <= n ; i++)
		{
			rmnq[i][j] = mn_pos(rmnq[i][j - 1] , rmnq[i + len / 2][j - 1]);
			rmxq[i][j] = mx_pos(rmxq[i][j - 1] , rmxq[i + len / 2][j - 1]);
		}
	}
	vector <int> st;
	for(int i = 0 ; i < n ; i++)
	{
		nexL[i] = -1;
		nexR[i] = n;
		while(!st.empty())
		{
			if(a[st.back()] < a[i])
			{
				nexR[st.back()] = i;
				st.pop_back();
			}
			else
			{
				nexL[i] = st.back();
				break;
			}
		}
		st.push_back(i);
	}
	for(int i = 0 ; i < n ; i++)  if(i - nexL[i] > 1 && nexR[i] - i > 1)
	{
		int lc = Get_mn(nexL[i] + 1 , i - 1) , rc = Get_mn(i + 1 , nexR[i] - 1);
		all.push_back(make_pair(a[i] - max(a[lc] , a[rc]) , i));
	}
	sort(all.begin() , all.end());
	/*for(auto u : all)
		cout << u.F << " " << u.S << endl;
		*/
	for(int i = 0 ; i < n ; i++)
	{
		mvL[i][0] = nexL[i];
		mvR[i][0] = nexR[i];
	}
	for(int j = 1 ; j < Lg ; j++)  for(int i = 0 ; i < n ; i++)
	{
		if(mvL[i][j - 1] == -1)
			mvL[i][j] = -1;
		else
			mvL[i][j] = mvL[mvL[i][j - 1]][j - 1];
		if(mvR[i][j - 1] == n)
			mvR[i][j] = n;
		else
			mvR[i][j] = mvR[mvR[i][j - 1]][j - 1];
	}
	m = all.size();
	if(m == 0)
		return;
	seg.Build();
}
 
void init(int nn , vector <int> vec)
{
	n = nn;
	for(int i = 0 ; i < n ; i++)
		a[i] = vec[i];
	Build();
}
 
 
int max_towers(int l , int r , int d)
{
	int L = l , R = r;
	for(int i = Lg - 1 ; i >= 0 ; i--)  if(mvR[L][i] <= r)
	{
		int id = mvR[L][i];
		if(a[id] - a[Get_mn(l , id)] < d)
			L = id;
	}
	for(int i = Lg - 1 ; i >= 0 ; i--)  if(mvL[R][i] >= l)
	{
		int id = mvL[R][i];
		if(a[id] - a[Get_mn(id , r)] < d)
			R = id;
	}
	//cout << L << " " << R << endl;
	if(L + 1 >= R || m == 0)
		return 1;
	return 1 + seg.Get(d , L + 1 , R - 1);
}

