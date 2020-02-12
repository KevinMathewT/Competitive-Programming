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
const ll M = 998244353, N = 4000005;
ll tot, limit, c[N], d[N], w[2][N], fact[N], rev[N];

ll power(ll x, ll y){
    ll ans1 = 1;
    while(y){
        if(y & 1) 
            ans1 = 1ll * ans1 * x % M;
        y >>=  1;
        x = 1ll * x * x % M;
    }
    return ans1;
}

void init(ll len){
    tot = 0; 
    limit = 1;
    while(limit<=len) 
        limit *= 2, tot++;
    ll G = power(3, (M - 1) / limit);
    // cout << G << "\n";
    w[0][0] = w[0][limit] = w[1][0] = w[1][limit] = 1;
    for (ll i=1;i<limit;i++) 
        w[0][i] = 1ll * w[0][i-1] * G % M;
    for (ll i=limit-1;i;i--) 
        w[1][i] = w[0][limit - i];
    for (ll i=0;i<limit;i++) 
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (tot - 1));
}

inline void fft(ll *a, ll flag){
    for (ll i=0;i<limit;i++) 
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (ll i=2;i<=limit;i*=2){
        for (ll j=0;j<limit;j += i){
            for (ll k=0;k<(i>>1);k++){
                ll t = 1ll * a[j + k + (i >> 1)] * w[flag][limit / i * k] % M;
                a[j + k + (i >> 1)] = (a[j + k] - t + M) % M;
                a[j + k] = (a[j + k] + t) % M;
            }
        }
    }
    if (flag == 1){
        ll inv = power(limit, M-2);
        for (ll i=0;i<limit;i++) a[i] = 1ll * a[i] * inv % M;
    }
}

vector<ll> mul(vector<ll> a, vector<ll> b){
    // for(ll i=0;i<10;i++)
    //  cout << rev[i] << " ";
    // cout << "\n";
    ll n = a.size();
    ll m = b.size();
    init(n + m);
    // for(ll i=0;i<10;i++)
    //  cout << rev[i] << " ";
    // cout << "\n";

    for (ll i = 0;i < n;i++) c[i] = a[i];
    for (ll i = n;i < limit;i++) c[i] = 0;
    for (ll i = 0;i < m;i++) d[i] = b[i];
    for (ll i = m;i < limit;i++) d[i] = 0;
    
    fft(c, 0);
    fft(d, 0);
    
    for (ll i=0;i<limit;i++) c[i] = 1ll * c[i] * d[i] % M;
    
    fft(c, 1);
    vector<ll> ans;
    bool fg = 0;
    for (ll i = limit-1;~i;i--){
        if (c[i]) fg = 1;
        if (fg) ans.push_back(c[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans; 
}

vector<ll> solve(ll l, ll r){
    if (l == r){
        vector<ll> tp;
        tp.push_back(-l);
        tp.push_back(1);
        return tp;
    }

    ll mid = (l + r) >> 1;
    vector<ll> Lf = solve(l, mid);
    vector<ll> Rf = solve(mid + 1, r);
    return mul(Lf, Rf);
}

void solve(){
	// vector<ll> a, b;
 //    a.push_back(1);
 //    a.push_back(2);
 //    a.push_back(3);
 //    b.push_back(2);
 //    b.push_back(3);
 //    b.push_back(4);

    // cout << a << " " << b << "\n";
    // cout << multiply(a, b) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// solve();

	return 0;
}