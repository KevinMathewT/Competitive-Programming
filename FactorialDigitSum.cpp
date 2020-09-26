#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
	ll n = a.size();
	for (ll i = 1, j = 0; i < n; i++) {
		ll bit = n >> 1;
		for (; j & bit; bit >>= 1)
			j ^= bit;
		j ^= bit;
		if (i < j)
			swap(a[i], a[j]);
	}
	for (ll len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		cd wlen(cos(ang), sin(ang));
		for (ll i = 0; i < n; i += len) {
			cd w(1);
			for (ll j = 0; j < len / 2; j++) {
				cd u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert) {
		for (cd & x : a)
			x /= n;
	}
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	ll n = 1;
	while (n < a.size() + b.size())
		n <<= 1;
	fa.resize(n);
	fb.resize(n);
	fft(fa, false);
	fft(fb, false);
	for (ll i = 0; i < n; i++)
		fa[i] *= fb[i];
	fft(fa, true);
	vector<ll> result(n);
	for (ll i = 0; i < n; i++)
		result[i] = round(fa[i].real());
	return result;
}

const ll N = 10000, M = 1e9 + 7;

vector<ll> rec(ll x, ll y) {
	if (x == y) {
		vector<ll> ret(0);
		ll t = x;
		while (t > 0) ret.push_back(t % 10), t /= 10;
		return ret;
	}
	ll m = (x + y) / 2;
	vector<ll> ret = multiply(rec(x, m), rec(m + 1, y));

	ll i = 0, curr = 0;
	while (true) {
		if (i == ret.size() && curr == 0) break;
		if (i == ret.size() && curr != 0) {
			ret.push_back(curr % 10);
			curr /= 10;
			i++;
			continue;
		}

		ret[i] += curr;
		curr = ret[i] / 10;
		ret[i] %= 10;
		i++;
	}

	return ret;
}

void solve() {
	vector<ll> sol = rec(1, N);
	// cout << sol << "\n";
	cout << accumulate(sol.begin(), sol.end(), 0LL) << "\n";
}

int main() {
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