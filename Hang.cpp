#include "Hang.h"

Hang::Hang()
{
    //ctor
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ); //inicializalas
    music = NULL;
    maxelem = 0;

}

Hang::~Hang()
{
    //dtor
    //felszabaditas
    Mix_FreeMusic(music);

    for (int i=0; i<maxelem; i++)
        Mix_FreeChunk(sound[i]);
    Mix_CloseAudio();

    if (maxelem > 0)
        delete [] sound;
}

void Hang::hozzaad(char * ujhang)
{
    Mix_Chunk** temp = new Mix_Chunk*[maxelem+1];

    for (int i=0; i<maxelem; i++)
        temp[i] = sound[i];

    temp[maxelem] = Mix_LoadWAV(ujhang); //hang betoltese

    if (maxelem > 0)
        delete [] sound;

    maxelem++;

    sound = temp;

}

void Hang::play_music(char * path)
{
    music = Mix_LoadMUS(path); //zene betoltese
    Mix_PlayMusic(music, -1); //lejatszas 2. parameter: hanyszor ismetelje meg (-1: vegtelenszer)
}

void Hang::play_sound(const int & i)
{
    Mix_PlayChannel( -1, sound[i], 0 ); //hang lejatszasa
}

void Hang::stop()
{
    Mix_HaltMusic(); //megszakitas
}
