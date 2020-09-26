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


const ll N = 10, M = 1e9 + 7;
ll n, a[N];

void solve(){
	cin >> n;
	fi (0, n - 1) cin >> a[i];

	if (n == 0) {
		cout << "YES\n";
		cout << 1 << "\n";
		cout << 1 << "\n";
		cout << 3 << "\n";
		cout << 3 << "\n";
		return;
	} else if (n == 1) {
		cout << "YES\n";
		cout << a[0] << "\n";
		cout << a[0] << "\n";
		cout << 3 * a[0] << "\n";
		cout << 3 * a[0] << "\n";
		return;
	} else if (n == 2) {
		sort(a, a + n);
		if ((a[1] - a[0]) % 3 == 0) {
			a[3] = a[1];
			a[1] = a[0] + (a[3] - a[0]) / 3;
			a[2] = a[0] + (a[3] - a[0]) * 2 / 3;
			if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
				cout << "YES\n";
				cout << a[0] << "\n";
				cout << a[1] << "\n";
				cout << a[2] << "\n";
				cout << a[3] << "\n";
				return;
			}
		} else if ((a[1] - a[0]) % 2 == 0) {
			a[2] = a[1];
			a[1] = (a[0] + a[2]) / 2;
			a[3] = a[2] + ((a[2] - a[0]) / 2);
			if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
				cout << "YES\n";
				cout << a[0] << "\n";
				cout << a[1] << "\n";
				cout << a[2] << "\n";
				cout << a[3] << "\n";
				return;
			}

			a[1] = a[0];
			a[3] = a[2];
			a[2] = ((a[1] + a[3]) / 2);
			a[0] = a[1] - (a[2] - a[1]);
			if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
				cout << "YES\n";
				cout << a[0] << "\n";
				cout << a[1] << "\n";
				cout << a[2] << "\n";
				cout << a[3] << "\n";
			}
		} else {
			a[2] = a[1] + (a[1] - a[0]);
			a[3] = a[2] + (a[1] - a[0]);
			if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
				cout << "YES\n";
				cout << a[0] << "\n";
				cout << a[1] << "\n";
				cout << a[2] << "\n";
				cout << a[3] << "\n";
				return;
			}

			a[2] = a[1];
			a[1] = a[0];
			a[0] = a[1] - (a[2] - a[1]);
			a[3] = a[2] + (a[2] - a[1]);
			if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
				cout << "YES\n";
				cout << a[0] << "\n";
				cout << a[1] << "\n";
				cout << a[2] << "\n";
				cout << a[3] << "\n";
				return;
			}

			a[3] = a[2];
			a[2] = a[1];
			a[1] = a[2] - (a[3] - a[2]);
			a[0] = a[1] - (a[3] - a[2]);
			if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
				cout << "YES\n";
				cout << a[0] << "\n";
				cout << a[1] << "\n";
				cout << a[2] << "\n";
				cout << a[3] << "\n";
				return;
			}
		}
	} else if (n == 3) {
		sort(a, a + n);
		a[3] = a[2];
		a[2] = a[1];
		a[1] = a[0];
		a[0] = a[1] - (a[2] - a[1]);
		if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
			cout << "YES\n";
			cout << a[0] << "\n";
			cout << a[1] << "\n";
			cout << a[2] << "\n";
			cout << a[3] << "\n";
			return;
		}

		swap(a[0], a[1]);
		a[1] = (a[0] + a[2]) / 2;
		if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
			cout << "YES\n";
			cout << a[0] << "\n";
			cout << a[1] << "\n";
			cout << a[2] << "\n";
			cout << a[3] << "\n";
			return;
		}

		swap(a[1], a[2]);
		a[2] = (a[1] + a[3]) / 2;
		if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
			cout << "YES\n";
			cout << a[0] << "\n";
			cout << a[1] << "\n";
			cout << a[2] << "\n";
			cout << a[3] << "\n";
			return;
		}

		swap(a[2], a[3]);
		a[3] = a[2] + (a[2] - a[1]);
		if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
			cout << "YES\n";
			cout << a[0] << "\n";
			cout << a[1] << "\n";
			cout << a[2] << "\n";
			cout << a[3] << "\n";
			return;
		}
	} else if (n == 4) {
		if ((a[3] - a[1]) == ((a[1] + a[2]) / 2) && (a[3] - a[1]) == ((a[0] + a[1] + a[2] + a[3]) / 4)) {
			cout << "YES\n";
			cout << a[0] << "\n";
			cout << a[1] << "\n";
			cout << a[2] << "\n";
			cout << a[3] << "\n";
			return;
		}
	}

	cout << "NO\n";
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