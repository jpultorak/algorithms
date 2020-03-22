//algorithm for searching pattern in text
// complexity - O(|s| + |t|)

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


//build the prefix-suffix array
int pi[2*MAX];

void pref(string s, string t)
{
    s = s + '#' + t;
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

    // looking for s in t
    string s, t;
    cin>>s>>t;
    int sn = s.size(), tn = t.size();
    pref(s, t);

    //print occurences of s in t
    FOR(i, sn+1, tn + sn +1)
        if(pi[i] == sn)
           cout<<i-2*sn+1<<" ";

    return 0;
}
