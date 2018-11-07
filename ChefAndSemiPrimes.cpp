#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll p[250];
vector<ll> v;

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

    for(ll i=1;i<250;i++)
    	p[i] = 1;
  
    for (ll i=2; i*i<=250; i++)
    	if (p[i] == 1)
            for (ll j=i*2;j<=250;j+=i)
                p[j] = 0;

    for(ll i=2;i<=200;i++)
    	if(p[i] == 1)
    		v.push_back(i);

    // cout << v.size() << "\n";

    ll ans[210];
    for(ll i=0;i<210;i++)
    	ans[i] = 0;

    vector<ll> sp;
    for(ll i=0;i<v.size();i++)
    	for(ll j=i+1;j<v.size();j++)
    		if(v[i]*v[j] < 210)
    			sp.push_back(v[i]*v[j]);
    		else
    			break;


   	sort(sp.begin(), sp.end());
    // cout << sp.size() << "\n";

    for(ll i=0;i<sp.size();i++)
    	for(ll j=i;j<sp.size();j++)
    		if(sp[i]+sp[j] < 210)
    			ans[sp[i]+sp[j]] = 1;

    // for(ll i=0;i<v.size();i++)
    // 	cout << v[i] << " ";
    // cout << "\n";

    // for(ll i=0;i<sp.size();i++)
    // 	cout << sp[i] << " ";
    // cout << "\n";

    // for(ll i=0;i<210;i++)
    // 	cout << i << " - " << ans[i] << "\n";

	ll T;
	cin >> T;
	while(T--){
		ll z;
		cin >> z;
		if(ans[z] == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}