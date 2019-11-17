#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll a, b, c;

ll modExpo(ll x, ll y, ll m){
    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    if(y % 2 == 0)
        return modExpo((x * x) % m, y / 2, m);
    else
        return (modExpo((x * x) % m, y / 2, m) * x) % m;
}

void te(){
    cin >> a >> b >> c;
    // cout << modExpo(a, b, c) << "\n";
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