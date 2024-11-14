#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100'000;
const int MOD = 1'000'000'007;

vector<long long> sums(4 * MAXN, 0);
vector<long long> lazy_set(4 * MAXN, -1), lazy_add(4 * MAXN, 0), lazy_mul(4 * MAXN, 1);

void pullUpdate(int node)
{
    sums[node] = (sums[node * 2] + sums[node * 2 + 1]) % MOD;
}

void pushUpdates(int node, int low, int high)
{
    if (lazy_set[node] != -1)
    {
        sums[node] = (lazy_set[node] * (high - low + 1)) % MOD;
        if (low != high)
        {
            lazy_set[node * 2] = lazy_set[node * 2 + 1] = lazy_set[node];
            lazy_add[node * 2] = lazy_add[node * 2 + 1] = 0;
            lazy_mul[node * 2] = lazy_mul[node * 2 + 1] = 1;
        }
        lazy_set[node] = -1;
    }

    if (lazy_mul[node] != 1)
    {
        sums[node] = (sums[node] * lazy_mul[node]) % MOD;
        if (low != high)
        {
            lazy_mul[node * 2] = (lazy_mul[node * 2] * lazy_mul[node]) % MOD;
            lazy_mul[node * 2 + 1] = (lazy_mul[node * 2 + 1] * lazy_mul[node]) % MOD;
            lazy_add[node * 2] = (lazy_add[node * 2] * lazy_mul[node]) % MOD;
            lazy_add[node * 2 + 1] = (lazy_add[node * 2 + 1] * lazy_mul[node]) % MOD;
        }
        lazy_mul[node] = 1;
    }

    if (lazy_add[node] != 0)
    {
        sums[node] = (sums[node] + (lazy_add[node] * (high - low + 1)) % MOD) % MOD;
        if (low != high)
        {
            lazy_add[node * 2] = (lazy_add[node * 2] + lazy_add[node]) % MOD;
            lazy_add[node * 2 + 1] = (lazy_add[node * 2 + 1] + lazy_add[node]) % MOD;
        }
        lazy_add[node] = 0;
    }
}

int N, Q;
array<int, MAXN> B;

void buildTree(int node = 1, int low = 0, int high = N - 1)
{
    if (low == high)
    {
        sums[node] = B[low];
    }
    else
    {
        int middle = low + (high - low) / 2;
        buildTree(node * 2, low, middle);
        buildTree(node * 2 + 1, middle + 1, high);
        pullUpdate(node);
    }
}

void updateRangeSet(int L, int R, long long S, int node = 1, int low = 0, int high = N - 1)
{
    pushUpdates(node, low, high);
    if (R < low || high < L)
    {
        return;
    }
    else if (L <= low && high <= R)
    {
        lazy_set[node] = S;
        lazy_mul[node] = 1;
        lazy_add[node] = 0;
        pushUpdates(node, low, high);
    }
    else
    {
        int middle = low + (high - low) / 2;
        updateRangeSet(L, R, S, node * 2, low, middle);
        updateRangeSet(L, R, S, node * 2 + 1, middle + 1, high);
        pullUpdate(node);
    }
}

void updateRangeMul(int L, int R, long long M, int node = 1, int low = 0, int high = N - 1)
{
    pushUpdates(node, low, high);
    if (R < low || high < L)
    {
        return;
    }
    else if (L <= low && high <= R)
    {
        lazy_mul[node] = M;
        pushUpdates(node, low, high);
    }
    else
    {
        int middle = low + (high - low) / 2;
        updateRangeMul(L, R, M, node * 2, low, middle);
        updateRangeMul(L, R, M, node * 2 + 1, middle + 1, high);
        pullUpdate(node);
    }
}

void updateRangeAdd(int L, int R, long long A, int node = 1, int low = 0, int high = N - 1)
{
    pushUpdates(node, low, high);
    if (R < low || high < L)
    {
        return;
    }
    else if (L <= low && high <= R)
    {
        lazy_add[node] = A;
        pushUpdates(node, low, high);
    }
    else
    {
        int middle = low + (high - low) / 2;
        updateRangeAdd(L, R, A, node * 2, low, middle);
        updateRangeAdd(L, R, A, node * 2 + 1, middle + 1, high);
        pullUpdate(node);
    }
}

long long queryRange(int L, int R, int node = 1, int low = 0, int high = N - 1)
{
    pushUpdates(node, low, high);
    if (R < low || high < L)
    {
        return 0;
    }
    else if (L <= low && high <= R)
    {
        return sums[node];
    }
    else
    {
        int middle = low + (high - low) / 2;
        return (queryRange(L, R, node * 2, low, middle) + queryRange(L, R, node * 2 + 1, middle + 1, high)) % MOD;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = 0; i < N; ++i)
    {
        cin >> B[i];
    }
    buildTree();

    for (int q = 0; q < Q; ++q)
    {
        int T;
        cin >> T;

        if (T == 1)
        {
            int L, R, A;
            cin >> L >> R >> A;
            --L, --R;
            updateRangeAdd(L, R, A);
        }
        else if (T == 2)
        {
            int L, R, M;
            cin >> L >> R >> M;
            --L, --R;
            updateRangeMul(L, R, M);
        }
        else if (T == 3)
        {
            int L, R, S;
            cin >> L >> R >> S;
            --L, --R;
            updateRangeSet(L, R, S);
        }
        else
        {
            int L, R;
            cin >> L >> R;
            --L, --R;
            cout << queryRange(L, R) << "\n";
        }
    }

    return 0;
}

