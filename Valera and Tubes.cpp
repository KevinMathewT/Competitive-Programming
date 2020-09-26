#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll j=(a);j>=b;j--)

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

const ll N = 310, M = 1e9 + 7;
ll n, m, k, T[N][N];

void next(ll &a, ll &b) {
	if(a == -1 && b == -1) a = 0, b = 0; 
	else if(b == m - 1 && a % 2 == 0 || b == 0 && a % 2 == 1) a++;
	else if(a % 2 == 0) b++;
	else b--;
}

void solve(){
	cin >> n >> m >> k;
	ll sx = 0, sy = 0;
	fi(0, n - 1) fj(0, m - 1) T[i][j] = 0;
	ll dec = 0;
	ll left = k - 1;

	ll lastx = -1, lasty = -1, taken = 0;

	fi(0, n - 1) {
		if(left == 0) break;
		if(i % 2 == 0) {
			for(ll j=0;j + 1<m;j+=2) {
				if(left == 0) break;
				cout << 2 << ' ';
				cout << i + 1 << ' ' << j + 1 << " ";
				cout << i + 1 << ' ' << j + 2 << "\n";
				taken += 2;
				T[i][j] = k - left;
				T[i][j + 1] = k - left;
				lastx = i; lasty = j + 1;
				left--;
			}

			if(left == 0) break;
			if(m % 2 == 1) {
				T[i][m - 1] = k - left;
				T[i + 1][m - 1] = k - left;
				cout << 2 << ' ';
				cout << i + 1 << ' ' << m << " ";
				cout << i + 2 << ' ' << m << "\n";
				taken += 2;
				lastx = i + 1; lasty = m - 1;
				left--;
			}
		}	else {
			for(ll j=m % 2 == 0 ? m - 1 : m - 2;j > 0;j-=2) {
				if(left == 0) break;
				T[i][j] = k - left;
				T[i][j - 1] = k - left;
				cout << 2 << ' ';
				cout << i + 1 << ' ' << j + 1 << " ";
				cout << i + 1 << ' ' << j << "\n";
				taken += 2;
				lastx = i; lasty = j - 1;
				left--;
			}

			if(left == 0) break;
		}		
	}

	// fi(0, n - 1) {
	// 	fj(0, m - 1) cout << T[i][j] << ' ';
	// 	cout << "\n";
	// }

	next(lastx, lasty);
	lastx++;
	lasty++;

	cout << n * m - taken << " ";
	fi(lastx, n) {
		if(i % 2 == 1) fj(i == lastx ? lasty : 1, m) cout << i << " " << j << " ";
		else fjd(i == lastx ? lasty : m, 1) cout << i << " " << j << " ";
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