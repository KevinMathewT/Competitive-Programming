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

const ll N = 50010, M = 1e9 + 7;
ll n, q, a[N];

struct Node{
	ll pre, suff, sub, tot;
	Node(){
		pre = suff = sub = tot = 0;
	}

	Node merge(Node a, Node b){
		pre = max(a.pre, a.tot + b.pre);
		suff = max(b.suff, b.tot + a.suff);
		tot = a.tot + b.tot;
		sub = max(a.sub, max(b.sub, a.suff + b.pre));
		return *this;
	}
} tree[4 * N], mn;

void build(ll i, ll l, ll r){
	if(l == r){
		tree[i].pre = a[l];
		tree[i].suff = a[l];
		tree[i].sub = a[l];
		tree[i].tot = a[l];
		return;
	}

	ll m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
	tree[i].merge(tree[2 * i], tree[2 * i + 1]);
}

Node query(ll i, ll a, ll b, ll l, ll r){
	if(b < l || a > r) return mn;
	if(a >= l && b <= r) return tree[i];
	ll m = (a + b) / 2;
	Node ret;
	return ret.merge(query(2 * i, a, m, l, r), query(2 * i + 1, m + 1, b, l, r));
}

void solve(){
	mn.pre = mn.suff = mn.sub = mn.tot = -((ll)1e14);
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];
	build(1, 0, n - 1);
	
	cin >> q;
	while(q--){
		ll x, y;
		cin >> x >> y;
		cout << query(1, 0, n - 1, x - 1, y - 1).sub << "\n";
	}
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