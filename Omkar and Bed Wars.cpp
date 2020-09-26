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
ll n, a[N], p[N];
string s;

void solve(){
	cin >> n;
	cin >> s;

	ll f = 1;
	fi (1, n) if (s[i] != s[i - 1]) f = 0;
	if (f == 1) {
		cout << n / 2 << "\n";
		return;
	}

	fi (0, n - 1) a[i] = 0;

	fi (0, n - 1) 
		if (s[i] == 'R') a[(i + 1) % n]++;
		else a[(i - 1 + n) % n]++;

	fi (0, n - 1) 
		if (a[i] == 1 && 
				(
					(s[i] == 'R' && s[(i + 1) % n] == 'R') || 
					(s[i] == 'L' && s[(i - 1 + n) % n] == 'L')
				)
			) p[i] = 1; else p[i] = 0;

	ll s;
	fi (0, n - 1) if (p[i] == 0) {
		s = i;
		break;
	}

	vector<pair<ll, ll>> v;
	v.push_back({0, 1});
	fi (s + 1, s + n - 1) {
	ll k = (i + n) % n
		if (p[k] == v.back().F) v.back().S++;
		else v.push_back({p[k], 1});
	}

	ll steps = 0;
	fi (0, (ll) v.size() - 1)
		if (v[i].F == 1) steps += ceil((v[i].S + 0.0) / 2.0);

	cout << steps << "\n";
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