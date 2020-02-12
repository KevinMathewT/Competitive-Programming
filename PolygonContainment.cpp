#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto y : V) os << y << " ";
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

typedef struct {
   ll x, y;
} Point;

#define INF 1000000000
const ll N = 110, M = 1e9 + 7;
ll n, y, t;
vector<Point> poly[N];
vector<ll> poss;
const ld PI = 3.141592653589, TWOPI = 2 * 3.141592653589;
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define INSIDE 0
#define OUTSIDE 1

ll pnpoly(ll npol, ld *xp, ld *yp, ld x, ld y) {
  ll i, j, c = 0;
  for (i = 0, j = npol-1; i < npol; j = i++) {
    if ((((yp[i] <= y) && (y < yp[j])) ||
         ((yp[j] <= y) && (y < yp[i]))) &&
        (x < (xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i]))
      c = !c;
  }
  return c;
}

bool inside(ll u, ll y){
	ll ret1 = 1, ret2 = 1;

	ld xp[poly[y].size()], yp[poly[y].size()];
	ll it = 0;
	for(auto po : poly[y]) xp[it] = po.x, yp[it++] = po.y;

	for(auto p : poly[u]){
		// if(!InsidePolygon(polygon, poly[y].size(), p)){
		if(pnpoly(poly[y].size(), xp, yp, p.x, p.y)){ 
			// cout << p.x << " " << p.y << "-\n";
			ret1 = 0;
		}
	}

	it = 0;
	for(auto po : poly[u]) xp[it] = po.x, yp[it++] = po.y;

	for(auto p : poly[y]){
		// if(!InsidePolygon(polygon, poly[u].size(), p)){ 
		if(pnpoly(poly[u].size(), xp, yp, p.x, p.y)){ 
			// cout << p.x << " " << p.y << "\n";
			ret2 = 0;
		}
	}

	return ret1 | ret2;
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) poly[i].clear();
	for(ll i=0;i<n;i++){
		cin >> y;
		poly[i] = vector<Point>(y);
		for(ll j=0;j<y;j++){
			Point inp;
			cin >> poly[i][j].x >> poly[i][j].y;
		}
	}

	t = 1;
	poss.clear();
	poss.push_back(0);

	for(ll i=1;i<n;i++){
		// cout << poss << "\n";
		ll flag = 1;
		for(ll j=0;j<poss.size();j++)
			if(inside(i, j)) flag = 0;
		if(flag == 1)
			t++, poss.push_back(i);
	}

	cout << t << "\n";
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