#include <iostream>

int main(int argc, char* argv[]) {

    if(argc < 2) {
        std::cout << "INCO.SDK\n";
        return 0;
    }

    std::string cmd = argv[1];

    if(cmd == "new") {

        std::cout << "Criando projeto...\n";
    }

    if(cmd == "build") {

        std::cout << "Compilando projeto...\n";
    }

    return 0;
}
