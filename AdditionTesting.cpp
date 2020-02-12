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

void printBin(ll x){
	string s = "";

	while(x > 0){
		s.push_back('0' + (x % 2));
		x /= 2;
	}

	reverse(s.begin(), s.end());

	cout << s;
}

ll func(ll a, ll b){
	cout << a << ' ' << b << "\n";
		printBin(a);
		cout << '\n';
		printBin(b);
		cout << "\n";

	ll t = 0;
	while(b > 0){
		t++;
		ll u = a ^ b;
		ll v = a & b;
		a = u;
		b = 2 * v;

		cout << a << ' ' << b << "\n";
		printBin(a);
		cout << ' ';
		printBin(b);
		cout << "\n";
	}

	return t;
}

void solve(){
	ll mx = 0, l, r;
	ll x = 0, y = 0;
	// for(ll i=x;i<x+3000;i++)
	// 	for(ll j=y;j<y+3000;j++)
	// 		if(func(i, j) > mx){
	// 			mx = max(mx, func(i, j));
	// 			l = i; r = j;
	// 		}

	cout << func(2999, 1097) << "\n";

	// cout << l << ' ' << r << "\n";
	cout << mx << "\n";
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