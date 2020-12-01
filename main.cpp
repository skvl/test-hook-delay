#include <cstring>
#include <iostream>
#include <string>

#include <Windows.h>


const char* lorem_ipsum =
    "    Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."
    " Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."
    " Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur."
    " Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

int main(int argc, char** argv)
{
    const char* dummy[128] = { 0 };
    auto start = GetTickCount64();
    for (int i = 0; i < 1000000; ++i)
    {
        for (int c = 'a'; c < 'z'; ++c)
            dummy[c] = strrchr(lorem_ipsum, c);
        for (int c = 'A'; c < 'Z'; ++c)
            dummy[c] = strrchr(lorem_ipsum, c);
    }
    auto end = GetTickCount64();

    std::cout << "Start at " << start << ", finish at " << end << ", elapsed " << end - start;
    if (end - start > 5000)
        std::cout << "Too long! Are you hooked? ;)";
    std::cout << std::endl;

    return 0;
}
