#include "AI.h"

void AI::init___p(int a___, int agents_, int ra_, int rb_, int predator_____,
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

void AI::createAlert(m_* m) {
	pos pos_ = m->getp_P();
	int __alert = 30;
	int l;
	int x_ = m->getp_P().x, y_ = m->getp_P().y;
	for (int i= (__alert/2); i >= -(__alert/2); i--) {
	  for (int _= (1 * (((i * (0-i))+(__alert/2)+1)/2)); _ >= (-1 * (((i * (0-i))+(__alert/2)+1)/2)); _--) {
	      if (pos_.x+_ < LEN_x && pos_.y+i < LEN_y && pos_.x+_ >= 0 && pos_.y+i  >= 0) {
	  	    pos_.x = pos_.x+_;
	  	    pos_.y = pos_.y+i;
	  	    if (screen && f_x->getM_s(pos_) < 1 && !check____f(pos_.x, pos_.y)) {
	  	    l = (((pos_.x - x_) > 0) ? (pos_.x - x_) : ((pos_.x - x_) * -1)) + (((pos_.y - y_) > 0) ? (pos_.y - y_) : ((pos_.y - y_) * -1));
	  	      ___screen->___print__floor(100+((l^3)*l), pos_);
	  	    }
	  	    
	  	   pos_.x = pos_.x-_;
	  	   pos_.y = pos_.y-i;
	     }
	  }
   }
}

void AI::interact___()
{
    pos pos_;
    int i = 0;
    std::list<m_*> list_;
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

void AI::____realloc()
{
    int x = 0, y = 0, p = 0;
    b b_re;
    pos pos_;
    int* pos_i;
    int* d;
    pos __pos;
    pos back_pos;
    m_* prey__m = NULL;

    pos pos__b[predator];
    b b_[predator];
    int n__ = 0;

    if (screen) {
        ___screen->clean_m();
    }

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
    	prey__m = m_prey(pos__b[q], 10, 10);
    	back_pos = pos__b[q];
    	if (prey__m != NULL) {
    		pos__b[q].x = f_x->d__(back_pos.x, back_pos.y, prey__m->getp_P().x, prey__m->getp_P().y)[0];
    		pos__b[q].y = f_x->d__(back_pos.x, back_pos.y, prey__m->getp_P().x, prey__m->getp_P().y)[1];
		}
		else {
        pos__b[q] = f_x->pos__(pos__b[q].x, pos__b[q].y, LEN_x, LEN_y);
        }
        if (check____f(pos__b[q].x, pos__b[q].y)) {
        	pos__b[q] = back_pos;	
		}
		
        f_x->__insert(b_[q], pos__b[q]);
        if (screen) {
            ___screen->__image((int)b_[q], pos__b[q], 1);
		}
    }

    for (int i = 0; i <= (agents - 1); i++) {
        f_x->remove___m(&m___[i], m___[i].getp_P());
    }

    for (int i = 0; i <= (agents - 1); i++) {
        pos_ = f_x->pos__(m___[i].getp_P().x, m___[i].getp_P().y, LEN_x - 1, LEN_y - 1);
        
        if (check____f(pos_.x, pos_.y)) {
            pos_ = m___[i].getp_P(); // stay stopped
        }

        f_x->apon___(&m___[i], pos_);
        m___[i].setPos(pos_);
        if (screen == true) {
            ___screen->__image(3, pos_, f_x->getM_s(pos_));
        }
    }
}

bool AI::check____f(int x, int y)
{
    pos pos_;
    pos_.x = x;
    pos_.y = y;
    if (f_x->b_get___b(pos_) != _n) {
        return true;
    }
    return false;
}

bool AI::get_search(std::list<int> ls, int i)
{
    std::list<int>::iterator it = std::find(ls.begin(), ls.end(), i);
    if (it != ls.end()) {
        return true;
    }
    return false;
}

m_* AI::getMbyId(int i)
{
    for (int i__ = 0; i <= (agents - 1); i__++) {
        if (m___[i].____id == i) {
            return &m___[i];
        }
    }
    return NULL;
}

void AI::alert____(m_* _m, b _, int x_, int y_)
{
    pos pos_;
    int i;
    std::list<m_*> list_;
    std::list<m_*>::iterator it;
    m_* s = m_alert(_m, area_s, area_s, true);
    if (s != NULL) {
	    e[s->add___x(_m->x_get(_), _)] += 1;
    }
}

int AI::distance__(pos s, pos y)
{
    return (((s.x - y.x) > 0 ? (s.x - y.x) : ((s.x - y.x) * -1)) + ((s.y - y.y) > 0 ? (s.y - y.y) : ((s.y - y.y) * -1)));
}

bool AI::has_monkey_in_area(pos pos_, int l_)
{
    int t = 0;
    for (int i = 0; i <= (agents - 1); i++) {
        if (distance__(pos_, m___[i].getp_P()) < l_ && pos_.x != m___[i].getp_P().x && pos_.y != m___[i].getp_P().y)
            t = t + 1;
    }

    return (t == 0) ? false : true;
}

bool AI::is_dif_pos(pos pos_, pos _pos)
{
    return ((pos_.x != _pos.x && pos_.y != _pos.y) ? true : false);
}

pos AI::less_monkey_pos(m_ m__)
{
    pos l_pos = m__.getp_P();
    int x_ = l_pos.x, y_ = l_pos.y;
    int _ = LEN_x * LEN_y;
    pos pos_;
    int c_;
    x_ = m__.getp_P().x;
    y_ = m__.getp_P().y;
    for (int i = 0; i <= (agents - 1); i++) {
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

m_* AI::more__distance___m(int area_view)
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

m_* AI::m_alert(m_* sender, int area_x, int area_y, bool print_)
{
    m_* _m = NULL;
    int x_ = 0, y_ = 0;
    int _ = LEN_x * LEN_y;
    pos pos_;
    int c_;
    int m[2] = { area_x, area_y };
    x_ = sender->getp_P().x;
    y_ = sender->getp_P().y;
    int x__ = ((m[0] % 2) == 0) ? (m[0] / 2) - 1 : (m[0] / 2);
    int y__ = ((m[1] % 2) == 0) ? (m[1] / 2) - 1 : (m[1] / 2);
    for (int x = x_ - (m[0] / 2); x <= x_ + x__; x++) {
        for (int y = y_ - (m[1] / 2); y <= y_ + y__; y++) {
            if (x < LEN_x && y < LEN_y && x >= 0 && y >= 0) {
                pos_.x = x;
                pos_.y = y;
                if (screen && print_ && !check____f(pos_.x, pos_.y) && f_x->getM_s(pos_) < 1) {
                        ___screen->___print__floor(1, pos_);
                }
                if (f_x->getM_s(pos_) > 0) {
                    c_ = ((pos_.x - x_) > 0 ? (pos_.x - x_) : ((pos_.x - x_) * -1)) + ((pos_.y - y_) > 0 ? (pos_.y - y_) : ((pos_.y - y_) * -1));
                    if (c_ < _) {
                        _ = c_;
                        _m = *((*(f_x->m_get___m(pos_))).begin()); // okay the order of monkeys in this case don't care for this why they are in the same position pos
                    }
                }
            }
        }
    }
    return _m;
}

m_* AI::m_prey(pos pos_prey, int area_x, int area_y)
{
    m_* _m = NULL;
    int x_ = 0, y_ = 0;
    int _ = LEN_x * LEN_y;
    pos pos_;
    int c_;
    int m[2] = { area_x, area_y };
    x_ = pos_prey.x;
    y_ = pos_prey.y;
    int x__ = ((m[0] % 2) == 0) ? (m[0] / 2) - 1 : (m[0] / 2);
    int y__ = ((m[1] % 2) == 0) ? (m[1] / 2) - 1 : (m[1] / 2);
    for (int x = x_ - (m[0] / 2); x <= x_ + x__; x++) {
        for (int y = y_ - (m[1] / 2); y <= y_ + y__; y++) {
            if (x < LEN_x && y < LEN_y && x >= 0 && y >= 0) {
                pos_.x = x;
                pos_.y = y;
                if (f_x->getM_s(pos_) > 0 && !f_x->check_tree(pos_)) {
                    c_ = ((pos_.x - x_) > 0 ? (pos_.x - x_) : ((pos_.x - x_) * -1)) + ((pos_.y - y_) > 0 ? (pos_.y - y_) : ((pos_.y - y_) * -1));
                    if (c_ < _) {
                        _ = c_;
                        _m = *((*(f_x->m_get___m(pos_))).begin()); // okay the order of monkeys in this case don't care for this why they are in the same position pos
                    }
                }
            }
        }
    }
    return _m;
}

void AI::s__p_As(m_* m__, pos pos_)
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
                    createAlert(m__);
       //             alert____(m__, f_x->b_get___b(b__), m__->getp_P().x,
    //                 m__->getp_P().y);
                }
            }
        }
    }
}

void AI::init__floor()
{
    f_x = new floor__;
    f_x->___(LEN_x, LEN_y, screen, ___screen);
    f_x->__ = 12;
}

void AI::set___graphics_(interface_* x) { ___screen = x; }

template <typename T>
void AI::_statistics(T buf, bool t)
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
