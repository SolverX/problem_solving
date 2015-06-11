#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char T[]= "True";
char F[]= "False";
char* triplet_sum(int input1[],int input2,int input3)
{
    for(int i=0;i<input2;i++){
        if(input1[i]<=input3){
            for(int j=i+1;j<input2;j++)
                if(input1[i]+input1[j]<= input3){
                    for(int k=j+1;k<input2;k++){
                        if(input1[i]+input1[j]+input1[k] == input3){
                            return T;
                        }
                    }
                }

        }
    }
    return F;
}

int main(){
    int input1[]={1,4,45,6,10,8};
    // int input1[]={1,3,12,4};
    cout<<triplet_sum(input1,6,22)<<endl;
    return 0;
}