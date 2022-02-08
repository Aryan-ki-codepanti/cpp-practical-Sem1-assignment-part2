#include <iostream>
using namespace std;

void print_arr(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n , m , p;
    cout << "Enter lengths of array 1 and 2: " << endl;
    cin >> n >> m;
    if (n <= 0 || m <= 0){
        cout << "Array length can not be zero or negative" << endl;
        exit(1);
    }

    int arr1[n];
    int arr2[m];

    p = n + m;
    int arr[p];

    cout << "Enter elements of array 1" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter elements of array 2" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    
    // Merging
    int i = 0 , j = 0 , k = 0;

    while (i < n || j < m){
        if (i < n && j < m ){
            if (arr1[i] < arr2[j]){
                arr[k] = arr1[i];
                i++;
            }
            else{
                arr[k] = arr2[j];
                j++;
            }
        }
        else if (i < n){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    cout << "Array 1: ";
    print_arr(arr1 , n);
    cout << "Array 2: ";
    print_arr(arr2 , m);
    cout << "Merged Array: ";
    print_arr(arr , p);


    return 0;
}