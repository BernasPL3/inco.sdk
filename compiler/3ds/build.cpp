// compiler/3ds/build.cpp

#include <cstdlib>
#include <iostream>

void build3DS() {

    std::cout << "[INCO.SDK] Build Nintendo 3DS\n";

    // Criar pasta build
    system("mkdir -p build");

    // Compilar .cpp -> .elf
    int compile = system(
        "arm-none-eabi-g++ "
        "source/main.cpp "
        "-o build/game.elf "
        "-march=armv6k "
        "-mtune=mpcore "
        "-mfloat-abi=hard "
        "-mtp=soft "
        "-D__3DS__ "
        "-I/opt/devkitpro/libctru/include "
        "-L/opt/devkitpro/libctru/lib "
        "-lctru"
    );

    if(compile != 0) {
        std::cout << "Erro ao compilar ELF!\n";
        return;
    }

    std::cout << "ELF gerado!\n";

    // Gerar .3dsx
    int build3dsx = system(
        "3dsxtool "
        "build/game.elf "
        "build/game.3dsx"
    );

    if(build3dsx != 0) {
        std::cout << "Erro ao gerar 3DSX!\n";
        return;
    }

    std::cout << "3DSX gerado!\n";

    // Gerar ícone SMDH
    system(
        "bannertool makes
