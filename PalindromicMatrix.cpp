#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, freq[1010], a[410], final[30][30], vis[30][30];

void te(){
	cin >> n;
	for(ll i=0;i<n*n;i++)
		cin >> a[i];
	for(ll i=0;i<1010;i++)
		freq[i] = 0;

	for(ll i=0;i<30;i++)
		for(ll j=0;j<30;j++)
			vis[i][j] = 0;

	ll SZ = (n * n);
	sort(a, a+(n*n));

	for(ll i=0;i<n*n;i++)
		freq[a[i]]++;

	ll flag = 1;
	if(n % 2 == 0)
		flag = 0;

	for(ll i=1;i<=1000;i++){
		if(freq[i] >= 4){
			// cout << i << " " << freq[i] << "\n";
			for(ll j=0;j<n;j++){
				for(ll k=0;k<n;k++){
					if((j == n-1-j) || (k == n-1-k) || vis[j][k] == 1)
						continue;

					// cout << j << " " << k << "--\n";

					final[j][k] = i;
					final[n-1-j][k] = i;
					final[j][n-1-k] = i;
					final[n-1-j][n-1-k] = i;

					vis[j][k] = 1;
					vis[n-1-j][k] = 1;
					vis[j][n-1-k] = 1;
					vis[n-1-j][n-1-k] = 1;

					freq[i] -= 4;
					if(freq[i] < 4)
						break;
				}
				if(freq[i] < 4)
					break;
			}

			// cout << i << " " << freq[i] << "\n";
		}
	}

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			if(((i != n-1-i) && (j != n-1-j)) && vis[i][j] != 1){
				// cout << i << " " << j << " " << n-1-j << "-\n";
				cout << "NO\n";
				return;
			}
		}

	// for(ll i=0;i<n;i++){
	// 	for(ll j=0;j<n;j++)
	// 		cout << final[i][j] << " ";
	// 	cout << "\n";
	// }

	// cout << "---------------\n";
	for(ll i=1;i<=1000;i++){
		if(freq[i] >= 2){
			for(ll j=0;j<n;j++){
				for(ll k=0;k<n;k++){
					if((j == n-1-j && k == n-1-k) || vis[j][k] == 1)
						continue;

					if(j == n-1-j){
						final[j][k] = i;
						final[j][n-1-k] = i;
						vis[j][k] = 1;
						vis[j][n-1-k] = 1;
					}

					if(k == n-1-k){
						final[j][k] = i;
						final[n-1-j][k] = i;
						vis[j][k] = 1;
						vis[n-1-j][k] = 1;

					}

					freq[i] -= 2;
					if(freq[i] < 2)
						break;
				}
				if(freq[i] < 2)
					break;
			}
		}
	}

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			if((i != n-1-i && j != n-1-j) && vis[i][j] != 1){
				cout << "NO\n";
				return;
			}
		}

	for(ll i=1;i<=1000;i++){
		if(freq[i] == 1){
			if(n % 2 == 1){
				final[n/2][n/2] = i;
				vis[n/2][n/2] = 1;
				freq[i]--;
				break;
			}
		}
	}

	for(ll i=0;i<=1000;i++)
		if(freq[i] != 0){
			cout << "NO\n";
			return;
		}
	
	// for(ll i=0;i<n;i++){
	// 	for(ll j=0;j<n;j++)
	// 		cout << final[i][j] << " ";
	// 	cout << "\n";
	// }

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			if(vis[i][j] != 1){
				cout << "NO\n";
				return;
			}
		}
	
	cout << "YES\n";
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++)
			cout << final[i][j] << " ";
		cout << "\n";
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}