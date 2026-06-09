#include <cstdlib>
#include <iostream>

void buildPSP() {

    system(
        "psp-gcc source/main.c "
        "-o game.elf "
        "-lpspdebug"
    );

    system(
        "pack-pbp EBOOT.PBP PARAM.SFO NULL "
        "NULL NULL NULL NULL game.elf NULL"
    );

    std::cout << "EBOOT.PBP gerado!\n";
}
