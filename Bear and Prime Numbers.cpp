#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll i=(a);i>=b;j--)

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

const ll N = 1000010, M = 1e7 + 10;
ll n, a[N], s[M], f[M];
vector<ll> p, pre;
unordered_map<ll, ll> m;

void solve(){
	cin >> n;
	fi(0, n - 1) cin >> a[i];
	fi(0, n - 1) m[a[i]]++;

	fi(0, M - 1) s[i] = i;
	s[0] = 0;
	s[1] = 0;

	ll last;

	for(ll i=2;i*i<M;i++)
		if(s[i] == i)
			for(ll j=i*i;j<M;j+=i)
				s[j] = i;

	fi(2, M - 1) if(s[i] == i) p.push_back(i);
	pre = vector<ll>(p.size(), 0LL);

	fi(0, p.size() - 1) f[p[i]] = 0;

	unordered_map<ll, ll> m;

	fi(0, n - 1) {
		ll t = a[i];
		m.clear();

		while(t > 1) {
			if(m.find(s[t]) == m.end()) f[s[t]]++, m[s[t]] = 1;
			t /= s[t];
		}
	}

	fi(0, p.size() - 1) pre[i] = f[p[i]];

	// cout << p << "\n";
	// cout << pre << "\n";

	fi(1, pre.size() - 1) pre[i] += pre[i - 1];

	// cout << pre << "\n";

	ll q;
	cin >> q;
	while(q--) {
		ll l, r;
		cin >> l >> r;

		// cout << (p.rend() - upper_bound(p.rbegin(), p.rend(), l, greater<ll>())) - 1 << " ";
		// cout << ((p.rend() - lower_bound(p.rbegin(), p.rend(), r, greater<ll>()))) - 1 << "\n";

		if(l <= 2) {
			cout << pre[(p.rend() - lower_bound(p.rbegin(), p.rend(), r, greater<ll>())) - 1] << "\n";
		} else {
			cout << pre[(p.rend() - lower_bound(p.rbegin(), p.rend(), r, greater<ll>())) - 1] - pre[(p.rend() - upper_bound(p.rbegin(), p.rend(), l, greater<ll>())) - 1] << "\n";
		}
	}
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