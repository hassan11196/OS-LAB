#include<iostream>
#include<omp.h>
#include<cmath>

using namespace std;

long double x, fact[150], pwr[150], s[1];
int i, term;
void *Power(void *temp)
{
    double k;
    for (k = 0; k < 150; k++)
    {
        pwr[(int)k] = pow((double)x, (double)k);
        //printf("%.2Lf\n",pwr[k]);
    }
    return pwr;
}
void *Fact(void *temp)
{
    long double f;
    int j;
    fact[0] = 1.0;
    for (term = 1; term < 150; term++)
    {
        f = 1.0;
        for (j = term; j > 0; j--)
            f = f * j;
        fact[term] = f;
        printf("%.2Lf\n",fact[term]);
    }
    return fact;
}
void *Exp(void *temp)
{
    int t;
    s[0] = 0;
    for (t = 0; t < 150; t++)
        s[0] = s[0] + (pwr[t] / fact[t]);
    return s;
}

int main(){
    int nthreads;
    int tid;

    long double num = 0;
    cout << "Exponential [PROMPT] Enter the value of x (between 0 to 100) (for calculating exp(x)):" ;
    cin >> num;
    x = num;
    cout << "\nExponential [INFO] Threads creating.....\n";

    #pragma omp parallel
    {
        Power(NULL);
        Fact(NULL);
    }
    cout << "Exponential [INFO] Threads created\n";
    cout << "Exponential [INFO] Master thread and terminated threads are joining\n";
    cout << "Exponential [INFO] Result collected in Master thread\n" << endl;

    #pragma omp parallel
    {
        Exp(NULL);
    }
        
        
    

    cout << "\neXPONENTIAL [INFO] Value of exp(" << x << " ) is : " << s[0] << endl;    
    

    
    return 0;
}