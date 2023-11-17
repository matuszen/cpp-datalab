#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#endif

int main(const int argc, const char** argv) try {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    std::cout << "Hello world!" << std::endl;
    
    return 0;

} catch (std::exception& e) {
    std::cout << e.what() << std::endl;

    return 1;
}
