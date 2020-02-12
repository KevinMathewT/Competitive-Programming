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

const ld PR = 1e-4, INF = 1e6;

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
	bool operator==(const point& _P){ return point(*this).x == _P.x && point(*this).y == _P.y; }
};

ostream& operator<<(ostream &os, point P) {
    os << "(" << P.x << ", " << P.y << ")";
    return os;
}


bool comp(point p1, point p2){
	if(p1.x == p2.x) return p1.y < p2.y;
	return p1.x < p2.x;
}
ld det(ld a, ld b, ld c, ld d) { return a * d - b * c; }
ld dist(point a, point b) { return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y))); }
ld abs(point a) { return sqrt((a.x * a.x) + (a.y * a.y)); }
ld dot(point a, point b) { return (a.x * b.x + a.y * b.y); }
ld proj(point a, point b) { return dot(a, b) / abs(b); }
ld angle(point a, point b) { return acos(dot(a, b) / (abs(a) * abs(b))); }
ld angle(point a) { return angle(a, point(1, 0)); }
// ld angle(point a, point b, point c) { return  }
ld cross(point a, point b) { return a.x * b.y - a.y * b.x; }

// Triangle Related
ld parallelogram_area(point a, point b, point c){
	return cross(b - a, c - b);
}
ld signed_triangle_area(point a, point b, point c){
	return parallelogram_area(a, b, c) / 2;
}
ld triangle_area(point a, point b, point c){
	return abs(parallelogram_area(a, b, c)) / 2;
}
bool clockwise(point a, point b, point c){
	return parallelogram_area(a, b, c) < 0;
}
bool anti_clockwise(point a, point b, point c){
	return parallelogram_area(a, b, c) > 0;
}
bool collinear(point a, point b, point c){
	return parallelogram_area(a, b, c) == 0;
}

struct line {
	// Represents lines as ax + by + c = 0;
	ld a, b, c;
	line(ld _a, ld _b, ld _c) { a = _a, b = _b, c = _c; }
	//Initialize using Segment between 2 points
	line(point p, point q) { a = p.y - q.y, b = q.x - p.x, c = -(a * p.x) - (b * p.y); }
};
bool satisfy(point p, line l){ return (l.a * p.x + l.b * p.y + l.c == 0); }
// bool parallel(line l1, line l2){
// 	return det(l1.a, l1. b, l2.a, l2.b) < PR;
// }
// bool equivalent(line l1, line l2){
// 	return (l2.a / l1.a == l2.b / l1.b && l2.c / l1.c == l2.b / l1.b);
// }
point intersect(line m, line n) {
		point res;
    ld zn = det(m.a, m.b, n.a, n.b);
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return res;
}

bool parallel(line m, line n) {
    return abs(det(m.a, m.b, n.a, n.b)) < PR;
}

bool equivalent(line m, line n) {
    return abs(det(m.a, m.b, n.a, n.b)) < PR
        && abs(det(m.a, m.c, n.a, n.c)) < PR
        && abs(det(m.b, m.c, n.b, n.c)) < PR;
}

ostream& operator<<(ostream &os, line L) {
    os << "(" << L.a << "x + " << L.b << "y + " << L.c << ") ";
    return os;
}

// Segment - TBD
bool onSegment(point P, point a, point b){
	if((P.x >= min(a.x, b.x) && P.x <= max(a.x, b.x)) && (P.y >= min(a.y, b.y) && P.y <= max(a.y, b.y))) return true;
	return false;
}

//Polygon
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
		for(ll i=1;i<=n;i++)
			A += parallelogram_area(point(0, 0), P[i-1], P[i % n]) / 2;
		return A = abs(A);
	}

	ll border(){
		if(B != -1) return B;
		B = n;
		for(ll i=1;i<=n;i++)
			B += abs(__gcd((ll) (P[i-1].x - P[i % n].x), (ll) (P[i-1].y - P[i % n].y))) - 1;
		return B = abs(B);
	}

	// A = I + B / 2 - 1
	ll lattice(){
		return getArea() - (border() / 2) + 1;
	}

	// Works only for Convex Polygons
	bool inside(point pt){
		ld tot = 0;
		for(ll i=1;i<=n;i++)
			tot += abs(triangle_area(pt, P[i-1], P[i % n]));

		if(tot == getArea()) return 1;
		return 0;
	}

	vector<point> getConvexHull(){
		CH = P;

		sort(CH.begin(), CH.end(), comp);
		point A = CH[0], B = CH.back();
		vector<point> up(1, A), down(1, A);

		for(ll i=1;i<CH.size();i++){
			if(i == CH.size() - 1 || clockwise(A, CH[i], B)){
				while(up.size() >= 2 && !clockwise(up[up.size() - 2], up.back(), CH[i])) up.pop_back();
				up.push_back(CH[i]);
			}

			if(i == CH.size() - 1 || anti_clockwise(A, CH[i], B)){
				while(down.size() >= 2 && !anti_clockwise(down[down.size() - 2], down.back(), CH[i])) down.pop_back();
				down.push_back(CH[i]);
			}
		}

    CH.clear();
    for (ll i = up.size() - 1; i >= 0; i--)
        CH.push_back(up[i]);
    for (ll i = 1; i < down.size() - 1; i++)
        CH.push_back(down[i]);

    if(CH.size() == 2 && CH[0] == CH[1]) CH.pop_back(); 

		return CH;
	}
};

void solve(){
	point a(6, 0);
	point b(3, 4);
	cout << a + b << "\n";
	cout << a << "\n";
	cout << b << "\n";
	cout << b * 4 << "\n";
	cout << b << "\n";
	cout << dot(a, b) << "\n";
	cout << abs(b) << ' ' << b.abs() << "\n";
	cout << angle(a, b) << " " << angle(a) << "\n";
	cout << parallel(line(point(0, 1), point(2, 3)), line(point(1, 1), point(3, 3))) << "\n";
	cout << line(a, b) << "\n";

	point a1(2, 4);
	point a2(4, 2);
	point b1(1, 4);
	point b2(4, 2);
	cout << intersect(line(a1, a2), line(b1, b2)) << "--\n";

	cout << "--------------\n";

	point c1(0, 0);
	point c2(0, 4);
	point c3(-5, 0);
	point c4(7, 0);

	cout << doIntersectSegment(c1, c2, c3, c4) << "\n";
	cout << intersectSegment(c1, c2, c3, c4) << "\n";

	cout << "--------------\n";

	ll n;
	cin >> n;
	vector<point> P(n);
	for(ll i=0;i<n;i++){
		cin >> P[i].x >> P[i].y;
	}
	polygon p(P);
	point in; cin >> in.x >> in.y;
	cout << p.getArea() << "\n";
	cout << p.lattice() << "\n";
	cout << p.inside(in) << "\n";
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