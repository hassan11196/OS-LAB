#include<iostream>
#include<omp.h>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;


vector<vector<int> > Msum( vector<vector<int> > &arr1, vector<vector<int> > &arr2){
    vector<vector<int> > sumV(3,vector<int>(3));
    if(arr1.size() != arr2.size() || arr1[0].size() != arr2[0].size()){
        cout << endl << "ERROR IN MATRIX RC" << endl;
        exit(1);
    }
    for(int i = 0; i < arr1.size(); i++){
        for(int j = 0; j < arr1[1].size(); j++){
            sumV[i][j] = arr1[i][j] + arr2[i][2];
        }
    }
    return sumV;
}

vector<vector<int> > Mpro( vector<vector<int> > &arr1, vector<vector<int> > &arr2){
    vector<vector<int> > sumV(3,vector<int>(3));
    if(arr1.size() != arr2.size() || arr1[0].size() != arr2[0].size()){
        cout << endl << "ERROR IN MATRIX RC" << endl;
        exit(1);
    }

    for(int i = 0; i < arr1.size(); i++){
        long int sum = 0;
        for(int j = 0; j < arr1[1].size(); j++){

            for(int k = 0; k < arr1[1].size(); k++){
                sum += arr1[i][k]*arr2[k][i];
            }
            sumV[i][j] = sum;
        }
    }
    return sumV;
}

int main(){
    int nthreads;
    int tid;

    long double num = 0;
    int r = 3, c = 3;
    vector<vector<int> >  arr1(3,vector<int>(3));
    cout << endl <<"Enter 3 x 3 Array1 : " << endl ;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int temp = i+j;
            //cin >> temp;
            arr1[i][j] = temp;
        }
    }
    vector<vector<int> >  arr2(3,vector<int>(3));
    cout << endl << "Enter 3 x 3 Array2 : " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int temp = i+j;
            //cin >> temp;
            arr2[i][j] = temp;
        }
    }
    cout << "\nMATRIX [INFO] Threads creating.....\n";

     vector<vector<int> > summ(3,vector<int>(3));

    #pragma omp parallel
    {

        
        summ = Msum(arr1,arr2);
        
    }
    
    cout << "MATRIX [INFO] Threads created\n";

        vector<vector<int> > proo(3,vector<int>(3));
    #pragma omp parallel
    {
        proo= Mpro(arr1,arr2);
    }

    cout << endl << "ARRAy 1 : " << endl;
    for(int i = 0; i < 3;  i++){
        for(int j = 0; j < 3; j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }    

    cout << endl << "ARRRY 2 : " << endl;
    for(int i = 0; i < 3;  i++){
        for(int j = 0; j < 3; j++){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }    
        

        

    cout << endl << "Sum : " << endl;
    for(int i = 0; i < 3;  i++){
        for(int j = 0; j < 3; j++){
            cout << summ[i][j] << " ";
        }
        cout << endl;
    }    

    cout << endl << "Product : " << endl;
    for(int i = 0; i < 3;  i++){
        for(int j = 0; j < 3; j++){
            cout << proo[i][j] << " ";
        }
        cout << endl;
    }    
        
        

    

    
    return 0;
}