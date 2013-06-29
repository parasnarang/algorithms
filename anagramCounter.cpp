/* Paras Narang 
 * 
 * Write a function that accepts two parameters, a parent and a child string. 
 * Determine how many times the child string - or an anagram of the of the child 
 * string appears in the parent string.
 * 
 * */
#include <iostream>
#include <string>

using namespace std;

int hashString(string str){
    int charMap[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241};
    int result = 1;
    for(int i=0; i<str.length(); i++)
        result *= charMap[str[i]-'a'];
    return result;
}

int anagram_counter(string parent, string child){
    int len = child.length(), plen = parent.length();
    int anagram = hashString(child);
    int count = 0;

    for(int i=0; i<=(plen-len); i++)
        if(hashString(parent.substr(i, len)) == anagram)
            count++;

    return count;
}

int main()
{
    string parent, child;
    cin >> parent >> child;
    cout << anagram_counter(parent, child) << endl;
    return 0;
}
