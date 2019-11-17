#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

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
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, m;

void solve(){
	m = 1e18;
	cin >> n;

	ll a, b;
	b = pow(2, n);
	
	a = 5;
	ll c = 0;

	// cout << a << " " << b << ' ' << c << '\n';
	for(ll i=0;i<n;i++){
		c += (pow(2, i) * (i + 1) * pow(7, n - 1 -i));
		c %= M;
	}

	// cout << a << " " << b << ' ' << c << '\n';
	a *= c;
	a = (a + pow(2, n) * n) % M;

	// cout << a << " " << b << ' ' << c << '\n';
	ll g = __gcd(a, b);
	a /= g;
	b /= g;

	// cout << a << " " << b << ' ' << c << '\n';

	cout << a + b << "\n";
}

int main()
{
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