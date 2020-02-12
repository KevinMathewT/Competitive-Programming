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

const ll N = 10010, M = 1e9 + 7;
ll n, s, k, a[N];

void solve(){
	cin >> n >> s >> k;
	for(ll i=0;i<k;i++) cin >> a[i];
	sort(a, a + k);

	ll p = -1;
	for(ll i=0;i<k;i++)
		if(a[i] == s) p = i;

	if(p == -1){
		cout << 0 << "\n";
		return;
	}

	ll mn1 = 1;
	for(ll i=p-1;i>=0;i--)
		if(a[i + 1] - a[i] == 1)
			mn1++;


	ll mn2 = 1;
	for(ll i=p+1;i<=k-1;i++)
		if(a[i] - a[i - 1] == 1)
			mn2++;

	if(s - mn1 < 1) cout << mn2 << "\n";
	else if(s + mn2 > n) cout << mn1 << "\n";
	else cout << min(mn1, mn2) << "\n";
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