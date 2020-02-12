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

const ll N = 100010, M = 1e9 + 7;
ll n, p, s, t, v, vis[N], d[N];
vector<pair<ll, ll> > G[N];
multiset<pair<ll, ll> > m;

ll minCost(ll u, ll v){
	m.clear();
	m.insert({0, u});
	fill(vis, vis + N, 0);
	fill(d, d + N, LLONG_MAX);
	vis[u] = 1;

	while(!m.empty()){
		auto pll = *m.begin();
		m.erase(m.lower_bound(pll));
		vis[pll.S] = 1;

		if(pll.S == v) return pll.F;
		for(auto x : G[pll.S])
			if(vis[x.S] != 1 || (x.F + pll.F) < d[x.S])
				m.insert({x.F + pll.F, x.S}), d[x.S] = x.F + pll.F;
	}
}

void solve(){
	cin >> n >> p >> s >> t >> v;
	s--; t--; v--;

	for(ll i=0;i<n;i++)
		G[i].clear();
	for(ll i=0;i<p;i++){
		ll u, v, w; cin >> u >> v >> w;
		u--; v--;
		G[u].push_back({w, v});
		G[v].push_back({w, u});
	}

	ll mn = LLONG_MAX;
	for(ll i=0;i<n;i++)
		mn = min(mn, minCost(s, i) + minCost(v, i) + minCost(t, i));
	cout << mn << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}