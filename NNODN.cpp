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

const ll N = 1000010, M = 1e9 + 7;
ll n, a[N], l, r, s[N];

void preprocess(){
	a[0] = 0;
	a[1] = 1;

	fi(2, N - 1) s[i] = i, a[i] = 0;
	for(ll i=2;i*i<N;i++)
		if(s[i] == i)
			for(ll j=i*i;j<N;j+=i) s[j] = i;

	a[2] = 1;
	ll c = 2;
	while(c < N){
		ll t = c;

		vector<ll> f(0);
		std::vector<pair<ll, ll> > pf(0);
		while(t > 1) f.push_back(s[t]), t /= s[t];

		sort(f.begin(), f.end());

		pf.push_back({f[0], 1});
		fi(1, f.size() - 1)
			if(f[i] == pf.back().F) pf.back().S++;
			else pf.push_back({f[i], 1});


		ll add = 1;
		fi(0, pf.size() - 1) add *= pf[i].S + 1;

		c += add;
		a[c] = 1;
	}

	fi(1, N - 1) a[i] += a[i - 1];
}

void solve(ll cs){
	cin >> l >> r;
	cout << "Case " << cs << ": " << a[r] - a[l - 1] << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	preprocess();

	ll T;
	cin >> T;
	fi(1, T)
		solve(i);

	return 0;
}