#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
ll a[1000+100], v[1000+100];

void dfs(ll n){
	if(v[n] == 1){
		cout << n << " ";
		return;
	}
	v[n] = 1;
	dfs(a[n]);
}

void memset(ll *a, ll b, ll c){
	for(ll i=0;i<c;i++)
		a[i] = b;
}

void te(){
	cin >> n;
	for(ll i=1;i<=n;i++)
		cin >> a[i];

	for(ll i=1;i<=n;i++){
		memset(v, (ll)0, (ll)1000+100);
		dfs(i);
	}
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