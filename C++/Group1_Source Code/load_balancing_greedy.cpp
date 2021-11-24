#include <iostream>
#include <vector>
using namespace std;

void approxAlgo(int M, int N, int T[]);
int smallestValueIndex(int arr_size, int arr[]);

int main(){
    int M,N,buffer;
    cin >> M;
    cin >> N;

    int T[N];
    for(int i = 0; i < N; i++){
        cin >> buffer;
        T[i] = buffer;
    }

    approxAlgo(M,N,T);
    return 0;
}

void approxAlgo(int M, int N, int T[]){
    vector <int> dtsb[M];
    int acc[M] = {0};
    for(int i = 0; i < N; i++){
        int min = smallestValueIndex(M,acc);
        acc[min] += T[i];
        dtsb[min].push_back(T[i]);
    }

    for(int i = 0; i < M; i++){
        cout << '[' << i+1 << "] = ";
        for(int j = 0; j < dtsb[i].size(); j++){
            cout << dtsb[i].at(j) << ' ';
        }
        cout << endl;
    }

}

int smallestValueIndex(int arr_size, int arr[]){
    int index = 0;
    for(int i = 1; i < arr_size; i++){
        if(arr[index] > arr[i])
            index = i;
    }
    return index;
}
