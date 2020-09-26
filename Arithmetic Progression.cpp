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

const ll N = 1000010, M = 1e9 + 7;
ll n, a[N], d[N];

void solve(){
	cin >> n;
	fi(0, n - 1) cin >> a[i];
	if(n == 1) {
		cout << -1 << "\n";
		return;
	}

	sort(a, a + n);
	fi(1, n - 1) d[i] = a[i] - a[i - 1];

	if(n == 2) {
		if(a[0] == a[1]) {
			cout << 1 << '\n';
			cout << a[0] << "\n";
		} else if((a[1] - a[0]) % 2 == 0) {
			cout << 3 << "\n";
			ll cd = a[1] - a[0];
			cout << a[0] - cd << " ";
			cout << a[0] + cd / 2 << " ";
			cout << a[1] + cd << " ";
		} else {
			cout << 2 << "\n";
			ll cd = a[1] - a[0];
			cout << a[0] - cd << " ";
			cout << a[1] + cd << " ";
		}

		return;
	}

	vector<ll> diffs;
	vector<pair<ll, ll> > f;
	map<ll, ll> m;
	fi(1, n - 1) {
		if(m.find(d[i]) == m.end()) diffs.push_back(d[i]), m[d[i]] = 1;
		else m[d[i]]++;
	}

	fi(0, diffs.size() - 1) f.push_back({m[diffs[i]], diffs[i]});
	fi(0, f.size() - 1) f[i].S = -f[i].S;
	sort(f.begin(), f.end());
	fi(0, f.size() - 1) f[i].S = -f[i].S;

	if(diffs.size() == 1) {
		if(a[0] == a[1]) {
			cout << 1 << "\n";
			cout << a[0] << "\n";
			return;
		} else {
			cout << 2 << '\n';
			cout << a[0] - f[0].S << " ";
			cout << a[n - 1] + f[0].S << "\n";
			return;
		}
	}

	if(f.size() > 2 || f.back().F != n - 2 || f[0].S != 2 * f[1].S) {
		cout << 0 << "\n";
		return;
	}

	fi(1, n - 1) {
		if(d[i] == f[0].S) {
			cout << 1 << "\n";
			cout << a[i] - f[1].S << "\n";
			return;
		}
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