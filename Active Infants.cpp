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


const ll N = 2010, M = 1e9 + 7;
ll n, a[N];
vector<pair<ll, pair<ll, ll> > > v;

void solve(){
	cin >> n;
	fi(0, n - 1) cin >> a[i];
	fi(0, n - 1) v.push_back({a[i], {i + 1, max(i, n - i - 1)}});
	set<ll> s;
	fi(1, n) s.insert(i);

	sort(v.begin(), v.end());
	ll prize = 0;
	fid(n - 1, 0) {
		ll val = v[i].F;
		ll pos = v[i].S.F;

		ll front = *s.begin();
		ll back = *prev(s.end());

		cout << front << ' ' << back << "\n";

		if(abs(front - pos) >= abs(back - pos)) {
			s.erase(s.begin());
			prize += val * abs(front - pos);
		} else {
			s.erase(prev(s.end()));
			prize += val * abs(back - pos);
		}

		if(s.size() == 0) break;

		front = *s.begin();
		back = *prev(s.end());

		fj(0, i) v[j].S.S = max(abs(front - v[j].S.F), abs(back - v[j].S.F));
		sort(v.begin(), v.end());

		cout << prize << '\n';
	}

	cout << prize << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}