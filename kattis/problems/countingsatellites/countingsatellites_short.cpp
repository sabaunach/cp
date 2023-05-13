#include <bits/stdc++.h>
using namespace std;
int main(){
using l=long long;
l k,b=400,j,i=0;
cin>>k;
list<l> p[26];
string a="ATELLITE",t='S'+a;
for(;i<9;i++)p[t[i]-'A'].push_front(i);
vector<l> c(10),s={0},v;c[0]=1;
for(j=0;++j<b;){for(i=0;i<9;i++)for(int x:p[t[i]-'A'])c[x+1]+=c[x];s.push_back(c[9]);}
for(;--j>0;)s[j]-=s[j-1],cout<<string(k/s[j],'S')+a,k%=s[j];
}