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

const ll N = 1000010;
ll arr[N];

struct segment {
    ll _and;

    void mergee(segment left, segment right) {
    		_and = left._and & right._and;
    }
} seg[4 * N];

void build(ll low, ll high, ll node) {
    if (low > high)
        return;
    if (low == high) {
        seg[node]._and = arr[low];
        return;
    }

    ll mid = low + high >> 1;
    build(low, mid, 2 * node + 1);
    build(mid + 1, high, 2 * node + 2);
    seg[node].mergee(seg[2 * node + 1], seg[2 * node + 2]);
}

segment query(ll low, ll high, ll lq, ll hq, ll node) {
    segment ans;
    ans._and = (1LL << 32) - 1;
    // cout << ans._and << "-\n";

    if (low > high || low > hq || high < lq)
        return ans;
    if (lq <= low && high <= hq)
        return seg[node];

    ll mid = low + high >> 1;
    if (lq > mid)
        return query(mid + 1, high, lq, hq, 2 * node + 2);
    if (hq <= mid)
        return query(low, mid, lq, hq, 2 * node + 1);

    ans.mergee(query(low, mid, lq, hq, 2 * node + 1), query(mid + 1, high, lq, hq, 2 * node + 2));
    return ans;
}

void solve(){
	ll n;
	cin >> n;
    ll i;
    for (i = 0; i < n; i++) cin >> arr[i];
    build(0, n - 1, 0);
    ll m;
    cin >> m;
    ll x, y;
    for (i = 0; i < m; i++) {
	    	cin >> x >> y;

	    	// cout << query(0, n - 1, x - 1, y - 1, 0)._and << "\n";
        if(query(0, n - 1, x - 1, y - 1, 0)._and % 2 == 0) cout << "EVEN\n";
        else cout << "ODD\n";
    }
}

int main() {
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