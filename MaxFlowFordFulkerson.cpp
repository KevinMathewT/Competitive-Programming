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
ll n;

struct MaxFlowFord{
	vector<vector<ll> > G, F;
	ll n;
	const ll INF = 10000000000LL;

	// Keep in Mind this takes an Adjacency Matrix (vector<vector<ll> >) as input.

	MaxFlowFord(vector<vector<ll> > &_G, ll _n){
		G = _G;
		n = _n;
	}

	ll bfs(ll s, ll t, vector<ll> &parent){
		fill(parent.begin(), parent.end(), -1);
		queue<pair<ll, ll> > q;
		q.push({s, INF});
		while(!q.empty()){
			pair<ll, ll> pll = q.front(); q.pop();
			for(ll i=0;i<n;i++)
				if(i != pll.F && parent[i] == -1 && F[pll.F][i] > 0){
					parent[i] = pll.F;
					ll new_flow = min(pll.S, F[pll.F][i]);
					if(i == t) return new_flow;
					q.push({i, new_flow});
				}
		}
		return 0;
	}

	ll getFlow(ll s, ll t){
		ll flow = 0, new_flow;
		vector<ll> parent(n, 0);
		F = G;

		while(new_flow = bfs(s, t, parent)){
			flow += new_flow;

			ll rev = t;
			while(rev != s){
				F[parent[rev]][rev] -= new_flow;
				F[rev][parent[rev]] += new_flow;
				rev = parent[rev];
			}
		}
		return flow;
	}
};

void solve(){
	vector<ll> G[3];
	
		
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