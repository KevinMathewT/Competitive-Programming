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
ll n, m;
vector<ll> G[N], GR[N];
vector<bool> used;
vector<ll> order, comp;

void dfs1(ll v) {
    used[v] = true;
    for (ll u : G[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(ll v, ll cl) {
    comp[v] = cl;
    for (ll u : GR[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

ll SCC() {
    used.assign(n, false);
    order.clear();
    for (ll i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    ll i, j;
    for (i = 0, j = 0; i < n; ++i) {
        ll v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    vector<ll> sz(j, 0);
    for(ll i=0;i<n;i++) sz[comp[i]]++;

    ll ans = n;
  	for(ll i=0;i<j;i++) if(sz[i] == 1) ans--;

  	return ans;
}

void solve(){
	cin >> n >> m;
	for(ll i=0;i<N;i++) G[i].clear(), GR[i].clear();

	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		GR[v].push_back(u);
	}

	cout << SCC() << "\n";
}

int main(){
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