//
//  main.cpp
//  Postfix
//
//  Created by Denta Bramasta Hidayat on 16/03/21.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    // string postfix = "2 3 + 5 *";
    // string postfix = "2 3 1 * + 9 -";
    string postfix = "2 9 + 5 *";

    stack<int> myStack;
    int len = postfix.length();
    string temp;

    for (int i = 0; i < len; i++) {
        if (isdigit(postfix[i])) {
            temp = postfix[i];
            int myTemp = stoi(temp);
            myStack.push(myTemp);
        }
        else if (!isspace(postfix[i])){

            int num1 = myStack.top();
            myStack.pop();
            int num2 = myStack.top();
            myStack.pop();

            switch (postfix[i]) {
                case '+':
                    myStack.push(num2 + num1);
                    break;
                case '-':
                    myStack.push(num2 - num1);
                    break;
                case '*':
                    myStack.push(num2 * num1);
                    break;
                case '/':
                    myStack.push(num2 / num1);
                    break;
            }
            
        }
    }

    cout << myStack.top() << endl;

    return 0;
}
 
