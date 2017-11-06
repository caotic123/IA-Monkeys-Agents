#include "agent.h"
 
    void floor__::___(int LEN_x___, int LEN_y___, bool screen__, interface_* screen)
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

    void floor__::__insert(b m, pos pos_)
    {
    	std::cout << "ola" << std::endl;
        memcpy(&f[pos_.x][pos_.y].b_, &m, sizeof(m));
    }

    void floor__::apon___(m_* e, pos pos_)
    {
        f[pos_.x][pos_.y].a_s.push_back(e);
        f[pos_.x][pos_.y]._ = f[pos_.x][pos_.y]._ + 1;
    }

    int* floor__::d__(int x, int y, int x_, int y_)
    {
        d[0] = x + (x > x_ ? -1 : (x == x_) ? 0 : 1);
        d[1] = y + (y > y_ ? -1 : (y == y_) ? 0 : 1);
        return d;
    }

    bool floor__::check_tree(pos pos_)
    {
        if (f[pos_.x][pos_.y].t != 0) {
            return true;
        }
        return false;
    }

    std::list<m_*>* floor__::m_get___m(pos pos_) { return &f[pos_.x][pos_.y].a_s; }

    b floor__::b_get___b(pos pos_) { return f[pos_.x][pos_.y].b_; }

    int floor__::getM_s(pos pos_) { return f[pos_.x][pos_.y]._; }

    pos floor__::pos__(int x, int y, int limit_x, int limit_y)
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

    void floor__::remove___m(m_* m, pos pos_)
    {
        f[pos_.x][pos_.y].a_s.remove(m);
        f[pos_.x][pos_.y]._ = f[pos_.x][pos_.y]._ - 1;
    }

    void floor__::delete____b(pos pos_) { f[pos_.x][pos_.y].b_ = _n; }

    void floor__::_generate_image_tree(interface_* screen)
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

    pos floor__::get_lower_pos_of_tree(pos from_pos)
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

    pos floor__::get_tree_pos()
    {
        pos pos_;
        pos_.x = tree_x;
        pos_.y = tree_y;
        return pos_;
    }

    void floor__::__pos(int LEN_x_, int LEN_y_)
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

    void floor__::_generate_tree(int LEN_x_, int LEN_y_, bool screen_, interface_* screen)
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
