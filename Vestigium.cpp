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

const ll N = 110, M = 1e9 + 7;
ll n, a[N][N], trace, nr, nc;
unordered_map<ll, ll> m;

void solve(ll cs){
	cin >> n;
	fi(0, n - 1) fj(0, n - 1) cin >> a[i][j];
	trace = nr = nc = 0;

	fi(0, n - 1) trace += a[i][i];
	fi(0, n - 1) {
		m.clear();
		fj(0, n - 1) if(m.find(a[i][j]) != m.end()) { nr++; break; } else { m[a[i][j]] = 1; }
	}

	fi(0, n - 1) {
		m.clear();
		fj(0, n - 1) if(m.find(a[j][i]) != m.end()) { nc++; break; } else { m[a[j][i]] = 1; }
	}

	cout << "Case #" << cs << ": " << trace << ' ' << nr << " " << nc << "\n";
}

int main(){
	freope

	return 0;
}