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
        for(int i=0;i<n;i++){
            if(dummy.length()==kk){
                output+= reversefirstk(dummy , k);
                dummy = "";
            } 
            dummy += s[i];
        }

        if(!dummy.empty()){
            if(dummy.length()<k){
                output+= reverseAll(dummy);
            }else{
                output+= reversefirstk(dummy , k);
            }

        }
        return output;


    }
};