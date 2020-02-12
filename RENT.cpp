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
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
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
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {
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

const ll N = 10010, M = 1e9 + 7;
ll n, dp[N], T[4 * N];
vector<pair<ll, pair<ll, ll> > > V;

void update(ll i, ll l, ll r, ll p, ll v){
	if(l == r){
		T[i] = v;
		return;
	}

	ll m = (l + r) / 2;
	if(p <= m) update(2 * i, l, m, p, v);
	else update(2 * i + 1, m + 1, r, p, v);
	T[i] = max(T[2 * i], T[2 * i + 1]);
}

ll query(ll i, ll l, ll r, ll a, ll b){
	if(l > b || r < a) return LLONG_MIN;
	if(l >= a && r <= b) return T[i];

	ll m = (l + r) / 2;
	return max(query(2 * i, l, m, a, b), query(2 * i + 1, m + 1, r, a, b));
}

void solve(){
	cin >> n;
	V.assign(n, {0, {0, 0}});
	for(ll i=0;i<n;i++) cin >> V[i].F >> V[i].S.F >> V[i].S.S;
	sort(V.begin(), V.end());
	fill(dp, dp + N, 0LL);

	ll best = 0;
	for(ll i=n-1;i>=0;i--){
		if(i == n - 1){
			update(1, 0, n - 1, n - 1, V[i].S.S);
			dp[i] = best = max(best, V[i].S.S);
			continue;
		}

		dp[i] = V[i].S.S;
		auto pt = lower_bound(V.begin(), V.end(), make_pair(V[i].F + V[i].S.F, make_pair(0LL, 0LL)));
		if(pt != V.end())
			dp[i] = dp[i] + query(1, 0, n - 1, pt - V.begin(), n - 1);
		update(1, 0, n - 1, i, dp[i]);
	}

	cout << *max_element(dp, dp + n) << "\n";
}

int main(){
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