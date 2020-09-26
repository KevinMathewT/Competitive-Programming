    //raja1999

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string> 
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define int ll

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


//std::ios::sync_with_stdio(false);

int arr[300005],l[300005],deg[300005],a[300005];
vector<vector<int> >adj(300005);
int leaf=0;
int dfs(int u,int p){
	if(deg[u]==1){
		l[u]=1;
	}
	else{
		l[u]=0;
	}
	int i,s=0;
	for(i=0;i<adj[u].size();i++){
		if(adj[u][i]!=p){
			dfs(adj[u][i],u);
			l[u]+=l[adj[u][i]];
			s+=l[adj[u][i]];
		}
	}
	int val=0;
	for(i=0;i<adj[u].size();i++){
		if(adj[u][i]!=p){
			val+=(s-l[adj[u][i]])*(l[adj[u][i]]);
		}
	}
	val/=2;
	val+=l[u]*(leaf-l[u]);
	arr[u]=val;
	return 0;
}
main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	int t,t1;
	cin>>t;
	//t=1;
	t1=t;
	while(t--){
		int n,i,sum=0,u,v,root,ans=0;
		cin>>n;
		leaf=0;
		for(i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
			sum%=mod;
			adj[i].clear();
			deg[i]=0;
		}
		for(i=0;i<n-1;i++){
			cin>>u>>v;
			u--;
			v--;
			adj[u].pb(v);
			adj[v].pb(u);
			deg[u]++;
			deg[v]++;
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		if(n==2){
			cout<<sum<<endl;
			continue;
		}
		for(i=0;i<n;i++){
			if(deg[i]==1){
				leaf++;
			}
			else{
				root=i;
			}
		}
		dfs(root,-1);
		sort(arr,arr+n);
		sort(a,a+n);
		for(i=0;i<n;i++){
			arr[i]%=mod;
			ans+=(arr[i]*a[i])%mod;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
} 