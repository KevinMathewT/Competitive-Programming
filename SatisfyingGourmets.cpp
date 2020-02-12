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
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
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
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

const ll N = 2000010, M = 1e9 + 7;
ll n, k, vis[N], c[N];
vector<ll> g[N], revg[N];
vector<ll> dfs_ord;

void dfs1(ll u){
	vis[u] = 1;
	for(ll v : g[u])
		if(vis[v] != 1)
			dfs1(v);

	dfs_ord.push_back(u);
}

void dfs2(ll u, ll cp){
	vis[u] = 1;
	c[u] = cp;

	for(ll v : revg[u])
		if(vis[v] != 1)
			dfs2(v, cp);
}

void solve(){
	cin >> n >> k;
	dfs_ord.clear();
	fill(vis, vis + 2 * n + 10, 0);
	for(ll i=0;i<2*n;i++){
		g[i].clear();
		revg[i].clear();
	}
	fill(c, c + 2 * n + 10, 0);
	for(ll i=0;i<k;i++){
		ll i1, b1, i2, b2;
		cin >> i1 >> b1 >> i2 >> b2;

		i1--; b1--; i2--; b2--;
		g[2 * i1 + (b1)].push_back(2 * i2 + (1 - b2));
		g[2 * i2 + (b2)].push_back(2 * i1 + (1 - b1));
		revg[2 * i1 + (1 - b1)].push_back(2 * i2 + (b2));
		revg[2 * i2 + (1 - b2)].push_back(2 * i1 + (b1));
	}

	for(ll i=0;i<2*n;i++)
		if(vis[i] != 1)
			dfs1(i);

	// cout << dfs_ord << "\n";

	reverse(dfs_ord.begin(), dfs_ord.end());
	fill(vis, vis + 2 * n + 10, 0);

	ll cmp = 0;
	for(auto it : dfs_ord)
		if(vis[it] == 0)
			dfs2(it, cmp++);

	for(ll i=0;i<2*n;i+=2)
		if(c[i] == c[i + 1]){
			cout << "NO\n";
			return;
		}

	cout << "YES\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}