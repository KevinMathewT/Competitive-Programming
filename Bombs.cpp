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
ll n, x[N], y[N];
vector<pair<ll, pair<ll, ll> > > v;

void solve(){
	cin >> n;
	fi(0, n - 1) cin >> x[i] >> y[i];
	fi(0, n - 1) v.push_back({abs(x[i]) + abs(y[i]), {x[i], y[i]}});
	sort(v.begin(), v.end());

	ll tot = 0;
	fi(0, n - 1) {
		tot += 2;
		tot += 2 * ((x[i] == 0 ? 0 : 1) + (y[i] == 0 ? 0 : 1));
	}

	cout << tot << '\n';

	fi(0, n - 1) {
		if(v[i].S.F > 0) cout << 1 << ' ' << abs(v[i].S.F) << ' ' << "R\n";
		if(v[i].S.F < 0) cout << 1 << ' ' << abs(v[i].S.F) << ' ' << "L\n";
		if(v[i].S.S > 0) cout << 1 << ' ' << abs(v[i].S.S) << ' ' << "U\n";
		if(v[i].S.S < 0) cout << 1 << ' ' << abs(v[i].S.S) << ' ' << "D\n";

		cout << 2 << '\n';

		if(v[i].S.F > 0) cout << 1 << ' ' << abs(v[i].S.F) << ' ' << "L\n";
		if(v[i].S.F < 0) cout << 1 << ' ' << abs(v[i].S.F) << ' ' << "R\n";
		if(v[i].S.S > 0) cout << 1 << ' ' << abs(v[i].S.S) << ' ' << "D\n";		
		if(v[i].S.S < 0) cout << 1 << ' ' << abs(v[i].S.S) << ' ' << "U\n";

		cout << 3 << "\n";
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