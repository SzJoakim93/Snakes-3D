#ifndef JATEK_H
#define JATEK_H

#include "Object.h"
#include "Elem_tarolo.h"
#include "Hang.h"
#include "vector.h"

#include <cstdio>
#include <cstring>

#define N 6 //fordulas merteke
#define max_base_objects 35 //elemek szama a tereptargyak elott
#define MAX_ENERGY 1500
#define MAX_HP 3; //maximalis elet

class Jatek
{
    public:
        Jatek();
        void esemenyek(int & jatekresz);
        void balgomb();
        void jobbgomb();
        void balgomb2();
        void jobbgomb2();
        int getkesleltet_0();
        int getkesleltet2_0();
        bool speedable();
        bool getbal_0();
        bool getjobb_0();
        void megjelenit(int & jatekresz);
        void setelemek(Elem_tarolo * beelemek, Elem_tarolo * terep);
        void zene(char * eleres);
        void zene_stop();
        void reset();
        void sethangok(bool * behang);
        void loadlevel(const int & level);
        void setspeed(float ujspeed);
        void apple_pickup(const int & x);
    protected:
    private:
        int pontok[2]; //aktualis pontok
        float diff; // az ellenfel es a te pontod kozti kulonbseg
        int hossz[2]; //a kigyo aktualis hossza
        bool bal[10]; //a kigyo elem balra fordul-e
        bool jobb[10]; //a kigyo elem jobbra fordul-e
        int kesleltet[10]; //a balra fordulas kesleltetese
        int kesleltet2[10]; //a jobbra fordulas kesleltetese
        float kesleltet3[10]; //az ellenfel kesleltetese
        vector<Object*> game_objects; //az osszes jatekbeli elem taroloja
        vector<Object*>  terrain; //a terep elemei
        Object * points_title[4];
        Object * energy_title[2];
        Object * hp_title[2];
        Object * game_over;
        Object * end_status;
        Object * apple;
        Object * snakes[20];
        Hang hang; //jatek hangok
        void kigyonoveles(const int & x);
        void damage(int & jatekresz);
        bool * vanhang; //a beallitasokban engedelyezve van-e a hangok
        float MX, MY;
        float speed; //a kigyo sebessege
        int energy; //aktualis energia
        int hp; //aktualis elet
        char ** textureidenity; //a terep texturainak azonositoja
        int maxdomb;
        int max_objects; //az elemek maximalis szama
        int max_terrain; //a terep elemek maximalis szama (dombok & talaj)
};

#endif // JATEK_H
