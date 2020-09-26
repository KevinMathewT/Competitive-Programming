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

const ll N = 100010, M = 1e9 + 7;
ll n, occ[N], p[N], d[N], root, hc[N];
vector<ll> T[N], leaves;

void dfs(ll u, ll par = 0, ll depth = 0) {
	p[u] = par;
	d[u] = depth;
	for(ll v : T[u])
		if(v != par) dfs(v, u, depth + 1);
}

void solve(){
	cin >> n;

	fi(0, n - 2) {
		ll u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
		occ[u]++;
		occ[v]++;
	}

	fi(1, n) if(occ[i] >= 2) { root = i; break; }
	// cout << root << "\n";
	dfs(root);
	fi(1, n) if(T[i].size() == 1) leaves.push_back(i);
	// fi(1, n) cout << p[i] << ' ';
	// cout << "\n";
	// fi(1, n) cout << d[i] << ' ';
	// cout << "\n";
	// cout << leaves << "\n";
	ll e = 0, o = 0;

	fi(0, leaves.size() - 1) {
		if(d[leaves[i]] % 2 == 0) e++; else o++;
	}

	if(e == 0 || o == 0) cout << 1 << " ";
	else cout << 3 << " ";

	ll mx = n - 1;
	fi(1, n) hc[i] = 0;
	fi(0, leaves.size() - 1) hc[p[leaves[i]]]++;

	fi(1, n) if(hc[i] > 0) {
		mx -= (hc[i] - 1);
	}

	cout << mx << "\n";
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