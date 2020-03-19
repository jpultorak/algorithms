//LCA algorithm

#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i<b; ++i)
#define FR(a, b) for(int i = a; i>=b;--i)
#define _upgrade cin.tie(0); ios_base::sync_with_stdio(0)
#define pb push_back
#define mp make_pair
#define INF 1e9

using namespace std;

typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef pair<int, int> iPair;

const int MAX = 1e5+2;
const int M = 1e9+7;

int n, q, ancestor[MAX][18], tpar[MAX], depth[MAX];
vector<int> tree[MAX];

void get_parents(int v, int pr)
{
    tpar[v] = pr;
    for(auto i : tree[v])
        if(i != pr)
        {
            depth[i] = depth[v]+1;
            get_parents(i, v);
        }
}
void preprocess()
{
    FOR(i, 1, n+1)
        ancestor[i][0] = tpar[i];
    FOR(i, 1, 18)
        FOR(j, 1, n+1)
            ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
}
int LCA(int a, int b)
{
    if(depth[a] > depth[b])
        swap(a, b);
    for(int i = 17; i>=0; --i)
        if(depth[ancestor[b][i]] >= depth[a])
            b = ancestor[b][i];
    if(a == b)
        return a;

    for(int i = 17; i>=0; --i)
        if(ancestor[b][i] != ancestor[a][i])
        {
            b = ancestor[b][i];
            a = ancestor[a][i];
        }
    return tpar[a];
}
int dist(int a, int b)
{
    return depth[a] + depth[b] - 2*depth[LCA(a, b)];
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
    get_parents(1, 1);
    preprocess();
    cin>>q;
    while(q--)
    {
        int a, b;
        cout<<dist(a, b)<<"\n";
    }
    return 0;
}
