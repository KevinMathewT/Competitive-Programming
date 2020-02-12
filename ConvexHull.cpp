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
	point operator+=(const point& _P){ x += _P.x, y += _P.y; return *this; }
	point operator-=(const point& _P){ x -= _P.x, y -= _P.y; return *this; }
	point operator+(const point& _P){ return point(*this) += _P; }
	point operator-(const point& _P){ return point(*this) -= _P; }
	bool operator==(const point& _P){ return point(*this).x == _P.x && point(*this).y == _P.y; }
};

ostream& operator<<(ostream &os, point P){
	return os << "(" << P.x << ", " << P.y << ")";
}

ld cross(point a, point b){
	return a.x * b.y - a.y * b.x;
}

bool clockwise(point a, point b, point c){
	return cross(b - a, c - b) < 0;
}

bool anti_clockwise(point a, point b, point c){
	return cross(b - a, c - b) > 0;
}

bool comp(point p1, point p2){
	if(p1.x == p2.x) return p1.y < p2.y;
	return p1.x < p2.x;
}

struct polygon{
	ll n;
	vector<point> P, CH;
	polygon(vector<point> _P){ P = _P, n = _P.size(); }

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
ll n;

void solve(){
	cin >> n;
	if(n == 0) exit(0);

	vector<point> _P(n);
	for(ll i=0;i<n;i++) cin >> _P[i].x >> _P[i].y;
	polygon P(_P);
	vector<point> CH = P.getConvexHull();
	cout << CH.size() << "\n";
	for(auto it : CH) cout << it.x << ' ' << it.y << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	while(true)
		solve();

	return 0;
}