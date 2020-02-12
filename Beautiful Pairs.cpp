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
ll n, q;
vector<pair<ll, ll> > V;

vector<ll> T[4 * N];

void build(ll i, ll l, ll r){
	if(l == r){
		T[i] = vector<ll>(1, V[l].S);
		return;
	}

	ll m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
	merge(T[2 * i].begin(), T[2 * i].end(), T[2 * i + 1].begin(), T[2 * i + 1].end(), back_inserter(T[i]));
}

ll query(ll i, ll l, ll r, ll a, ll b, ll r1, ll r2){
	if(r < a || l > b) return 0LL;
	if(l >= a && r <= b) return upper_bound(T[i].begin(), T[i].end(), r2) - lower_bound(T[i].begin(), T[i].end(), r1);
	ll m = (l + r) / 2;
	return query(2 * i, l, m, a, b, r1, r2) + query(2 * i + 1, m + 1, r, a, b, r1, r2);
}

void solve(){
	cin >> n;
	V = vector<pair<ll, ll> >(n);
	for(ll i=0;i<n;i++){ cin >> V[i].F >> V[i].S; }
	sort(V.begin(), V.end());
	vector<ll> F;
	for(auto pll : V) F.push_back(pll.F);
	build(1, 0, n - 1);

	cin >> q;
	while(q--){
		ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		ll l = lower_bound(F.begin(), F.end(), l1) - F.begin();
		ll r = upper_bound(F.begin(), F.end(), r1) - F.begin();

		cout << query(1, 0, n - 1, l, r - 1, l2, r2) << '\n';
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