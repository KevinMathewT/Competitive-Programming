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
    ll _presum, _sufsum, _totalsum, _maxsum;

    void mergee(segment left, segment right) {
        _presum = max(left._presum, left._totalsum + right._presum);
        _sufsum = max(right._sufsum, right._totalsum + left._sufsum);
        _totalsum = left._totalsum + right._totalsum;
        _maxsum = max(_presum, max(_sufsum, max(left._maxsum, max(right._maxsum, left._sufsum + right._presum))));
    }
} seg[4 * N];

void build(ll low, ll high, ll node) {
    if (low > high)
        return;
    if (low == high) {
        seg[node]._presum = seg[node]._sufsum = seg[node]._totalsum = seg[node]._maxsum = arr[low];
        return;
    }

    ll mid = low + high >> 1;
    build(low, mid, 2 * node + 1);
    build(mid + 1, high, 2 * node + 2);
    seg[node].mergee(seg[2 * node + 1], seg[2 * node + 2]);
}

segment query(ll low, ll high, ll lq, ll hq, ll node) {
    segment ans;
    ans._presum = ans._sufsum = ans._totalsum = ans._maxsum = INT_MIN;

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
    register ll i;
    for (i = 0; i < n; i++)
    	cin >> arr[i];
    build(0, n - 1, 0);
    ll m;
    cin >> m;
    ll x, y;
    for (i = 0; i < m; i++) {
    	cin >> x >> y;
        printf("%d\n", query(0, n - 1, x - 1, y - 1, 0)._maxsum);
    }
}

int main() {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();
    
    return 0;
}