#include "agent_header.h"

float ran_()
{
    float x;
    int n = 10;
    x = (float)(((rand() % (10 + 1 - 0) + 0))) / 10;
    return x;
}

char* to_char(int i)
{
    std::stringstream buffer;
    char* x = (char*)malloc(sizeof(char) * 100);
    buffer << (int)i;
    return (char*)buffer.str().c_str();
}

bool getInt_Input(int& x)
{
    char buffer[100];
    std::cin >> buffer;
    x = atoi(buffer);
    return atoi(buffer) ? true : false;
}

void catch_error(const char* error_msg)
{
    printf("Error\n%s\n", error_msg);
    system("pause");
    system("exit");
    return;
}
