#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	ll alice = 0, bob = 0;

	for(ll i=0;i<n;i++){
		ll u;
		cin >> u;
		if(i % 2 == 0){
			if(u < 4)
				alice += 2;
			else
				bob += 1;
		}
		else{
			if(u > 3)
				bob += 2;
			else
				alice += 1;
		}
	}

	if(alice > bob)
		cout << "Alice\n";
	else if(bob > alice)
		cout << "Bob\n";
	else
		cout << "Draw\n";
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