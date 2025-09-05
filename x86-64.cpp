#include <iostream>
#include <string>
int main() {
    std::string input {};
    std::cout << "Enter what print: ";
    std::cin >> input;
    asm (           // can be with 'volatile' keyword
        ".intel_syntax noprefix \n\t"
        "mov rax, 1 \n\t"
        "mov rdi, 1 \n\t"
        "lea rsi, BYTE PTR [%0] \n\t"
        "mov rdx, %1 \n\t"
        "inc rdx \n\t"
        "syscall \n\t"
        "push 10 \n\t"
        "mov rax, 1 \n\t"
        "mov rdi, 1 \n\t"
        "lea rsi, BYTE PTR [rsp] \n\t"
        "mov rdx, 1 \n\t"
        "syscall \n\t"
        "add rsp, 8 \n\t" // adding 8 because push by default doing 8 byte operation
        ".att_syntax prefix \n\t"
        :
        : "r" (input.c_str()), "r" (input.length())
        : "rax", "rdi", "rsi", "rdx", "memory"
    );
}
