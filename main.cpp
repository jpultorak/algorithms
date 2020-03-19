#include <bits/stdc++.h>


#define FOR(i, a, b) for(int i = a; i<b; ++i)
#define FR(i, a, b) for(int i = a; i>=b; --i)
#define _upgrade cin.tie(0); ios_base::sync_with_stdio(0)
#define pb push_back
#define mp make_pair
#define INF 1e9

using namespace std;

typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef pair<int, int> iPair;


const int MAX = 5e4 +2;
const int MOD = 1e9 +7;


int sub[MAX], n;
vector<int> tree[MAX];
bool dead[MAX];


int get_size(int node, int pr)
{
    sub[node] = 1;
    for(int i : tree[node])
        if(!dead[i] && i != pr)
            sub[node] += get_size(i, node);
    return sub[node];
}
int find_centroid(int node, int pr, int sz)
{
    for(int i : tree[node])
        if(i != pr && !dead[i] && sub[i] > sz/2)
            return find_centroid(i, node, sz);
    return node;
}
void decompose(int x)
{
    int sz = get_size(x, -1), v = find_centroid(x, -1, sz);

    //solve problem for current centroid here
    dead[v] = true;
    for(int i : tree[v])
        if(!dead[i])
            decompose(i);
}

int main()
{
    //_upgrade;
    cin>>n;
    FOR(i, 0, n-1)
    {
        int a, b;
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    decompose(1);
}
