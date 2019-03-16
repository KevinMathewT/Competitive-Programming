#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll x, y, z, a, b, c;

void te(){
	cin >> x >> y >> z >> a >> b >> c;

	if(a < x){
		cout << "NO\n";
		return;
	}

	a -= x;

	if(a + b < y){
		cout << "NO\n";
		return;
	}

	if(y < a){
		a -= y;
	}
	else{
		b -= (y - a);
		a = 0;
	}

	if((a + b + c) < z){
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
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