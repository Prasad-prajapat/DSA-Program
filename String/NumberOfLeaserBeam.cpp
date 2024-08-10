#include<iostream>
#include<vector>
using namespace std;

int countDevices(string &binary){
    int c = 0;
    for(auto ch: binary){
        c = c + ch - '0';
    }
    return c;
}

int numberOfBeam(vector<string>& bank){
    vector<int>devices;
    for(auto row: bank){
        devices.push_back(countDevices(row));
    }
    int beam =0;

    for(int i=0;i<devices.size();i++){
        int j = i+1;
        while(j<devices.size()){
            beam = beam + devices[i]*devices[j];
            if(devices[j] == 0){
                j++;
            }
            else{
                break;
            }
        }
    }
    return beam;
}

int main(){
    vector<string> v = {"011001","000000","010100","001000","111011"};
    int ans = numberOfBeam(v);
    cout<<ans;
}