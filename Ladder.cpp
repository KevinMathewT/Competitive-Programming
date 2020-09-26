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

const ll N = 100010, M = 1e9 + 7;
ll n, m, a[N], inc[N], decr[N];

void solve(){
	cin >> n >> m;
	fi(1, n) cin >> a[i];

	inc[0] = 0;
	inc[1] = 1;
	decr[n] = 1;
	decr[n + 1] = 0;
	fi(2, n) if(a[i] >= a[i - 1]) inc[i] = inc[i - 1] + 1; else inc[i] = 1;
	fid(n - 1, 1) if(a[i] >= a[i + 1]) decr[i] = decr[i + 1] + 1; else decr[i] = 1;

	// fi(0, n + 1) cout << inc[i] << " ";
	// cout << "\n";

	// fi(0, n + 1) cout << decr[i] << " ";
	// cout << "\n";

	while(m--){
		ll l, r; cin >> l >> r;

		if((r - l + 1) <= 2) {
			cout << "Yes\n";
			continue;
		}

		ll low = 0, high = r - l, p1 = 0;
		while(low <= high) {
			ll m = (low + high) / 2;
			if((inc[l + m] - inc[l]) == m) {
				p1 = m;
				low = m + 1;
			} else {
				high = m - 1;
			}
		}

		low = 0, high = r - l;
		ll p2 = 0;
		while(low <= high) {
			ll m = (low + high) / 2;
			if((decr[r - m] - decr[r]) == m) {
				p2 = m;
				low = m + 1;
			} else {
				high = m - 1;
			}
		}

		// cout << p1 << ' ' << p2 << "\n";

		if(p1 + p2 >= (r - l)) cout << "Yes\n";
		else cout << "No\n";
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