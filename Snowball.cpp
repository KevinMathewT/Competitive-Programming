#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll w, h, u1, d1, u2, d2;

void te(){
	cin >> w >> h >> u1 >> d1 >> u2 >> d2;

	for(ll i=h;i>=0;i--){
		w += i;
		if(i == d1)
			w -= u1;
		if(i == d2)
			w -= u2;
		w = max((ll)0, w);
	}

	cout << w << "\n";
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