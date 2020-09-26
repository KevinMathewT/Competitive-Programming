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


const ll N = 100010, M = 1e9 + 7;
ll n, p, a[N], b[N];

void solve(){
	cin >> n >> p;
	fi (0, n - 1) cin >> a[i];
	sort(a, a + n);

	ll l = a[n - 1] - (n - 1), r = a[n - 1];
	vector<ll> v;
	fi (l, r) {
		ll s = upper_bound(a, a + n, i) - a;
		// cout << i << ' ' << s << "\n";
		if (v.size() == 0 && s != 0 || v.size() > 0 && s != upper_bound(a, a + n, v.back()) - a)
			v.push_back(i);
	}

	fi (0, v.size() - 1) b[i] = upper_bound(a, a + n, v[i]) - a;

	vector<ll> out;
	ll ans = 0;
	if (v.size() > 1) {
		fi (0, v.size() - 2) {
			ll low = i, high = v.size() - 1, flag = 0;
			while (low <= high) {
				ll mid = (low + high) / 2;
				if (b[mid] - (mid - i) >= p) {
					flag = 1;
					break;
				} else {
					low = mid + 1;
				}
			}

			if (flag == 0) {
				ans += v[i + 1] - v[i];
				fj (v[i], v[i + 1] - 1) out.push_back(j);
			}
		}
	}

	cout << v << "\n";
	fi (0, v.size() - 1) cout << b[i] << ' ';
	cout << "\n";
	cout << out.size() << "\n";
	if (out.size() > 0)
		fi (0, out.size() - 1) cout << out[i] << " ";
	cout << "\n";
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