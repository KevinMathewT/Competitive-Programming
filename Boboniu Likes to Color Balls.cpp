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


const ll N = 110, M = 1e9 + 7;
ll r, g, b, w;

void solve(){
	cin >> r >> g >> b >> w;

	if (min(r, min(g, b)) > 0) {
		ll r1 = r - 1, g1 = g - 1, b1 = b - 1, w1 = w + 1;
		ll e = 0, o = 0, e1 = 0, o1 = 0;
		if (r % 2 == 0) e++; else o++;
		if (g % 2 == 0) e++; else o++;
		if (b % 2 == 0) e++; else o++;
		if (w % 2 == 0) e++; else o++;

		if (r1 % 2 == 0) e1++; else o1++;
		if (g1 % 2 == 0) e1++; else o1++;
		if (b1 % 2 == 0) e1++; else o1++;
		if (w1 % 2 == 0) e1++; else o1++;

		if (e == 3 && o == 1 || e == 4 || e1 == 3 && o1 == 1 || e1 == 4) cout << "Yes\n";
		else cout << "No\n";
	} else {
		ll e = 0, o = 0;
		if (r % 2 == 0) e++; else o++;
		if (g % 2 == 0) e++; else o++;
		if (b % 2 == 0) e++; else o++;
		if (w % 2 == 0) e++; else o++;

		if (e == 3 && o == 1 || e == 4) cout << "Yes\n";
		else cout << "No\n";
	}
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