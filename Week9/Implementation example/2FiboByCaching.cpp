#include<iostream>

using namespace std;

#define MAXN 45
#define UNKNOWN -1

long f[MAXN+1];

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
    return(fib_c(n));
}


int main(){
	cout<< fib_c_driver(10);
	
	return 0;
}
