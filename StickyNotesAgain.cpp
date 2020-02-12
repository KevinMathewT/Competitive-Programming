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

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

const ll N = 5000010;
ll n, d[N], a[N], p1, p2;

void solve(){
	p1 = p2 = 0;
	cin >> n;

	for(ll i=0;i<n-1;i++){
		ll u, v, w;
		cin >> u >> v >> w;
		d[i] = w;
	}

	for(ll i=0;i<n;i++)
		cin >> a[i];

	sort(d, d + n - 1);
	sort(a, a + n);

	// for(ll i=0;i<n;i++)
	// 	cout << a[i] << ' ';
	// cout << "\n";

	// for(ll i=0;i<n-1;i++)
	// 	cout << d[i] << ' ';
	// cout << "\n";

	ll tot = 0;

	p1 = n - 1;
	ll i;

	for(ll i=0;i<p1;i++){
		if(a[i] < d[p2]){
			tot++;
			a[++p1] = 1e9 + 1;
			continue;
		}
		p2++;
	}

	cout << tot << "\n";
}

int main()
{
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