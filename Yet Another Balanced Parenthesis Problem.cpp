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
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, k;

void solve(){
	cin >> n >> k;

	// cout << n << ' ' << k << " ";
	if(k == 2 || k == n){
		cout << -1 << "\n";
		return;
	}

	n /= 2;
	k /= 2;

	ll tot = 0;
	vector<ll> s;

	for(ll i=0;i<n / (k - 1);i++)
		s.push_back(k - 1);

	if(n % (k - 1) != 0)
		s.push_back(n % (k - 1));

	// cout << s << "\n";

	if((s[s.size() - 2] + s[s.size() - 1]) % (k) == 0)
		cout << -1 << "\n";
	else{
		for(ll i=0;i<s.size();i++){
			for(ll j=0;j<s[i];j++) cout << "(";
			for(ll j=0;j<s[i];j++) cout << ")";
		}

		cout << "\n";
	}
}

int main()
{
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