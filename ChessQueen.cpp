#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll a, b, c, d;

void te(){
	cin >> a >> b >> c >> d;
	if(a == c || b == d || (abs(a-c)) == (abs(b - d)))
		cout << "Dead\n";
	else
		cout << "Alive\n";
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