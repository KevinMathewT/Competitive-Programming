#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	string s;
	cin >> s;

	ll n;
	cin >> n;
	ll a[n], b[n];

	for(ll i=0;i<n;i++)
		cin >> a[i] >> b[i];

	ll size = ceil((ld)(sqrt(s.size())));

	char mat[size][size];

	for(ll i=0;i<size;i++)
		for(ll j=0;j<size;j++)
			if((((i)*size)+(j)) > s.size()-1)
				mat[i][j] = '_';
			else
				mat[i][j] = s[(((i)*size)+(j))];

	for(ll i=0;i<size;i++){
		for(ll j=0;j<size;j++)
			cout << mat[i][j];
		cout << "\n";
	}

	char (*ptr)[size][size];

	for(ll i=0;i<size;i++)
		ptr[i] = &mat[i];

	for(ll i=0;i<n;i++){
		a--;
		b--;

		char *t = ptr[a];
		ptr[a] = ptr[b];
		ptr[b] = ptr[a];
	}

	for(ll i=0;i<size;i++)
		for(ll j=0;j<size;j++)
			if(ptr[i][j] != '_')
				cout << ptr[i][j];
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