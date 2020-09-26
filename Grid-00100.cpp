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


const ll N = 310, M = 1e9 + 7;
ll n, k, a[N][N];
ll c[N], r[N];

void printA() {
	fi (0, n - 1) c[i] = r[i] = 0;
	fi (0, n - 1) fj (0, n - 1) c[i] += a[i][j], r[j] += a[i][j];

	ll cmax = *max_element(c, c + n);
	ll cmin = *min_element(c, c + n);
	ll rmax = *max_element(r, r + n);
	ll rmin = *min_element(r, r + n);

	cout << pow((rmax - rmin), 2) + pow((cmax - cmin), 2) << "\n";

	fi (0, n - 1) {
		fj (0, n - 1) cout << a[i][j];
		cout << "\n";
	}
	return;
}

void solve(){
	cin >> n >> k;
	fi (0, n - 1) fj (0, n - 1) a[i][j] = 0;

	if (k <= n) {
		fi (0, k - 1) a[i][i] = 1;
		printA();
		return;
	} else {
		fi (0, n - 1)
			fj (0, n - 1) {
				a[(i + j) % n][j] = 1;
				k--;
				if (k == 0) {
					printA();
					return;
				}
			}
	}


	// } else {
	// 	fi (0, n - 1) a[i][i] = 1;
	// 	k -= n;
	// 	fi (1, n - 1) {
	// 		ll x1 = i, y1 = 0;
	// 		ll x2 = n - 1 - i, y2 = n - 1;
			
	// 		fj (0, n - i - 1) {
	// 			if (a[x1][y1] == 0) {
	// 				a[x1][y1] = 1;
	// 				k--;
	// 				if (k == 0) {
	// 					printA();
	// 					return;
	// 				}
	// 			}

	// 			if (a[y1][x1] == 0) {
	// 				a[y1][x1] = 1;
	// 				k--;
	// 				if (k == 0) {
	// 					printA();
	// 					return;
	// 				}
	// 			}

	// 			x1++; y1++;

	// 			if (a[x2][y2] == 0) {
	// 				a[x2][y2] = 1;
	// 				k--;
	// 				if (k == 0) {
	// 					printA();
	// 					return;
	// 				}
	// 			}

	// 			if (a[y2][x2] == 0) {
	// 				a[y2][x2] = 1;
	// 				k--;
	// 				if (k == 0) {
	// 					printA();
	// 					return;
	// 				}
	// 			}

	// 			x2++; y2++;
	// 		}
	// 	}
	// }
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