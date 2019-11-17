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

ll fact(ll n){
	ll c = 0;
	for(ll i=1;i<=n;i++)
		if(n % i == 0)
			c++;

	return c;
}

void solve(){
	for(ll i=1;i<100;i++)
		for(ll j=1;j<100;j++){
			if((fact(i) * fact(j)) == fact(i * j))
				cout << i << " " << j << " " << fact(i) << " " << fact(j) << " " << fact(i * j) << "\n";
		}	
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment[-]
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}