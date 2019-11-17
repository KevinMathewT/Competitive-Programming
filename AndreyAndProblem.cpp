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

ll n;
ld a[100];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	sort(a, a + n);
	ld probability = 0.0;
	
	if(a[n-1] == 1){
		cout << 1.0 << "\n";
		return;
	}
	
	ld ans = 0;
   	ld s = 0;
   	ld c = 1;
   	ll j = n-1;
   	while((s < 1) && (j >= 0))
   	{
    	c *= (1 - a[j]);
       	s += (a[j]) / (1 - a[j]);
       	j--;
   	}
   	cout << setprecision(9) << (c * s);
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	cout << fixed << setprecision(9);

	solve();

	return 0;
}