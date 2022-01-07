#include "array.h"

int main()
{
    srand(time(NULL));
    int n1=10,n2=n1;
    int arr1[10000]={};

    int arr2[10000]={};
    int arr3[20000]={};
    do{
        n2=n1;
    /*
    int choose;
    do{
    cout << "0. Quit" <<endl;
    cout << "1. Random" << endl;
    cout << "2. Random Sorted" << endl;
    cout << "3. Sorted" << endl;
    cout << "4. Random Sorted Backward" <<endl;
    cout << "5. Sorted backward" << endl;
    cout << "Pilih : ";
    cin >> choose;
    cout << "Jumlah data (maksimal 10.000) :";
    cin >> n1;
    n2=n1;
    switch(choose){
    case 1:

        generateRandom(n1,arr1);
        generateRandom(n2,arr2);

        break;
    case 2:

        generateRandom(n1,arr1);
        sort(arr1,arr1+n1);
        generateRandom(n2,arr2);
        sort(arr2,arr2+n2);

        break;
    case 3:

        generateRandom(n1+n2,arr3);
        sort(arr3,arr3+n1+n2);
        for(int i=0;i<n1+n2;i++){
            if(i<n1){
                arr1[i]=arr3[i];
            }else{
                arr2[i-n1]=arr3[i];
        }
            }
        break;
    case 4:
        generateRandom(n1,arr1);
        sort(arr1, arr1 + n1, greater<int>());
        generateRandom(n2,arr2);
        sort(arr2, arr2 + n2, greater<int>());

        break;
    case 5:
*/
        generateRandom(n1+n2,arr3);
        sort(arr3,arr3+n1+n2,greater<int>());
        for(int i=0;i<n1+n2;i++){
            if(i<n1){
                arr1[i]=arr3[i];
            }else{
                arr2[i-n1]=arr3[i];
            }
        }
/*
        break;
    }

    if(choose!=0){
        char yn;*/
        bool show=false;
        /*do{
        cout << "Print array? (Y/N) :";
        cin >> yn;
        }while(yn!='Y'&&yn!='N'&&yn!='y'&&yn!='n');
        if(yn=='Y'||yn=='y'){
            show=true;
        }
        cout <<endl;
        cout << "arrays 1 : " << n1 << " data"<<endl;
        if(show){
            printArray(n1,arr1);
        }
        cout << "arrays 2 : " << n2 << " data" <<endl;
        if(show){
            printArray(n2,arr2);
        }
        cout << "hasil arrays cara 1 : " << n1+n2 <<" data" <<endl;
        mergeArrays1(n1,n2,arr1,arr2,arr3);
        if(show){
            printArray(n1+n2,arr3);
        }
        cout << endl;
        */
        cout << "hasil arrays cara 2 : " << n1+n2 << " data"<<endl;
        mergeArrays2(n1,n2,arr1,arr2,arr3);
        cout<< endl;
        /*
        if(show){
            printArray(n1+n2,arr3);
        }
    //}*/
        if(n1<100){
            n1=n1+10;
        }else if(n1<1000){
            n1=n1+100;
        }else if(n1<10000){
            n1=n1+1000;
        }else{
            n1=n1+1;
        }
    }while(n1<=10000);
    return 0;
}
