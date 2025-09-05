#include <iostream>
#include <string>
int main() {
    std::string message {};
    std::cout << "Enter what print: ";
    std::cin >> message;
    asm(                    // can be with 'volatile' keyword
        "mov x0, #1 \n\t"       // file descriptor
        "mov x8, #64 \n\t"     // write   
        "mov x1, %0 \n\t"      // what write
        "mov x2, %1 \n\t"       // length of what write   
        "svc 0 \n\t"             
        "eor x0, x0, x0 \n\t"   
        "mov x8, #93 \n\t"    
        "svc 0 \n\t"
        :
        :  "p"(message.c_str()), "p"(message.length())
        : "x0", "x1", "x2", "x8", "memory"
    );
}
