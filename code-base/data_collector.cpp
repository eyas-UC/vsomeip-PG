#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include "vsomeip_server.h"


/* create a socket file descriptor FD using socket()
   then do
        1 create a server address struct
        2 bind the socket fd with the address structure
        3 listen using the socket fd
        4 accept connection requests
        5 reveive until exit is called
   then*/
   void ipc_handler()
   {
        int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

        // specifying the address
        sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(8090);
        std::cout<<"port is "<<serverAddress.sin_port<<std::endl;
        serverAddress.sin_addr.s_addr = INADDR_ANY;
        std::cout<<"address is "<<serverAddress.sin_addr.s_addr<<std::endl;

        // binding socket.
        bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

        // listening to the assigned socket
        listen(serverSocket, 5);
        // accepting connection request
        int clientSocket{accept(serverSocket, nullptr, nullptr)};

        // recieving data
        char buffer[1024] = { 0 };
        std::string std_buffer;
        while(std::strcmp("exit",std_buffer.c_str()) || std_buffer.length()==0)
        {
            std::cout<<"------------------------"<<std::endl;
            bzero(buffer,1024);
            auto ret = recv(clientSocket, buffer, sizeof(buffer), 0);
            if((0 ==ret) || (-1 == ret))
                break;
            std_buffer = std::string(buffer);
            std::cout <<"received ...>> "<< buffer << std::endl;
        }
        close(serverSocket);
   }
int main()
{
    std::thread ipc_thread{ipc_handler};
    
    ipc_thread.join();



	return 0;
}
