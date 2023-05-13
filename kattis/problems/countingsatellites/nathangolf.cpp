#include<iostream>
long i=270,k,h=8,m;
long b(){
    return(h--) ? b()*(i+8-h)/++h : 1|i--&&h++;
}
main(){
    for(std::cin>>k;i+=3;k%=m)
        std::cout<<std::string(k/(m=b()+9*b()+27*(b()+b())),'S')+"ATELLITE";
}