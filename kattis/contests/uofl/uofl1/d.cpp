#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    unordered_map<string, int> month = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6},
                                        {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
    while(n--){
        int day;
        string m;
        cin >> day;
        getline(cin,m);
        int m_int = month[m.substr(1, 3)];
        switch(m_int){
            case 1:
                if(day >= 21){
                    cout << "Aquarius" << endl;
                }else{
                    cout << "Capricorn" << endl;
                }
                break;
            case 2:
            if(day >= 20){
            cout << "Pisces" << endl;
            }else{
            cout << "Aquarius" << endl;
            }
            break;
            case 3:
            if(day >= 21){
            cout << "Aries" << endl;
            }else{
            cout << "Pisces" << endl;
            }
            break;
            case 4:
            if(day >= 21){
            cout << "Taurus" << endl;
            }else{
            cout << "Aries" << endl;
            }
            break;
            case 5:
            if(day >= 21){
            cout << "Gemini" << endl;
            }else{
            cout << "Taurus" << endl;
            }
            break;
            case 6:
            if(day >= 22){
            cout << "Cancer" << endl;
            }else{
            cout << "Gemini" << endl;
            }
            break;
            case 7:
            if(day >= 23){
            cout << "Leo" << endl;
            }else{
            cout << "Cancer" << endl;
            }
            break;
            case 8:
            if(day >= 23){
            cout << "Virgo" << endl;
            }else{
            cout << "Leo" << endl;
            }
            break;
            case 9:
            if(day >= 22){
            cout << "Libra" << endl;
            }else{
            cout << "Virgo" << endl;
            }
            break;
            case 10:
            if(day >= 23){
            cout << "Scorpio" << endl;
            }else{
            cout << "Libra" << endl;
            }
            break;
            case 11:
            if(day >= 23){
            cout << "Sagittarius" << endl;
            }else{
            cout << "Scorpio" << endl;
            }
            break;
            case 12:
            if(day >= 22){
            cout << "Capricorn" << endl;
            }else{
            cout << "Sagittarius" << endl;
            }
            break;
        }
    }
}