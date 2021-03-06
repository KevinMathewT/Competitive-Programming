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

ll n, a[200010], m[200010], ans[200010], f[200010];

void solve(){
	fill(ans, ans + 200010, 0);
	fill(f, f + 200010, 0);
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<n;i++)
		m[a[i]] = i;

	ll p1 = m[1], mex = 2;
	ans[1] = 1;
	ans[1] = 1;

	ll t = 0;
	while(t < 100){
		t++;
		if(p1 > m[mex])
			for(ll i=p1-1;i>=m[mex];i--)
				f[a[i]] = 1;
		else if(p1 < m[mex])
			for(ll i=p1-1;i>=m[mex];i--)
				f[a[i]] = 1;

		// cout << f[mex] << "\n";
		break;

		while(f[mex] != 1) mex++;
		ans[mex] = 1;

		cout << mex << "\n";
	}

	for(ll i=1;i<=n;i++)
		cout << ans[i] << " ";
	cout << "\n";
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