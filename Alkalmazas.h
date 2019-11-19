#ifndef ALKALMAZAS_H
#define ALKALMAZAS_H

#include <cstdio>

#include "GL/gl.h"
#include "SDL/SDL.h"
#include "gl/glu.h"

#include "Jatek.h"
#include "Menu.h"


class Alkalmazas
{
    public:

        Alkalmazas(char *frame_title, int bewidth, int beheight, int bedepth, char befullscreen);
        ~Alkalmazas();
        void eLoadProjectionMatrix(int width, int height, float near, float far);
        void handleSDL2Events(bool & quit);
        void render();
        int getfar();

    protected:
    private:
        Jatek * jatek;
        Menu * menu;
        int width; // Az ablak szelessege pixelben.
        int height; // Az ablak magassaga pixelben.
        int depth; // Szinmelyseg
        bool fullscreen; // Az ablak teljes kepernyos beallitasa.
        float near; //a latotavolsag kezdete
        float far; //latotavolsag
        SDL_Event event;
        Uint8 *keystates;
        int jatekresz; /*0: menu, 1: ingame, 2:game-over, 3: gyozelem, 4: vereseg
                         5: palyamenu, 6: beallitasok menu 7: felbontas
                         8: felbontas egyeni szelesseg 9: felbontas egyeni magassag*/
        bool hang;
        bool zene;
        bool valtozas;
        int setres;
};

#endif // ALKALMAZAS_H
