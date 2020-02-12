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

const ll N = 1, M = 1e9 + 7;
ld x1, x2, y3, y2, v1, v2;

ld dist(ld x1, ld y3, ld x2, ld y2){
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y3, 2));
}

void solve(){
	cin >> x1 >> y3 >> x2 >> y2 >> v1 >> v2;

	ld t = 0;

	if(y3 >= 0 && y2 >= 0){
		t = dist(x1, y3, x2, y2) / v2;
	}

	else if(y3 <= 0 && y2 <= 0){
		t = dist(x1, y3, x2, y2) / v1;
	}

	else if(y3 <= 0 && y2 >= 0){
		t = LLONG_MAX;
		ld l = min(x1, x2), r = max(x1, x2);

		for(ll i=0;i<100000;i++){
			ld m = (l + r) / 2;
			ld m2 = m + 0.00001;

			ld val1 = dist(x1, y3, m, 0.0) / v1 + dist(x2, y2, m, 0.0) / v2;
			ld val2 = dist(x1, y3, m2, 0.0) / v1 + dist(x2, y2, m2, 0.0) / v2;

			t = min(t, val1);

			if(val1 <= val2)
				r = m;
			else l = m2;
		}
	}

	else{
		t = LLONG_MAX;
		ld l = min(x1, x2), r = max(x1, x2);

		for(ll i=0;i<100000;i++){
			ld m = (l + r) / 2;
			ld m2 = m + 0.00001;

			ld val1 = dist(x1, y3, m, 0.0) / v2 + dist(x2, y2, m, 0.0) / v1;
			ld val2 = dist(x1, y3, m2, 0.0) / v2 + dist(x2, y2, m2, 0.0) / v1;

			t = min(t, val1);

			if(val1 <= val2)
				r = m;
			else l = m2;
		}
	}

	cout << fixed << setprecision(5);
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