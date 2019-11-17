#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;

void te(){
	cin >> n;
	ll start = 0;

	for(ll i=0;i<n;i++){
		for(ll j=start;j>0;j-=2)
			cout << j << " ";
		for(ll j=0;j<=(n-1)*2-start;j+=2)
			cout << j << " ";
		cout << "\n";
		start += 2;
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