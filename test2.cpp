// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://w...content-available-to-author-only...n.com/in/KevinMathewT/
// GitHub - https://g...content-available-to-author-only...b.com/KevinMathewT
// CodeForces - https://c...content-available-to-author-only...s.com/profile/KevinMathew
// CodeChef - https://w...content-available-to-author-only...f.com/users/KevinMathew
// HackerRank - https://w...content-available-to-author-only...k.com/KevinMathew
 
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
 
const ll N = 40010, M = 1e9 + 7;
ll mx;
vector<ll> T[N];
 
void dfs(ll st) {
	stack<pair<ll, ll>> s;

	s.push({st, -1});
	while (!s.empty()) {
		auto top = s.top(); s.pop();
		ll u = top.F, p = top.S;
		cout << u << "\n";
		for (ll v : T[u]) if (v != p) s.push({v, u});
	}
}

void solve(){
	mx = LLONG_MAX;
	ll n = 40000;
	T[400].push_back(401);
	fi (401, n - 1) T[i].push_back(i - 1), T[i].push_back(i + 1);
	T[n].push_back(n - 1);

	dfs(n);
}
 
int main(){
  freopen("input.txt", "r", stdin);        //Comment
  freopen("output.txt", "w", stdout);        //this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
 
	// ll T;
	// cin >> T;
	// while(T--)
		solve();
 
	return 0;
}