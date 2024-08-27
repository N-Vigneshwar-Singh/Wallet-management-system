#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int p;
vector<pair<int,int>>vec;
bool compare(pair<int,int>&a,pair<int,int>&b){
    if(a.second==b.second){
        return a.first>b.second;
    }
    return a.second<b.second;
}
int user(int& a){
    for(int k=0;k<p;k++){
        if(vec[k].first==a){
            return k;
        }
    }
    return 0;
}
int main(){
    cin>>p;
    for(int i=0;i<p;i++){
        int b,a;
        cin>>b>>a;
        vec.push_back({b,a});
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y,a;
        cin>>x>>y>>a;
        int xl=user(x);
        int yl=user(y);
        if(vec[xl].second>=a){
            vec[xl].second-=a;
            vec[yl].second+=a;
            cout<<"Success\n";
        }
        else{
            cout<<"Failure\n";
        }
    }
    cout<<"\n";
    sort(vec.begin(),vec.end(),compare);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].first<<" "<<vec[i].second<<"\n";
    }
    return 0;
}