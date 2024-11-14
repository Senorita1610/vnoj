#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN=1e4;
bool used[MAXN];
int perm[MAXN];
vector <int> last, removed;
int n, ss, d;
bool check(int x) {
    if (!last.empty()) last.clear();
    if (!removed.empty()) removed.clear();
    for (int i=0;i<n;i++) {
        int j=perm[i];
        if (used[j]) continue;
        move_inside(j);
        if (press_button()>x) {
            move_outside(j);
            removed.push_back(j);
        } else last.push_back(j);
        if (ss+last.size()==d*x) return true;
    }
    return false;
}
int min_cardinality(int N) {
    n=N;
    d=0;
    for (int i=0;i<n;i++) perm[i]=i;
    random_shuffle(perm,perm+n);
    for (int i=0;i<n;i++) {
        int j=perm[i];
        move_inside(j);
        if (press_button()>1) move_outside(j);
        else {
            used[j]=true;
            d++;
        }
    }
    ss=d;
    int l, r, mid;
    l=1; r=n/d+1;
    while (l<r-1) {
        mid=(l+r)/2;
        if (check(mid)) {
            l=mid;
            ss+=last.size();
            for (auto i:last) used[i]=true;
        } else {
            r=mid;
            for (auto i:removed) used[i]=true;
            for (auto i:last) move_outside(i);
        }
    }
    return l;
}

