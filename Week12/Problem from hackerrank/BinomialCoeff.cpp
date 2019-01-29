//https://www.hackerrank.com/challenges/binomial-coefficients/problem
//But still not working for very long number problems
//It can be achieved by using lucas theorem here
//https://en.wikipedia.org/wiki/Lucas%27s_theorem
//But my main focus is to implement the dynamic programming

#include <bits/stdc++.h>

using namespace std;

#define MAXN 11

int main(){
    int i, j;
    long bc[MAXN][MAXN];
    int lastn = 0;//To see what is the last n we have already


    int T, count;
    long n,P;

    cin>>T;
    for (int m = 0; m<T; m++){
        cin>>n>>P;

        //Making to a newer index
        if (lastn < n){
            //cout<<"Input "<<n<<"\n";
            for (i = lastn; i <= n; i++)
                bc[i][0] = 1;
            for (j = lastn; j <= n; j++)
                bc[j][j] = 1;

            for (i = lastn; i <= n; i++) {
                for (j = 1; j < i; j++) {
                    bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
                }
            }
            lastn = n;
        }

        count = 0; //reset count
        for (j = 0; j<=n; j++){
            if (bc[n][j] % P == 0) {
                count++;
            }
        }
        cout<<count<<"\n";
    }

    /*
    //Seeing the Pascal Triangle
    for (int i = 0; i<=lastn; i++){
        for (int j = 0; j<=i; j++) {
            cout<<bc[i][j]<<" ";
        }
        cout <<"\n";
    }
    */

    return 0;
}
