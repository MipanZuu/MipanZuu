//
//  03_overloading.cpp
//  03_overloading
//
//  Created by Denta Bramasta Hidayat on 24/11/20.
//

// I'm Using Mr. Irfan's Hint
#include <iostream>
using namespace std;
//Overloading

// This for 1 Variables
int add(int a){
    return a;}//end of int for 1 variable

//int for 2 variables
int add(int a, int b){
    return a+b;}//end of 2 variables

//double for 3 variables
double add(double a, double b, double c){
    return a+b+c;}// end of 3 variables

// int for 4 variables
int add(int a, int b, int c, int d){
    return a+b+c+d;}//end of the 4 variables

// int for 5 variables
int add(int a, int b, int c, int d, int e){
    return a+b+c+d+e;}//end of the 5 variable


    int main (){//int main function
        cout << "Add : " << add(100) << endl;//cout for 1 variable
        cout << "Add : " << add(22, 34) << endl;//cout for 2 variables
        cout << "Add : " << add(2.1, 7.5, 11.3) << endl;//cout for 3 variables
        cout << "Add : " << add(11, 20, 13, 10) << endl;//cout for 4 variables
        cout << "Add : " << add (32, 19, 12, 41, 12) << endl;//cout for 5 variables
       
        cin.get();//Cin run the program
        return 0;
        
}// end of the main
