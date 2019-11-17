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

const ll N = 100005;
ll lazy[4 * N];
ll seg[4 * N];
ll n, q;
 
void build(ll low, ll high, ll node)
{
    if(low > high)
    return;
    if(low == high){
        seg[node]=0;
        return;
    }
    ll mid = low + high >> 1;
    build(low, mid, 2 * node + 1);
    build(mid+1, high, 2 * node + 2);
    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}
 
void update(ll low, ll high, ll lq, ll hq, ll node, ll val){
    if(lazy[node]){
        seg[node] += (high - low + 1) * lazy[node];
        if(high != low){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(low > hq || high < lq)
    	return;
    if(lq <= low && high <= hq){
        seg[node] += (high - low + 1) * val;
        if(high != low){
            lazy[2 * node + 1] += val;
            lazy[2 * node + 2] += val;
        }
        return;
    }
    ll mid = low + high >> 1;
    update(low, mid, lq, hq, 2 * node + 1, val);
    update(mid + 1, high, lq, hq, 2 * node + 2, val);
    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}
 
ll query(ll low, ll high, ll lq, ll hq, ll node){
    if(lazy[node]){
        seg[node]+=(high-low+1) * lazy[node];
        if(high!=low){
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node]=0;
    }
    if(low > hq || high < lq)
    	return 0;
    if(lq <= low && high <= hq)
        return seg[node];

    ll mid = low + high >> 1;
   	return query(low, mid, lq, hq, 2*node+1) + query(mid+1, high, lq, hq, 2*node+2);
}

void solve(){
	memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));
    cin >> n >> q;
    ll type;
    ll x, y;
    ll val;
    build(0, n-1, 0);
    while(q--){
    	cin >> type;
        if(type){
        	cin >> x >> y;
            cout << query(0, n-1, x-1, y-1, 0) << "\n";
        }
        else{
        	cin >> x >> y >> val;
            update(0, n-1, x-1, y-1, 0, val);
        }
    }
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