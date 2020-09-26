#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

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

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

const ll N = 200010, M = 1e9 + 7;
ll n, k, a[N];

void solve(){
	cin >> n >> k;
	for(ll i=0;i<n;i++) cin >> a[i];
	sort(a, a + n);

	ll l = a[0] * a[1], r = a[n] * a[n - 1];
	cout << l << ' ' << r << '\n';

	cout << "sdkfj\n";

	while(l <= r){
		ll m = (l + r) / 2;

		ll l1 = 0, r1 = n - 1;
		ll t1 = 0;
		while(l1 < r1){
			while(a[l1] * a[r1] > m && l1 < r1) r1--;
			if(l1 == r1) break;
			t1 += r1;
			l1++;
		}

		cout << "skdhf\n";

		l1 = 0, r1 = n - 1;
		ll t2 = 0;
		while(l1 < r1){
			while(a[l1] * a[r1] >= m && l1 < r1) r1--;
			if(l1 == r1) break;
			t2 += r1;
			l1++;
		}

		if(k < t1) l = m + 1;
		else if(k > t2) r = m - 1;
		else{
			cout << m << "\n";
			return;
		}
	}
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