#include<iostream>
using namespace std;

int main(){
    union{
        short value;
        char bytes[sizeof(short)];
    } test;
    
    test.value = 0x0102 ;
    //bytes0是低地址，01 是高位字节 ， 02是低位字节 
    //如果低地址(bytes[0])存储的高位字节(01),那么是大端
    //如果低地址(bytes[0])存储的低位字节(02),那么是小端
    if(test.bytes[0] == 1){
        cout<<"大端字节序"<<endl;
    }else if(test.bytes[0]==2){
        cout<<"小端字节序"<<endl;
    }else{
        cout<<"error"<<endl;
    }
}