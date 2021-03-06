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

ll a[3], b[3], tot;

void solve(){
	tot = 0;
	cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];

	if(a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2])
		tot++;
	swap(a[1], a[2]);

	if(a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2])
		tot++;
	
	swap(a[0], a[1]);
	swap(a[0], a[2]);
	
	if(a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2])
		tot++;

	swap(a[1], a[2]);
	
	if(a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2])
		tot++;
	
	swap(a[1], a[0]);

	
	if(a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2])
		tot++;

	swap(a[1], a[2]);

	if(a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2])
		tot++;

	cout << tot * 4 << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}