
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 80

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char hello[] =
        "GET http://www.google.com/ HTTP/1.1\nUser-Agent: Mozilla/4.0 "
        "(compatible; MSIE5.01; Windows NT)\nHost: localhost\nAccept-Language: "
        "en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n\n";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(sock, hello, strlen(hello), 0);
    const int MAX_BYTES = 1024;
    int available = 0;
    int retry_count = 0;
    int MAX_RETRY = 3;
    while (1 > 0) {
        valread = read(sock, buffer, MAX_BYTES);
        if (valread > 0) {
            printf("%s", buffer);
        }
        if (valread < MAX_BYTES) {
            break;
        }
    }
    close(sock);
    return 0;
}