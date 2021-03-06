#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

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
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, w;
int ss[500100], pp[500100], f[500100], cnt, l1, l2;
vector<int> s, p;

void build_f(){
	f[0] = f[1] = 0;
	int j;
	for(int i = 2; i <= l1; i++){
		j = f[i-1];
		while(true){
			if(p[j] == p[i-1]){
				f[i] = j+1; break;	// match found, next char to match is j+1
			}
			else if(j == 0){
				f[i] = 0; break; // no match found
			}
			j = f[j];	// try next prefix/suffix
		}
	}
	return;	
}

bool match(){
	for(int i = 0, j = 0; j < l2;){
		if(s[j] == p[i]){	// try to expand the prefix ending at index i with character t[j]
			j++, i++;
			if(i == l1){
				cnt++;	// match found
				i = f[i];
			}
		}
		else if(i > 0) i = f[i];	// try the next/prefix suffix to match
		else j++;	// no match found, try from the empty string again
	}
	return false;
}

int main(){
	sd2(n,w);
	
	if(n < w){
		printf("0\n"); return 0;
	}
	
	for(int i = 0; i < n; i++){
		sd(ss[i]);
	}
	for(int i = 0; i < w; i++){
		sd(pp[i]);
	}
	for(int i = 1; i < n; i++){
		s.pb(ss[i] - ss[i-1]);
	}
	for(int i = 1; i < w; i++){
		p.pb(pp[i] - pp[i-1]);
	}
	
	if(w == 1){
		printf("%d\n", n); return 0;
	}
	
	l1 = p.size();
	l2 = s.size();
	
	build_f();
	match();
	
	printf("%d\n", cnt);
	
	return 0;
}
