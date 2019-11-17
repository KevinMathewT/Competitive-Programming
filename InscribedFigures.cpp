#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Shubham Kumar
// Birla Institute of Technology, Mesra

ll n, a[500];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll tot = 0;

	for(ll i=1;i<n;i++){
		if(a[i-1] == 1 && a[i] == 2) tot += 3;
		if(a[i-1] == 2 && a[i] == 1) tot += 3;
		if(a[i-1] == 3 && a[i] == 1) tot += 4;
		if(a[i-1] == 1 && a[i] == 3) tot += 4;
		if(a[i-1] == 2 && a[i] == 3) { tot = -1; break; }
		if(a[i-1] == 3 && a[i] == 2) { tot = -1; break; }
	}

	if(tot == -1){
		cout << "Infinite\n";
	}
	else
		cout << "Finite\n" << tot << "\n";
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