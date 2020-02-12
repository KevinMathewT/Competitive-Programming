
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

const ll N = 8, M = 1e9 + 7;
ll n, c;
vector<ll> a(N, 0), T(4 * N, 0), L(4 * N, 0);

void build(ll i, ll l, ll r){
	L[i] = 0;
	if(l == r){
		T[i] = a[l];
		return;
	}

	ll m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
	T[i] = T[2 * i] + T[2 * i + 1];
}

void push(ll i, ll l, ll r){
	if(l != r) L[2 * i] += L[i], L[2 * i + 1] += L[i];
	T[i] += (r - l + 1) * L[i];
	L[i] = 0;
}

void update(ll i, ll l, ll r, ll a, ll b, ll v){
	cout << i << ' ' << l << ' ' << r << '\n';
	cout << T << "\n";
	cout << L << "\n";
	push(i, l, r);
	if(r < a || l > b) return;
	if(l >= a && r <= b){
		L[i] = v;
		push(i, l, r);
		return;
	}

	ll m = (l + r) / 2;
	update(2 * i, l, m, a, b, v);
	update(2 * i + 1, m + 1, r, a, b, v);
	T[i] = T[2 * i] + T[2 * i + 1];
}

ll query(ll i, ll l, ll r, ll a, ll b){
	cout << i << '-' << l << ' ' << r << "\n";
	cout << T << "\n";
	cout << L << "\n";

	push(i, l, r);
	if(r < a || l > b) return 0LL;
	if(l >= a && r <= b) return T[i];

	ll m = (l + r) / 2;
	query(2 * i, l, m, a, b);
	query(2 * i + 1, m + 1, r, a, b);
}

void solve(){
	cin >> n >> c;
	for(ll i=0;i<n;i++) a[i] = 0;
	build(1, 0, n - 1);

	while(c--){
		ll t; cin >> t;
		if(t == 0){
			ll l, r, v; cin >> l >> r >> v;
			update(1, 0, n - 1, l, r, v);
			cout << T << "\n";
		}
		else{
			ll l, r; cin >> l >> r;
			cout << query(1, 0, n - 1, l, r) << "\n";
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}