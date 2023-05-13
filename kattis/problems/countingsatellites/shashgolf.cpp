#include<iostream>
long B[400],I=9;
main(long n){
    std::cin>>n;
    for(B[8]=1;B[0]<=n;B[I++]=B[0])
        for(int i:"27165343427160")
            B[i-48]+=B[i-47];
    while(I-->9)
        std::cout<<std::string(n/B[I],'S')<<"ATELLITE",n%=B[I];
}