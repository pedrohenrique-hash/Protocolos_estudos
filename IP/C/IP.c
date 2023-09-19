#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<unistd.h>

#include<arpa/inet.h>

#include<netinet/in.h>

#include<sys/socket.h>

int main(){
	
	int server_socket, client_socket;
	
	struct sockaddr_in server_address, client_address;
	
	socklen_t client_address_len;
	
	char buffer[1024];
	
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	if(server_socket == -1){
		
		perror("SOCKET ERROR");
		
		exit(1);
	
	}
	
	memset(&server_address, 0 , sizeof(server_address));
	
	server_address.sin_family = AF_INET;
	
	server_address.sin_port = htons(8080);
	
	server_address.sin_addr.s_addr = INADOR_ANY;
	
	
	if(bind(server_socket, (struct socketaddr *)&server_address, sizeof(server_address))== -1){
		
		perror("BIND ERROR");
		
		close(server_socket);
		
		exit(1);
		
	}
	
	
	if(listen(server_socket, 5)== -1 ){
		
		perror("ERROR");
		
		close(server_socket);
		
		exit(1);
	}
	
	
	printf("Connect server");
	
	
	while(1){
		
		client_address_len = sizeof(client_address);
		
		client_socket = accept(sever_socket, (struct sockaddr *) &client_address, &client_address_len);
		
		if(client_socket == -1){
			
			perror("erro client");
			
			continue;
				
		}
		
		printf("Data %.s\n", (int)bytes_received, buffer);
		
		close(client-socket);
	
	}
	
	close(server_socket);
	
	return 0;
	
}
