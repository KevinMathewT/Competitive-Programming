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
 
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
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
 
// find_by_order(k) : Value at kth index in sorted array. 
// order_of_key(k) : Index of the value k.
 
const ll N = 1010, M = 1e9 + 7;
ll n, a[N];
set<ll> b;

void solve(){
	cin >> n;
	fi (0, n - 1) cin >> a[i];
	vector<ll> p;
	ll ans = 0;
	fi (0, n - 1) {
		if (a[i] == i) continue;

		bool so = true;
		fj (1, n - 1) if (a[j] < a[j - 1]) so = false;
		if (so == true) break;
 
		vector<ll> ps;
		fj (0, n - 1) if (a[j] == i) ps.push_back(j);
 
		fj (0, (ll) ps.size() - 1) {
			b.clear();
			for (ll k = 0; k < n; k++) b.insert(a[k]);
			ll mex = n;
			ll c = 0;
			for (ll x : b) if (x != c) {
				mex = c;
				break;
			} else c++;
 
			if (ans == 2 * n) break;
			ans++;
			a[ps[j]] = mex;
			p.push_back(ps[j]);
			fi (0, n - 1) cout << a[i] << " ";
			cout << "\n";
		}
		
		b.clear();
		fj (0, n - 1) b.insert(a[j]);
		ll mex = n;
		ll c = 0;
		for (ll x : b) if (x != c) {
			mex = c;
			break;
		} else c++;
 
		if (ans == 2 * n) break;
		ans++;
		a[i] = mex;
		p.push_back(i);
		fi (0, n - 1) cout << a[i] << " ";
		cout << "\n";
	}
 
	cout << ans << "\n";
	fi (0, ans - 1) cout << p[i] + 1 << ' ';
	cout << "\n";
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