#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
typedef vector<int> vi;

void bubbleSort(vi &A){
    int n = A.size();
    bool ready;
    
    for(int i = 0; i < n-1; ++i){
        ready = false;
        for(int j = 0; j < n-i-1; ++j)
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]);
                ready = true;
            }
        if(!ready)
            break;
    }
}

void display(vi & a){
    for(int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout <<"\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    srand (time(NULL));

    int n = 100;
    vector<int> muestra(n);

    for(int i = 0; i < n; ++i){
        muestra[i] = rand() % 1000;
    }

    display(muestra);
    cout << "\n";
    bubbleSort(muestra);
    display(muestra);

    return 0;
}