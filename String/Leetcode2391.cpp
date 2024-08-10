// 2391. Minimum Amount of Time to Collect Garbage
#include<iostream>
#include<vector>
using namespace std;
int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP = 0;
        int pickG = 0; 
        int pickM = 0; 

        int travelP = 0;
        int travelG = 0;
        int travelM = 0;

        int lastP = 0;
        int lastG = 0;
        int lastM = 0;

        for(int i=0;i<garbage.size();i++){
            string curr = garbage[i];
            // cout<<curr<<endl;
            for(int j=0;j<curr.length();j++){
                char ch = curr[j];
                // cout<<ch<<" ";
                if(ch == 'P'){
                    pickP++;
                    lastP = i;
                }
                else if(ch == 'G'){
                    pickG++;
                    lastG = i;
                }
                else if(ch == 'M'){
                    pickM++;
                    lastM = i;
                }
            }
            // cout<<pickP<<" "<<pickG<<" "<<pickM<<" "<<endl;
        }
        // calculate travel time
        for(int i=0;i<lastP;i++){
            travelP = travelP + travel[i];
        }
        for(int i=0;i<lastG;i++){
            travelG = travelG + travel[i];
        }
        for(int i=0;i<lastM;i++){
            travelM = travelM + travel[i];
        }

        int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);
        return ans;
}


int main(){
    vector<string> v = {"G","P","GP","GG"};
    vector<int> t = {2,4,3};

    int ans = garbageCollection(v,t);
    cout<<"Minimum Amount of Time to Collect Garbage "<<ans<<endl;
}