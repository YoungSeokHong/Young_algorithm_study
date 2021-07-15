#include <iostream>

long long arr[100000][2];
long long tmpt[100000][2];
long long cnt[100000];

int main(void){
    printf("start\n");
    
    int cnt = 0;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for(int i=0; i<n; i++){
        bool c= false;
        for(int j=0; j<cnt; j++){
            if(!(arr[j][0] >= arr[i][1] || arr[j][1] <= arr[i][0])) {
                print
                c = true;
                break;
            }
        }

        if(!c) {
            tmpt[cnt][0] = arr[i][0];
            tmpt[cnt][1] = arr[i][1];
            printf("(%d, %d)\n", tmpt[cnt][0], tmpt[cnt][1]);
            cnt++;
        }
    }

    printf("%d", cnt);
}