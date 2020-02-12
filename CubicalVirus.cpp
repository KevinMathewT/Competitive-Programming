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

const ll N = 110;
ll n, a[N][N][N];

void solve(){
	cin >> N;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			for(ll k=0;k<n;k++){
				char c; cin >> c;
				a[k][j][i] = c - '0';
			}

	queue<pair<ll, pair<ll> > > q;
	q.push({n - 1, {n - 1, n - 1}});
	pair<ll, pair<ll, ll> > pll;

	while(!q.empty()){
		p = q.top(); q.pop();
		if(a[p.F][p.S.F][p.S.S] == 1){
			pll = p;
			break;
		}

		q.push({p.F - 1, {p.S.F, p.S.S}});
		q.push({p.F, {p.S.F - 1, p.S.S}});
		q.push({p.F, {p.S.F, p.S.S - 1}});
	}

	
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}