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
ll n, a[N + 10];

void solve(){
	ll p = 0, s;
	for (ll i = 1; i < N; i += 3) {
		cout << 1 << ' ' << i << ' ' << i + 2 << endl;
		cin >> s;

		if (s == 0) a[i] = a[i + 1] = a[i + 2] = 0;
		else if (s == 3) a[i] = a[i + 1] = a[i + 2] = 1;
		else if (s == 1) {
			p = (p + 1) % 3;
			cout << 1 << ' ' << i + p << ' ' << i + p << endl;
			cin >> s;
			if (s == 1) a[i + p] = 1, a[i + ((p + 1) % 3)] = a[i + ((p + 2) % 3)] = 0;
			else {
				p = (p + 1) % 3;
				cout << 1 << ' ' << i + p << ' ' << i + p << endl;
				cin >> s;
				if (s == 1) a[i + p] = 1, a[i + ((p + 1) % 3)] = a[i + ((p + 2) % 3)] = 0;
				else p = (p + 1) % 3, a[i + p] = 1, a[i + ((p + 1) % 3)] = a[i + ((p + 2) % 3)] = 0, p = (p + 2) % 3;
				p = (p + 2) % 3;
			}
		} else if (s == 2) {
			p = (p + 1) % 3;
			cin >> s;
			if (s == 0) a[i + p] = 0, a[i + ((p + 1) % 3)] = a[i + ((p + 2) % 3)] = 1;
			else {
				p = (p + 1) % 3;
				cout << 1 << ' ' << i + p << ' ' << i + p << endl;
				cin >> s;
				if (s == 0) a[i + p] = 0, a[i + ((p + 1) % 3)] = a[i + ((p + 2) % 3)] = 1;
				else p = (p + 1) % 3, a[i + p] = 0, a[i + ((p + 1) % 3)] = a[i + ((p + 2) % 3)] = 1, p = (p + 2) % 3;
				p = (p + 2) % 3;
			}
		}
	}

	cout << 1 << ' ' << N << " " << N << endl;
	cin >> s;
	a[N] = s;

	cout << 2 << ' ';
	fi (1, N) cout << a[i] << ' '; cout << endl;
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