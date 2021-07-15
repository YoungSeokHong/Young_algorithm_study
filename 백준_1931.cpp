#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second){
		return a.first > b.first;
	}else{
		return a.second < b.second;
	}
}

int main(void){
	int n;
	vector<pair<int, int> > v;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(pair<int, int>(a, b));
	}
	
	sort(v.begin(), v.end(), compare);
	
	int cnt = 0;
	pair<int, int> tmpt = make_pair(0, 0);
	for(int i=0; i<n; i++){
		if(v[i].second <= tmpt.first || v[i].first >= tmpt.second){
			tmpt = pair<int, int>(v[i].first, v[i].second);
			cnt++;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
