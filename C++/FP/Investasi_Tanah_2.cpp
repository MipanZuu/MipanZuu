//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//

#include <bits/stdc++.h>

using namespace std;

int kadane(int a[],int n){
    int currentSum=a[0],maxSum=a[0];
    for(int i=1;i<n;i++){
        if(currentSum<0){
            currentSum=a[i];
        }
        else{
            currentSum+=a[i];
        }
        if(currentSum>maxSum){
            maxSum=currentSum;
        }
    }
    return maxSum;
}

int main(void){
    int n;
    cin>>n;
    int a[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
}

    int maxSum=INT_MIN;
    int left,right,sum,tmp[n];


    for(left=0;left<n;left++){
        memset(tmp,0,sizeof(tmp));
        for(right=left;right<n;right++){
            for(int i=0;i<n;i++)
                tmp[i]+=a[i][right];

            sum=kadane(tmp,n);
            if(sum>maxSum){
                maxSum=sum;
            }
        }
    }

    cout<<maxSum<<endl;

    return 0;
}


