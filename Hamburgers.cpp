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
ll nb, ns, nc, pb, ps, pc, cash;
string st;

void solve(){
	cin >> st;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> cash;

	ll b = 0, s = 0, c = 0;
	fi(0, st.size() - 1) if(st[i] == 'B') b++; else if(st[i] == 'S') s++; else c++;

	ll tot = 0;
	tot = min(b == 0 ? LLONG_MAX : nb / b, min(s == 0 ? LLONG_MAX : ns / s, c == 0 ? LLONG_MAX : nc / c));

	nb = nb - b * tot;
	ns = ns - s * tot;
	nc = nc - c * tot;

	ll l = 0, r = 100000000000000LL, p = 0;

	while(l <= r) {
		ll m = (l + r) / 2;

		ll bb = max(0LL, m * b - nb);
		ll bs = max(0LL, m * s - ns);
		ll bc = max(0LL, m * c - nc);

		ll money = bb * pb + bs * ps + bc * pc;
		if(money <= cash) {
			p = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	cout << tot + p << "\n";
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