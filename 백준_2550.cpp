#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[10001],b[10001],c[10002],dp[10002];
pair<int,int> trc[10001];
int main(){
	int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int v;
        scanf("%d",&v);
        a[v]=i;
    }
    for(int i=1;i<=n;i++) {
		scanf("%d",&b[i]);
	}
    for(int i=1;i<=n;i++) {
    	c[a[b[i]]]=i;
	}
 
    vector<int> v;
    for(int i=1;i<=n;i++){
        int j = lower_bound(v.begin(),v.end(),c[i])-v.begin();
        if(j<v.size()) v[j]=c[i];
        else v.push_back(c[i]);
        trc[i]={j,c[i]};
    }
    int j=v.size()-1;
    
    vector<int> l;
    for(int i=n;i>0;i--){
        if(trc[i].first==j){
            l.push_back(trc[i].second);
            j--;
        }
    }
 
    printf("%d\n",l.size());
    for(int i=0; i<l.size(); i++){
    	l[i] = b[l[i]];
	}
    sort(l.begin(),l.end());
    for(int i=0; i<l.size(); i++){
    	printf("%d ",l[i]);
	}
}
