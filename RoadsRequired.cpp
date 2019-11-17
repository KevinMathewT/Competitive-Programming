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

ll n, m, vis1[100010], vis2[100010];
vector<ll> graph[100010];

ll dfs1(ll u){
	vis1[u] = 1;
	ll ret = 1;
	for(ll v : graph[u])
		if(vis1[v] == 0)
			ret += dfs1(v);
	return ret;
}

ll dfs2(ll u){
	vis2[u] = 1;
	ll ret = graph[u].size();
	for(ll v : graph[u])
		if(vis2[v] == 0)
			ret += dfs2(v);
	return ret;
}

void solve(){
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	fill(vis1, vis1 + 100010, 0);
	fill(vis2, vis2 + 100010, 0);

	ll tot = 0;

	for(ll i=0;i<n;i++)
		if(vis1[i] == 0){
			ll p = dfs1(i);
			ll q = dfs2(i) / 2;
			tot += (p * (p - 1)) / 2;
			tot -= q;
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

	// solve();

	return 0;
}