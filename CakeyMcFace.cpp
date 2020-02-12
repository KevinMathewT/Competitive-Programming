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

const ll N = 2010, M = 1e9 + 7;
ll n, m, a[N], b[N];

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++) cin >> a[i];
	for(ll i=0;i<m;i++) cin >> b[i];

	sort(a, a + n);
	sort(b, b + m);

	vector<ll> diff;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			if(b[j] >= a[i])
				diff.push_back(b[j] - a[i]);

	sort(diff.begin(), diff.end());

	ll c = 1, b = -1, d = -1;
	for(ll i=1;i<diff.size();i++){
		// cout << c << " ";
		if(diff[i] == diff[i-1])
			c++;
		else{
			if(c > b || (c == b && diff[i-1] < d)){
				b = c;
				d = diff[i - 1];
			}
			c = 1;
		}
	}

	// cout << diff << "\n";

	cout << d << "\n";
}

int main()
{
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