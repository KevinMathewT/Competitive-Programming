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

struct rect{
	ld x1, y1, x2, y2;
	rect(){}
	rect(ld _x1, ld _y1, ld _x2, ld _y2){
		x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;
	}

	ld inside(ld x, ld y){
		if(x > x1 && x < x2 && y < y1 && y > y2) return 1;
		return 0;
	}
};

const ll N = 20, M = 1e9 + 7;
rect R[N];

void solve(){
	ll i = 0;
	while(true){
		char ch; cin >> ch;
		if(ch == '*') break;
		ld a, b, c, d;
		cin >> a >> b >> c >> d;
		R[i++] = rect(a, b, c, d);
	}

	ll k = 0;
	while(true){
		ld x, y; cin >> x >> y;
		if(x == 9999.9 && y == 9999.9) break;
		ll flag = 1;
		for(ll j=0;j<i;j++)
			if(R[j].inside(x, y)){
				flag = 0;
				cout << "Point " << k + 1 << " is contained in figure " << j + 1 << "\n";
			}
		if(flag) cout << "Point " << k + 1 << " is not contained in any figure\n";
		k++;
	}
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ld T;
	// cin >> T;
	// while(T--)

		solve();

	return 0;
}