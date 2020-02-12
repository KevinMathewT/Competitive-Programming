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
	vector<ll> a, b, c;
	a.push_back(1);
	b.push_back(2);
	a.push_back(3);
	b.push_back(4);
	a.push_back(5);

	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	cout << c << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}