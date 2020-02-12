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

ll r, c, m[100][100];

void solve(){
	cin >> r >> c;

	ll ans = 4;
	ll A = 0, P = 0;

	for(ll i=0;i<r;i++)
		for(ll j=0;j<c;j++){
			char ch; cin >> ch;
			if(ch == 'A'){
				A++;
				if((i == 0 && j == 0) || (i == r - 1 && j == 0) || (i == 0 && j == c - 1) || (i == r - 1 && j == c - 1)) ans = min(ans, (ll) 2);
				else if(i == 0 || j == 0 || i == r - 1 || j == c - 1) ans = min(ans, (ll) 3);
				m[i][j] = 1;
			}
			else P++, m[i][j] = 2;
		}

	ll flag = 1;
	for(ll j=0;j<c;j++)
		if(m[0][j] == 2)
			flag = 0;
	if(flag == 1) ans = min(ans, (ll) 1);

	flag = 1;
	for(ll j=0;j<r;j++)
		if(m[j][0] == 2)
			flag = 0;
	if(flag == 1) ans = min(ans, (ll) 1);

	flag = 1;
	for(ll j=0;j<c;j++)
		if(m[r-1][j] == 2)
			flag = 0;
	if(flag == 1) ans = min(ans, (ll) 1);

	flag = 1;
	for(ll j=0;j<r;j++)
		if(m[j][c-1] == 2)
			flag = 0;
	if(flag == 1) ans = min(ans, (ll) 1);

	for(ll i=1;i<r-1;i++){
		flag = 1;
		for(ll j=0;j<c;j++)
			if(m[i][j] == 2)
				flag = 0;
		if(flag == 1) ans = min(ans, (ll) 2);
	}

	for(ll i=1;i<c-1;i++){
		flag = 1;
		for(ll j=0;j<r;j++)
			if(m[j][i] == 2)
				flag = 0;
		if(flag == 1) ans = min(ans, (ll) 2);
	}

	if(P == 0) cout << 0 << '\n';
	else if(A == 0) cout << "MORTAL\n";
	else cout << ans << "\n";
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