// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll j=(a);j>=b;j--)

// #include <ext/pb_ds/assoc_container.hpp> // Common file 
// #include <ext/pb_ds/tree_policy.hpp> 
// #include <functional> // for less 
// #include <iostream> 
// using namespace __gnu_pbds; 
// using namespace std; 
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order(k) : Value at kth index in sorted array. 
// order_of_key(k) : Index of the value k.

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


const ll N = 500010, M = 1e9 + 7;
ll n, c, x[N], y[N];
unordered_map<ll, vector<pair<ll, ll> > > m;
unordered_map<ll, vector<ll> > um;

void solve(){
	m.clear();
	um.clear();
	cin >> n >> c;
	fi (0, n - 1) cin >> x[i] >> y[i];
	vector<ll> d;

	fi (0, n - 1) {
		if (m.find(x[i] - y[i]) == m.end()) d.push_back(x[i] - y[i]);
		m[x[i] - y[i]].push_back({x[i], y[i]});
	}

	ll check = 0, steps = 0;
	vector<ll> ud;
	fi (0, d.size() - 1) {
		um.clear();
		ud.clear();
		fj (0, m[d[i]].size() - 1) {
			ll x1 = m[d[i]][j].F;
			if (um.find(((x1 % c) + c) % c) == um.end()) ud.push_back(((x1 % c) + c) % c);
			um[((x1 % c) + c) % c].push_back(x1);
		}

		fj (0, ud.size() - 1) {
			check++;
			sort(um[ud[j]].begin(), um[ud[j]].end());
			ll mid = um[ud[j]][um[ud[j]].size() / 2];
			for (ll k = 0; k < um[ud[j]].size(); k++)
				steps += abs(um[ud[j]][k] - mid) / c;
		}
	}

	cout << check << ' ' << steps << "\n";
}

int main(){
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