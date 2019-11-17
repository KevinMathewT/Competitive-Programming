#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Shubham Kumar
// Birla Institute of Technology, Mesra

ll n;
char board[100][100];

void te(){
	cin >> n;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			cin >> board[i][j];

	for(ll i=0;i<=n+1;i++)
		board[i][0] = '#';
	for(ll i=0;i<=n+1;i++)
		board[0][i] = '#';
	for(ll i=0;i<=n+1;i++)
		board[i][n+1] = '#';
	for(ll i=0;i<=n+1;i++)
		board[n+1][i] = '#';

	for(ll j=1;j<=n;j++){
		for(ll i=j;i<=n-j+1;i++)
			if(board[j][i] == '.'){
				if(!(board[j+1][i] == '.' && board[j+1][i-1] == '.' && board[j+1][i+1] == '.' && board[j+2][i] == '.')){
					cout << "NO1\n";
					return;
				}
				board[j][i] = '#';
				board[j+1][i] = '#';
				board[j+1][i-1] = '#';
				board[j+1][i+1] = '#';
				board[j+2][i] = '#';
			}

		for(ll i=0;i<=n;i++){
			for(ll k=0;k<=n;k++)
				cout << board[i][k];
			cout << "\n";
		}
		cout << "\n\n\n";
		
		for(ll i=j;i<=n-j+1;i++)
			if(board[i][j] == '.'){
				if(!(board[i][j+1] == '.' && board[i-1][j+1] == '.' && board[i+1][j+1] == '.' && board[i][j+2] == '.')){
					cout << "NO2 " << i << " " << j << "\n";
					return;
				}
				board[j][i] = '#';
				board[i][j+1] = '#';
				board[i-1][j+1] = '#';
				board[i+1][j+1] = '#';
				board[i][j+2] = '#';
			}
		
		for(ll i=0;i<=n;i++){
			for(ll k=0;k<=n;k++)
				cout << board[i][k];
			cout << "\n";
		}
		cout << "\n\n\n";
	}

	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(board[i][j] == '.'){
				cout << "NO\n";
				return;
			}

	cout << "YES\n";
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