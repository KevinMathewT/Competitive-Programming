#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll r, c;
	cin >> r >> c;

	char pasture[r][c];

	for(ll i=0;i<r;i++)
		for(ll j=0;j<c;j++)
			cin >> pasture[i][j];

	for(ll i=0;i<r;i++)
		for(ll j=0;j<c;j++){
			if(pasture[i][j] == 'S'){
				if(pasture[i+1][j] == 'W' || pasture[i-1][j] == 'W' || pasture[i][j+1] == 'W' || pasture[i][j-1] == 'W'){
					cout << "NO\n";
					return;
				}
			}
		}

	cout << "YES\n";

	for(ll i=0;i<r;i++){
		for(ll j=0;j<c;j++)
			if(pasture[i][j] == '.')
				cout << 'D';
			else
				cout << pasture[i][j];
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

	te();

	return 0;
}