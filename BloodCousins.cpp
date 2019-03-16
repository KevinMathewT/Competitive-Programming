#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define size (ll)1e5 + 100;
#define level 18

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
ll parent[size][level];
ll children[size][level];

void te(){
	for(ll i=0;i<size;i++)
		for(ll j=0;j<level;j++){
			parent[i][j] = -1;
			children[i][j] = 0;
		}

	for(ll i=1;i<=n;i++){
		ll a;
		cin >> a;
		if(a == 0) continue;

		parent[i][0] = a;
		children[a][0]++;
	}

	for(ll j=1;j<level;j++)
		for(ll i=0;i<n;i++){
			if(parent[i][j] == -1){
				parent[i][j] = parent[parent[i][j-1]][j-1];
				children[parent[i][j]][j]++;
			}
		}

	ll q;
	cin >> q;
	while(q--){
		ll v, p;
		cin >> v >> p;

		for(ll i=0;i<18;i++)
			if((p >> i) & 1 != 0)
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}