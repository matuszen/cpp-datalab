#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#endif

#include "../src/matrix.cpp"

int main(const int argc, const char** argv) try {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    matrix A(3, 4);

    A += 2;

    std::cout << A;
    
    std::cout << std::endl;
    return 0;

} catch (std::exception& e) {
    std::cout << e.what() << std::endl;

    return 1;
}
