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

const ll N = 100010, M = 1e9 + 7;
ll lazy[4 * N][2];
ll seg[4 * N];
ll n, q, b[N];
pair<ll, ll> a[N];

void update(ll low, ll high, ll lq, ll hq, ll node, ll a, ll b){
    if(lazy[node]){
        seg[node] = ((seg[node] * lazy[node][0]) % M + ((high - low + 1) * lazy[node][1]) % M) % M;
        if(high != low){
            lazy[2 * node + 1][0] = (lazy[node][0] * lazy[2 * node + 1][0]) % M;
            lazy[2 * node + 1][1] = ((lazy[node][0] * lazy[2 * node + 1][1]) % M + lazy[node][1]) % M;
            lazy[2 * node + 2][0] = (lazy[node][0] * lazy[2 * node + 2][0]) % M;
            lazy[2 * node + 2][1] = ((lazy[node][0] * lazy[2 * node + 2][1]) % M + lazy[node][1]) % M;
        }
        lazy[node][0] = 1;
        lazy[node][1] = 0;
    }
    if(low > hq || high < lq)
    	return;
    if(lq <= low && high <= hq){
        seg[node] = ((seg[node] * a) % M + (((high - low + 1) * b) % M)) % M;
        if(high != low){
            lazy[2 * node + 1][0] = (a * lazy[2 * node + 1][0]) % M;
            lazy[2 * node + 1][1] = ((a * lazy[2 * node + 1][1]) % M + b) % M;
            lazy[2 * node + 2][0] = (a * lazy[2 * node + 2][0]) % M;
            lazy[2 * node + 2][1] = ((a * lazy[2 * node + 2][1]) % M + b) % M;
        }
        return;
    }
    ll mid = low + high >> 1;
    update(low, mid, lq, hq, 2 * node + 1, a, b);
    update(mid + 1, high, lq, hq, 2 * node + 2, a, b);
    seg[node] = (seg[2 * node + 1] + seg[2 * node + 2]) % M;
}
 
ll query(ll low, ll high, ll lq, ll hq, ll node){
    if(lazy[node]){
        seg[node] = ((seg[node] * lazy[node][0]) % M + ((high - low + 1) * lazy[node][1]) % M) % M;
        if(high != low){
            lazy[2 * node + 1][0] = (lazy[node][0] * lazy[2 * node + 1][0]) % M;
            lazy[2 * node + 1][1] = ((lazy[node][0] * lazy[2 * node + 1][1]) % M + lazy[node][1]) % M;
            lazy[2 * node + 2][0] = (lazy[node][0] * lazy[2 * node + 2][0]) % M;
            lazy[2 * node + 2][1] = ((lazy[node][0] * lazy[2 * node + 2][1]) % M + lazy[node][1]) % M;
        }
        lazy[node][0] = 1;
        lazy[node][1] = 0;
    }
    if(low > hq || high < lq)
    	return 0;
    if(lq <= low && high <= hq)
        return seg[node] % M;

    ll mid = low + high >> 1;
   	return (query(low, mid, lq, hq, 2*node+1) + query(mid+1, high, lq, hq, 2*node+2)) % M;
}

void solve(){
		for(ll i=0;i<4*N;i++) seg[i] = 0,  lazy[i][1] = 0, lazy[i][0] = 1;
    cin >> n >> q;

    for(ll i=0;i<n;i++) cin >> a[i].F, a[i].S = i, b[i] = a[i].F;

    sort(a, a + n);
    sort(b, b + n);

    while(q--){
    	ll l, r, x, y;
    	cin >> l >> r >> x >> y;

    	l = lower_bound(b, b + n, l) - b;
    	r = upper_bound(b, b + n, r) - b - 1;

    	if(l >= n) continue;
    	if(r < 0) continue;
    	if(l > r) continue;

      update(0, n-1, l, r, 0, x % M, y % M);

	    // for(ll i=0;i<n;i++)
	    // 	cout << query(0, n - 1, i, i, 0) << " ";
	    // cout << "\n";
    }

    vector<ll> ans(n, 0);

    for(ll i=0;i<n;i++)
    	ans[a[i].S] = query(0, n - 1, i, i, 0);

    for(ll i=0;i<n;i++)
    	cout << ans[i] % M << " ";
    cout << "\n";
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