#include <list>
#include "interface.h"
#include "agent_header.h"

#ifndef AGENT_H
#define AGENT_H

class m_ {
public:
void init_agent();
void set__dir_vect(int x, int y);
int add___x(int sx, b p_);
int x_get(b p_);
void set_king(bool b = true);
bool is_king();
pos getp_P();
float get_y(int n, int y);
void setPos(pos x);
int ____id;

private:
double** m;
pos pos_;
int* d_;
bool d;
bool k_;
};

typedef struct {
    pos pos_;
    std::list<m_*> a_s;
    int p;
    b b_;
    int _;
    int t;
} floor_;


class floor__ {
public:
void ___(int LEN_x___, int LEN_y___, bool screen__, interface_* screen = NULL);
void __insert(b m, pos pos_);
void apon___(m_* e, pos pos_);
int* d__(int x, int y, int x_, int y_);
bool check_tree(pos pos_);
std::list<m_*>* m_get___m(pos pos_);
b b_get___b(pos pos_);
int getM_s(pos pos_);
pos pos__(int x, int y, int limit_x, int limit_y);
void remove___m(m_* m, pos pos_);
void delete____b(pos pos_);
void _generate_image_tree(interface_* screen);
pos get_lower_pos_of_tree(pos from_pos);
pos get_tree_pos();
int __;
private:
void __pos(int LEN_x_, int LEN_y_);
void _generate_tree(int LEN_x_, int LEN_y_, bool screen_, interface_* screen);
int tree_x;
int tree_y;
floor_** f;
int* d;
};

#endif
