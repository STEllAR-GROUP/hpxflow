#include <vector>
#include <iostream>
#include <string>

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>
#include <fstream>    
#include <typeinfo>


#include <typeinfo>
#include <queue>
#include <thread>
#include <assert.h>

#include <pthread.h> //for threading , link with lpthread
 
void *connection_handler(void *);

using namespace nlohmann;
using namespace RedisCluster;

int runProcessing() {
    int socket_desc , new_socket , c , *new_sock;
    struct sockaddr_in server , client;
    char *message;

    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
     
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8885 );
     
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("bind failed");
        return 1;
    }
    puts("bind done");
     
    listen(socket_desc , 3);
     
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
         
        pthread_t sniffer_thread;
        new_sock = (int *)malloc(1);
        *new_sock = new_socket;
         
        if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }

    }
     
    if (new_socket<0)
    {
        perror("accept failed");
        return 1;
    }
     
    return 0;
}


void *connection_handler(void *socket_desc)
{

    int sock = *(int*)socket_desc;
    int read_size;
    json object;
    long long countIter;
    const char *s1;
    int passing;
    std::vector<const char *> vect3;
    long long count;
    const char *interString;
    std::ifstream file;
     

     
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        
    }
    
    if(read_size == 0)
    {
        my_printf("Client Disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        my_printf("recv failed");
    }
         
    free(socket_desc);
    file.close(); 
    return 0;
}