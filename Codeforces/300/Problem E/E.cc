#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, u, v, cnt;
vector<int> g[200100];

int dfs(int x, bool ismax){
	if(g[x].empty()) return 1;
	int ret;
	if(ismax){
		ret = 1e9;
		foreach(it, g[x]) ret = min(ret, dfs(*it, false));
	}
	else{
		ret = 0;
		foreach(it, g[x]) ret += dfs(*it, true);
	}
	return ret;
}

int main(){
	sd(n);
	for(int i = 1; i < n; i++){
		sd2(u,v);
		g[u].pb(v);
	}
	
	for(int i = 1; i <= n; i++) if(g[i].empty()) cnt++;
	
	printf("%d %d\n", cnt - dfs(1,true) + 1, dfs(1,false));
	
	return 0;
}
