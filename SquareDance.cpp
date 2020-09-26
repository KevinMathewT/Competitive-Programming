#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll i=(a);i>=b;j--)

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

const ll N = 110, M = 1e9 + 7;
ll n, m, a[N][N], t[N][N];

void solve(ll cs){
	cin >> n >> m;
	fi(0, n - 1) fj(0, m - 1) cin >> a[i][j];

	ll interest = 0;

	ll zh = 0;

	while(true) {
		ll curr = 0;
		fi(0, n - 1) fj(0, m - 1) curr += a[i][j];
		if(curr == 0) break;
		fi(0, n - 1) fj(0, m - 1) interest += a[i][j];
		ld changes = 0;
		fi(0, n - 1) fj(0, m - 1) t[i][j] = a[i][j];
		fi(0, n - 1) {
			fj(0, m - 1) {
				ll l = 0, r = 0, u = 0, d = 0;
				for(ll k=i+1;k<=n-1;k++) if(a[k][j] != 0) {l = a[k][j]; break; }
				for(ll k=i-1;k>=0;k--) if(a[k][j] != 0) {r = a[k][j]; break; }
				for(ll k=j+1;k<=m-1;k++) if(a[i][k] != 0) {d = a[i][k]; break; }
				for(ll k=j-1;k>=0;k--) if(a[i][k] != 0) {u = a[i][k]; break; }

				ld avg;
				if(((l != 0) + (r != 0) + (u != 0) + (d != 0) + 0.0) == 0) avg = 0;
				else avg = (l + r + u + d) / ((l != 0) + (r != 0) + (u != 0) + (d != 0) + 0.0);

				// cout << l << ' ' << r << ' ' << u << ' ' << d << "\n";

				if((a[i][j] + 0.0) < avg && a[i][j] != 0) t[i][j] = 0, changes++;
				// cout << avg << ' ';
			}
			// cout << "\n";
		}

		fi(0, n - 1) fj(0, m - 1) a[i][j] = t[i][j];
		if(changes == 0) break;
	}

	cout << "Case #" << cs << ": " << interest << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	fi(1, T)
		solve(i);

	return 0;
}