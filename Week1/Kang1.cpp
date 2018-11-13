#include <bits/stdc++.h>

using namespace std;

string kangaroo(unsigned long int x1, unsigned long int v1, unsigned long int x2, unsigned long int v2) {
    if (v1<=v2) return "NO";
    if (x1==x2){
        return "YES";
    } else if (x1<x2) {
        return kangaroo(x1+v1, v1, x2+v2, v2);
    } else {
        return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));


    unsigned long int x1, v1, x2, v2;
    cin>>x1>>v1>>x2>>v2;

    string result = kangaroo(x1, v1, x2, v2);

    fout << result << "\n";

    fout.close();

    return 0;
}