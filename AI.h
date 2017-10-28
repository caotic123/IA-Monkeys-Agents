#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <limits>
#include <algorithm>
#include <list>
#include <map>

#include "agent.h"
#include "agent_header.h"

#ifndef AI_H
#define AI_H

class AI {
public:
    void init___p(int a___, int agents_, int ra_, int rb_, int predator_____, bool graphics);
    pos m_to_tree(m_* m);
    void interact___();
    void ____realloc();
    bool check____f(int x, int y);
    bool get_search(std::list<int> ls, int i);
    m_* getMbyId(int i);
    void prepare_monkey_pos();
    void alert____(m_* _m, b _, int x_, int y_);
    m_* get_king();
    int distance__(pos s, pos y);
    bool has_monkey_in_area(pos pos_, int l_);
    bool is_dif_pos(pos pos_, pos _pos);
    pos less_monkey_pos(m_ m__);
    m_* more__distance___m(int area_view);
    void s__p_As(m_* m__, pos pos_);
    void init__floor();
    void set___graphics_(interface_* x);
    template <typename T>
    void _statistics(T buf, bool t);
    
private:
    floor__* f_x;
    m_* m___;
    std::map<int, pos> map_pos;
    int agents;
    int predator;
    int* e;
    bool screen;
    interface_* ___screen;
    int LEN_x;
    int LEN_y;
    int area_s;
    int area_view;
};

#endif
