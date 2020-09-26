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


const ll N = 100010, M = 1e9 + 7, e = 29;
ll n, p[N], f[N], dp[N];
string s;

class SuffixArray {
public:
	string s, original;

	SuffixArray(string s) {
		this->s = s;
		this->original = s;
	}

	vector<ll> sort_cyclic_shifts() {
    ll n = s.size();
    const ll alphabet = 256;

    vector<ll> p(n), c(n), cnt(max(alphabet, n), 0);
    for (ll i = 0; i < n; i++)
      cnt[s[i]]++;
    for (ll i = 1; i < alphabet; i++)
      cnt[i] += cnt[i-1];
    for (ll i = 0; i < n; i++)
      p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    ll classes = 1;
    for (ll i = 1; i < n; i++) {
      if (s[p[i]] != s[p[i-1]])
        classes++;
      c[p[i]] = classes - 1;
    }

		vector<ll> pn(n), cn(n);
    for (ll h = 0; (1 << h) < n; ++h) {
      for (ll i = 0; i < n; i++) {
        pn[i] = p[i] - (1 << h);
        if (pn[i] < 0)
          pn[i] += n;
      }
      fill(cnt.begin(), cnt.begin() + classes, 0);
      for (ll i = 0; i < n; i++)
        cnt[c[pn[i]]]++;
      for (ll i = 1; i < classes; i++)
        cnt[i] += cnt[i-1];
      for (ll i = n-1; i >= 0; i--)
        p[--cnt[c[pn[i]]]] = pn[i];
      cn[p[0]] = 0;
      classes = 1;
      for (ll i = 1; i < n; i++) {
        pair<ll, ll> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
        pair<ll, ll> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
        if (cur != prev)
          ++classes;
        cn[p[i]] = classes - 1;
      }
      c.swap(cn);
    }
    return p;
	}

	vector<ll> getSuffixArray() {
    s += "$";
    vector<ll> sorted_shifts = sort_cyclic_shifts();
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
	}
};

ll power(ll a, ll x) {
	if (x == 0) return 1;
	if (x == 1) return a % M;
	if (x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * power((a * a) % M, x / 2)) % M;
}

void solve(){
	cin >> s;
	n = s.size();
	fill (dp, dp + n, -1);

	SuffixArray sa(s);
	vector<ll> suffarr = sa.getSuffixArray();

	vector<pair<ll, ll> > v;



	fi (0, n - 2) {
		ll pre = 0, suff = 0;

		fj (0, i) pre = (pre + (((s[j] - 'A') * power(e, j))) % M) % M;
		fjd (n - 1, n - i - 1) suff = ((suff * e) % M + (s[j] - 'A')) % M;

		if (pre != suff) continue;
		v.push_back({i + 1, f[i + 1] + 1});
	}

	cout << v.size() + 1 << "\n";
	for (pair<ll, ll> it : v) cout << it.F << " " << it.S << '\n'; 
	cout << n << ' ' << 1 << "\n";
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