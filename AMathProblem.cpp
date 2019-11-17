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

ll powera(ll a, ll x){
	if(x == 0) return 1;
	if(x == 1) return x;
	if(x % 2 == 0) return pow((a * a), x / 2);
	else return (a * pow((a * a), x / 2));
}

ll n;

void solve(){
	ll c = 0;
	for(ll i=1;i<1000;i++)
		if(powera(i, i) <= n && powera(i, i) > 0)
			c++;
		else
			break;

	cout << c << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	
	while(cin >> n)
		solve();

	return 0;
}