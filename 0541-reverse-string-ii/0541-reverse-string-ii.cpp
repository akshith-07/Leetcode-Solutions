#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseAll(string str){
        reverse(str.begin(),str.end());
        return str;
    }
    string reversefirstk(string str , int k){
        int n = str.length();
        string reverseString= str.substr(0,k);
        string remainingString = str.substr(k ,n);

        reverse(reverseString.begin(), reverseString.end());
        return reverseString + remainingString;
    }
    string reverseStr(string s, int k) {
        
        int n = s.length();
        if(n<k){
            return reverseAll(s);
        }
        string dummy="";
        int kk = 2*k;
        string output="";
        int dummyLength = 0;
        for(int i=0;i<n;i++){

            if(dummyLength==kk){
                output+= reversefirstk(dummy , k);
                dummy = "";
                dummyLength=0;
            } 
            dummy += s[i];
            dummyLength++;
        }

        if(dummyLength<k){
            output+= reverseAll(dummy);
        }

        if(dummyLength == kk){
            output+= reversefirstk(dummy , k);
        }

        if(dummyLength< kk && dummyLength>=k){
            output+= reversefirstk(dummy , k);
        }

        return output;


    }
};