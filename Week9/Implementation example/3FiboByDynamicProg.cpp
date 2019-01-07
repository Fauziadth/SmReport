#include<iostream>

using namespace std;

//Fibonacci Numbers by dynamic programming

void fib_dp(int n){
    int i;          //counter
	long f[MAXN+1];
	
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i<=n; i++) f[i] = f[i-1]+f[i+2];
	
    return(f[n]);
}


int main(){
	cout<< fib_dp(10);
	
	return 0;
}
