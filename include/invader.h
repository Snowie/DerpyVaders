#ifndef INVADER_H
#define INVADER_H
#include "vector.h"

class Invader
{
    public:
        Invader(double, double);
        virtual ~Invader();
        void update();
        void translate (double, double);
        double getX() const;
        double getY() const;
        Vector getVelocity() const;
        Vector setVelocity(Vector);

    protected:
    private:
        double x, y;
        Vector velocity;
};

#endif // INVADER_H
