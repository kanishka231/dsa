vector<int>count(int num){
    vector<int>memo;
    memo[0]=0;
    for(int i=1;i<=num;i++){
        memo[i]=memo[i/2]+(i%2==0?0:1);
    }
    return memo;
}

int sumOfallBits(int num){
    int sum=0;
    vector<int> memo = count(num);
    for(int i=1;i<=num;i++){
        sum = sum + memo[i];
    }
   return sum;
}