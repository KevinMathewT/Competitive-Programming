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

ll n, k, a[200010];
unordered_map<ll, vector<ll> > m;
unordered_map<ll, ll> v;
const ll mod = 1000000007;

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    ll n = a.size();
    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (ll len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (ll i = 0; i < n; i += len) {
            cd w(1);
            for (ll j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll s1 = a.size();
    ll s2 = b.size();
    ll n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    vector<ll> result(n);
    for (ll i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    // cout << result << "\n";
    result.resize(s1 + s2);
    for(ll i=s1 + s2 - 1;i>0;i--)
        result[i] = result[i-1];
    result[0] = 0;
    return result;
}


ll calc(ll x){
	ll tot = 0;
	vector<ll> p, s1, s2;
	for(ll i=0;i<m[x].size();i++)
		p.push_back(m[x][i]);
	s1.push_back(m[x][0] - 0 + 1);

	for(ll i=1;i<p.size();i++)
		s1.push_back(m[x][i] - m[x][i - 1]);

	for(ll i=0;i<p.size()-1;i++)
		s2.push_back(m[x][i + 1] - m[x][i]);
	s2.push_back(n - m[x][m[x].size() - 1]);

    reverse(s1.begin(), s1.end());
	vector<ll> mul = multiply(s1, s2);

    cout << s1 << ' ' << s2 << "\n";
    cout << mul << "\n";

	for(ll i=m[x].size();i<mul.size();i++){
        cout << mul[i] << " " << modpow(i - m[x].size() + 1, k) << "\n";
		tot = (tot + (modpow(i - m[x].size() + 1, k) * (mul[i] % mod)) % mod) % mod;
    }

    return tot;
}

void solve(){
	m.clear();
	v.clear();
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<n;i++)
		m[a[i]].push_back(i);

	ll t = 0;
	for(ll i=0;i<n;i++)
		if(v[a[i]] != 1)
			v[a[i]] = 1, t = (t + calc(a[i])) % mod;

	cout << t << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}