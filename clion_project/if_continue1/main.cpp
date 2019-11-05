#include <iostream>

int main() {
    int i=0;
    while (i<10)
    {
        if(i<9)
        {
//            continue;
            if(i<8)
            {
//                continue;
                break;
                std::cout << "Hello, World!" << std::endl;
            }
        }
        i++;
    }

    return 0;
}