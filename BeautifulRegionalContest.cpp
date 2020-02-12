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

ll n, a[400010], c[400010];

void solve(){
	cin >> n;
	fill(a, a + n + 10, 0);
	fill(c, c + n + 10, 0);
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll p = n % 2 == 0 ? n / 2 - 1 : n / 2;
	while(p >= 0 && a[p] == a[p+1]) p--;

	if(p <= 2){
		cout << "0 0 0\n";
		return;
	}

	n = p + 1;
	p++;
	while(p--)
		c[p] = a[p];

	// cout << n << "\n";

	for(ll i=0;i<n;i++)
		cout << c[i] << " ";
	cout << "\n";

	ll g = 1, s = 1, b = 1;

	ll i = 1;
	for(i=1;i<n;i++)
		if(c[i] == c[i-1]) g++;
		else break;

	s = g + 1;
	for(i=g + g + 1;i<n;i++)
		if(c[i] == c[i-1]) s++;
		else break;
	b = n - i;

	if(g >= s || g >= b)
		cout << "0 0 0\n";
	else
		cout << g << " " << s << ' ' << b << "\n";
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