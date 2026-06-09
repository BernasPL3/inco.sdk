// compiler/3ds/build.cpp

#include <cstdlib>
#include <iostream>

void build3DS() {

    std::cout << "[INCO.SDK] Nintendo 3DS Build\n";

    system("mkdir -p build");

    // Compilar ELF
    int compile = system(
        "./toolchains/3ds/arm-none-eabi-g++ "
        "source/main.cpp "
        "-o build/game.elf"
    );

    if(compile != 0) {
        std::cout << "Erro ao compilar ELF\n";
        return;
    }

    std::cout << "ELF gerado!\n";

    // Gerar 3DSX
    int build3dsx = system(
        "./toolchains/3ds/3dsxtool "
        "build/game.elf "
        "build/game.3dsx"
    );

    if(build3dsx != 0) {
        std::cout << "Erro ao gerar 3DSX\n";
        return;
    }

    std::cout << "3DSX gerado!\n";

    // Criar SMDH
    system(
        "./toolchains/3ds/bannertool makesmdh "
        "-s \"MarioClone3DS\" "
        "-l \"INCO.SDK\" "
        "-p \"Bernardo\" "
        "-i icon.png "
        "-o build/icon.icn"
    );

    // Gerar CIA
    system(
        "./toolchains/3ds/makerom "
        "-f cia "
        "-o build/game.cia "
        "-elf build/game.elf "
        "-icon build/icon.icn"
    );

    std::cout << "CIA gerado!\n";
}
