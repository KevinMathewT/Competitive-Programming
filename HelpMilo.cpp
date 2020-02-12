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

ll a, b, c, d, e, n, M, s;
vector<vector<ll>> id;
vector<vector<ll>> matmul(vector<vector<ll>> a, vector<vector<ll>> b){
	vector<vector<ll>> ret(a.size(), vector<ll>(b[0].size(), 0));
	for(ll i=0;i<a.size();i++)
		for(ll j=0;j<b.size();j++)
			for(ll k=0;k<b[0].size();k++)
				ret[i][k] = (ret[i][k] + (a[i][j] * b[j][k]) % M) % M;

	return ret;
}
vector<vector<ll>> matrix_expo(vector<vector<ll>> a, ll p){
	if(p == 0)
		return id;
	if(p == 1)
		return a;
	if(p % 2 == 0)
		return matrix_expo(matmul(a, a), p / 2);
	return matmul(a, matrix_expo(matmul(a, a), p / 2));
}
void solve(){
	s = 4;
	M = 1e9 + 7;
	id = vector<vector<ll>>(s, vector<ll>(s, 0));
	for(ll i=0;i<s;i++)
		id[i][i] = 1;
	cin >> n;

	if(n == 0)
		cout << 1 << "\n";
	else{
		vector<vector<ll>> A(s, vector<ll>(1, 0));
		A[0][0] = 1; A[1][0] = 36; A[2][0] = (36LL * 36LL) % M; A[3][0] = 36LL;
		vector<vector<ll>> X(s, vector<ll>(s, 0));
		X[0][0] = 36; X[0][1] = 1; X[0][2] = 0; X[0][3] = 1;
		X[1][0] = 0; X[1][1] = 36; X[1][2] = 1; X[1][3] = 0;
		X[2][0] = 0; X[2][1] = 0; X[2][2] = 36; X[2][3] = 0;
		X[3][0] = 0; X[3][1] = 0; X[3][2] = 0; X[3][3] = 1;

		// cout << X << "\n";

		vector<vector<ll>> B = matmul(matrix_expo(X, n), A);

		cout << B[0][0] << "\n";
	}
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