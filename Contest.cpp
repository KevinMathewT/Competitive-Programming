#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	double a, b, c, d; cin >> a >> b >> c >> d;

	if(max((3*a/10), a - (a*c/250)) < max((3*b/10), b - (b*d/250)))
		cout << "Vasya\n";
	else if(max((3*a/10), a - (a*c/250)) > max((3*b/10), b - (b*d/250)))
		cout << "Misha\n";
	else
		cout << "Tie\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}