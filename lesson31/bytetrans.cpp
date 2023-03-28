#include<iostream>
#include<arpa/inet.h>
#include<cstdio>
int main(){
    // //转换端口
    // htons();
    // ntohs();
    // //转换ip
    // htonl();
    // ntohl();
    unsigned short a = 0x0102;
    unsigned short b = htons(a);
    std::cout<<std::hex<<"a:"<<a<<std::endl<<"b:"<<b<<std::endl; //std::hex 是 以16进制输出结果

    std::cout<<"============================\n";

    unsigned char buf[4] = {192,168,10,132};

    int num = *(int *)buf;
    int transnum = htonl(num);
    unsigned char *p = (unsigned char*)&transnum;
    printf("%d %d %d %d",*p,*(p+1),p[2],p[3]);
}