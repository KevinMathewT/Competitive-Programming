#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n = 10, x;

void te(){
	ll tot = 0;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			cin >> x;
			if(x <= 30)
				tot++;
		}


	if(tot >= 60)
		cout << "yes\n";
	else
		cout << "no\n";
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