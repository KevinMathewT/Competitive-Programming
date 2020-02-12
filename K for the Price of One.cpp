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

ll n, p, k;

void solve(){
	cin >> n >> p >> k;
	vector<ll> a(n);
	for(ll i=0;i<n;i++) cin >> a[i];
	sort(a.begin(), a.end());

	vector<vector<ll> > v(k, vector<ll>(0));
	vector<ll> pre(0);

	for(ll i=0;i<n;i++){
		if(i < k) v[i % k].push_back(a[i]);
		else v[i % k].push_back(v[i % k][v[i % k].size() - 1] + a[i]);

		if(i == 0) pre.push_back(a[i]);
		else pre.push_back(pre[pre.size() - 1] + a[i]);
	}

	ll ans = 0;

	ll i;
	for(i=-1;i<n;i++){
		if(i >= 0 && pre[i] > p) break;

		ll left = p - (i < 0 ? 0 : pre[i]);

		ll s, l;

		if(i == -1)
			s = l = 0;
		else s = l = i / k + 1;

		ll r = v[((i + k) % k)].size() - 1;
		ll be = 0;

		while(l <= r){
			ll m = (l + r) / 2;

			if(v[(i+k)%k][m] - (i == -1 ? 0 : (v[(i+k)%k][s - 1])) <= left)
				be = m - s + 1, l = m + 1;
			else r = m - 1;
		}

		ans = max(ans, (be * k) + i + 1);
	}

	cout << ans << "\n";
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