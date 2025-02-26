#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

void reciv(int rawSocket) {
    char buffer[2048]; // Buffer para armazenar os pacotes recebidos

    while (true) {
        ssize_t data_size = recv(rawSocket, buffer, sizeof(buffer), 0); 

        if (data_size < 0) {
            cerr << "Erro ao receber pacotes." << endl;
            break;
        }

        // Aqui você pode adicionar lógica para processar os pacotes recebidos
        // Exemplo: Mostrar o conteúdo do pacote
        cout << "Pacote recebido de tamanho: " << data_size << endl;
    }
}

int main() {
    // Criação de um socket raw
    int rawSocket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);  // A captura será de pacotes TCP
    if (rawSocket < 0) {
        cerr << "Erro ao criar o socket raw." << endl;
        return 1;
    }

    cout << "Socket raw criado com sucesso!" << endl;

    // Começar a captura de pacotes
    reciv(rawSocket);

    // Fechar o socket ao final
    close(rawSocket);
    return 0;
}
