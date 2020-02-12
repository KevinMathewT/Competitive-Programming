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

const ll N = 30010, M = 1e9 + 7;
ll n, q, a[N];

struct Node{
	vector<ll> V;

	Node m(Node a, Node b){
		merge(a.V.begin(), a.V.end(), b.V.begin(), b.V.end(), back_inserter(V));
		return *this;
	}
};

Node T[4 * N];

void build(ll i, ll l, ll r){
	if(l == r){
		T[i].V = vector<ll>(1, a[l]);
		return;
	}

	ll m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
	T[i].m(T[2 * i], T[2 * i + 1]);
}

ll query(ll i, ll l, ll r, ll a, ll b, ll k){
	if(r < a || l > b) return 0;
	else if(l >= a && r <= b) return T[i].V.end() - upper_bound(T[i].V.begin(), T[i].V.end(), k);
	else {
		ll m = (l + r) / 2;
		return query(2 * i, l, m, a, b, k) + query(2 * i + 1, m + 1, r, a, b, k);
	}
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];
	build(1, 0, n - 1);

	cin >> q;
	while(q--){
		ll i, j, k;
		cin >> i >> j >> k;
		cout << query(1, 0, n - 1, i - 1, j - 1, k) << "\n";
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