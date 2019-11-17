#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

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

ll n, m, degree[100010], d, c, vis[100010];
vector<ll> graph[100010];

void dfs(ll u){
	vis[u] = 1;
	c++;
	d += degree[u];

	for(ll v : graph[u])
		if(vis[v] == 0)
			dfs(v);
}

void solve(){
	cin >> n >> m;
	fill(degree, degree + n, 0);
	fill(vis, vis + n, 0);
	for(ll i=0;i<m;i++){
		ll u, v; cin >> u >> v; u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}

	ll tot = 0;

	for(ll i=0;i<n;i++)
		if(vis[i] == 0){
			// cout << i << "\n";
			c = 0, d = 0;
			dfs(i);
			tot += ((c * (c - 1)) / 2) - (d / 2);
		}

	cout << tot << "\n";
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