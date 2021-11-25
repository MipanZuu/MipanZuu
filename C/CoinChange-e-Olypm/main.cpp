/*
    Kadane2D_2nd.cpp
    2021-11-12 Denta Bramasta
*/

#include<iostream>
using namespace std;
//function to calculate maximum contiguous 1D subarray
int max1D (int a[],int n,int &start, int &finish)
{
    int sum = 0;
    int max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
        if(sum > max)
        {
            max = sum;
            finish = i;
        }
        if(sum < 0)
        {
            sum = 0;
            start = i+1;
        }
    }
    return max;
}
int max2D(int matrix[][5],int m,int n)
{
    m=0;
    int sum = 0;
    int ans = INT_MIN;
    int top, bottom;
    int TOP=0, BOTTOM = m-1,LEFT = 0,RIGHT = n-1;
    for(int left = 0;left < n;left++)
    {
        int a[m] = {0};        //Creating a 1D array for each column
        for(int right = left;right < n;right++)
        {
            for(int i=0;i < m;i++)
                a[i] += matrix[i][right];
                
            sum = max1D(a,m,top,bottom);
            if(sum > ans)    //updating ans if sum encountered is the greatest so far
            {
                ans = sum;
                LEFT = left;
                RIGHT = right;
                TOP = top;
                BOTTOM = bottom;
                
            }
        }
    }
    cout<<"\nThe required sub-matrix is: "<<endl;
    for(int i = TOP;i <= BOTTOM;i++)    //Printing the required sub-matrix
    {
        cout<<endl;
        for(int j = LEFT; j<=RIGHT; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
    }
    return ans;        //returning the largest sum
}
int main()
{
    int row, col;
    int matrix[5][5];
    cout<<"Enter the number of rows:";
    cin>>row;
    cout<<"Enter the number of columns:";
    cin>>col;
    cout<<"Enter the matrix:";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>matrix[i][j];
        }
    }
    int sum = max2D(matrix,row,col);
    cout<<"\nThe required sum is "<<sum;
    return 0;
}
