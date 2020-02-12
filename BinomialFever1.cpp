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
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> M) {
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
 
/*
NTT Code Adapted from: https://www.codechef.com/viewsolution/18397100
*/


ll n, p, r;
const ll M = 998244353;
const ll MAX_N = 1e6 + 5;
const ll MAX_T = 111;
 
ll power(ll a, ll p) {
    ll r = 1;
    while (p) {
        if (p & 1) r = r * a % M;
        p >>= 1; a = a * a % M;
    }
    return r;
}
 
namespace NTT {
    const ll P = M;
    const ll K = 23;
    const ll ROOT = 3;
    const ll N = 1 << K;
    vector<ll> W, invW;
    vector<ll> rev;
 
    void init() {
        ll n2 = N >> 1;
        W.resize(n2 + 1); W[0] = 1;
        W[1] = power(ROOT, (P - 1) / N);
        for (ll i = 2; i <= n2; i++)
            W[i] = 1LL * W[i - 1] * W[1] % P;
        invW.resize(n2 + 1); invW[n2] = W[n2];
        for (ll i = n2 - 1; i >= 0; i--)
            invW[i] = 1LL * invW[i + 1] * W[1] % P;
        rev.resize(N);
    }
 
    void transform(vector<ll> &a, bool inv=false) {
        ll k = 0; while ((1 << k) < a.size()) k++;
        ll n = 1 << k;
        a.resize(n, 0);
        rev[0] = 0;
        for (ll i = 1; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | ((i & 1) << (k - 1));
            if (i < rev[i]) swap(a[i], a[rev[i]]);
        }
 
        vector<ll> &twiddle = inv ? invW : W;
        for (ll len = 2; len <= n; len <<= 1) {
            ll half = len >> 1, diff = N / len;
            for (ll i = 0; i < n; i += len) {
                ll pw = 0;
                for (ll j = i; j < i + half; j++) {
                    ll v = 1LL * a[j + half] * twiddle[pw] % P;
                    a[j + half] = a[j] - v;
                    if (a[j + half] < 0) a[j + half] += P;
                    a[j] += v;
                    if (a[j] >= P) a[j] -= P;
                    pw += diff;
                }
            }
        }
 
        if (inv) {
            ll inv_n = power(n, P - 2);
            for (ll &x : a) x = x * inv_n % P;
        }
    }
 
    void convolve(vector<ll> &a, vector<ll> &b) {
        ll m = a.size() + b.size() - 1;
        a.resize(m, 0); transform(a);
        b.resize(m, 0); transform(b);
        for (ll i = 0; i < a.size(); i++)
            a[i] = 1LL * a[i] * b[i] % P;
        transform(a, true);
        a.resize(m);
    }
};
 
ll T, ans[MAX_T];
pair<pair<ll, ll>, pair<ll, ll> > A[MAX_T];
ll fact[MAX_N], invfact[MAX_N];
 
void init() {
    fact[0] = invfact[0] = 1;
    for (ll i = 1; i < MAX_N; i++) {
        fact[i] = i * fact[i - 1] % M;
        invfact[i] = power(fact[i], M - 2);
    }
}
 
vector<ll> calcR(vector<ll> L, ll n) {
    vector<ll> a(n + 1), b(n + 1);
    ll npow = 1;
    for (ll i = n; i >= 0; i--) {
        a[i] = L[i] * fact[i] % M;
        b[i] = npow * invfact[n - i] % M;
        npow = npow * n % M;
    }
    NTT::convolve(a, b);
    b.resize(n + 1);
    for (ll i = 0; i <= n; i++)
        b[i] = a[i + n] * invfact[i] % M;
    return b;
}
 
vector<ll> recur(ll L, ll R) {
    if (L == R) return vector<ll>({L, 1});
    ll n = R - L + 1, n2 = n >> 1;
    vector<ll> polyL = recur(L, L + n2 - 1);
    vector<ll> polyR = calcR(polyL, n2);
    NTT::convolve(polyL, polyR);
    if (n & 1) {
        polyL.push_back(0);
        for (ll i = n; i > 0; i--) {
            polyL[i] = polyL[i - 1] + 1LL * R * polyL[i] % M;
            if (polyL[i] >= M) polyL[i] -= M;
        }
        polyL[0] = 1LL * R * polyL[0] % M;
    }
    return polyL;
}
 
void solve() {
    init();
    NTT::init();
 
    sort(A, A + T);
    ll prev = 0;
    vector<ll> prevpoly({1});
    for (ll t = 0; t < T; t++) {
        ll n = A[t].S.F;
        ll p = A[t].F.S;
        ll r = A[t].F.F + 1;
        ll N, K;
        tie(N, K) = A[t].F;

		if(p == 1 && r == 1){
			ans[A[t].S.S] = ((n + 1) % M);
			continue;
		}

		if(p == 998244352){
			if(r == 1){
				if(n % 2 == 0) ans[A[t].S.S] = 1;
				else ans[A[t].S.S] = 0;
				continue;
			}

			if(r % 2 == 0) ans[A[t].S.S] = (n % 2 == 1 ? (n + 1) / 2 : n / 2) % M;
			else ans[A[t].S.S] = (M - (n % 2 == 1 ? (n + 1) / 2 : n / 2)) % M;

			continue;
		}

        if (prev < N) {
            vector<ll> poly = recur(prev + 1, N);
            NTT::convolve(prevpoly, poly);
            prev = N;
        }

        // for(ll i=0;i<10;i++)
        // 	cout << prevpoly[i] << ' ';
        // cout << "\n";

		ll sum = 0;

		for(ll i=0;i<r;i++){
			ll k = i + 1;
			ll k2 = (power(p, n * k + k) - 1);
			if(k2 < 0) k2 += M;
			ll k3 = (power(p, k) - 1);
			if(k3 < 0) k3 += M;
			ll k4 = k2;
			ll k5 = (k4 * power(k3, M - 2)) % M;
			ll k6 = (prevpoly[i] * k5) % M;

			// cout << k << ' ' << k5 << "\n";

			if((r - i) % 2 == 1){
				sum = (sum + k6);
				if(sum > M) sum -= M;
			}
			else{
				sum = (sum - k6);
				if(sum < 0) sum += M;
			}
		}

		sum = (sum * power(fact[r], M - 2)) % M;

        ans[A[t].S.S] = sum % M;
    }
}

int main() {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
 
    cin >> T;
    for (ll i = 0; i < T; i++) {
        cin >> A[i].S.F >> A[i].F.S >> A[i].F.F;
        A[i].S.S = i;
        A[i].F.F--;
    }
 
    solve();
 
    for (ll i = 0; i < T; i++)
        cout << ans[i] << "\n";
 
    return 0;
}