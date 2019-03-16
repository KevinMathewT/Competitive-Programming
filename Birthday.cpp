#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[110];
std::vector<ll> v;
void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	sort(a, a + n);

	ll ans[n];
	ll end = 0;

	ll flag = 0;
	for(ll i=n-1;i>=0;i--){
		if(flag == 0){
			ans[end++] = a[i];
			flag = 1;
		}
		else{
			for(ll j=end;j>=1;j--)
				ans[j] = ans[j-1];
			end++;
			ans[0] = a[i];
			flag = 0;
		}
	}

	for(ll i=0;i<n;i++)
		cout << ans[i] << " ";
	cout << "\n";
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