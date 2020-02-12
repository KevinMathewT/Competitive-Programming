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

const ll N = 100, M = 1e9 + 7;
ll a, b, c, d, n, x[N];
char M1[N][N], M2[N][N];

void solve(){
	cin >> a >> b >> c >> d >> n;
	for(ll i=0;i<n;i++) cin >> x[i];

	ll tot = (a * b) + (c * d);
		
	char fill = 'a';
	ll cu = 0;
	if(a % 2 == 0){
		for(ll i=0;i<a;i++){
			for(ll j=0;j<b;j++){
				M1[j][i] = fill, x[cu]--;
				if(x[cu] == 0) cu++, fill++;
			}

			i++;
			if(i >= a) break;

			for(ll j=b-1;j>=0;j--){
				M1[j][i] = fill, x[cu]--;
				if(x[cu] == 0) cu++, fill++;
			}
		}

		for(ll i=0;i<c;i++){
			for(ll j=0;j<d;j++){
				M2[j][i] = fill, x[cu]--;
				if(x[cu] == 0) cu++, fill++;
			}

			i++;
			if(i >= c) break;
			
			for(ll j=d-1;j>=0;j--){
				M2[j][i] = fill, x[cu]--;
				if(x[cu] == 0) cu++, fill++;
			}
		}
	}
	else{
		for(ll i=0;i<a;i++){
			for(ll j=b-1;j>=0;j--){
				M1[j][i] = fill, x[cu]--;
				if(x[cu] == 0) cu++, fill++;
			}

			i++;
			if(i >= a) break;

			for(ll j=0;j<b;j++){
				M1[j][i] = fill, x[cu]--;
				if(x[cu] == 0) cu++, fill++;
			}
		}

		for(ll i=0;i<c;i++){
			for(ll j=0;j<d;j++){
				M2[j][i] = fill, x[cu]--;
				if(x[cu] == 0) cu++, fill++;
			}

			i++;
			if(i >= c) break;
			
			for(ll j=d-1;j>=0;j--){
				M2[j][i] = fill, x[cu]--;
				if(x[cu] == 0) cu++, fill++;
			}
		}
	}

	cout << "YES\n";
	for(ll i=0;i<max(b, d);i++){
		for(ll j=0;j<a;j++) if(i >= b) cout << "."; else cout << M1[i][j];
		for(ll j=0;j<c;j++) if(i >= d) cout << "."; else cout << M2[i][j];
		cout << "\n";
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