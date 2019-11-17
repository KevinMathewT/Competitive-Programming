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

ll n, m;
char a[2010][2010];

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			cin >> a[i][j];

	ll b[4][26];
	for(ll i=0;i<2;i++)
		for(ll j=0;j<26;j++)
			b[i][j] = LLONG_MAX;

	for(ll i=2;i<4;i++)
		for(ll j=0;j<26;j++)
			b[i][j] = LLONG_MIN;

	// for(ll i=0;i<n;i++){
	// 	for(ll j=0;j<m;j++){
	// 		if(a[i][j] != '.'){
	// 			b[0][a[i][j] - 'a'] = min(b[0][a[i][j] - 'a'], i);
	// 			b[1][a[i][j] - 'a'] = min(b[1][a[i][j] - 'a'], j);
	// 			b[2][a[i][j] - 'a'] = max(b[2][a[i][j] - 'a'], i);
	// 			b[3][a[i][j] - 'a'] = max(b[3][a[i][j] - 'a'], j);
	// 		}
	// 	}
	// 	// cout << "\n";
	// }

	for(ll i=26;i>=0;i--){
		for(ll j=0;j<n;j++){
			for(ll k=0;k<m;k++){
				if(a[j][k] == ('a' + i)){
					// cout << j << " " << k << "\n";
					b[0][a[j][k] - 'a'] = min(b[0][a[j][k] - 'a'], j);
					b[1][a[j][k] - 'a'] = min(b[1][a[j][k] - 'a'], k);
					b[2][a[j][k] - 'a'] = max(b[2][a[j][k] - 'a'], j);
					b[3][a[j][k] - 'a'] = max(b[3][a[j][k] - 'a'], k);
				}
			}
		}

			if(b[0][i] != b[2][i] && b[1][i] != b[3][i] && b[2][i] >= 0){
				cout << b[0][i] << " " << b[1][i] << " " << b[2][i] << " " << b[3][i] << "\n";
				cout << "NO1\n";
				return;
			}

			if(b[2][i] >= 0 && b[0][i] != b[2][i]){
				for(ll l=b[0][i];l<=b[2][i];l++){
					if(a[l][b[1][i]] != ('a' + i) && a[l][b[1][i]] != '$'){
				// cout << b[0][i] << " " << b[1][i] << " " << b[2][i] << " " << b[3][i] << "\n";
						cout << "NO\n";
						return;
					}
					a[l][b[1][i]] = '$';
				}
			}

			if(b[2][i] >= 0 && b[1][i] != b[3][i]){
				for(ll l=b[1][i];l<=b[3][i];l++){
					if(a[b[0][i]][l] != ('a' + i) && a[b[0][i]][l] != '$'){
				// cout << b[0][i] << " " << b[1][i] << " " << b[2][i] << " " << b[3][i] << "\n";
						cout << "NO\n";
						return;
					}
					a[b[0][i]][l] = '$';
				}
			}
		
	}

	// for(ll i=0;i<26;i++){
	// 	for(ll j=0;j<4;j++){
	// 		cout << b[j][i] << " ";
	// 	}
	// 	cout << "\n";
	// }

	for(ll i=0;i<26;i++){
		if(b[2][i] >= 0 && b[0][i] != b[2][i] && b[1][i] != b[3][i]){
			// cout << b[0][i] << " " << b[1][i] << " " << b[2][i] << " " << b[3][i] << "\n";
			cout << "NO\n";
			return;
		}
	}

	for(ll i=24;i>=0;i--){
		if(b[2][i] < 0){
			b[0][i] = b[0][i+1];
			b[1][i] = b[1][i+1];
			b[2][i] = b[2][i+1];
			b[3][i] = b[3][i+1];
		}
	}
	ll last = 0;
	for(ll i=0;i<26;i++){
		if(b[2][i] >= 0)
			last++;
	}


	// cout << last << "////////\n";

	if(last == 0){
		cout << "YES\n0\n";
		return;
	}


	cout << "YES\n";
	cout << last << "\n";

	for(ll i=0;i<26;i++){
		if(b[2][i] >= 0)
			cout << b[0][i] + 1 << " " << b[1][i] + 1 << " " << b[2][i] + 1 << " " << b[3][i] + 1 << "\n";
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}