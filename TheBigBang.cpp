#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

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

ll n, a, q, x, arr[100];

void solve(){
	cin >> n >> a >> q;

	arr[0] = a;
	ll s = 1;
	while(true){
		if((s % 2) == 0)
			arr[s] = 2 * (arr[s-1] + arr[s-2]);
		else
			arr[s] = 3 * arr[s-1];
		if(arr[s] > (1e18) || s == n)
			break;
		s++;
	}

	while(q--){
		cin >> x;
		ll c = 0;

		for(ll i=0;i<s-2;i++){
			for(ll j=i+1;j<s-1;j++)
				for(ll k=j+1;k<s;k++)
					if((x % (arr[i] + arr[j] + arr[k])) == 0){
						c++;
					}
		}

		cout << c << "\n";
	}
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