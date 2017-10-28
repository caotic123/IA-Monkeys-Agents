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

#define S 10 // Don't change
#define vision_tree 3 // ((the total of map area/vision_tree)*2)
#define max_follow 30 // (vision of monkey "friend")

//architecture of mapping
#define len_tree 10
#define sub_tree 1

#include "interface.cpp"

enum b { t_ = 0,
    a_ = 1,
    c_ = 2,
    _n = 3 };

float ran_()
{
    float x;
    int n = 10;
    x = (float)(((rand() % (10 + 1 - 0) + 0))) / 10;
    return x;
}

// Mini-blibiotecas para auxiliar a codificação de tipos estaticos
template <typename T>
char* to_char(T i)
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

class m_ {
public:
    void init_agent()
    {
        m = (double**)malloc(sizeof(double*) * S - 1);
        d_ = (int*)malloc(sizeof(int) * 3);
        d = false;
        k_ = false;
        for (int i = 0; i <= (S - 1); i++) {
            m[i] = (double*)malloc(sizeof(double) * 3);
            for (int x = 0; x <= 2; x++) {
                m[i][x] = ran_();
            }
        }
    }

    void set__dir_vect(int x, int y)
    {
        d_[0] = x;
        d_[1] = y;
        d = true;
    }

    int add___x(int sx, b p_)
    {
        //	char* type = (char*)malloc(sizeof(char)*100);

        m[sx][(int)p_] += 0.1;
        // type = (char*)(p_==t_ ? "Tigre" : p_==a_ ? "Aguia" : p_==c_ ? "Cobra" :
        // "ERROR");
        // printf("Um macaquinho %d ouviu perigo de %s e ficou com valor %f\n",
        // ____id, type, m[__[0]][(int)p_]);
        return sx;
    }

    int x_get(b p_)
    {
        int i = 0;
        float x_ = 0;
        for (int p = 0; p <= 9; p++) {
            if (m[p][(int)p_] > x_) {
                x_ = m[p][(int)p_];
                i = p;
            }
        }
        return i;
    }

    void set_king(bool b = true)
    {
        k_ = b;
    }

    bool is_king()
    {
        return k_;
    }

    pos getp_P() { return pos_; }

    float get_y(int n, int y) { return m[n][y]; }

    void setPos(pos x) { memcpy(&pos_, &x, sizeof(x)); }

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
    void ___(int LEN_x___, int LEN_y___, bool screen__, interface_* screen = NULL)
    {
        f = new floor_*[LEN_x___];
        for (int i = 0; i <= (LEN_x___ - 1); i++) {
            f[i] = new floor_[LEN_y___];
        }

        tree_x = 0;
        tree_y = 0;
        d = (int*)malloc(sizeof(int) * 3);
        __pos(LEN_x___, LEN_y___);
        _generate_tree(LEN_x___, LEN_y___, screen__, screen);
    }

    template <typename T>
    void __insert(T m, pos pos_)
    {
        memcpy(&f[pos_.x][pos_.y].b_, &m, sizeof(m));
    }

    void apon___(m_* e, pos pos_)
    {
        f[pos_.x][pos_.y].a_s.push_back(e);
        f[pos_.x][pos_.y]._ = f[pos_.x][pos_.y]._ + 1;
    }

    int* d__(int x, int y, int x_, int y_)
    {
        d[0] = x + (x > x_ ? -1 : (x == x_) ? 0 : 1);
        d[1] = y + (y > y_ ? -1 : (y == y_) ? 0 : 1);
        return d;
    }

    bool check_tree(pos pos_)
    {
        if (f[pos_.x][pos_.y].t != 0) {
            return true;
        }
        return false;
    }

    std::list<m_*>* m_get___m(pos pos_) { return &f[pos_.x][pos_.y].a_s; }

    b b_get___b(pos pos_) { return f[pos_.x][pos_.y].b_; }

    int getM_s(pos pos_) { return f[pos_.x][pos_.y]._; }

    pos pos__(int x, int y, int limit_x, int limit_y)
    {
        pos pos_;
        pos_.x = 0;
        pos_.y = 0;
        int x_, y_;
        while (1) {
            x_ = (rand() % 3 + 1) - 2;
            y_ = (rand() % 3 + 1) - 2;
            if (x + x_ < limit_x && x + x_ > 0 && y + y_ < limit_y && y + y_ > 0) {
                pos_.x = x + x_;
                pos_.y = y + y_;
                return pos_;
            }
        }

        catch_error("Check you limit\n");
        return pos_;
    }

    void remove___m(m_* m, pos pos_)
    {
        m->set_king(false);
        f[pos_.x][pos_.y].a_s.remove(m);
        f[pos_.x][pos_.y]._ = f[pos_.x][pos_.y]._ - 1;
    }

    void delete____b(pos pos_) { f[pos_.x][pos_.y].b_ = _n; }

    int __;

    void _generate_image_tree(interface_* screen)
    {
        pos pos_;
        for (int x_ = tree_x - (len_tree - 1); x_ <= tree_x; x_++) {
            for (int y_ = tree_y - (len_tree - 1); y_ <= tree_y; y_++) {
                pos_.x = x_;
                pos_.y = y_;
                if (b_get___b(pos_) == _n && getM_s(pos_) < 1) {
                    screen->___print__floor(f[x_][y_].t, pos_);
                }
            }
        }
        return;
    }

    pos get_lower_pos_of_tree(pos from_pos)
    {
        pos pos_;
        int _ = tree_x * tree_y;
        int c_;
        for (int x_ = tree_x - (len_tree - 1); x_ <= tree_x; x_++) {
            for (int y_ = tree_y - (len_tree - 1); y_ <= tree_y; y_++) {
                c_ = ((from_pos.x - x_) > 0 ? (from_pos.x - x_) : ((from_pos.x - x_) * -1)) + ((from_pos.y - y_) > 0 ? (from_pos.y - y_) : ((from_pos.y - y_) * -1));
                if (c_ < _) {
                    pos_.x = x_;
                    pos_.y = y_;
                    _ = c_;
                }
            }
        }

        return pos_;
    }

    pos get_tree_pos()
    {
        pos pos_;
        pos_.x = tree_x;
        pos_.y = tree_y;
        return pos_;
    }

private:
    void __pos(int LEN_x_, int LEN_y_)
    {
        for (int x = 0; x <= (LEN_x_ - 1); x++) {
            for (int y = 0; y <= (LEN_y_ - 1); y++) {
                f[x][y].pos_.x = x + 1;
                f[x][y].pos_.y = y + 1;
                f[x][y]._ = 0;
                f[x][y].b_ = _n;
                f[x][y].t = 0;
            }
        }
    }

    void _generate_tree(int LEN_x_, int LEN_y_, bool screen_, interface_* screen)
    {
        pos pos_;
        int c_x, c_y;
        int x_ = 0, y_ = 0;
        bool _ = false;
        while (true) {
            tree_x = ((rand() % (LEN_x_ + 1 - 0) + 0));
            tree_y = ((rand() % (LEN_y_ + 1 - 0) + 0));
            if (tree_x >= (len_tree - 1) && tree_y >= (len_tree - 1) && tree_x <= LEN_x_ - tree_x && tree_y <= LEN_y_ - tree_y) {
                for (x_ = tree_x - (len_tree - 1); x_ <= tree_x; x_++) {
                    for (y_ = tree_y - (len_tree - 1); y_ <= tree_y; y_++) {
                        c_x = len_tree % 2 != 0 ? tree_x - ((len_tree - 1) / 2) - 1 : tree_x - ((len_tree - 1) / 2);
                        c_y = len_tree % 2 != 0 ? tree_y - ((len_tree - 1) / 2) - 1 : tree_y - ((len_tree - 1) / 2);
                        for (int i_ = 0; i_ <= sub_tree; i_++) {
                            if (y_ == (tree_y - (len_tree - 1)) + i_ || x_ == (tree_x - (len_tree - 1)) + i_ || x_ == tree_x - i_ || y_ == tree_y - i_) {
                                f[x_][y_].t = 2;
                                _ = true;
                            }
                        }
                        if (!_) {
                            f[x_][y_].t = 1;
                        }
                        if (screen_) {
                            pos_.x = x_;
                            pos_.y = y_;
                        }
                    }
                    _ = false;
                }
                return;
            }
        }

        return;
    }

    int tree_x;
    int tree_y;
    floor_** f;
    int* d;
};

class AI {
public:
    void init___p(int a___, int agents_, int ra_, int rb_, int predator_____,
        bool graphics)
    {
        LEN_x = a___;
        LEN_y = a___;
        area_s = ra_;
        area_view = rb_;
        agents = agents_;
        predator = predator_____;
        screen = graphics;
        int x, y, p;
        pos pos_;
        if (screen) {
            ___screen->init_(LEN_x, LEN_y);
        }

        init__floor();
        e = (int*)malloc(sizeof(int) * 9);
        for (int e_ = 0; e_ <= 9; e_++) {
            e[e_] = 0;
        }
        m___ = (m_*)malloc(sizeof(m_) * agents);
        for (int i = 0; i <= (agents - 1); i++) {
            x = rand() % ((LEN_x - 1) + 1 - 0) + 0;
            y = rand() % ((LEN_y - 1) + 1 - 0) + 0;
            pos_.x = x;
            pos_.y = y;
            m___[i].init_agent();
            m___[i].setPos(pos_);
            m___[i].____id = i;
            f_x->apon___(&m___[i], pos_);
            if (screen == true) {
                ___screen->__image((b)3, pos_, f_x->getM_s(pos_));
            }
        }

        for (int __ = 0; __ <= (predator - 1); __++) {
            x = rand() % ((LEN_x - 1) + 1 - 0) + 0;
            y = rand() % ((LEN_y - 1) + 1 - 0) + 0;
            p = rand() % (2 + 1 - 0) + 0;
            pos_.x = x;
            pos_.y = y;
            if (check____f(pos_.x, pos_.y) || f_x->getM_s(pos_) > 0) {
                __ = __ - 1;
            }
            else {
                f_x->__insert((p == 0) ? t_ : (p == 1) ? a_ : c_, pos_);
                if (screen == true) {
                    ___screen->__image((p == 0) ? t_ : (p == 1) ? a_ : c_, pos_, 1);
                }
            }
        }
    }

    pos m_to_tree(m_* m)
    {
        pos pos_ = m->getp_P();
        if (!f_x->check_tree(m->getp_P())) {
            pos_.x = f_x->d__(m->getp_P().x, m->getp_P().y, f_x->get_lower_pos_of_tree(m->getp_P()).x, f_x->get_lower_pos_of_tree(m->getp_P()).y)[0];
            pos_.y = f_x->d__(m->getp_P().x, m->getp_P().y, f_x->get_lower_pos_of_tree(m->getp_P()).x, f_x->get_lower_pos_of_tree(m->getp_P()).y)[1];
        }
        return pos_;
    }

    void interact___()
    {
        pos pos_;
        int i = 0;
        std::list<m_*> list_;
        m_* m_king;
        m_king = more__distance___m(area_view); //(area_view/vision_tree)*2
        if (m_king != NULL) {
            m_king->set_king();
            if (screen) {
                ___screen->__image(4, m_king->getp_P(), f_x->getM_s(m_king->getp_P()));
            }
        }

        for (int x = 0; x <= (LEN_x - 1); x++) {
            for (int y = 0; y <= (LEN_y - 1); y++) {
                pos_.x = x;
                pos_.y = y;
                if (f_x->getM_s(pos_) > 0) {
                    list_ = *f_x->m_get___m(pos_);
                    for (std::list<m_*>::iterator it = list_.begin(); it != list_.end(); ++it) {
                        i = i + 1;
                        s__p_As((*it), pos_);
                    }
                }
            }
        }

        if (screen) {
            f_x->_generate_image_tree(___screen);
        }

        if (screen) {
            _statistics((char*)NULL, false);
            ___screen->wait_and_continue();
        }

        ____realloc();
    }

    void ____realloc()
    {
        int x = 0, y = 0, p = 0;
        b b_re;
        pos pos_;
        int* pos_i;
        int* d;
        m_* m_king_ = get_king();
        pos __pos;

        pos pos__b[predator];
        b b_[predator];
        int n__ = 0;

        if (screen) {
            ___screen->clean_m();
        }
        
        prepare_monkey_pos();
        for (int x = 0; x <= (LEN_x - 1); x++) {
            for (int y = 0; y <= (LEN_y - 1); y++) {
                if (check____f(x, y)) {
                    pos__b[n__].x = x;
                    pos__b[n__].y = y;
                    b_[n__] = f_x->b_get___b(pos__b[n__]);
                    f_x->delete____b(pos__b[n__]);
                    n__ = n__ + 1;
                }
            }
        }

        for (int q = 0; q <= n__ - 1; q++) {
            pos__b[q] = f_x->pos__(pos__b[q].x, pos__b[q].y, LEN_x, LEN_y);
            f_x->__insert(b_[q], pos__b[q]);
            if (screen) {
                ___screen->__image((int)b_[q], pos__b[q], 1);
            }
        }

        for (int i = 0; i <= (agents - 1); i++) {
            f_x->remove___m(&m___[i], m___[i].getp_P());
        }

        for (int i = 0; i <= (agents - 1); i++) {
            if ((m_king_ != NULL && m_king_->____id == m___[i].____id)) {
                pos_ = m_to_tree(m_king_);
            }
            else {
                if (m_king_ != NULL) {
                    __pos = map_pos[m___[i].____id];
                    std::cout << std::endl;
                    std::cout << "id: " << m___[i].____id << " pos " << __pos.x << " " << __pos.y << std::endl;
                    d = f_x->d__(m___[i].getp_P().x, m___[i].getp_P().y, __pos.x, __pos.y);
                    pos_.x = d[0];
                    pos_.y = d[1];
                }
                else {
                    pos_ = f_x->pos__(m___[i].getp_P().x, m___[i].getp_P().y, LEN_x - 1, LEN_y - 1);
                }
            }

            if (check____f(pos_.x, pos_.y)) {
                pos_ = m___[i].getp_P(); // stay stopped
            }

            f_x->apon___(&m___[i], pos_);
            m___[i].setPos(pos_);
            std::cout << "id : " << m___[i].____id << " go to " << pos_.x << " " << pos_.y << std::endl;
            if (screen == true) {
                ___screen->__image(3, pos_, f_x->getM_s(pos_));
            }
        }
        
    }

    bool check____f(int x, int y)
    {
        pos pos_;
        pos_.x = x;
        pos_.y = y;
        if (f_x->b_get___b(pos_) != _n) {
            return true;
        }
        return false;
    }

    bool get_search(std::list<int> ls, int i)
    {
        std::list<int>::iterator it = std::find(ls.begin(), ls.end(), i);
        if (it != ls.end()) {
            return true;
        }
        return false;
    }

    m_* getMbyId(int i)
    {
    	for (int i__=0; i <= (agents-1); i__++) {
    		if (m___[i].____id == i) {
    			return &m___[i];
		  }
		}
    	return NULL;
    }

    void prepare_monkey_pos()
    {
        m_* m_king = get_king();
        m_* last_m = m_king;
        m_* re_m;
        int x_=0,y_=0;
        if (m_king == NULL) {
        	std::cout << "not king" << std::endl;
        	return;
		}
        int _ = LEN_x * LEN_y;
        int c_;
        pos pos_;
        pos_.x = m_king->getp_P().x;
        pos_.y = m_king->getp_P().y;
        std::list<int> lis__;
        std::list<m_*> iter_m;
        map_pos.clear();

        for (int i_ = 0; i_ <= (agents - 1); i_++) {
            lis__.push_back(i_);
        }
                            system("cls");

            while(lis__.size() > 1) {
                for (int i=0; i <= (agents-1); i++) {
                        x_ = m___[i].getp_P().x;
                        y_ = m___[i].getp_P().y;
                        c_ = ((pos_.x - x_) < 0 ? ((pos_.x - x_)*-1) : (pos_.x - x_)) + ((pos_.y - y_) < 0 ? ((pos_.y - y_)*-1)  : (pos_.y - y_));
                        if (get_search(lis__, m___[i].____id)  && m___[i].____id != last_m->____id)  {
                            if (c_ < _) {
                            _ = c_;
                            re_m = &m___[i];
                            }
                        }
                    }

            map_pos[re_m->____id] = last_m->getp_P();
            std::cout << "id: " << re_m->____id << " pos " << re_m->getp_P().x << " " << re_m->getp_P().y << " distance " << _ << " " << "id: " << last_m->____id << " pos " << last_m->getp_P().x << " " << last_m->getp_P().y << std::endl;
            lis__.remove(last_m->____id);
            last_m = re_m;
            pos_ = last_m->getp_P();
           _ = LEN_x*LEN_y;
           std::cout << _ << std::endl;
        }          
    }

    void alert____(m_* _m, b _, int x_, int y_)
    {
        pos pos_;
        int i;
        std::list<m_*> list_;
        std::list<m_*>::iterator it;
        int m[2] = { area_s, area_s };
        int x__ = ((m[0] % 2) == 0) ? (m[0] / 2) - 1 : (m[0] / 2);
        int y__ = ((m[1] % 2) == 0) ? (m[1] / 2) - 1 : (m[1] / 2);

        for (int x = x_ - (m[0] / 2); x <= x_ + x__; x++) {
            for (int y = y_ - (m[1] / 2); y <= y_ + y__; y++) {
                if (x < LEN_x && y < LEN_y && x >= 0 && y >= 0) {
                    pos_.x = x;
                    pos_.y = y;
                    if (screen && !check____f(pos_.x, pos_.y) && f_x->getM_s(pos_) < 1) {
                        ___screen->___print__floor(false, pos_);
                    }

                    if (f_x->getM_s(pos_) > 0 && _m->getp_P().x != pos_.x && _m->getp_P().y != pos_.y) {
                        i = 0;
                        list_ = *f_x->m_get___m(pos_);
                        for (it = list_.begin(); it != list_.end(); it++) {
                            if (_m->____id != (*it)->____id) {
                                e[(*it)->add___x(_m->x_get(_), _)] += 1;
                            }
                        }
                    }
                }
            }
        }
    }

    m_* get_king()
    {
        for (int i = 0; i <= (agents - 1); i++) {
            if (m___[i].is_king()) {
                return &m___[i];
            }
        }
        return NULL;
    }

    int distance__(pos s, pos y)
    {
        return (((s.x - y.x) > 0 ? (s.x - y.x) : ((s.x - y.x) * -1)) + ((s.y - y.y) > 0 ? (s.y - y.y) : ((s.y - y.y) * -1)));
    }

    bool has_monkey_in_area(pos pos_, int l_)
    {
        int t = 0;
        for (int i = 0; i <= (agents - 1); i++) {
            if (distance__(pos_, m___[i].getp_P()) < l_ && pos_.x != m___[i].getp_P().x && pos_.y != m___[i].getp_P().y)
                std::cout << "add" << std::endl;
            t = t + 1;
        }

        return (t == 0) ? false : true;
    }

    bool is_dif_pos(pos pos_, pos _pos)
    {
        return ((pos_.x != _pos.x && pos_.y != _pos.y) ? true : false);
    }

    pos less_monkey_pos(m_ m__)
    {
        pos l_pos = m__.getp_P();
        int x_ = l_pos.x, y_ = l_pos.y;
        int _ = LEN_x * LEN_y;
        pos pos_;
        int c_;
        x_ = m__.getp_P().x;
        y_ = m__.getp_P().y;
        for (int i = 0; i <= (agents - 1); i++) {
            std::cout << has_monkey_in_area(m__.getp_P(), (max_follow ^ 2)) << std::endl;
            if (distance__(m__.getp_P(), m___[i].getp_P()) < (max_follow ^ 2) && m__.____id != m___[i].____id && (!has_monkey_in_area(m__.getp_P(), max_follow ^ 2) || (has_monkey_in_area(m__.getp_P(), max_follow ^ 2) && is_dif_pos(m__.getp_P(), m___[i].getp_P())))) {
                pos_ = m___[i].getp_P();
                c_ = (pos_.x - x_) > 0 ? (pos_.x - x_) : ((pos_.x - x_) * -1) + ((pos_.y - y_) > 0 ? (pos_.y - y_) : ((pos_.y - y_) * -1));
                if (c_ < _) {
                    _ = c_;
                    l_pos.x = pos_.x;
                    l_pos.y = pos_.y;
                }
            }
        }
        return l_pos;
    }

    m_* more__distance___m(int area_view)
    {
        m_* _m = NULL;
        int x_ = 0, y_ = 0;
        int _ = LEN_x * LEN_y;
        pos pos_;
        int c_;
        int m[2] = { area_view, area_view };
        for (int i = 0; i <= (agents - 1); i++) {
            x_ = m___[i].getp_P().x;
            y_ = m___[i].getp_P().y;
            int x__ = ((m[0] % 2) == 0) ? (m[0] / 2) - 1 : (m[0] / 2);
            int y__ = ((m[1] % 2) == 0) ? (m[1] / 2) - 1 : (m[1] / 2);
            for (int x = x_ - (m[0] / 2); x <= x_ + x__; x++) {
                for (int y = y_ - (m[1] / 2); y <= y_ + y__; y++) {
                    if (x < LEN_x && y < LEN_y && x >= 0 && y >= 0) {
                        pos_.x = x;
                        pos_.y = y;
                        if (f_x->check_tree(pos_)) {
                            c_ = ((pos_.x - x_) > 0 ? (pos_.x - x_) : ((pos_.x - x_) * -1)) + ((pos_.y - y_) > 0 ? (pos_.y - y_) : ((pos_.y - y_) * -1));
                            if (c_ < _) {
                                _ = c_;
                                _m = &m___[i];
                            }
                        }
                    }
                }
            }
        }
        return _m;
    }

    void s__p_As(m_* m__, pos pos_)
    {
        int x_ = pos_.x;
        int y_ = pos_.y;
        pos b__;
        pos pos___;

        int m[2] = { area_view, area_view };

        int x__ = ((m[0] % 2) == 0) ? (m[0] / 2) - 1 : (m[0] / 2);
        int y__ = ((m[1] % 2) == 0) ? (m[1] / 2) - 1 : (m[1] / 2);

        for (int x = x_ - (m[0] / 2); x <= x_ + x__; x++) {
            for (int y = y_ - (m[1] / 2); y <= y_ + y__; y++) {
                if (x < LEN_x && y < LEN_y && x >= 0 && y >= 0) {
                    pos___.x = x;
                    pos___.y = y;
                    if (check____f(x, y)) {
                        b__.x = x;
                        b__.y = y;
                        alert____(m__, f_x->b_get___b(b__), m__->getp_P().x,
                            m__->getp_P().y);
                    }
                }
            }
        }
    }

    void init__floor()
    {
        f_x = new floor__;
        f_x->___(LEN_x, LEN_y, screen, ___screen);
        f_x->__ = 12;
    }

    void set___graphics_(interface_* x) { ___screen = x; }

    template <typename T>
    void _statistics(T buf, bool t)
    {
        char x[1000] = "Dados :\n";
        char buffer[100];
        char int_[1000];
        int s;
        int a = 7;
        std::string c;
        bool screen__ = (t == false ? true : false);

        if (screen__) {
            goto msg;
        }

        for (int i = 0; i <= 9; i++) {
            s = sprintf(buffer, "was used %d %d times\n", i, e[i]);
            a = a + s;
            strncat(x, buffer, a);
        }

        a = 0;
    msg:
        for (int i = 0; i <= (agents > 10 ? 10 : agents - 1); i++) {
            if (screen__) {
                sprintf(buffer, "%d", i);
                c = (std::string) "Monkey " + buffer + (std::string) "={tigre = " + std::string(to_char(m___[i].x_get(t_))) + (std::string) ", aguia = " + std::string(to_char(m___[i].x_get(a_))) + (std::string) ", cobra = " + std::string(to_char(m___[i].x_get(c_))) + "}";
                ___screen->___print(c);
            }
            else {
                s = sprintf(buffer, "Monkey %d = {tigre = %d aguia = %d cobra = %d}\n",
                    i, m___[i].x_get(t_), m___[i].x_get(a_), m___[i].x_get(c_));
                a = a + s;
                strncat(x, buffer, a);
            }
        }

        if (!screen__) {
            strcpy(buf, x);
        }
    }

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

int main(int argc, char** argv)
{
    char cons_[1000] = "";
    srand(time(NULL));
    int x = 100;
    int i = 0;
    std::string __, conf;
    int a___ = 0, agents__ = 0, predator____ = 0, rb____ = 16, ra____ = 10,
        it____ = 0;
    bool graph;
    interface_* screen;
    AI* ___AI;

    printf("                            AI - Intelligent Agents\n");
    std::cout << "This project of IA and principally intelligent agents has the "
                 "purpose of\nto study the factors, standards, math calcs, "
                 "behavior and logic in imperative language of programming."
              << std::endl;

    printf("What configuration you want? \"normal\" or \"higher\"\n");
    std::cin >> conf;
    if (conf == "higher" or conf == "HIGHER") {
        printf("Set area of precision of monkey vision!(only intenger number)\n");
        while (!getInt_Input(rb____)) {
            printf("Please digit one new valid number (intenger) \n");
        }
        printf("Set area of precision of monkey alert!(only intenger number)\n");
        while (!getInt_Input(ra____)) {
            printf("Please digit one new valid number (intenger) \n");
        }
    }

    printf(
        "Please define the area of your agents will be to insired (only one "
        "intenger number)");
    while (!getInt_Input(a___)) {
        printf("Please digit one new valid number (intenger) \n");
    }
    printf(
        "Please define the number of agents will be to insired its strongly "
        "recommend one number in between (1 and 10)\nCase number its higher of "
        "10 the mini-display don't show all monkeys only of\n firsts ten (only "
        "one intenger number)");

    while (!getInt_Input(agents__)) {
        printf("Please digit one new valid number (intenger) \n");
    }

    printf(
        "Please define the number of predators will be to insired its strongly "
        "recommend one number in between (1 and 10) (only one intenger number)");

    while (!getInt_Input(predator____)) {
        printf("Please digit one new valid number (intenger) \n");
    }

    printf("Please define the number of iterations\n");

    while (!getInt_Input(it____)) {
        printf("Please digit one new valid number (intenger) \n");
    }

    printf("Active mode graphical?\n");
    std::cin >> __;
    if (__ == "true" || __ == "TRUE" || __ == "YES" || __ == "yes") {
        graph = true;
        printf("Mode graphical actived\n");
    }
    else {
        graph = false;
        printf("Mode graphical OFF\n");
    }

    screen = new interface_;
    ___AI = new AI;
    if (graph) {
        ___AI->set___graphics_(screen);
    }
    ___AI->init___p(a___, agents__, ra____, rb____, predator____, graph);
    for (i = 0; i < it____;) {
        ___AI->interact___();
        i++;
    }
    ___AI->_statistics(cons_, true);
    printf("%s\n", cons_);

    if (graph) {
        screen->close___();
    }

    printf("Enter whatever key of to continue\n");
    delete ___AI;
    system("pause");

    return 0;
}
