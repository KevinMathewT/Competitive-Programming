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
ll n;
string s[N];
vector<vector<string> > v;

void solve(){
	n = 6;
	fi (0, n - 1) cin >> s[i];

	sort(s, s + n);
	ll flag = 0;

	while (next_permutation(s, s + n)) {
		if (s[1].size() + s[5].size() - 1 != s[2].size()) continue;
		if (s[0].size() + s[4].size() - 1 != s[3].size()) continue;
		if (s[0][0] != s[1][0]) continue;
		if (s[0][s[0].size() - 1] != s[2][0]) continue;
		if (s[1][s[1].size() - 1] != s[3][0]) continue;
		if (s[2][s[1].size() - 1] != s[3][s[0].size() - 1]) continue;
		if (s[3][s[3].size() - 1] != s[5][0]) continue;
		if (s[2][s[2].size() - 1] != s[4][0]) continue;
		if (s[4][s[4].size() - 1] != s[5][s[5].size() - 1]) continue;
		// cout << s[0] << " " << s[1] << " " << s[2] << ' ' << s[3] << " " << s[4] << " " << s[5] << "\n";

		flag = 1;
		vector<string> add;
		string id = "";
		fi (1, s[3].size()) id.push_back('.');
		fi (1, s[2].size()) add.push_back(id);

		ll l = 0;
		fi (0, s[0].size() - 1) add[l][i] = s[0][i];
		fi (0, s[1].size() - 1) add[i][0] = s[1][i];
		fi (0, s[2].size() - 1) add[i][s[0].size() - 1] = s[2][i];
		fi (0, s[3].size() - 1) add[s[1].size() - 1][i] = s[3][i];
		fi (0, s[4].size() - 1) add.back()[i + s[0].size() - 1] = s[4][i];
		fi (0, s[5].size() - 1) add[i + s[1].size() - 1][add[0].size() - 1] = s[5][i];

		v.push_back(add);
	}

	// cout << v.size() << "\n";

	sort(v.begin(), v.end());
	if (flag)	for (string s : v[0]) cout << s << '\n';
	else cout << "Impossible\n";
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