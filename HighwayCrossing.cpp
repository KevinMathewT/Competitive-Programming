#include <bits/stdc++.h>
typedef long long ll;
typedef double ld;

using namespace std;

ld dx = 0.000001;

void te(){
	ll n; ld s, y;
	cin >> n >> s >> y;
	ld v[n], d[n], p[n], c[n];

	for(ll i=0;i<n;i++) cin >> v[i];
	for(ll i=0;i<n;i++){ cin >> d[i]; if(d[i] == 0) d[i]--; }
	for(ll i=0;i<n;i++) cin >> p[i];
	for(ll i=0;i<n;i++) cin >> c[i];

	cout << fixed << setprecision(6);
	ld ans = 0.000000000;
	for(ll i=0;i<n;i++){
		ld time = 0.0;
		ld crosstime = y / s;
		ld back = p[i] - d[i]*c[i];
		cout << "fron : " << p[i] << " back : " << back << "\n";
		if(d[i] == 1 && p[i] > dx && back > dx)
			time = crosstime;
		else if(d[i] == -1 && p[i] < -dx && back < -dx)
			time = crosstime;
		else{
			ld reachdx = (abs(p[i])) / v[i];
			if(reachdx > crosstime)
				time = crosstime;
			else
				time = crosstime + (abs(back) / v[i]);
		}
		for(ll j=i+1;j<n;j++)
			p[j] = p[j]+(d[j]*v[j]*time);

		ans += time;
		// cout << "front : " << p[i] << " back : " << p[i]-(d[i]*c[i]) << "\n";
		// ld carfrontbcross = ((v[i]*(crosstime))*(d[i]))+p[i];
		// ld carbackbcross = ((v[i]*(crosstime))*(d[i]))+p[i]-(d[i]*c[i]);
		// cout << carfrontbcross << " " << carbackbcross << "\n";
		// if((carbackbcross*carfrontbcross) > 0 && (p[i]*carfrontbcross) > 0 && (carbackbcross*(p[i]-d[i]*c[i])) > 0 && ((p[i])*(p[i]-d[i]*c[i])) > 0 && (abs(carfrontbcross)-dx) > 0 && (abs(carbackbcross)-dx) > 0  && (abs(p[i])-dx) > 0 && (abs(p[i]-d[i]*c[i])-dx) > 0){
		// 	time += crosstime;
		// }
		// else{
		// 	time += (crosstime + abs((abs(p[i])+c[i])/v[i]) + abs((dx)/v[i]));
		// }
		cout << "time : " << time << "\n";
	}

	cout << ans << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll T; cin >> T;
	while(T--) te();
	return 0;
}