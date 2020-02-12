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

ll r, c;
ll mat[510][510];

void solve(){
	cin >> r >> c;

	if(r == 1 && c == 1) { cout << 0 << '\n'; return; }

	if(r == 1){
		for(ll i=2;i<=c + 1;i++)
			cout << i << " ";
		return;
	}

	if(c == 1){
		for(ll i=2;i<=r + 1;i++)
			cout << i << "\n";
		return;
	}

	for(ll i=0;i<r;i++)
		for(ll j=0;j<c;j++)
			mat[i][j] = (i + 1) * (r + j + 1);

	for(ll i=0;i<r;i++){
		for(ll j=0;j<c;j++)
			cout << mat[i][j] << ' ';
		cout << "\n";
	}
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