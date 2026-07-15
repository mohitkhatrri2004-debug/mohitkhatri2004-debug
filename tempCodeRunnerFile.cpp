#include<bits/stdc++.h>
using namespace std;
int main(){
    string s ="abcabcbb";
    int maxlength = 0;
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            string sub = s.substr(i,j-i+1);

            bool duplicate = false;

            for(int x=0;x<sub.length();x++){
                for(int y=x+1;y<sub.length();y++){
                    if(sub[x] == sub[y]){
                        duplicate = true;
                        break;
                    }
                }
                if(duplicate){
                    break;
                }
            }
            if(!duplicate){
                if(sub.length() > maxlength){
                    maxlength = sub.length();
                }
            }
        }
    }
    cout << maxlength << endl;
    return 0;
}