#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    int x = strcmp(a.second.c_str(), b.second.c_str());
    if(x == 0){
        return a.first < b.first;
    }else{
        return x < 0;
    }
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<pair<int, string> > arr;
    for(int i=0; i<gems.size(); i++){
        arr.push_back(pair<int, string>(i + 1, gems[i]));
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    vector<pair<0, string> > dp;
    string tmpt = arr[0].second;
    dp.push_back(pair<arr[0].first, tmpt>);
    for(int i=1; i<arr.size(); i++){
        if(strcmp(tmpt.c_str(), arr[i].second.c_str()) != 0){
            tmpt = arr[i].second;
            dp.push_back(pair<i, tmpt>);
        }
    }

    int i=0;
    int a, b;
    while(strcmp(arr[i].second.c_str(), arr[0].second.c_str)){
        int tmptA = arr[i].first
        int tmptB = arr[i].second
        for(int j=1; j<dp.size(); j++){
             int x = arr[dp[j].first].first;
             int y;
             if(dp[j].first < arr.size() - 1) y = arr[dp[j].first].first;
             else arr[arr.size() - 1].first;
            if((x >= tmptA && x <= tmptB) || (x >= tmptA && x <= tmptB))
        }
    }

    dp


    return answer;
}

int main(void){
    vector<string> v;
    v.push_back("A");
    v.push_back("B");
    v.push_back("B");
    v.push_back("A");
    v.push_back("A");
    v.push_back("C");
    v.push_back("D");
    v.push_back("A");

    solution(v);

    return 0;
}