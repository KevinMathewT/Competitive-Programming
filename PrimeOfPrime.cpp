#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100010];

void te(){
	cin >> n;
	for(ll i=0;i<100010;i++)
		a[i] = 1;

	a[0] = a[1] = 0;

	for(ll i=2;i*i<100010;i++)
		if(a[i] == 1)
			for(ll j=i*i;j<100010;j+=i)
				a[j] = 0;

	ll ans = 0;
	for(ll i=2;i<=n;i++){
		if(a[i] == 1){
			// cout << i << "\n";
			ll t = i, flag = 1;
			while(t > 0){
				if(a[t%10] != 1)
					flag = 0;
				t /= 10;
			}

			ans += flag;
		}
	}

	cout << ans << "\n";
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