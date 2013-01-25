/* Paras Narang 
 *
 * To check whether number is a perfect square
 *
 * Ref : http://www.johndcook.com/blog/2008/11/17/fast-way-to-test-whether-a-number-is-a-square/ 
 */
#include <iostream>
#include <math.h>
using namespace std;

int PerfectSquare(int n)
{
    int h = n & 0xF; // last hexidecimal "digit"
    if (h > 9)
        return 0; // return immediately in 6 cases out of 16.

    // Take advantage of Boolean short-circuit evaluation
    if ( h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8 )
    {
        // take square root if you must
        int t = (int) floor( sqrt((double) n) + 0.5 );
            return t*t == n;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    if(PerfectSquare(n))
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
    return 0;
}
