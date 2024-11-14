#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
 
vector<vector<pair<int, ll>>> pov;
vector<ll> distX, distY, cost1, cost2, q0;
vector<int> level;
vector<pair<ll, int>> q1, q2, q3;
 
void dfs(int u, int p, ll dist, int op)
{
    if(op) distY[u] = dist;
    else distX[u] = dist;
    for (pair<int, ll> pr : pov[u]) {
        int v = pr.first;
        ll w = pr.second;
        if (v == p) { continue; }
        dfs(v, u, dist + w, op);
    }
}
 
 
int max_score(int N, int X, int Y, ll K, vector <int> U, vector <int> V, vector <int> W)
{
    pov.clear();
    distX.clear();
    distY.clear();
    cost1.clear();
    cost2.clear();
    level.clear();
    q0.clear();
    q1.clear();
    q2.clear();
    q3.clear();
 
    pov.resize(N);
    distX.resize(N, 0);
    distY.resize(N, 0);
    cost1.resize(N, 0);
    cost2.resize(N, 0);
    level.resize(N, 0);
    q0.resize(N);
    q1.reserve(2 * N);
    q2.reserve(N);
    q3.reserve(N);
    for (int j = 0; j < N - 1; j++)
    {
        pov[U[j]].push_back({ V[j], W[j] });
        pov[V[j]].push_back({ U[j], W[j] });
    }
    dfs(X, X, 0, 0);
    dfs(Y, Y, 0, 1);
    for (int i = 0; i < N; i++)
    {
        cost1[i] = min(distX[i], distY[i]);
        cost2[i] = max(distX[i], distY[i]) - cost1[i];
    }
    // case 1:
    for (int i = 0; i < N; i++) { q0[i] = -cost1[i]; }
    if (q0.size()) { sort(q0.begin(), q0.end()); }
    ll budget = K;
    ll ans1 = 0;
    while (q0.size() > 0)
    {
        ll p = q0[q0.size() - 1];
        if (p + budget >= 0)
        {
            budget += p;
            q0.pop_back();
            ans1++;
        }
        else { break; }
    }
 
    // case 2:
    budget = K;
    ll ans2 = 0;
 
    for (int i = 0; i < N; i++) {
        if (distX[i] + distY[i] == distY[X]) {
            budget -= cost1[i];
            if (budget < 0) { return ans1; }
            level[i] = 1;
            q1.push_back({ -(cost2[i]), i });
            ans2++;
        }
        else if (cost1[i] > cost2[i]) { //MAYBE >=
            q2.push_back({ -(cost1[i] + cost2[i]), i });
            q3.push_back({ -cost1[i], i });
        }
        else {
            q1.push_back({ -(cost1[i]), i });
            q1.push_back({ -(cost2[i]), i });
        }
    }
    if (q1.size())sort(q1.begin(), q1.end());
    if (q2.size())sort(q2.begin(), q2.end());
    if (q3.size())sort(q3.begin(), q3.end());
    while (!q2.empty()) {
        pair<ll,int> p2 = q2[q2.size()-1];
        if (p2.first + budget < 0) { break; }
 
        if (q1.size() >= 2) {
            pair<ll, int> p1a = q1[q1.size() - 2], p1b = q1[q1.size() - 1];
            if (-p2.first <= -(p1a.first + p1b.first)) {
                budget += p2.first;
                level[p2.second] = 2;
                q2.pop_back();
                ans2 += 2;
                continue;
            }
 
            budget += p1b.first;
            level[p1b.second]++;
            q1.pop_back();
            ans2 += 1;
            continue;
        }
 
        budget += p2.first;
        if(budget < 0){
                break;
        }
        level[p2.second] = 2;
        q2.pop_back();
        ans2 += 2;
        continue;
    }
 
    while (!q1.empty()) {
        pair<ll, int> p1 = q1[q1.size()-1];
        if (p1.first + budget < 0) { break; }
        budget += p1.first;
        level[p1.second]++;
        q1.pop_back();
        ans2 += 1;
    }
 
    while (!q3.empty()) {
        pair<ll, int> p3 = q3[q3.size() - 1];
        if (p3.first + budget < 0) { break; }
        if (level[p3.second] != 0) {
            q3.pop_back();
            continue;
        }
        budget += p3.first;
        level[p3.second]++;
        q1.pop_back();
        ans2 += 1;
        break;
    }
 
    return max(ans1, ans2);
}

