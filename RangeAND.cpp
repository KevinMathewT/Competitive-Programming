// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll j=(a);j>=b;j--)

// #include <ext/pb_ds/assoc_container.hpp> // Common file 
// #include <ext/pb_ds/tree_policy.hpp> 
// #include <functional> // for less 
// #include <iostream> 
// using namespace __gnu_pbds; 
// using namespace std; 
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order(k) : Value at kth index in sorted array. 
// order_of_key(k) : Index of the value k.

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


const ll N = 1, M = 1e9 + 7;
ll l, r;

ll power(ll a, ll x) {
	a %= M;
	if (x == 0) return 1;
	if (x == 1) return a % M;
	if (x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * (power((a * a) % M, x / 2))) % M;
}

ll powerNoM(ll a, ll x) {
	if (x == 0) return 1;
	if (x == 1) return a;
	if (x % 2 == 0) return powerNoM((a * a), x / 2);
	return (a * (powerNoM((a * a), x / 2)));
}

void solve(){
	cin >> l >> r;

	vector<ll> v(0);
	ll t = l;
	while (t > 0) {
		v.push_back(t % 2);
		t /= 2;
	}

	vector<ll> u(0);
	for (ll b : v) u.push_back(b);

	ll ans = 0;

	fi (0, v.size() - 1) {
		if (v[i] == 0) continue;
		fj (0, i) u[j] = 1;
		ll num = 0;
		fj (0, u.size() - 1) if (u[j] == 1) num += (1LL << j);
		// cout << num << '\n';

		if (num >= r) ans = (ans + ((((r - l + M + 1) % M) * ((1LL << i) % M)) % M)) % M;
		else ans = (ans + ((((num - l + 1 + M) % M) * ((1LL << i) % M)) % M)) % M; 
	}

	cout << ans << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}