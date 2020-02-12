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

struct MaxFlowFord{
	vector<vector<ll> > G, F;
	ll n;
	const ll INF = 10000000000LL;

	MaxFlowFord(vector<vector<ll> > &_G, ll _n){
		// G = vector<vector<ll> >(n, vector<ll>(n, 0));
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

const ll N = 110, M = 1e9 + 7;
ll n, m, a[N], b[N];
vector<vector<ll> > G;

void solve(ll te){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];
	cin >> m;
	for(ll i=0;i<m;i++) cin >> b[i];

	G = vector<vector<ll> >(n + m + 2, vector<ll>(n + m + 2, 0));
	ll s = n + m, t = n + m + 1;

	for(ll i=0;i<n;i++)
		G[s][i]++;

	for(ll i=0;i<m;i++)
		G[i + n][t]++;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			if(b[j] % a[i] == 0)
				G[i][n + j] = 1000;

	MaxFlowFord F(G, n + m + 2);
	cout << "Case "<< te << ": " << F.getFlow(s, t) << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	for(ll i=1;i<=T;i++)
		solve(i);

	return 0;
}