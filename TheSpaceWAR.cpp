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
ll n, m, vis[N];
vector<ll> t[N];

pair<ll, ll> dfs(ll u, ll p){
	vis[u] = 1;
	pair<ll, ll> mx = {u, 0};
	for(ll v : t[u])
		if(v != p){
			auto ret = dfs(v, u);
			if(ret.S > mx.S) mx = ret;
		}

	mx.S++;
	// cout << u << ' ' << mx << "\n";
	return mx;
}

ll findDiameter(ll u){
	auto pll = dfs(u, -1);
	pll = dfs(pll.F, -1);
	pll.S /= 2;
	return pll.S;
}

void solve(){
	cin >> n >> m;
	fill(vis, vis + n, 0);

	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		t[u].push_back(v);
		t[v].push_back(u);
	}

	ll mx = 0;
	for(ll i=0;i<n;i++)
		if(vis[i] == 0)
			mx = max(findDiameter(i), mx);

	cout << mx << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}