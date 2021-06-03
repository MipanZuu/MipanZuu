//
//  main.cpp
//  Toki 9C
//
//  Created by Denta Bramasta Hidayat on 30/05/21.
//

#include <bits/stdc++.h>
using namespace std;
map <string, vector<string>> myMap;
stack <string> myStack;

bool DFS(string start,string end){
    if(start == end){
        return true;
    }
    else{
        for(auto i:myMap[start]){
            if(DFS(i, end)){
                myStack.push(i);
                return true;
                }
            }
            return false;
        }
    }

int main(){
    int M, N;
    string Pi, Ci;
    cin >> N >>M;
        for(int i = 0; i < M;i++){
            cin >> Pi >> Ci;
            myMap[Pi].push_back(Ci);
        }
    
    string start, finish;
    cin >> start >> finish;
    
        if(DFS(start, finish)) {
            cout << start <<endl;
            while(!myStack.empty()){
                cout << myStack.top() <<endl;
                myStack.pop();
            }
        }
        else if(DFS(finish, start)) {
            cout << finish <<endl;
            while(!myStack.empty()){
                cout << myStack.top() << endl;
                myStack.pop();
    }
}
    else{
        cout<<"TIDAK MUNGKIN"<<endl;
    }
}
