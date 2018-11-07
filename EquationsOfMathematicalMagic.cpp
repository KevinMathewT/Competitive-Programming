#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll a;
	cin >> a;

	for(ll j=0;j<50;j++){
	a = j;
	ll c = 0;
	for(ll i=0;i<=a+10;i++)
		if((a - (a ^ i) - i) >= 0)
			c++;
	cout << a << " " << c << "\n";
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
	while(T--)
		te();

	return 0;
}