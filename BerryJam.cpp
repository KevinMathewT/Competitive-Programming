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

ll n, a[200010], d[200010];

void solve(){
	cin >> n;
	for(ll i=0;i<2 * n;i++) cin >> a[i];

	ll s = 0, b = 0;
	for(ll i=0;i<2*n;i++) if(a[i] == 1) s++; else b++;

	ll diff = s - b;

	if(diff == 0){
		cout << 0 << "\n";
		return;
	}

	d[n - 1] = 0;
	for(ll i=n;i<2*n;i++)
		if(a[i] == 1)
			d[i] = d[i - 1] + 1;
		else d[i] = d[i - 1] - 1;

	if(a[n-1] == 1) d[n - 1] = 1; else d[n - 1] = -1;
	for(ll i=n-2;i>=0;i--) 
		if(a[i] == 1) d[i] = d[i + 1] + 1;
		else d[i] = d[i + 1] - 1;

	// for(ll i=0;i<2*n;i++)
	// 	cout << d[i] << " ";
	// cout << "\n";

	unordered_map<ll, ll> m1, m2;

	for(ll i=n - 1;i>=0;i--)
		if(m1.find(d[i]) == m1.end())
			m1[d[i]] = i;

	for(ll i=n;i<2*n;i++)
		if(m2.find(d[i]) == m2.end())
			m2[d[i]] = i;
	m2[0] = n - 1;

	ll best = LLONG_MAX;
	if(m2.find((diff)) != m2.end())
		best = min(best, m2[(diff)] - n + 1);
	for(ll i=n-1;i>=0;i--){
		if(m2.find((diff - d[i])) != m2.end())
			best = min(best, m2[(diff - d[i])] - i + 1);
		// cout << i << ' ' << best << ' ' << m2[(diff - d[i])] << "\n";
	}

	cout << best << "\n";
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