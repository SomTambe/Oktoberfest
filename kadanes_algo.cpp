#include <iostream>
using namespace std;

// n complexity

int main(){

    int n;
    cout << "Enter the no. of elements in the array " << endl;
    cin >> n;

    int arr[n];

    int curr_sum = 0;
    int max_sum = 0;

    cout << "Enter the elements of the array " << endl;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int j=0; j<n; j++){

        curr_sum = curr_sum + arr[j];

        if(curr_sum<0){
            curr_sum = 0;
        }

        max_sum = max(curr_sum, max_sum);

    }

    cout << "The max sum is " << max_sum << endl;

    return 0;
}
