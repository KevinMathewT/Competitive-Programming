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

ll n, a[100010], b[100010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	sort(a, a + n);

	b[n-1] = a[n-1];
	b[0] = a[n-2];
	b[n-2] = a[n-3];

	ll i = 1, j = n - 3, k = n - 4;

	while(i < j){
		b[i++] = a[k--];
		if(k >= 0)
			b[j--] = a[k--];
		else
			break;
	}

	for(ll i=0;i<n;i++){
		if(b[i] >= (b[(i-1+n) % n] + b[(i+1) % n])){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";

	for(ll i=0;i<n;i++){
		cout << b[i] << " ";
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