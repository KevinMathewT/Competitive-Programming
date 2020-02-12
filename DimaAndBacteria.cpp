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

const ll N = 100010, M = 1e9 + 7, Z = 510;
ll n, m, k, c[N], p[N], r[N], f[N], dp[Z][Z];
vector<pair<ll, ll> > G[N];

ll find_set(ll x){
	if(p[x] == x) return x;
	return p[x] = find_set(p[x]);
}

ll same_set(ll x, ll y){ return find_set(x) == find_set(y); }

void union_sets(ll x, ll y){
	x = find_set(x);
	y = find_set(y);

	if(!same_set(x, y)){
		if(r[y] > r[x]) swap(x, y);
		p[y] = x;
		r[x] += r[y];
	}
}

ll find_bacteria(ll x){
	x--;
	return (ll) (upper_bound(f, f + k, x) - f) + 1;
}

void solve(){
	cin >> n >> m >> k;
	for(ll i=0;i<k;i++) cin >> c[i];
	f[0] = c[0];
	for(ll i=1;i<k;i++) f[i] = c[i] + f[i - 1];
	for(ll i=0;i<N;i++) p[i] = i, r[i] = 1;
	for(ll i=0;i<m;i++){
		ll u, v, x; cin >> u >> v >> x;

		if(x == 0)
			union_sets(u, v);

		u = find_bacteria(u);
		v = find_bacteria(v);
		if(u == v) continue;
		G[u].push_back({v, x});
		G[v].push_back({u, x});
	}

	ll curr = 1;
	for(ll i=0;i<k;i++){
		for(ll j=1;j<c[i];j++)
			if(!same_set(curr + j, curr + j - 1)){
				cout << "No\n";
				return;
			}

		curr += c[i];
	}

	cout << "Yes\n";

	for(ll i=1;i<=k;i++)
		for(ll j=1;j<=k;j++)
			if(i == j) dp[i][j] = 0;
			else dp[i][j] = INT_MAX;

	for(ll i=1;i<=k;i++)
		for(auto v : G[i])
			dp[i][v.F] = v.S, dp[v.F][i] = v.S;

	for(ll i=1;i<=k;i++)
		for(ll j=1;j<=k;j++)
			for(ll l=1;l<=k;l++){
				dp[j][l] = min(dp[j][l], dp[j][i] + dp[i][l]);
			}

	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=k;j++)
			if(dp[i][j] != INT_MAX)
				cout << dp[i][j] << ' ';
			else cout << -1 << " ";

		cout << "\n";
	}
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}