//algorithm for calculating prefix array in O(n)

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

const int MAX = 1e6+1;
const int M = 1e9+7;

int pi[MAX];


void pref(string s)
{
    int c = 0;
    pi[0] = 0;

    for(int i = 1; i<(int)s.size(); ++i)
    {
        while(c != 0 && s[i] != s[c])
            c = pi[c-1];
        if(s[i] == s[c])
            c++;
        pi[i] = c;
    }

}
int main()
{
    //_upgrade;
    string s;
    cin>>s;
    pref(s);
    return 0;
}
