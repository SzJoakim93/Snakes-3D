#ifndef ELEM_TAROLO_H
#define ELEM_TAROLO_H

#include "Object.h"

class Elem_tarolo
{
    public:
        Elem_tarolo();
        ~Elem_tarolo();
        void hozzaad(Object ujelem); //uj elem hozzaadasa
        void torol(); //osszes elem torlese
        Object & operator [] (int i); //egy elem elerese
        /*utkozes detektalas (sajnos egyenlore csak vizszintesen vizsgalaja meg,
        azaz ha egymas folott vannak, az is utkozes, meg cak 90-fokos elforgatast
        kezeli!)*/
        bool utkozes(const int & e1, const int & e2, const int & space);
        /*kovetes algoritmusa: mi kovessen micsodat*/
        void kovet(const int & e1, const int & e2);
        int & getelemszam();
        void camera_elore(const float & x);
        void camera_hatra(const float & x);
        void setCameraY(const float & x);

    protected:
    private:
        Object * elemek;
        int elemszam;
};

#endif // ELEM_TAROLO_H
