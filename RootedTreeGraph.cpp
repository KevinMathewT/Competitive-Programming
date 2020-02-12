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
ll n, m, d[N], vis[N], c[N], p[N];
vector<ll> g[N], t[N];
vector<pair<ll, ll> > e;

void dfs(ll u){
	vis[u] = 1;

	vector<pair<ll, ll> > next;
	for(ll v : g[u])
		next.push_back({d[v], v});
	sort(next.begin(), next.end());

	for(ll i=next.size()-1;i>=0;i--){
		auto pll = next[i];
		if(vis[pll.S] != 1){
			e.push_back({u, pll.S});
			t[pll.S].push_back(u);
			t[u].push_back(pll.S);
			p[pll.S] = u + 1;
			dfs(pll.S);
		}
	}
}

ll dfs2(ll u, ll p){
	c[u] = 1;
	for(ll v : t[u])
		if(v != p)
			c[u] += dfs2(v, u);
	return c[u];
}

bool dfs3(ll u, ll de = 0, ll p = -1){
	if(c[u] - 1 + de != d[u])
		return 0;

	bool ret = 1;
	for(ll v : t[u])
		if(v != p)
			ret &= dfs3(v, de + 1, u);

	return ret;
}

void solve(){
	e.clear();
	cin >> n >> m;
	fill(c, c + n, 0);
	fill(d, d + n, 0);
	fill(p, p + n, 0);
	fill(vis, vis + n, 0);
	for(ll i=0;i<n;i++) g[i].clear(), t[i].clear();
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++;
		d[v]++;
	}

	ll mx = 0, pos = 0;
	for(ll i=0;i<n;i++)
		if(d[i] > mx) mx = d[i], pos = i;
	dfs(pos);
	dfs2(pos, -1);
	p[pos] = 0;
	bool check = dfs3(pos);

	if(!check || e.size() != n - 1){
		cout << "NO\n";
		return;
	}

	cout <<"YES\n";
	for(ll i=0;i<n;i++) cout << p[i] << ' ';
	cout << "\n";	
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