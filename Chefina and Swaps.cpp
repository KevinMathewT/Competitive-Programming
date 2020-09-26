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


const ll N = 200010, M = 1e9 + 7;
ll n, a[N], b[N], f[N];

void solve(){
	cin >> n;
	fi (0, n - 1) cin >> a[i];
	fi (0, n - 1) cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);

	vector<ll> all;
	fi (0, n - 1) all.push_back(a[i]), all.push_back(b[i]);

	sort(all.begin(), all.end());
	vector<ll> u;
	u.push_back(all[0]);
	fi (1, (ll) all.size() - 1) if (all[i] != u.back()) u.push_back(all[i]);

	sort(u.begin(), u.end());
	fi (0, (ll) u.size() - 1) f[i] = 0;

	fi (0, n - 1) 
		f[lower_bound(u.begin(), u.end(),	a[i]) - u.begin()]++, 
		f[lower_bound(u.begin(), u.end(), b[i]) - u.begin()]--;

	fi (0, (ll) u.size() - 1) if (((f[i] % 2) + 2) % 2 == 1) {
		cout << "-1\n";
		return;
	}

	ll mn = min(*min_element(a, a + n), *min_element(b, b + n));

	ll tot = 0;
	vector<ll> e;
	fi (0, (ll) u.size() - 1) fj (1, abs(f[i] / 2)) e.push_back(u[i]);
	fi (0, (((ll) e.size()) / 2) - 1) tot += min(2 * mn, e[i]);

	cout << tot << '\n';
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