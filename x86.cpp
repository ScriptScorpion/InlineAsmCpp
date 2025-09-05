#include <iostream>
#include <string>
int main() {
    std::string input {};
    std::cout << "Enter what print: ";
    std::cin >> input;
    asm volatile (           // can be with 'volatile' keyword
        ".intel_syntax noprefix \n\t"
        "mov eax, 4 \n\t"
        "mov ebx, 1 \n\t"
        "lea ecx, [%0] \n\t"
        "mov edx, %1 \n\t"
        "inc edx \n\t"
        "int 0x80 \n\t"
        "push 0x0A \n\t"
        "mov eax, 4 \n\t"
        "mov ebx, 1 \n\t"
        "lea ecx, [esp] \n\t"
        "mov edx, 1 \n\t"
        "int 0x80 \n\t"
        "add esp, 4 \n\t" // adding 4 because push by default doing 4 byte operation in 32 bit mode
        ".att_syntax prefix \n\t"
        :
        : "r" (input.c_str()), "r" (input.length())
        : "eax", "ebx", "ecx", "edx", "memory"
    );
}
