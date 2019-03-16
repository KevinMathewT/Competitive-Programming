#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll l, r, n1, n2;

void te(){
	cin >> l >> r >> n1 >> n2;
	if(n1 == 9)
		n1 == 0;
	if(n2 == 9)
		n2 = 0;

	ll x1, x2;
	x1 = x2 = 0;

	x1 = 

	if(x1 > x2)
		cout << "Onkar\n";
	else if(x2 > x1)
		cout << "Krushna\n";
	else
		cout << "Draw\n";
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
		te();

	return 0;
}