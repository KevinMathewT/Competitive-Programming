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

ld PR = 1e-4;

struct point {
	ld x, y;
	point(){ x = 0, y = 0; }
	point(ld _x, ld _y){ x = _x, y = _y; }
	ld abs() { return sqrt((x * x) + (y * y)); }
	point operator+=(const point &t) { x += t.x, y += t.y; return *this; }
	point operator-=(const point &t) { x -= t.x, y -= t.y; return *this; }
	point operator*=(const point &t) { x *= t.x, y *= t.y; return *this; }
	point operator/=(const point &t) { x /= t.x, y /= t.y; return *this; }
	point operator+(const point &t) const { return point(*this) += t; }
	point operator-(const point &t) const { return point(*this) -= t; }
	point operator*(const point &t) const { return point(*this) *= t; }
	point operator/(const point &t) const { return point(*this) /= t; }
	point operator*(const ld &t) const { return point(*this) *= point(t, t); }
};

ostream& operator<<(ostream &os, point P) {
    os << "(" << P.x << ", " << P.y << ")";
    return os;
}

ld cross(point a, point b) { return a.x * b.y - a.y * b.x; }
ld parallelogram_area(point a, point b, point c){
	return cross(b - a, c - b);
}
ld signed_triangle_area(point a, point b, point c){
	return parallelogram_area(a, b, c) / 2;
}

bool onSegment(point P, point a, point b){
	if((P.x >= min(a.x, b.x) && P.x <= max(a.x, b.x)) && (P.y >= min(a.y, b.y) && P.y <= max(a.y, b.y))) return true;
	return false;
}

bool doIntersectSegment(point a1, point a2, point b1, point b2){
	ld dir1 = signed_triangle_area(a1, b1, a2);
	ld dir2 = signed_triangle_area(a1, b2, a2);
	ld dir3 = signed_triangle_area(b1, a1, b2);
	ld dir4 = signed_triangle_area(b1, a2, b2);

	cout << dir1 << ' ' << dir2 << ' ' << dir3 << ' ' << dir4 << "\n";

	if(dir1 * dir2 < 0.0 && dir3 * dir4 < 0.0) return true;
	// if(dir1 * dir2 == 0 || dir3 * dir4 == 0) return (onSegment(a1, b1, b2) || onSegment(a2, b1, b2));
	return false;
}

struct line {
	// Represents lines as ax + by + c = 0;
	ld a, b, c;
	line(ld _a, ld _b, ld _c) { a = _a, b = _b, c = _c; }
	//Initialize using Segment between 2 points
	line(point p, point q) { a = p.y - q.y, b = q.x - p.x, c = -(a * p.x) - (b * p.y); }
};

ld det(ld a, ld b, ld c, ld d) { return a * d - b * c; }

point intersect(line m, line n) {
		point res;
    ld zn = det(m.a, m.b, n.a, n.b);
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return res;
}

point intersectSegment(point a1, point a2, point b1, point b2){
	ll dir1 = signed_triangle_area(a1, b1, a2);
	ll dir2 = signed_triangle_area(a1, b2, a2);
	ll dir3 = signed_triangle_area(b1, a1, b2);
	ll dir4 = signed_triangle_area(b1, a2, b2);

	if(dir1 * dir2 == 0 || dir3 * dir4 == 0) 
		if(onSegment(a1, b1, b2)) return a1;
		else if(onSegment(a2, b1, b2)) return a2;

	return intersect(line(a1, a2), line(b1, b2));
}

struct polygon {
	vector<point> P, CH;
	ll n, B;
	ld A;

	polygon(ll _n){ n = _n, P = vector<point>(_n, point(0, 0)), A = B = -1; }
	polygon(vector<point> _P){ n = _P.size(), P = _P, A = B = -1; }
	polygon(point *_P, ll _n){ 
		for(ll i=0;i<n;i++) P.push_back(_P[i]);
		n = _n, A = B = -1;
	}

	ll size() { return n; }

	ld getArea(){
		if(A != -1) return A;
		A = 0;
		for(ll i=1;i<n;i++) A += signed_triangle_area(point(0, 0), P[i-1], P[i % n]);
		return A = abs(A);
	}
	// Only Works for Convex Polygons
	bool inside(point pt){
		ld tot = 0;
		for(ll i=1;i<=n;i++)
			tot += abs(signed_triangle_area(pt, P[i-1], P[i % n]));

		if(tot == getArea()) return 1;
		return 0;
	}
};

const ll N = 3010, M = 1e9 + 7;
ll n, m, q, dp[110][110];
vector<point> R, B;

void solve(){
		// Testing

		point w = point(4, 3);
		point x = point(10004, 10002);
		point y = point(0, 0);
		point z = point(5, 4);
		cout << doIntersectSegment(w, x, y, z) << "\n";

		// Testing Ends

		R.clear(); B.clear();
		cin >> n >> m;
		R = vector<point>(n);
		B = vector<point>(m);

		for(ll i=0;i<n;i++) cin >> R[i].x >> R[i].y;
		for(ll i=0;i<m;i++) cin >> B[i].x >> B[i].y;

		// cout << R << ' ' << B << '\n';

		for(ll i=0;i<n-1;i++)
			for(ll j=i+1;j<n;j++){
				cout << i + 1 << ' ' << j + 1 << '\n';
				vector<point> V;
				V = { point(0, 0), R[i], R[j] };
				polygon P(V);
				// cout << P.P << " ";
				dp[i][j] = 0;
				dp[j][i] = 0;
				for(ll k=0;k<m;k++)
					if(P.inside(B[k]))
						dp[i][j]++, dp[j][i]++;
				// cout << dp[i][j] << "\n";
			}

		for(ll i=0;i<n-1;i++)
			for(ll j=i+1;j<n;j++)
				cout << i + 1 << ' ' << j + 1 << " " << dp[i][j] << '\n';

		cin >> q;
		while(q--){
			ll k; cin >> k;
			vector<ll> Q(k);
			for(ll i=0;i<k;i++) cin >> Q[i];

			// cout << Q << "\n";

			ll tot = 0;
			for(ll i=0;i<k-1;i++){
					ll j = (i + 1);
					if(signed_triangle_area(point(0, 0), R[Q[i]-1], R[Q[j]-1]) < 0.0) tot += dp[Q[i]-1][Q[j]-1];
					else tot -= dp[Q[i]-1][Q[j]-1];
				}

			cout << abs(tot) << "\n";
		}
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}