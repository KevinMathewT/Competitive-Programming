#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll a = 10;
	for(ll i=1;i<a;i++)
		cout << (i*i-i) * (((a-i)*(a-i)) - (a-i)) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// cout << "skdklkjsd\n";
	te();

	return 0;
}