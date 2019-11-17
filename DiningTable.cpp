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

ll r, n;

void solve(){
	cin >> r >> n;
	const ll maxn = max(r, n);
	ll C[maxn + 1][maxn + 1];
	C[0][0] = 1;
	for (ll n = 1; n <= maxn; ++n) {
	    C[n][0] = C[n][n] = 1;
	    for (ll k = 1; k < n; ++k)
	        C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
	}

	ll factorial[maxn + 1];
	factorial[0] = 1;
	for (ll i = 1; i <= maxn; i++) {
	    factorial[i] = factorial[i - 1] * i;
	}

	ll ex = n % r;
	ll each = n / r;
	ll tot = 1;
	ll curr = n;

	for(ll i=0;i<r;i++){
		ll p;
		if(i < ex) p = each + 1;
		else p = each;

		ll currp;
		if((p-1) >= 2)
			currp = (C[curr][p] * factorial[p-1]) / 2;
		else
			currp = (C[curr][p] * factorial[p-1]);

		cout << i << ' ' << p << " " << curr << ' ' << currp << "\n";

		curr -= p;
		tot *= currp;
	}

	cout << tot << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}