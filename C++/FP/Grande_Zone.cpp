//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//


#include<bits/stdc++.h>
using namespace std;

int GetRectangleMax(int hist[], int n)
{
    stack <int> myStack;
 
    int max_area = 0;
    int tp;
    int area_with_top;
    
    
    int i = 0;
    while (i < n) {
        if (myStack.empty() || hist[myStack.top()] <= hist[i])
            myStack.push(i++);
 
        else {
            tp = myStack.top();
            myStack.pop();
 
            area_with_top = hist[tp] * (myStack.empty() ? i :
                                   i - myStack.top() - 1);
 
         
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    while (myStack.empty() == false)
    {
        tp = myStack.top();
        myStack.pop();
        area_with_top = hist[tp] * (myStack.empty() ? i :
                                i - myStack.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}
 

 int main(){
    int input;
//  int arr[100005]
    while(true){
        cin >> input;
        if(!cin){
            break;
        }
    int arr[100005];
    for(int i = 0; i < input; i++){
        cin >> arr[i];
    }
    cout << GetRectangleMax(arr, input) << endl;
    }
    
    return 0;
}

