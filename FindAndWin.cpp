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

ll n, a, b, c, p, q, r;
ll M, s;
vector<vector<ll>> id;

void printmat(vector<vector<ll>> a){
	for(ll i=0;i<a.size();i++){
		for(ll j=0;j<a[i].size();j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}

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
	s = 7;
	M = 1e9 + 7;
	id = vector<vector<ll>>(s, vector<ll>(s, 0));
	for(ll i=0;i<s;i++)
		id[i][i] = 1;
	cin >> n >> a >> b >> c >> p >> q >> r;

	p %= M; q %= M; r %= M;

	if(n == 0)
		cout << p << "\n";
	else if(n == 1)
		cout << q << "\n";
	else if(n == 2)
		cout << r << "\n";
	else{
		vector<vector<ll>> A(s, vector<ll>(1, 0));
		A[0][0] = r; A[1][0] = q; A[2][0] = p; A[3][0] = 27; A[4][0] = 9; A[5][0] = 3; A[6][0] = 1;

		vector<vector<ll>> X(s, vector<ll>(s, 0));
		X[0][0] = a; X[0][1] = b; X[0][2] = c; X[0][3] = 1; X[0][4] = 1;
		X[1][0] = 1; 
		X[2][1] = 1; 
		X[3][3] = 1; X[3][4] = 3; X[3][5] = 3; X[3][6] = 1;
		X[4][4] = 1; X[4][5] = 2; X[4][6] = 1;
		X[5][5] = 1; X[5][6] = 1;
		X[6][6] = 1; 

		vector<vector<ll>> B = matmul(matrix_expo(X, n - 2), A);

		cout << B[0][0] << "\n";
	}
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