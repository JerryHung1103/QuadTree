#include <iostream>
using namespace std;
#include <vector>

//secret I generate it randomly!
vector<int> Nuts= {17, 3, 6, 9, 10, 16, 11, 5, 13, 7, 15, 19, 8, 12, 1, 4, 2, 14, 20, 18};
vector<int> Bolts={14, 20,7, 11, 18, 5, 10, 2, 17, 8, 16, 19, 6, 12, 1, 3, 13, 15, 4, 9};
int n=Nuts.size();

int compare(int i , int j){
    if(Nuts[i-1]==Bolts[j-1]) return 0;
    return Nuts[i-1]<Bolts[j-1]?-1:1;
}
vector<pair<int,int>> matching_pair;
int maxBolts(){
    int i=1,j=1;
    while(i<=n and j<=n){
        int result = compare(i,j);
        if(result==0){
            matching_pair.push_back({i,j});
            i++;j++;
        }
        else if(result==1){
            j++;
        }
        else if(result==-1){
            i++;
        }
    }
    int maxBolts=matching_pair[0].second;
    for(auto u : matching_pair){
        if(compare(u.first,maxBolts)==1)
            maxBolts=u.second;
    }
    return maxBolts;
}

int main(){
cout<<"the "<<maxBolts()<<"-th bolt is largest!!!"<<endl;;
}
