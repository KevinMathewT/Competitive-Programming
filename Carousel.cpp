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
ll n, a[N], t[N];

void solve(){
	cin >> n;
	fi (0, n - 1) cin >> a[i];
	t[0] = 0;
	fi (1, n - 1) if (a[i] == a[i - 1]) t[i] = t[i - 1]; else t[i] = 1 - t[i - 1];
	fi (0, n - 1) t[i]++;

	bool ok = false;
	ll z = -1;
	fi (1, n - 1) if (a[i] == a[i - 1]) ok = true, z = i - 1;

	if (t[0] == t[n - 1] && a[0] != a[n - 1]) {
		if (ok) {
			cout << z + 1 << ' ' << n - 1 << "--\n";
			fi (z + 1, n - 1) {
				t[i] = (t[i] == 1 ? 2 : 1);
			}
		} else {
			t[n - 1] = 3;
		}
	}

	fi (0, n - 1) cout << t[i] << ' '; cout << '\n';

	ll mx = LLONG_MIN;
	fi (0, n - 1) mx = max(mx, t[i]);

	cout << mx << "\n";
	fi (0, n - 1) cout << t[i] << ' ';
	bool ans = false;
	cout << '\n';
	fi (0, n - 1) ans |= (a[i] != a[(i + 1) % n] && t[i] == t[(i + 1) % n]);
	cout << ans << "\n";
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