#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll a[(ll)1e3][2], n, k;

ll recur(ll x, ll y, ll a){
	if(x >= n || y >= n) return 0;
	if(a == 1){
		// cout << x << " " << y << " " << a << "\n";
		return 1;
	}
	// return (recur(x+1, 1-y, a-1) + recur(x+2, 1-y, a-1) + recur(x+2, y, a-1));
	ll sum = recur(x+1, 1-y, a-1);
	for(ll i=x+2;i<n;i++)
		sum += recur(i, y, a-1) + recur(i, 1-y, a-1);
	return sum;
}

// ll recur(ll x, ll a){
// 	if(x >= n) return 0;
// 	if(a == 1){
// 		// cout << x << " " << y << " " << a << "\n";
// 		return 1;
// 	}
// 	// return (recur(x+1, 1-y, a-1) + recur(x+2, 1-y, a-1) + recur(x+2, y, a-1));
// 	ll sum = recur(x+1, a-1);
// 	for(ll i=x+2;i<n;i++)
// 		sum += 2 * recur(i, a-1);
// 	return sum;
// }

void te(){
	cin >> n >> k;
	ll a[200][200];
	for(ll i=1;i<=10;i++){
		for(ll j=1;j<=i;j++){
			n = i;
			k = j;
			ll sum = 0;
			for(ll i=0;i<n;i++)
				sum += recur(i, 0, k) + recur(i, 1, k);
			
				// sum += (recur(i, 0, k) + recur(i, 1, k));
			cout << sum << "\t";
			a[i][j] = sum;
		}
		cout << "\n";
	}

	// for(ll i=1;i<=5;i++){
	// 	for(ll j=i+1;j<=5;j++)
	// 		cout << a[j][i] << ",";
	// 	cout << "\n";
	// }
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}