#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    os << "]";
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

const ll N = 1e6 + 10;
ll n, l[N], r[N];
vector<ll> tree[N];

ll dfs2(ll u, ll s, ll rs, ll p){
	ll nrs = rs + tree[u].size() - (u == 1 ? 0 : 1) + 1;
	ll x = nrs - 2;
	r[u] = x + 1;
	for(ll v : tree[u])
		if(v != p){
			l[v] = x--;
			nrs = dfs2(v, l[v], nrs, u);
		}

	return nrs;
}

void solve(){
	cin >> n;

	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	l[1] = 1;
	dfs2(1, 1, 2, -1);

	for(ll i=1;i<=n;i++)
		cout << l[i] << ' ' << r[i] << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}