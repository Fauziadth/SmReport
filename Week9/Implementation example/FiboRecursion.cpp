#include<iostream>

using namespace std;


//Fibonacci Number by simply recursion

long fib_r(int n){
	if (n == 0) return (0);
	if (n == 1) return (1);
	
	return (fib_r(n-1) +fib_r(n-2));
}

int main(){
	cout<< fib_r(10);
	
	return 0;
}