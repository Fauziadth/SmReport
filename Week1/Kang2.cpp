#include <bits/stdc++.h>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    if (v1<=v2) return "NO";
    int dx = x2-x1, dv = v1-v2;
    if (dx % dv == 0){
        return "YES";
    } else {
        return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));


    int x1, v1, x2, v2;
    cin>>x1>>v1>>x2>>v2;

    string result = kangaroo(x1, v1, x2, v2);

    fout << result << "\n";

    fout.close();

    return 0;
}