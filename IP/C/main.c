#include <stdio.h>

#include <stdlib.h>

#include<netdb.h>

#include<arpa/inet.h>

#include<string.h>


int main(int argc, char *argv[]){
    if(argc != 2){
        
        fprintf(stderr, " %s Host \n", argv[0]);

        exit(1);
    }

    char *host = argv[1];

    struct addrinfo hints, *res, *p;

    int status;

    char ipstr[INET6_ADDRSTRLEN];

    memset(&hints,0, sizeof hints);

    hints.ai_family = AF_UNSPEC;

    hints.ai_socktype = SOCK_STREAM;

    if((status = getaddrinfo(host, NULL, &hints, &res)) != 0){

        fprintf(stderr, "%s \n", gai_strerror(status));
        
        exit(2);

    }

    printf("Endereço IP para %s:\n\n", host);

    for(p = res; p != NULL; p -> ai_next){
        
        void *addr;

        char *ipver;

        if(p-> ai_family == AF_INET){

            struct sockaddr_in *ipv4 = (struct sockaddr_in *) p->ai_addr;

            addr = &(ipv4-> sin_addr);
            
            ipver = "IPv4";
            
        }else{
            
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            
            addr = &(ipv6 -> sin6_addr);

            ipver = "IPv6";

        }

        inet_ntop(p-> ai_family, addr, ipstr, sizeof ipstr);
        
        printf("%s : %s\n", ipver, ipstr);

    }

}