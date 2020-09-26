#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll i=(a);i>=b;j--)

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

const ll N = 50, M = 1e9 + 7;
ll n, m, vis[N], flag;
vector<ll> g[N], v;
vector<vector<ll> > p;

void rec(ll u){
	vis[u] = 1;
	v.push_back(u);

	for(ll t : g[u])
		if(vis[t] == 0){
			rec(t);
		}
}

void solve(){
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	fill(vis, vis + n + 1, 0);

	for(ll i=1;i<=n;i++){
		v.clear();
		if(vis[i] == 0) {
			rec(i);
			p.push_back(v);
		}
	}

	vector<vector<ll> > one(0), two(0), three(0);

	for(ll i=0;i<p.size();i++){
		if(p[i].size() > 3){
			cout << -1 << "\n";
			return;
		}

		if(p[i].size() == 1)
			one.push_back(p[i]);
		else if(p[i].size() == 2)
			two.push_back(p[i]);
		else if(p[i].size() == 3)
			three.push_back(p[i]);
	}

	if(two.size() > one.size() || ((one.size() - two.size()) % 3 != 0)){
		cout << -1 << "\n";
		return;
	}

	ll i;

	for(i=0;i<two.size();i++){
		cout << two[i][0] << ' ' << two[i][1] << ' ' << one[i][0] << "\n";
	}

	ll k = 0;
	for(;i<one.size();i++){
		cout << one[i][0] << ' ';
		k++;
		if(k % 3 == 0) cout << "\n";
	}

	for(ll i=0;i<three.size();i++){
		for(ll j=0;j<3;j++) cout << three[i][j] << " ";
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