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

ll n;
vector<ll> tree[100010];
ll in[100010], out[100010], ans[100010];

ll dfs1(ll u, ll p){
	if(tree[u].size() == 1 && u != 0){
		in[u] = 1;
		return in[u];
	}

	in[u] = 1;
	for(ll v : tree[u])
		if(v != p)
			in[u] += dfs1(v, u);

	return in[u];
}

ll dfs2(ll u, ll p){
	vector<ll> c(0);

	for(ll v : tree[u])
		if(v != p)
			c.push_back(in[v]);
	if(p != -1)
		c.push_back(out[u]);

	sort(c.begin(), c.end());

	ll tot = 0;
	for(ll i=0;i<c.size()-1;i++)
		tot += c[i];

	// cout << u << ' ' << c << " " << tot << "\n";

	if(c[c.size() - 1] == tot + 1)
		ans[u] = 1;
	else ans[u] = 0;

	tot = 0;
	for(ll v : tree[u])
		if(v != p)
			tot += in[v];
	tot += out[u];
	// cout << u << ' ' << tot << "--\n";
	for(ll v : tree[u])
		if(v != p)
			out[v] = tot - in[v] + 1;


	for(ll v : tree[u])
		if(v != p)
			dfs2(v, u);
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++){
		tree[i].clear();
		in[i] = out[i] = ans[i] = -1;
	}
	for(ll i=0;i<n-1;i++){
		ll u, v; cin >> u >> v; u--; v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs1(0, -1);
	out[0] = 0;
	dfs2(0, -1);

	// for(ll i=0;i<n;i++)
	// 	cout << in[i] << ' ' << out[i] << "\n";

	for(ll i=0;i<n;i++)
		cout << ans[i];
	cout << "\n";
}

int main()
{
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