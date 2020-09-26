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
	for (auto v : V) os << v << " ";
	os << "]";
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S) {
	os << "{ ";
	for (auto s : S) os << s << " ";
	return os << "}";
}
template<class T> ostream& operator<<(ostream &os, multiset<T> S) {
	os << "{ ";
	for (auto s : S) os << s << " ";
	return os << "}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
	return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> M) {
	os << "{ ";
	for (auto m : M) os << "(" << m.F << ":" << m.S << ") ";
	return os << "}";
}
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L, R> M) {
	os << "{ ";
	for (auto m : M) os << "(" << m.F << ":" << m.S << ") ";
	return os << "}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

const ll N = 100010, M = 1e9 + 7;
ll n, f[N][26], q, y, t[26];
string s;

void solve(ll cs) {
	y = 0;
	cin >> n >> q;
	cin >> s;

	fi(0, n - 1) fill(f[i], f[i] + 26, 0);

	f[0][s[0] - 'A'] = 1;
	fi(1, n - 1) {
		fj(0, 25) f[i][j] = f[i - 1][j];
		f[i][s[i] - 'A'] = f[i - 1][s[i] - 'A'] + 1;
	}

	// fi(0, n - 1) { fj(0, 25) cout << f[i][j] << ' '; cout << "\n"; }

	fi(0, q - 1) {
		ll l, r; cin >> l >> r;
		fj(0, 25) t[j] = f[r - 1][j] - ((l == 1) ? 0 : f[l - 2][j]);
		ll o = 0, e = 0;
		fj(0, 25) if(t[j] % 2 == 0) e++; else o++;

		if(o == 0 || o == 1) y++;
	}

	cout << "Case #" << cs << ": " << y << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	fi(1, T)
		solve(i);

	return 0;
}