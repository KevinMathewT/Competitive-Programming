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

const ll N = 260, M = 1e9 + 7;
ll n, m, g[N][N], vis[N][N], dist[N][N];
vector<pair<ll, ll> > off;

bool okay(ll x, ll y){
	if(x >= 0 && x < n && y >= 0 && y < m) return 1;
	return 0;
}

ll getDist(ll a, ll b, ll x, ll y){
	return abs(abs(a - x) + abs(b - y));
}

void solve(ll cs){
	off = vector<pair<ll, ll> >(0, {0, 0});
	cin >> n >> m;
	for(ll i=0;i<n;i++) 
		for(ll j=0;j<m;j++){
			char c; cin >> c;
			if(c == '1') g[i][j] = 1, off.push_back({i, j});
			else g[i][j] = 0;
		}

	queue<pair<ll, pair<ll, ll> > > q;

	for(auto pll : off) q.push({0, pll});
	for(ll i=0;i<N;i++){
		fill(vis[i], vis[i] + N, 0LL);
		fill(dist[i], dist[i] + N, 0LL);
	}


	while(!q.empty()){
		auto ob = q.front(); q.pop();
		dist[ob.S.F][ob.S.S] = ob.F;
		vis[ob.S.F][ob.S.S] = 1;

		if(okay(ob.S.F + 1, ob.S.S) && vis[ob.S.F + 1][ob.S.S] == 0)
			q.push({ob.F + 1, {ob.S.F + 1, ob.S.S}});
		if(okay(ob.S.F - 1, ob.S.S) && vis[ob.S.F - 1][ob.S.S] == 0)
			q.push({ob.F + 1, {ob.S.F - 1, ob.S.S}});
		if(okay(ob.S.F, ob.S.S + 1) && vis[ob.S.F][ob.S.S + 1] == 0)
			q.push({ob.F + 1, {ob.S.F, ob.S.S + 1}});
		if(okay(ob.S.F, ob.S.S - 1) && vis[ob.S.F][ob.S.S - 1] == 0)
			q.push({ob.F + 1, {ob.S.F, ob.S.S - 1}});
	}

	ll mxi = 0;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			mxi = max(mxi, dist[i][j]);

	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++)
			cout << dist[i][j] << ' ';
		cout << "\n";
	}

	ll ans = mxi;
	ll l = 0, r = mxi;

	while(l <= r){
		ll m = (l + r) / 2;

		vector<pair<ll, ll> > intr;

		for(ll i=0;i<n;i++)
			for(ll j=0;j<m;j++)
				if(dist[i][j] > m) intr.push_back({i, j});

		cout << m << ' ' << intr << "\n";

		ll mx[2], x1[2], y1[2];
		ll mn[2], x2[2], y2[2];

		mx[0] = mx[1] = LLONG_MIN;
		mn[0] = mn[1] = LLONG_MAX;

		for(auto pll : intr){
			ll x = pll.F, y = pll.S;
			if((x + y) < mn[0]){
				mn[0] = (x + y);
				x2[0] = x, y2[0] = y;
			}
			if((x + y) > mx[0]){
				mx[0] = (x + y);
				x1[0] = x, y1[0] = y;
			}
			if((x - y) < mn[1]){
				mn[1] = (x - y);
				x2[1] = x, y2[1] = y;
			}
			if((x - y) > mx[1]){
				mx[1] = (x - y);
				x1[1] = x, y1[1] = y;
			}
		}

		ll mni = LLONG_MAX;
		for(ll i=0;i<n;i++)
			for(ll j=0;j<m;j++){
				ll an = LLONG_MIN;
				an = max(an, getDist(i, j, x1[0], y1[0]));
				an = max(an, getDist(i, j, x1[1], y1[1]));
				an = max(an, getDist(i, j, x2[0], y2[0]));
				an = max(an, getDist(i, j, x2[1], y2[1]));

				mni = min(mni, an);
			}

		if(mni <= m){
			ans = mni;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}

	cout << "Case #" << cs << ": " << ans << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	for(ll i=1;i<=T;i++)
		solve(i);

	return 0;
}