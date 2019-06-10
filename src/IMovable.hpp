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
            dx - destinacija na x osi, 
            dy - destinacija na y osi, 
        return: void
        */
        virtual void move(int dx, int dy) = 0;
        
};


#endif // I_MOVABLE_H