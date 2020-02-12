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

struct point{
	ld x, y;
	point(){ x = 0, y = 0; }
	point(ld _x, ld _y){ x = _x, y = _y; }
	point(const point& _P){ x = _P.x, y = _P.y; }
	point operator+=(const point &_P) { x += _P.x, y += _P.y; return *this; }
	point operator-=(const point &_P) { x -= _P.x, y -= _P.y; return *this; }
	point operator-(const point &_P) { return point(*this) -= _P; }
};

ostream& operator<<(ostream &os, point P) {
    return os << "(" << P.x << ", " << P.y << ")";
}

ld cross(point a, point b){
	return (a.x * b.y) - (a.y * b.x);
}
ld triangle_area(point a, point b, point c){
	// cout << a << ' ' << b << ' ' << c << " " << b - a << ' ' << c - b << "\n";
	return cross(b - a, c - b) / 2;
}

struct polygon{
	ll n;
	vector<point> P;
	polygon(){ P = vector<point>(0), n = 0; }
	polygon(vector<point> _P){ P = _P, n = _P.size(); }
	ll size() { return n = P.size(); }

	ld getArea(){
		ld area = 0;
		for(ll i=1;i<n;i++) area += triangle_area(point(0, 0), P[i-1], P[i % n]);
		return abs(area);	
	}

	bool inside(point pt){
		ld tot = 0;
		for(ll i=1;i<=n;i++)
			tot += abs(triangle_area(pt, P[i-1], P[i % n]));

		if(tot == getArea()) return 1;
		return 0;
	}
};

const ll N = 3010, M = 1e9 + 7;
ll n, m, q, dp[N][N];
vector<point> R, B;
const point ID = point(0, 0), TR = point(100000, 100000);

void solve(){
	// cout << triangle_area(point(0, 3), point(3, 0), point(0, 0)) << "\n";
	cin >> n >> m;
	R = vector<point>(n, point(0, 0));
	B = vector<point>(m, point(0, 0));

	for(ll i=0;i<n;i++) cin >> R[i].x >> R[i].y, R[i] += TR;
	for(ll i=0;i<m;i++) cin >> B[i].x >> B[i].y, B[i] += TR;

	for(ll i=0;i<n-1;i++)
		for(ll j=i+1;j<n;j++){
			// cout << i + 1 << " " << j + 1 << "------------\n";
			vector<point> V;
			V = { ID, R[i], R[j] };
			polygon P(V);
			dp[i][j] = dp[j][i] = 0;
			for(ll k=0;k<m;k++)
				if(P.inside(B[k])) dp[i][j]++, dp[j][i]++;
		}

	// for(ll i=0;i<n-1;i++)
	// 	for(ll j=i+1;j<n;j++)
	// 		cout << i + 1 << " " << j + 1 << " " << dp[i][j] << '\n';

	cin >> q;
	while(q--){
		ll k; cin >> k;
		vector<ll> Q(k, 0);
		for(ll i=0;i<k;i++) cin >> Q[i], Q[i]--;

		// cout << Q << "\n";

		ll tot = 0;
		for(ll i=1;i<=k;i++) if(triangle_area(ID, R[Q[i - 1]], R[Q[i % k]]) < 0)
			tot += dp[Q[i - 1]][Q[i % k]];
		else tot -= dp[Q[i - 1]][Q[i % k]];

		cout << abs(tot) << "\n";
	}
}

int main(){
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