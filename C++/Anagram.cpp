//
//  04_Anagram.cpp
//  04_Anagram
//
//  Created by Denta Bramasta Hidayat on 25/11/20.
//


//i'm use hint from mr. irfan for use is_permutation
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
void Anagrams(string str, string pat)
{//void
    int a, b;
    if ((b = str.length()) < (a = pat.length()))//The length of the String and Pattern
        return;
 
    for (int i = 0; i <= b - a; i++){ //start looping
        if (is_permutation(str.begin() + i, str.begin() + i + a, pat.begin()))
        {// if function
            cout << str.substr(i, a) <<
            " at index " << i << endl;
        }//end of if function
    }//end of looping
}//end of void


int main(){//main funcion
    char str[200];
    char pat[200];
    
    cout << "String : " << endl;
    cin >> str;
    cout << "Pattern : " << endl;
    cin >> pat;
    Anagrams(str, pat);
    
    return 0;
}//end of main
