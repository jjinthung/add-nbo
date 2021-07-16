#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE* fp = 0;
    FILE* fp2 = 0;
    u_int8_t data[4];
    u_int8_t data2[4];

    char file_address[50] = "/home/jinsung/untitled3/";
    char file_address2[50] = "/home/jinsung/untitled3/";

    strcat(file_address,argv[1]);
    strcat(file_address2,argv[2]);


    fp = fopen(file_address,"rb");
    fp2 = fopen(file_address2,"rb");

    if(fp == 0)
    {
        fprintf(stderr, "오류\n");
        return 1;
    }

    if(fp2 == 0)
    {
        fprintf(stderr, "오류\n");
        return 1;
    }


    fread(data,sizeof(int),4,fp);
    fread(data2,sizeof(int),4,fp2);



    u_int32_t* p = reinterpret_cast<u_int32_t*>(data);
    u_int32_t* p2 = reinterpret_cast<u_int32_t*>(data2);

    u_int32_t n = ntohl(*p);
    u_int32_t n2 = ntohl(*p2);

    printf("0x%x + 0x%x = 0x%x\n",n,n2,n+n2);
    printf("%d + %d = %d\n",n,n2,n+n2);



    fclose(fp);
    fclose(fp2);

    return 0;
}





