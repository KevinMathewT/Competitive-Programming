#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

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
vector<ll> a, b;

ll match(vector<ll> &c, vector<ll> &d){
	// cout << c << ' ' << d << "\n";
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());

	ll x = d[0] - c[0];
	if(x < 0) return -1;

	for(ll i=0;i<n;i++) if(d[i] != c[i] + x) return -1;

	return x;
}


void solve(){
	cin >> n >> m;

	a = vector<ll>(n, 0);
	b = vector<ll>(n, 0);

	// swap(a, b)

	for(ll i=0;i<n;i++) cin >> a[i];
	for(ll i=0;i<n;i++) cin >> b[i];

	ll l = n - 1;
	ll x = 0;
	while(true){
		if(match(a, b) != -1){
			x += match(a, b); 
			break;
		}

		x += m - a[n - 1];
		ll d = m - a[n - 1];

		for(ll i=0;i<n;i++) a[i] = (a[i] + d) % m;
	}

	cout << (((x % m) + m) % m) << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}