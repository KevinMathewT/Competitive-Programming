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
ll n, a[N];
vector<pair<ll, ll>> v;

void solve(){
	cin >> n;
	fi (0, n - 1) cin >> a[i];
	fi (0, n - 1) v.push_back({a[i], i + 1});

	sort(v.begin(), v.end());
	vector<pair<ll, pair<pair<ll, ll>, pair<ll, ll>>>> z;

	fi (1, (ll) v.size() - 1) z.push_back({v[i].F - v[i - 1].F, {v[i - 1], v[i]}}), i++;
	

	sort(z.begin(), z.end());
	// cout << z << "\n";

	vector<ll> t1, t2;
	fi (0, (ll) z.size() - 1) {
		if (i % 2 == 0) t1.push_back(z[i].S.F.S), t2.push_back(z[i].S.S.S);
		else t2.push_back(z[i].S.F.S), t1.push_back(z[i].S.S.S);
	}

	if (n % 2 == 1) {
		ll sum1 = 0, sum2 = 0;
		fi (0, (ll) t1.size() - 1) sum1 += a[t1[i] - 1];
		fi (0, (ll) t2.size() - 1) sum2 += a[t2[i] - 1];

		if (sum1 < sum2) t1.push_back(v.back().S); else t2.push_back(v.back().S);
	}

	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());

	cout << t1.size() << "\n";
	fi (0, (ll) t1.size() - 1) cout << t1[i] << ' '; cout << "\n";
	cout << t2.size() << "\n";
	fi (0, (ll) t2.size() - 1) cout << t2[i] << ' '; cout << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}