#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, m, c, M;

ll power(ll x, ll a){
	x = x % M;
	if(a == 0) return 1;
	if(a == 1) return x;
	if(a % 2 == 0) return power((x * x) % M, a / 2);
	else return ((x * (power((x * x) % M, a / 2))) % M);
}

// void rec(ll n, ll m, ll c){
// 	ll tot = 0, c = 0, ans = power(c, n * n * m);
// 	for(ll i=0;i*i<=m;i++)
// 		if(m % i == 0)
// 			c++;
// 	if(c == 2)
// 		return ((((((power(c, n * n * m) - power(c, n * n) + M) % M) * (power(m, M - 2))) % M) + power(c, n * n)) % M);

// 	for(ll i=0;i*i<m;i++){
// 		if(m % i == 0){
// 			tot = (tot + power(c, n * n * i)) % M;
// 			tot = (tot + power(c, n * n * (m / i))) % M;
// 			ans = (((ans - rec(n, i, c)) % M) + M) % M;
// 			ans = (((ans - rec(n, m / i, c)) % M) + M) % M;
// 		}
// 	}


// }

void solve(){
	M = 1e9 + 7;
	cin >> n >> m >> c;
	
	cout << ((((((power(c, n * n * m) - power(c, n * n) + M) % M) * (power(m, M - 2))) % M) + power(c, n * n)) % M) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}