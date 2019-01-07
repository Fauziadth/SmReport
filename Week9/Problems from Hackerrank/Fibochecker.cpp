#include <bits/stdc++.h>

using namespace std;

#define MAXN 45
#define UNKNOWN -1

long f[MAXN+1];

//-----------------------------------
//Fibonacci Numbers by Caching
long fib_c(int n){
    if  (f[n] == UNKNOWN){
        f[n] = fib_c(n-1) + fib_c(n-2);
    }

    return(f[n]);
}

void fib_c_driver(int n){
    int i;          //counter

    f[0] = 0;
    f[1] = 1;
    for (i = 2; i<=n; i++) f[i] = UNKNOWN;
    (fib_c(n));
}

//----------------------------------
//Check for fibonacci

void checkfib(long n){
    int i = 2;
    bool ada = false;
    while(!ada && f[i] <= n && i<= MAXN){
        if (f[i] == n){
            ada = true;
        }
        i++;
    }

    if (ada){
        cout<<"IsFibo\n";
    } else {
        cout<<"IsNotFibo\n";
    }
}

int main()
{
    fib_c_driver(MAXN);
    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        checkfib(n);
    }

    //cout<<"HELLO";


    return 0;
}
