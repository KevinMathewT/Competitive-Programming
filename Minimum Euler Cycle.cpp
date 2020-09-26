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
ll n, l, r;

void solve(){
	cin >> n >> l >> r;

	if(r <= 3) {
		ll a[4];
		a[1] = 1;
		a[2] = 2;
		a[3] = 1;
		fi(l, r) cout << a[i] << ' ';
		cout << "\n";
		return;
	}

	if(l <= 3) {
		ll a[4];
		a[1] = 1;
		a[2] = 2;
		a[3] = 1;
		fi(l, 3) cout << a[i] << ' ';
		l = 4;
	}

	while(l <= r) {
		ll part, m;
		ll low = 1, high = 10000010;
		while(low <= high) {
			m = (low + high) / 2;
			if(((m * (m + 1)) + 1) < l) {
				part = m;
				low = m + 1;
			} else {
				high = m - 1;
			}
		}

		m = part;
		ll z = m;
		ll t = m + 1;
		m += 2;


		while(l <= ((t * (t + 1LL)) + 1LL) && l <= r) {
			if((l % 2) == 0) cout << m << " ";
			else if(l == ((t * (t + 1LL)) + 1LL)) cout << 1LL << " ";
			else cout << ((l - ((z * (z + 1LL)) + 1LL)) / 2LL) + 1LL << " ";
			l++;
		}

		if(l > r) break;
	}

	cout << "\n";
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