#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    
    for(auto v : V) os << v + 1 << " ";
    
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
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

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, win[2010][2010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			win[i][j] = 0;
	for(ll i=0;i<n;i++){
		ll k; cin >> k;
		for(ll j=0;j<k;j++){
			ll l; cin >> l; l--;
			win[i][l] = 1;
		}
	}

	vector<ll> sol(1, 0);
	for(ll i=1;i<n;i++){
		if(win[sol.back()][i])
			sol.push_back(i);
		else if(win[i][sol[0]])
			sol.insert(sol.begin(), i);
		else
			for(ll j=0;j<n-1;j++)
				if(win[sol[j]][i] && win[i][sol[j+1]]){
					sol.insert(sol.begin() + j + 1, i);
					break;
				}
	}

	cout << "YES\n";
	cout << sol << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}