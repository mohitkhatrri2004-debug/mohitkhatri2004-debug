#include<bits/stdc++.h>
using namespace std;
int main(){

    //pairs
    pair<int,int>arr[] = {{1,3},{2,5},{3,7}};
    for(int i=0;i<3;i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
    pair<int,pair<int,int>> p = {1,{1,2}};
    cout << p.first << "\n" << p.second.first << " " << p.second.second;

    //Vectors
    vector<int> nums = {1,2,3,4,5};
    int n = nums.size();
    nums.push_back(6);
    cout << endl;
    vector<int> vec(nums);
    for(auto it=vec.begin();it != vec.end();it++){
        cout << *it << " ";
    }
    cout << endl;
    for(auto it : vec){
        cout << it << " ";
    }
    vec.erase(vec.begin() + 2);
    cout << endl;
    for(auto it : vec){
        cout << it << " ";
    }
    vec.erase(vec.begin()+1,vec.begin() + 3);
    cout << endl;
    for(auto it : vec){
        cout << it << " ";
    }
    vec.insert(vec.begin()+1,300);
    cout << endl;
    for(auto it : vec){
        cout << it << " ";
    }
    vector<int>copy = {50,50};
    vec.insert(vec.begin(),copy.begin(),copy.end());
    cout << endl;
    for(auto it : vec){
        cout << it << " ";
    }
    
    return 0;
}