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

const ll N = 2010, M = 1e9 + 7;
ll n, k, a[N], b[N];
map<ll, ll> m;

ll power(ll a, ll x) {
	a = a % M;
	if(x == 0) return 1;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * power((a * a) % M, x / 2)) % M;
}

void solve(){
	cin >> n >> k;
	fi(0, n - 1) cin >> a[i];
	fi(0, n - 1) b[i] = a[i];
	sort(b, b + n);

	ll cc = 0;
	fi(0, n - 1) if(m.find(b[i]) == m.end()) m[b[i]] = cc++;
	fi(0, n - 1) a[i] = m[a[i]];

	ll inv = 0;
	fi(0, n - 1) {
		ll curr_inv = 0;
		fj(i + 1, n - 1) if(a[j] < a[i]) curr_inv = (curr_inv + 1) % M;
		inv = (inv + (((((((k * (k - 1)) % M) * power(2LL, M - 2)) % M)) % M) * a[i]) % M) % M;
		inv = (inv + ((curr_inv * k) % M)) % M;
	}

	cout << inv << "\n";
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