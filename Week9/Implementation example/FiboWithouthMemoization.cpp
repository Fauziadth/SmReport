#include<iostream>

using namespace std;

//Fibonacci Numbers

void fib_ultimate(int n){
    int i;          		//counter
	long back2=0, back1=1;	//Last two values that we have to find the next number of fubo
	long next;				//Placeholder for sum
	
	
    if (n == 0) return (0);
	
	for(i=2; i<n; i++){
		next = back1+back2;
		back2 = back1;
		back1 = next;
	}
    return(back2+back1);
}


int main(){
	cout<< fib_ultimate(10);
	
	return 0;
}