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

const ll N = 1000010;
ll n, d[N], a[N];
vector<ll> s1, s2;

void solve(){
	s1.clear();
	s2.clear();
	cin >> n;

	fill(d, d + n + 10, 0);

	for(ll i=0;i<n-1;i++){
		ll u, v, w;
		cin >> u >> v >> w;
		d[u]++;
		d[v]++;
		s2.push_back(w);
	}

	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<n;i++)
		s1.push_back(a[i]);

	multiset<ll> ds;
	for(ll i=1;i<=n;i++)
		ds.insert(d[i]);
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	vector<ll> left(n - 1, 2);

	ll i;
	for(i=s1.size()-1;i>=0;i--){
		cout << s1 << "\n";
		cout << s2 << "\n";
		cout << ds << "\n";
		cout << left << "\n";
		ll p = s2.rend() - lower_bound(s2.rbegin(), s2.rend(), s1[i], greater<ll>());
		p--;

		cout << p << "\n";
		while(p >= 0 && (s2[p] > s1[i] || left[p] <= 0)) p--;

		cout << p << "\n";

		if(p < 0) break;

		if(lower_bound(ds.rbegin(), ds.rend(), p + 1, greater<ll>()) == ds.rend()) break;

		ll sz = *lower_bound(ds.rbegin(), ds.rend(), p + 1, greater<ll>());
		ds.erase(ds.lower_bound(sz));

		// cout << sz << "\n";

		for(ll i=p;i>=p-sz+1;i--)
			left[i]--;
	}

	cout << i + 1 << "\n";
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