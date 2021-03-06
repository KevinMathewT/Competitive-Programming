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

ll a, b, c, d, e, n, M;
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
	M = 1e9 + 7;
	id = vector<vector<ll>>(5, vector<ll>(5, 0));
	id[0][0] = 1; id[1][1] = 1; id[2][2] = 1; id[3][3] = 1; id[4][4] = 1;
	cin >> a >> b >> c >> d >> e >> n;

	a %= M; b %= M; c %= M; d %= M; e %= M; 

	if(n == 0)
		cout << 0 << "\n";
	else if(n == 1)
		cout << 1 << "\n";
	else if(n == 2)
		cout << 2 << "\n";
	else if(n == 3)
		cout << 3 << "\n";
	else{
		vector<vector<ll>> A(5, vector<ll>(1, 0));
		A[0][0] = 3; A[1][0] = 2; A[2][0] = 1; A[3][0] = 0; A[4][0] = e;
		vector<vector<ll>> X(5, vector<ll>(5, 0));
		X[0][0] = a; X[0][1] = b; X[0][2] = c; X[0][3] = d; X[0][4] = 1;
		X[1][0] = 1; X[2][1] = 1; X[3][2] = 1; X[4][4] = 1;

		vector<vector<ll>> B = matmul(matrix_expo(X, n - 4), A);

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