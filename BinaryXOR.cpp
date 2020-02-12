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

ll n, z1, z2, x, y, fact[100010], M = 1e9 + 7;
string s1, s2;

ll power(ll a, ll x){
	if(x == 0) return 1;
	if(x == 1) return a % M;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * (power((a * a) % M, x / 2)) % M);
}

ll inverse(ll x){
	return power(x, M - 2);
}

void solve(){
	z1 = LLONG_MIN;
	z2 = LLONG_MAX;
	x = y = 0;
	cin >> n;
	cin >> s1 >> s2;

	for(ll i=0;i<n;i++)
		if(s1[i] == '1')
			x++;
	for(ll i=0;i<n;i++)
		if(s2[i] == '1')
			y++;

	z1 = max(x, y) - min(x, y);
	z2 = x + y;
	if(z2 > n)
		z2 = n - (z2 - n);

	ll tot = 0;

	if(z1 > z2)
		swap(z1, z2);

	// cout << z1 << ' ' << z2 << "\n";

	for(ll i=z1;i<=z2;i+=2)
		tot = (tot + ((fact[n] * inverse((fact[n - i] * fact[i]) % M)) % M)) % M;
	
	cout << tot << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fact[0] = 1;
	for(ll i=1;i<100010;i++)
		fact[i] = (i * fact[i-1]) % M;

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}