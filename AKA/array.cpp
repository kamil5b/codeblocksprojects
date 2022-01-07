#include "array.h"

void mergeArrays1(int n1, int n2, int arr1[], int arr2[], int arr3[]){
    int i,j,k,waktu;
    auto start = chrono::steady_clock::now();
    i=0;j=0;k=0;waktu=0;
    while(i<n1 && j <n2){
        waktu++;
        if(arr1[i]<arr2[j]){
            arr3[k]=arr1[i];
            k++;i++;
        }else{
            arr3[k]=arr2[j];
            k++;j++;
        }
    }
    while(i < n1){
        waktu++;
        arr3[k]=arr1[i];
        k++;i++;
    }
    while(j < n2){
        waktu++;
        arr3[k]=arr2[j];
        k++;j++;
    }
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds : "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
    cout << "Melakukan iterasi sebanyak : " << waktu << endl;
}

void mergeArrays2(int n1, int n2, int arr1[], int arr2[], int arr3[]){
    int i,j,k,key,waktu;
    auto start = chrono::steady_clock::now();
    i=k=waktu=0;
    while(k<n1){
        waktu++;
        arr3[k]=arr1[k];
        k++;
    }
    while(i<n2){
        waktu++;
        key = arr2[i];
        j = n1 - 1;
        while( j >= 0 and arr3[j] > key ){
            waktu++;
            arr3[j + 1] = arr3[j];
            j--;
        }
        arr3[j + 1] = key;
        n1++;
		i++;
    }
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds : "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
    cout << "Melakukan iterasi sebanyak : " << waktu << endl;
}

void generateRandom(int n, int arr[]){

    int random_number;
    for(int i=0;i<n;i++){
       random_number = rand() % n;
       arr[i]=random_number;
    }
}

void printArray(int n, int arr[]){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }cout<< endl << endl;
}
