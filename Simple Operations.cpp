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


const ll N = 1000010, M = 1e9 + 7;
ll n;
string s, t;

void solve(){
	cin >> s >> t;
	n = s.size();

	if (s == t) {
		cout << 0 << '\n';
		return;
	}

	ll c = 0;
	vector<ll> same(0), diff(0);
	fi (0, n - 1) {
		if (s[i] == t[i]) same.push_back(i);
		else diff.push_back(i), c++;
	}

	if (same.size() == 0) {
		cout << 1 * n << "\n";
		return;
	}

	vector<pair<ll, ll> > sr, dr;
	sr.push_back({same[0], same[0]});
	fi (1, same.size() - 1)
		if (same[i] == sr.back().S + 1) sr.back().S++;
		else sr.push_back({same[i], same[i]});

	dr.push_back({diff[0], diff[0]});
	fi (1, diff.size() - 1)
		if (diff[i] == dr.back().S + 1) dr.back().S++;
		else dr.push_back({diff[i], diff[i]});

	// cout << sr << ' ' << dr << '\n';

	ll best = c * diff.size();
	// cout << best << "\n";

	priority_queue<ll> q;
	fi (0, sr.size() - 1) {
		if (sr[i].S < dr[0].F || sr[i].F > dr.back().S) continue;
		q.push(sr[i].S - sr[i].F + 1);
	}

	ll size = c, ranges = diff.size();

	while(!q.empty()) {
		size += q.top(); q.pop();
		ranges--;
		best = min(best, size * ranges);
	}

	cout << best << "\n";
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