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
	for(ll i=0;i<n;i++) cin >> d[i];
	for(ll i=0;i<n;i++) cin >> p[i];
	for(ll i=0;i<n;i++) cin >> c[i];

	cout << fixed << setprecision(6);
	
	ld ans = 0.0;
	// cout << n << "\n";
	for(ll i=0;i<n;i++){
		// cout << "Hey\n";
		ld time = 0.0;
		if(d[i] == 1){
			ld front = p[i];
			ld back = p[i] - c[i];
			ld t = (abs(p[i])) / v[i];
			// cout << t << " : time\n";
			if(p[i] < (-dx)){
				if(t <= (y / s))
					time = (y / s) + ((abs(p[i]) + c[i]) / v[i]);
				else
					time = (y / s);
			}
			else if(p[i] > (-dx) && (p[i]-c[i]) < (+dx)){
				time = (abs(p[i] - c[i])) / v[i];
			}
			else{
				time = (y / s);
			}
		}
		else{
			ld front = p[i];
			ld back = p[i] + c[i];
			ld t = (abs(p[i]) - dx) / v[i];
			// cout << t << " : time\n";
			if(p[i] > dx){
				if(t <= (y / s))
					time = (y / s) + ((abs(p[i]) + c[i] + dx) / v[i]);
				else
					time = (y / s);
			}
			else if(p[i] < (dx) && p[i]-c[i] > (-dx)){
				time = (y / s) + (abs(p[i] + c[i]) + dx) / v[i];
			}
			else{
				time = (y / s);
			}
		}
		for(ll k=(i+1);k<n;k++){
			if(d[k] == 0)
				p[k] = p[k] - (v[k]*time);
			else 
				p[k] = p[k] + (v[k]*time);
		}
		ans = ans + time;
		//cout << time << " " << p[i] << "\n";
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