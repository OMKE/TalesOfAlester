#ifndef I_MOVABLE_H
#define I_MOVABLE_H

/*
** IMovable **
desc:
    Interface
    Ovaj interfejs ce naslijediti svaka klasa koja ima mogucnost kretanja
*/
class IMovable {
    public:
        virtual void move() = 0;
        /*
        ** move **
        desc:
            pomjera objekat na ekranu na osnovu proslijedjenih koordinata
        params:
            destinationX - destinacija na x osi
        return: void
        */
        virtual void move(int destinationX) = 0;
        
};


#endif // I_MOVABLE_H