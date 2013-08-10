/* Paras Narang
 *
 * length of LCS using DP
 */
#include<iostream>
#include<string>

using namespace std;

int lcs(string A, string B, int lenA, int lenB ){
    int L[lenA+1][lenB+1];
    int i, j;

    for(i = 0; i <= lenA; i++){
        for(j = 0; j <= lenB; j++){
            if(i == 0 || j == 0)
                L[i][j] = 0;

            else if(A[i-1] == B[j-1])
                L[i][j] = L[i-1][j-1] + 1;

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[lenA][lenB];
}

int max(int a, int b){
    return (a > b)? a : b;
}

int main(){
    string A = "PARASSMILING";
    string B = "POTASSIUM";

    int lenA = A.length();
    int lenB = B.length();

    cout << "Length of LCS : " << lcs(A, B, lenA, lenB) << endl;
    return 0;
}

