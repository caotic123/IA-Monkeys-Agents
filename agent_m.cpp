#include "agent.h"

  void m_::init_agent()
    {
        m = (double**)malloc(sizeof(double*) * S - 1);
        d_ = (int*)malloc(sizeof(int) * 3);
        d = false;
        for (int i = 0; i <= (S - 1); i++) {
            m[i] = (double*)malloc(sizeof(double) * 3);
            for (int x = 0; x <= 2; x++) {
                m[i][x] = ran_();
            }
        }
    }

    void m_::set__dir_vect(int x, int y)
    {
        d_[0] = x;
        d_[1] = y;
        d = true;
    }

    int m_::add___x(int sx, b p_)
    {
        m[sx][(int)p_] += 0.1;
        return sx;
    }

    int m_::x_get(b p_)
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

    pos m_::getp_P() { return pos_; }

    float m_::get_y(int n, int y) { return m[n][y]; }

    void m_::setPos(pos x) { memcpy(&pos_, &x, sizeof(x)); }

