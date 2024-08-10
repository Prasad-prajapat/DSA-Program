#include <iostream>
using namespace std;

string encrypt(string text, int s)
{
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])){
            result += char(int(text[i] + s - 65) % 26 + 65);
        }
        else if(islower(text[i])){
            result += char(int(text[i] + s - 97) % 26 + 97);
        }
        else{
            cout<<"Invalid character: "<<text[i]<<endl;
        }
    }
    return result;
}

int main()
{
     string text;
    cout<<"Enter the input String: ";
    cin>>text;
    cout<<"Enter the shift value: ";
    int x;
    cin>>x;
    
    string ans = encrypt(text,x);
    cout<<"encrypt string: "<<ans;
}
