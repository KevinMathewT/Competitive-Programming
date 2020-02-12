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
ll n, a[N], q;
vector<ll> T[4 * N];

void build(ll i, ll l, ll r){
	if(l == r){
		T[i] = vector<ll>(1, a[l]);
		return;
	}

	ll m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);

	T[i] = vector<ll>(0);
	merge(T[2 * i].begin(), T[2 * i].end(), T[2 * i + 1].begin(), T[2 * i + 1].end(), back_inserter(T[i]));
}

void update(ll i, ll l, ll r, ll p, ll x){
	if(l == r){
		a[l] = x;
		T[i] = vector<ll>(1, a[l]);
		return;
	}

	ll m = (l + r) / 2;
	if(p <= m) update(2 * i, l, m, p, x);
	else update(2 * i + 1, m + 1, r, p, x);
	T[i] = vector<ll>(0);
	merge(T[2 * i].begin(), T[2 * i].end(), T[2 * i + 1].begin(), T[2 * i + 1].end(), back_inserter(T[i]));
}

vector<ll> query(ll i, ll l, ll r, ll a, ll b){
	if(r < a || l > b) return vector<ll>(0);
	if(l >= a && r <= b) return T[i];

	ll m = (l + r) / 2;
	vector<ll> retL = query(2 * i, l, m, a, b);
	vector<ll> retR = query(2 * i + 1, m + 1, r, a, b);
	vector<ll> ret(0);
	merge(retL.begin(), retL.end(), retR.begin(), retR.end(), back_inserter(ret));

	return ret;
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];

	build(1, 0, n - 1);

	cin >> q;
	while(q--){
		char c;
		cin >> c;

		if(c == 'Q'){
			ll l, r; cin >> l >> r; l--; r--;
			vector<ll> Q = query(1, 0, n - 1, l, r);
			cout << Q.back() + Q[Q.size() - 2] << "\n";
		}

		if(c == 'U'){
			ll i, x; cin >> i >> x; i--;
			update(1, 0, n - 1, i, x);
		}
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