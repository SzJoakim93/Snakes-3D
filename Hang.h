#ifndef HANG_H
#define HANG_H

#include "SDL/SDL_mixer.h"

class Hang
{
    public:
        Hang();
        ~Hang();
        void play_music(char * path); //zene lejatszasa
        void play_sound(const int & i); //hang lejatszasa
        void stop(); //zene leallitasa
        void hozzaad(char * hang);
    protected:
    private:
        Mix_Music* music; //zene valtozoja
        Mix_Chunk** sound; //hang valtozoja
        int maxelem;
};

#endif // HANG_H
