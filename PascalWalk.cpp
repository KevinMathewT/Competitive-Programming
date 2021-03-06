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
ll n;

void solve(ll cs){
	cin >> n;
	cout << "Case #" << cs << ": \n";
	if(n >= 1) {
		cout << 1 << ' ' << 1 << "\n";
		n--;
	}
	if(n >= 1) {
		cout << 2 << ' ' << 1 << "\n";
		n--;
	}

	ll x = 3, y = 2;

	ll z = 2;
	while(z <= n) {
		cout << x++ << ' ' << y++ << "\n";
		n -= z;
		z++;
	}

	x--;
	fi(1, n) {
		cout << x++ << ' ' << y++ << "\n";
	}
}

int main(){
	freopen("input.txt", "r", stdin);			//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);					//Not
	cin.tie(NULL);												//this.
	cout.tie(0);													//or this.

	ll T;
	cin >> T;
	fi(1, T)
		solve(i);

	return 0;
}