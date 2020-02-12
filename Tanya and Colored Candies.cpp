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

const ll N = 100, M = 1e9 + 7;
ll n, st, k, a[N], c[N];

void solve(){
	cin >> n >> st >> k;
	for(ll i=0;i<n;i++) cin >> a[i];
	for(ll i=0;i<n;i++){
		char ch; cin >> ch;
		if(ch == 'R') c[i] = 0;
		if(ch == 'G') c[i] = 1;
		if(ch == 'B') c[i] = 2;
	}

	ll globmn = LLONG_MAX;

	for(ll s=0;s<n;s++){
		ll t1 = a[s], sec1 = 1;
		for(ll i=s + 1;i<n;i++){
			if(t1 >= k) break;
			if(c[i] == c[i-1] || a[i] <= a[i-1]) break;
			t1 += a[i];
			sec1++;
		}

		ll t2 = a[s], sec2 = 1;
		for(ll i=s - 1;i>=0;i--){
			if(t2 >= k) break;
			if(c[i] == c[i+1] || a[i] <= a[i+1]) break;
			t2 += a[i];
			sec2++;
		}

		ll ans;

		cout << s << ' ' << t1 << ' ' << t2 << '\n';

		if(t1 < k && t2 < k) continue;
		else if(t1 < k) ans = sec2;
		else if(t2 < k) ans = sec1;
		else ans = min(sec1, sec2);


		ans += abs(st - (s - 1));
		globmn = min(globmn, ans);
	}

	if(globmn == LLONG_MAX) cout << "-1\n";
	else cout << globmn << "\n";
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