#include <string>
#include <sstream>
#include <stdlib.h> 
#include <iostream>

#define S 10 // Don't change
#define vision_tree 3 // ((the total of map area/vision_tree)*2)
#define max_follow 30 // (vision of monkey "friend")

//architecture of mapping
#define len_tree 10
#define sub_tree 1

#ifndef AGENT_HEADER_H
#define AGENT_HEADER_H

enum b { t_ = 0,
    a_ = 1,
    c_ = 2,
    _n = 3 };

float ran_();
char* to_char(int i);
bool getInt_Input(int& x);
void catch_error(const char* error_msg);

#endif
