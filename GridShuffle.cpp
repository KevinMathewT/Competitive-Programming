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
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

const ll M = 998244353;
ll n, k, r, c, s;

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
	if(p == 0) return id;
	if(p == 1) return a;
	if(p % 2 == 0) return matrix_expo(matmul(a, a), p / 2);
	return matmul(a, matrix_expo(matmul(a, a), p / 2));
}

ll power(ll a, ll x) {
	if (x == 0) return 1;
	if (x == 1) return a;
	if (x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * power((a * a) % M, x / 2)) % M;
}

void solve(){
	s = 3;
	cin >> n >> k >> r >> c;

	id = vector<vector<ll>>(s, vector<ll>(s, 0));
	for(ll i=0;i<s;i++)
		id[i][i] = 1;

	vector<vector<ll>> transition = vector<vector<ll>>(s, vector<ll>(s, 0));

	ll ninv = power(n, M - 2);
	ll ninv2 = power(2 * n, M - 2);
	ll nninv = power((n * n) % M, M - 2);
	ll nninv2 = power((2 * n * n) % M, M - 2);

	transition[0][0] = ((((n * n) % M - n + 1 + M) % M) * nninv) % M;
	transition[0][1] = (((n - 1 + M) % M) * nninv) % M;
	transition[0][2] = 0;
	transition[1][0] = nninv2;
	transition[1][1] = (((2 * n - 1 + M) % M) * ninv2) % M;
	transition[1][2] = (((n - 1 + M) % M) * nninv2) % M;
	transition[2][0] = 0;
	transition[2][1] = nninv;
	transition[2][2] = (((n * n - 1 + M) % M) * nninv) % M;

	vector<vector<ll>> final = matrix_expo(transition, k);
	cout << final[0][0] << "\n";
}

int main() {
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