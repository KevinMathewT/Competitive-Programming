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


const ll N = 710, M = 1e9 + 7;
ll n, m, A[N][N], x, y, B[N][N], AR[N][N], BR[N][N], AC[N][N], BC[N][N], p = 1009;

ll power(ll a, ll x) {
	a %= M;
	if(x == 0) return 1;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	else return (a * (power((a * a) % M, x / 2))) % M;
}

ll calcHash(ll z) {
	string s = "$" + to_string(z);
	ll h = 0;
	fi(0, s.size() - 1) h = (h + ((s[i]) * p)) % M;
	return h;
}

ll calcHashVector(vector<ll> &v) {
	vector<ll> h(v.size(), 0);
	fi(0, h.size() - 1) h[i] = calcHash(v[i]);
	fi(1, h.size() - 1) h[i] = (((h[i - 1] * p) % M) + h[i]) % M;
	return h.back();
}

void test() {
	// // cout << calcHash(2) << "\n";
	// ll z = calcHash(1);
	// // cout << ((z * p) + z) << "\n";
	// vector<ll> y;
	// y.push_back(1);
	// y.push_back(1);
	// y.push_back(2);

	// cout << 2 * calcHashVector(y) << "\n";
}

void preCalculate() {
	fi(0, N) fj(0, N) AR[i][j] = AC[i][j] = 0;
	fi(0, N) fj(0, N) BR[i][j] = BC[i][j] = 0;

	fi(1, n) {
		fj(1, m) AR[i][j] = calcHash(A[i][j]);
		fj(2, m) AR[i][j] = (((AR[i][j - 1] * p) % M) + AR[i][j]) % M;
		fj(1, m) AR[i][j] = (AR[i - 1][j] + AR[i][j]) % M;
	}

	fi(1, x) {
		fj(1, y) BR[i][j] = calcHash(B[i][j]);
		fj(2, y) BR[i][j] = (((BR[i][j - 1] * p) % M) + BR[i][j]) % M;
		fj(1, y) BR[i][j] = (BR[i - 1][j] + BR[i][j]) % M;
	}

	fi(1, m) {
		fj(1, n) AC[j][i] = calcHash(A[j][i]);
		fj(2, n) AC[j][i] = (((AC[j - 1][i] * p) % M) + AC[j][i]) % M;
		fj(1, n) AC[j][i] = (AC[j][i - 1] + AC[j][i]) % M;
	}

	fi(1, y) {
		fj(1, x) BC[j][i] = calcHash(B[j][i]);
		fj(2, x) BC[j][i] = (((BC[j - 1][i] * p) % M) + BC[j][i]) % M;
		fj(1, x) BC[j][i] = (BC[j][i - 1] + BC[j][i]) % M;
	}

	// fi(1, n) {
	// 	fj(1, m) cout << AR[i][j] << ' ';
	// 	cout << "\n";
	// }

	// cout << "\n";

	// fi(1, n) {
	// 	fj(1, m) cout << AC[i][j] << ' ';
	// 	cout << "\n";
	// }

	// cout << "\n";

	// fi(1, x) {
	// 	fj(1, y) cout << BR[i][j] << ' ';
	// 	cout << "\n";
	// }

	// cout << "\n";

	// fi(1, x) {
	// 	fj(1, y) cout << BC[i][j] << ' ';
	// 	cout << "\n";
	// }
}

ll check(ll z) {
	unordered_map<ll, ll> um;
	um.clear();

	fi(1, n) fj(1LL, m) {
		ll k = i + z - 1;
		ll l = j + z - 1;
		if(k > n || l > m) continue;
		ll h1 = ((AR[k][l] - AR[i - 1][l] - ((((AR[k][j - 1] - AR[i - 1][j - 1] + M) % M) * power(p, z)) % M)) + M) % M;
		ll h2 = ((AC[k][l] - AC[k][j - 1] - ((((AC[i - 1][l] - AC[i - 1][j - 1] + M) % M) * power(p, z)) % M)) + M) % M;
			// cout << i << ' ' << j << ' ' << k << ' ' << l << " " << z << " " << (h1 + h2) << "\n";
		um[h1 + h2] = 1;
	}

	// cout << um << "\n";

	fi(1, x) fj(1, y) {
		ll k = i + z - 1;
		ll l = j + z - 1;
		if(k > x || l > y) continue;
		ll h1 = ((BR[k][l] - BR[i - 1][l] - ((((BR[k][j - 1] - BR[i - 1][j - 1] + M) % M) * power(p, z)) % M)) + M) % M;
		ll h2 = ((BC[k][l] - BC[k][j - 1] - ((((BC[i - 1][l] - BC[i - 1][j - 1] + M) % M) * power(p, z)) % M)) + M) % M;
		if(um.find(h1 + h2) != um.end()) {
			cout << "\\\\\\\\\\\\\n";
			cout << i << ' ' << j << ' ' << k << ' ' << l << " " << z << " " << (h1 + h2) << "\n";
			cout << h1 << ' ' << h2 << "\n";
			cout << ((((BR[k][j - 1] - BR[i - 1][j - 1] + M) % M) * power(p, z)) % M) << "\n";
			cout << BR[k][l] << ' ' << BR[i - 1][l] << " " << BR[k][j - 1] << ' ' << BR[i - 1][j - 1] << "\n";
			cout << BC[k][l] << ' ' << BC[i - 1][l] << " " << BC[k][j - 1] << ' ' << BC[i - 1][j - 1] << "\n";
			return 1;
		}
	}

	return 0;
}

void solve(){
	test();
	cin >> n >> m;
	fi(1, n) fj(1, m) cin >> A[i][j];
	cin >> x >> y;
	fi(1, x) fj(1, y) cin >> B[i][j];
	preCalculate();

	ll p = 0;
	ll l = 1, r = min(min(n, m), min(x, y));
	while(l <= r) {
		ll m = (l + r) / 2;
		// cout << m << "\n";
		if(check(m)) {
			p = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	cout << p << "\n";
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