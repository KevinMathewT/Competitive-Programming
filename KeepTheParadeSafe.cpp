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
bool onSegment(point a, point s1, point s2){
	return signed_triangle_area(a, s1, s2) == 0 && a.x >= min(s1.x, s2.x) && a.x <= max(s1.x, s2.x) && a.y >= min(s1.y, s2.y) && a.y <= min(s1.y, s2.y);
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

const ll N = 1, M = 1e9 + 7;
ll n, m;

void solve(){
	cin >> n;
	vector<point> _N(n);
	for(ll i=0;i<n;i++) cin >> _N[i].x >> _N[i].y;
	polygon N(_N);

	vector<point> _CH = N.getConvexHull();
	polygon CH(_CH);

	// cout << _CH << "\n";

	cin >> m;
	vector<point> _S(m);
	for(ll i=0;i<m;i++) cin >> _S[i].x >> _S[i].y;

	if(_CH.size() < 3){
		cout << 0 << "\n";
		return;
	}

	if(_CH.size() == 3){
		for(ll i=1;i<_CH.size()-1;i++)
				if(onSegment(_CH[i], _CH[i-1], _CH[i+1])){
					cout << 0 << "\n";
					return;
				}
	}

	ll tot = 0;
	for(auto pt : _S) if(CH.inside(pt)) tot++;
	// for(auto pt : _S) for(ll i=1;i<=_CH.size();i++) if(onSegment(pt, _CH[i-1], _CH[i % _CH.size()])) tot++;

	cout << tot << "\n";
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