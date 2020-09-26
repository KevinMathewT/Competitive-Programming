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

struct node {
	node *l, *r;
	ll val;

	node(ll val) {
		l = nullptr;
		r = nullptr;
		this.val = val;
	}

	node(node *l, node *r) {
		this.l = l;
		this.r = r;
		val = l.val + r.val;
	}
};

const ll N = 100010, M = 1e9 + 7;
ll n, m, W[N], T[N];
vector<ll> T[N], v;
node* roots[N];
unordered_map<ll, ll> m, revm;

void dfs(){

}

void solve() {
	cin >> n >> m;
	fi(0, n - 1) cin >> W[i], v.push_back(W[i]);
	sort(v.begin(), v.end());
	ll ind = 0;
	fi(0, n - 1) if(m.find(W[i]) == m.end()) m[W[i]] = ind++, revm[m[W[i]]] = W[i];
	fi(0, n - 1) W[i] = m[W[i]];

	fi(0, n - 2) {
		ll u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}

	T[0].push_back(1);
	T[1].push_back(0);

	dfs(0);
}

int main() {
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