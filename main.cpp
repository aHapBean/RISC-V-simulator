#include <iostream>
#include <cstring>
#include "cpu.hpp"

void init(cpu * &RISCV){
    RISCV->init(std::cin);
}
int main(){
    cpu *RISCV = new cpu;
    init(RISCV);
    RISCV->pipeRUN();
    delete RISCV;
    return 0;
}
