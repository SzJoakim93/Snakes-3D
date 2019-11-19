#include "GL/gl.h"
#include "SDL/SDL.h"
#include "gl/glu.h"

#include "Alkalmazas.h"
#include "Object.h"
#include "Elem_tarolo.h"

#include <ctime>
#include <cstdio>

bool quit;/* Az alkalmazas fo ciklusanak a futasat jelzi.
        Ha az erteke igazra allitodik, akkor az alkalmazas a
        kovetkezo iteracio elejen kilep.*/



int main(int argc, char *argv[])
{
    int width;
    int height;
    int fullscreen;

    FILE * file = fopen("settings.ini", "r");

	fscanf(file, "screen_width=%d\n", &width);
	fscanf(file, "screen_height=%d\n", &height);
	fscanf(file, "fullscreen=%d\n", &fullscreen);

	fclose(file);

    srand(time(0));
    Alkalmazas alkalmazas("Snakes 3D", width, height, 32, fullscreen); //kepernyo inicializalasa
    quit = false; //kilepes feltetele

    int far = (alkalmazas.getfar() - 0.1)*(-1); //latotavolsag


    while (!quit) //a fo ciklus kezdete
    {
        alkalmazas.handleSDL2Events(quit); //az esemenyvezerlo megnyitasa (pl billentyuzetkezeles)
        alkalmazas.render(); //kepernyo osszeallitasa
    }

    return 0;
}
