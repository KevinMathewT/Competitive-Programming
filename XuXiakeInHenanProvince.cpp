#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a, b, c, d;

void te(){
	cin >> a >> b >> c >> d;
	ll s = 0;

	if(a > 0) s++;
	if(b > 0) s++;
	if(c > 0) s++;
	if(d > 0) s++;

	if(s == 0) cout << "Typically Otaku\n";
	if(s == 1) cout << "Eye-opener\n";
	if(s == 2) cout << "Young Traveller\n";
	if(s == 3) cout << "Excellent Traveller\n";
	if(s >= 4) cout << "Contemporary Xu Xiake\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	cin >> n;
	while(n--)
		te();

	return 0;
}