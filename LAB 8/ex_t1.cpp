#include<iostream>
#include<omp.h>

using namespace std;

int main(){
    int nthreads;
    int tid;
    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        cout << endl << "Hello : " << tid << endl;
        if(tid == 0){
            nthreads = omp_get_num_threads();
            cout << endl << "No. of threads : " << nthreads << endl ;

        }
    }
    return 0;
}