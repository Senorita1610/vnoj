#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
 
using namespace std;
 
typedef long long ll;
struct node
{
    int id;     
    int region; 
    int low;    
    int high;  
    vector<int> children;   
};
 
struct region
{
    vector<int> ids;           
    vector<pair<int, int> > ranges;
    int depth; 
 
    region() : ids(), ranges(), depth(0) {}
};
 
static int N, R, Q;
static vector<node> nodes;
static vector<region> regions;

static void process_tree(int root, int &id_pool)
{
    int id = id_pool++;
    int r = nodes[root].region;
    regions[r].ids.push_back(id);
    regions[r].depth++;
    regions[r].ranges.push_back(make_pair(id_pool, regions[r].depth));

    for (size_t i = 0; i < nodes[root].children.size(); i++)
        process_tree(nodes[root].children[i], id_pool);
    regions[r].depth--;
    regions[r].ranges.push_back(make_pair(id_pool, regions[r].depth));
}
 
static int log2(int x)
{
    int ans = -1;
    while (x)
    {
        x >>= 1;
        ans++;
    }
    return ans;
}
 
static ll query_by_id(const region &r1, const region &r2)
{
    ll ans = 0;
    for (size_t i = 0; i < r2.ids.size(); i++)
    {
        int pos = r2.ids[i];
        vector<pair<int, int> >::const_iterator site;
        site = lower_bound(r1.ranges.begin(), r1.ranges.end(), make_pair(pos, INT_MAX));
        if (site == r1.ranges.begin())
        {
            continue;
        }
        --site; 
        ans += site->second;
    }
    return ans;
}
static ll query_by_range(const region &r1, const region &r2)
{
    ll ans = 0;
    for (size_t i = 0; i + 1 < r1.ranges.size(); i++)
    {
        int pos1 = r1.ranges[i].first;
        int pos2 = r1.ranges[i + 1].first;
        ll depth = r1.ranges[i].second;
        vector<int>::const_iterator first, last;
        first = lower_bound(r2.ids.begin(), r2.ids.end(), pos1);
        last = lower_bound(r2.ids.begin(), r2.ids.end(), pos2);
        ans += depth * (last - first);
    }
    return ans;
}
 
static ll query_stitch(const region &r1, const region &r2)
{
    ll ans = 0;
    vector<int>::const_iterator id = r2.ids.begin();
    if (r1.ranges.empty())
        return 0;
    while (id != r2.ids.end() && *id < r1.ranges[0].first)
        id++;
    for (size_t i = 0; i + 1 < r1.ranges.size() && id != r2.ids.end(); i++)
    {
        int pos2 = r1.ranges[i + 1].first;
        ll depth = r1.ranges[i].second;
        vector<int>::const_iterator old_id = id;
        while (id != r2.ids.end() && *id < pos2)
            id++;
        ans += depth * (id - old_id);
    }
    return ans;
}
 
int main()
{
    scanf("%d %d %d", &N, &R, &Q);
    nodes.resize(N);
    regions.resize(R);
    scanf("%d", &nodes[0].region);
    nodes[0].region--;
    for (int i = 1; i < N; i++)
    {
        int parent;
        scanf("%d %d", &parent, &nodes[i].region);
        parent--;
        nodes[i].region--;
        nodes[parent].children.push_back(i);
    }
 
    int id_pool = 0;
    process_tree(0, id_pool);
    map<pair<int, int>, ll> cache;
    for (int q = 0; q < Q; q++)
    {
        int r1, r2;
        scanf("%d %d", &r1, &r2);
        r1--;
        r2--;
        pair<int, int> key(r1, r2);
        if (cache.count(key))
        {
            printf("%lld\n", cache[key]);
            fflush(stdout);
            continue;
        }
        static const int LOG_FACTOR = 5;
        const region &region1 = regions[r1];
        const region &region2 = regions[r2];
        int size1 = region1.ids.size();
        int size2 = region2.ids.size();
        int costs[3] = {
            size1 * (log2(size2) + 2) * LOG_FACTOR,
            size2 * (log2(size1) + 2) * LOG_FACTOR,
            size1 + size2
        };
        ll ans = 0;
        switch (min_element(costs, costs + 3) - costs)
        {
        case 0:
            ans = query_by_range(region1, region2);
            break;
        case 1:
            ans = query_by_id(region1, region2);
            break;
        case 2:
            ans = query_stitch(region1, region2);
            break;
        }
        printf("%lld\n", ans);
        fflush(stdout);
        cache[key] = ans;
    }
    return 0;
}

