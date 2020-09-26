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

const ll N = 400010, M = 1e9 + 7;
ll n, a[N], bit[32], p[40];

void solve(){
	cin >> n;
	fill(bit, bit + 32, 0LL);
	fill(p, p + 40, 0LL);

	for(ll i=0;i<n;i++) cin >> a[i];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<32;j++)
			if((a[i] & (1LL << j)) != 0)
				bit[j]++;


	for(ll i=0;i<32;i++) cout << bit[i] << " ";
	cout << "\n";

	for(ll i=0;i<32;i++) cout << p[i] << " ";
	cout << "\n";

	for(ll i=0;i<32;i++){
		for(ll j=i;j<32;j++){
			if(i == j){
				p[i + 1] += (bit[i] * (bit[i] - 1)) / 2;
			} else {
				ll t = (1LL << i) + (1LL << j);

				for(ll k=0;k<32;k++)
					if((t & (1LL << k)) != 0)
						p[k] += bit[i] * bit[j];
			}

			for(ll i=0;i<32;i++) cout << p[i] << " ";
			cout << "\n";
		}
	}

	for(ll i=0;i<32;i++) cout << bit[i] << " ";
	cout << "\n";

	for(ll i=0;i<32;i++) cout << p[i] << " ";
	cout << "\n";

	ll ans = 0;
	for(ll i=0;i<40;i++)
		if(p[i] % 2 == 1) ans += (1LL << i);
	cout << ans << "\n";
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