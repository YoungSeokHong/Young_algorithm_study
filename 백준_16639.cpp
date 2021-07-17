#include <iostream>
#include <string>
 
int calculate(int a, int b, char op);
 
int main(void){
    int n;
    char str[19];
    int nums[10];
    char ops[9];
    int dpNum[10][10];
    char dpOp[9][10];
 
    scanf("%d", &n);
    scanf("%s", str);
    for(int i=0; i<n; i++){
        if(i % 2 == 0) nums[i / 2] = str[i] - '0';
        else ops[i / 2] = str[i];
    }
 
    int max = -2147483648;
    int index;
    for(int i=0; i < n / 2 - 1; i++){
        for(int j=0; j < n / 2 - i; j++){
            for(int k=0; k < j; k++){    
                dpNum[k][j] = nums[k]; 
                dpOp[k][j] = ops[k];
            }
            int cnt = 0;
            if(ops[j] == '-'){
                while(ops[j + cnt] == '-'){
                    dpNum[j][j] = calculate(dpNum[j][j], nums[j + cnt + 1], ops[j + cnt]);
                    cnt++;
                    printf("%d\n", dpNum[j][j]);
                }
            }else{
                dpNum[j][j] = calculate(nums[j], nums[j + 1], ops[j]);
            }
            for(int k = j + 1; k < j + 2 + cnt; k++){    
                dpNum[k][j] = 0; 
            }
            for(int k = j + 1; k < j + 2 + cnt; k++){
                dpOp[k][j] = '+';
            } 
            for(int k = j + 2 + cnt; k <= n / 2 - i; k++){    
                dpNum[k - 1][j] = nums[k]; 
            }
            for(int k = j + 1 + cnt; k <= n / 2 - i - 1; k++){
                dpOp[k - 1][j] = ops[k];
            }
 
            int mid = dpNum[0][j];
 
            int tmpNum[10];
            char tmpOp[9];
            for(int k = 0; k <= n / 2 - i; k++){    
                tmpNum[k] = dpNum[k][j]; 
            }
            for(int k = 0; k <= n / 2 - i - 1; k++){
                tmpOp[k] = dpOp[k][j];
            }
 
            for(int k=n/2-i-1; k > 0; k--){
                if(tmpOp[k-1] == '*'){
                    tmpNum[k-1] = calculate(tmpNum[k-1], tmpNum[k], tmpOp[k-1]);
                    if(k==1) mid = tmpNum[k-1];
                }
            }
 
            for(int k=0; k < n / 2 - i - 1; k++){
                if(tmpOp[k] != '*'){
                    mid = calculate(mid, tmpNum[k + 1], tmpOp[k]);
                }
            }
            printf("mid : %d\n", mid);
            if(mid > max){
                index = j;
                max = mid;
            }
        }

        printf("-max : %d\n", max);
        for(int k = 0; k <= n / 2 - i; k++){    
            nums[k] = dpNum[k][index]; 
        }
        for(int k = 0; k <= n / 2 - i - 1; k++){
            ops[k] = dpOp[k][index];
        }
    }
 
    printf("%d",max);
 
    return 0;
}
 
int calculate(int a, int b, char op){
    switch (op){
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    default: return 0;
    }
}