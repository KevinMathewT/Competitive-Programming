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

const ll N = 1000010, M = 1e9 + 7;
ll n, dp[N];
vector<ll> t[N];

ll dfs(ll u, ll p){
	if(dp[u] != -2) return dp[u];
	if(t[u].size() <= 1) return dp[u] = -1;
	ll mx = -2;
	ll tot = 0, te;
	for(ll v : t[u])
		if(v != p)
			te = dfs(v, u), mx = max(mx, te), tot += te;
	if(mx == -1)
		return dp[u] = -tot - 1;

	tot = 0;
	for(ll v : t[u])
		if(v != p){
			te = dfs(v, u);
			if(te == -1) tot++;
			else tot += te;
		}
	return dp[u] = tot;
}

void solve(){
	cin >> n;
	fill(dp, dp + N, -2);
	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		t[u].push_back(v);
		t[v].push_back(u);
	}

	ll ans = dfs(0, -1);
	if(ans == -1) cout << 1 << "\n";
	else cout << ans << "-\n";
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