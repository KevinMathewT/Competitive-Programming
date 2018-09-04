#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

const ll SUM = 1e5+100;
ll a[110];
bool dpforw[110][(int)SUM];
bool dpback[110][(int)SUM];

void te(){
	// cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	ll n;
	cin >> n; 
	for(ll i=0;i<n;i++) cin >> a[i];

	for(ll i=0;i<=n;i++)
		for(ll j=0;j<SUM;j++){
			dpforw[i][j] = false;
			dpback[i][j] = false;
		}

	for(ll i=0;i<=n;i++){
		dpforw[i][0] = 1;
	}

	// cout << dpforw[1][0] << "\\\\\\\\\\\n";

	for(ll i=1;i<SUM;i++){
		dpforw[0][i] = false;
	}
	// cout << "\n";

	// cout << dpforw[1][0] << "\\\\\\\\\\\n";

	// for(ll i=0;i<=n;i++){
	// 	for(ll j=0;j<10;j++){
	// 		cout << dpforw[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	ll c;
	for(ll i=1;i<=n;i++){
		c = 0;
		for(ll j=1;j<=SUM;j++){
			if(j < a[i-1])
				dpforw[i][j] = dpforw[i-1][j];
			else
				dpforw[i][j] = dpforw[i-1][j] || dpforw[i-1][j-a[i-1]];
			if(dpforw[i][j])
				c++;
		}
		if(c >= 2){
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";

	for(ll i=0;i<=n;i++){
		for(ll j=0;j<15;j++){
			cout << dpforw[i][j] << " ";
		}
		cout << "\n";
	}
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
	for(ll i=0;i<T;i++)
		te();

	return 0;
}