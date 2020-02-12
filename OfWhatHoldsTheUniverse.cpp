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

const ll N = 1, M = 1e9 + 7;
ll n;
unordered_map<ll, unordered_map<ll, ll> > dp;

ll power(ll a, ll x){
	if(x == 0) return 1;
	if(x == 1) return a;
	if(x % 2 == 0) return power(a * a, x / 2);
	return a * power(a * a, x / 2);
}

ll maxpow(ll x){
	if(x == 0) return -1;
	ll l = 0, r = 39, ret = -1;
	while(l <= r){
		ll m = (l + r) / 2;
		if(power(3, m) <= x){
			ret = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	return ret;
}

ll DP(ll x, ll y, ll d){
	// cout << x << ' ' << y << "\n";
	if(x <= 0 || y <= 0) return d;
	ll z = maxpow(x);
	if(z == y) z--;
	ll ret = power(2, z) - 1;
	// cout << x << " " << ret << "\n";
	return ret + DP(x - power(3, z), z, d + 1);
}

void solve(){
	dp.clear();
	cin >> n;
	for(ll i=0;i<n;i++)
		cout << DP(i, 10000, 0) << " ";
	cout << DP(n, 10000, 0) << "\n";
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