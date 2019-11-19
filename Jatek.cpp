#include "Jatek.h"

Jatek::Jatek()
{
    //ctor
    int i;

    this->pontok[0] = 0;
    this->pontok[1] = 0;
    this->hossz[0] = 0;
    this->hossz[1] = 0;
    this->speed = 0.02;
    this->energy = MAX_ENERGY;
    this->hp = MAX_HP;
    this->maxdomb = 0;
    this->diff = 0;

    hang.hozzaad("Sound/eat.wav");
    hang.hozzaad("Sound/damage.wav");

    for (i=0; i<10; i++)
    {
        this->bal[i] = false;
        this->jobb[i] = false;
        this->kesleltet[i] = 0;
        this->kesleltet2[i] = 0;
        this->kesleltet3[i] = 0;
    }

    max_objects=max_base_objects;

    //5 (alma)
    apple = new Object(0.0, -0.15, -0.25, //koordinatak
                        0, 90, -90, //elforgatas
                        0.1, 0.1, 0.1, //atmeretezes
                        "Textures/apple.bmp", 0, "negyzet", 1, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //6 (jelzi, hogy a mi pontunk)
    points_title[0] = new Object(-0.12, 0.09, 0.0, //koordinatak
                        0, 0, 0, //elforgatas
                        0.025, 1.0, 0.025, //atmeretezes
                        "Textures/head.bmp", 0, "negyzet", 3, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag
    //7(jelzi, hogy az ellenfel pontja)
    points_title[2] = new Object(0.12, 0.09, 0.0, //koordinatak
                        0, 0, 0, //elforgatas
                        0.025, 1.0, 0.025, //atmeretezes
                        "Textures/head2.bmp", 0, "negyzet", 3, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag
    //8 (mi pontunk)
   points_title[1] = new Object(-0.1, 0.09, 0.0, //koordinatak
                        0, 0, 0, //elforgatas
                        0.0125, 1.0, 0.0075, //atmeretezes
                        "Textures/letters1", 0, "negyzet", 4, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag
    //9 (ellenfel pontja)
    points_title[3] = new Object(0.09, 0.09, 0.0, //koordinatak
                        0, 0, 0, //elforgatas
                        0.0125, 1.0, 0.0075, //atmeretezes
                        "Textures/letters1", 0, "negyzet", 4, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag
    //10 (game-over felirat)
    game_over = new Object(0.075, -0.05, 0.0, //koordinatak
                        0, 0, 0, //elforgatas
                        0.2, 1.0, 0.4, //atmeretezes
                        "Textures/gameover.bmp", 0, "negyzet", 3, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag
     //11 (gyozelem/vesztettel felirat)
    end_status = new Object(-0.1, 0.0, 0.0, //koordinatak
                        0, 0, 0, //elforgatas
                        0.025, 1.0, 0.015, //atmeretezes
                        "Textures/letters1", 0, "negyzet", 4, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //12 (energiacsik)
    energy_title[0] = new Object(-0.1, -0.09, 0.0, //koordinatak
                        0, 0, 0, //elforgatas
                        0.0063, 1.0, 0.067, //atmeretezes
                        "Textures/bar_fill.bmp", 0, "negyzet", 3, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //13 (energia tabla)
    energy_title[1] = new Object(-0.1, -0.09, 0.0, //koordinatak
                        0, 0, 0, //elforgatas
                        0.01, 1.0, 0.07, //atmeretezes
                        "Textures/bar.bmp", 0, "negyzet", 3, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //14 (sziv)
    hp_title[0] = new Object(-0.13, -0.075, 0.0, //koordinatak
                        0, 0, 0, //elforgatas
                        0.01, 1.0, 0.01, //atmeretezes
                        "Textures/heart.bmp", 0, "negyzet", 3, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //15 (elet felirat)
    hp_title[1] = new Object(-0.12, -0.075, 0.0, //koordinatak
                        0, 0, 0, //elforgatas
                        0.0125, 1.0, 0.0075, //atmeretezes
                        "Textures/letters1", 0, "negyzet", 4, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag


    //16-25(hatarokkal!)  (az ellenfel kigyoja)
    for(int i=0; i<10; i++)
        snakes[i] = new Object(2.0, -0.15, 0.0+i/12.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.1, 0.01, 0.1, //atmeretezes
                            "Textures/head2.bmp", 0, "negyzet", 1, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag
    //26-35(hatarokkal!)  ((a mi kigyonk)
    for(int i=0; i<10; i++)
        snakes[10+i] = new Object(0.0, -0.15, 0.0+i/12.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.1, 0.01, 0.1, //atmeretezes
                            "Textures/head.bmp", 0, "negyzet", 1, 0); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges fla
}

void Jatek::esemenyek(int & jatekresz)
{
    int i;


    //gyozelem
    if (pontok[0] > 19)
        jatekresz = 3;

    //vesztettel
    if (pontok[1] > 19)
        jatekresz = 4;

    //felveszed az almat
    if (snakes[10]->collision(apple, 100))
    {
        if (*vanhang)
            hang.play_sound(0);
        apple_pickup(0);
    }

    //az ellenfel felveszi az almat
    if (snakes[0]->collision(apple, 100))
        apple_pickup(1);

    //utkozesek
    for (i=0; i<4; i++) //a falakba beleutkozol
        if (snakes[10]->collision(game_objects[i], 100))
            damage(jatekresz);

    for (i=0; i<1+hossz[1]; i++) //az ellenfelbe utkozol
        if (snakes[10]->collision(snakes[i], 100))
            damage(jatekresz);

    for (i=0; i<game_objects.size(); i++) //a terraintargyakba utkozol
        if (game_objects[i]->getflag() == 0 && snakes[10]->collision(game_objects[i], 100) || game_objects[i]->getflag() == 1 && snakes[10]->collision(game_objects[i], 5))
            damage(jatekresz);


    //az ellenfel farkanak kovetesi algoritmusa
    if (kesleltet3[0] < 0.001)
    {
        snakes[0]->follow(apple);
        kesleltet3[0] = 0.002;
    }

    for (i=0; i<9; i++)
    {
        if (kesleltet3[i] > 0)
            kesleltet3[i]+=0.02+diff;

        if (kesleltet3[i] > 0.08)
        {
            snakes[1+i]->setrabsolute(snakes[i]->getrabsolute());
            kesleltet3[i] = 0;
            kesleltet3[i+1] = 0.002;
        }
    }//itt vege



    //az ellenfel mozgasa
    for (i=0; i<10; i++)
            snakes[i]->aelore(0.02+diff);

    //az abszolut mozgasod
    for (i=10; i<20; i++)
        snakes[i]->aelore(speed);

    //a kornyezet, azaz a kamera mozgasa

    Object::cHorizontal(speed);

    //a farkad kovetesi algoritmusa, piszok bonyolult, mar ense ertem
    /*azon alapul, hogy ha lenyomsz egy gombot, a kigyo (vagy kukac)
    tobbi resze kis ido mulva csinalja ugyanazt, mint a fej*/
    for (i=0; i<9; i++)
    {
        {
            if (kesleltet[i]>0)
                kesleltet[i]--;

            if (kesleltet[i]<0)
                kesleltet[i]++;

            if (kesleltet[i]==1)
            {
                bal[i+1] = true;
                kesleltet[i+1] = N;
            }

            if (kesleltet[i]==-1)
            {
                bal[i+1] = false;
                kesleltet[i+1] = -N;
            }

            if (bal[i+1])
                snakes[11+i]->ajobbra();
        }

        {
            if (kesleltet2[i]>0)
            kesleltet2[i]--;

            if (kesleltet2[i]<0)
                kesleltet2[i]++;

            if (kesleltet2[i]==1)
            {
                jobb[i+1] = true;
                kesleltet2[i+1] = N;
            }


            if (kesleltet2[i]==-1)
            {
                jobb[i+1] = false;
                kesleltet2[i+1] = -N;
            }

            if (jobb[i+1])
                snakes[11+i]->abalra();
        }

    } //vege

    //a "nitro" kezelese
    if (speed < 0.022 && energy < MAX_ENERGY)
    {
        energy++;
        energy_title[0]->settx(-0.1333+(((float)energy/(float)MAX_ENERGY)*0.067)/2.0);
        energy_title[0]->setsz(((float)energy/(float)MAX_ENERGY)*0.067);
    }
    else if (speed > 0.028 && energy > 0)
    {
        energy-=10;
        energy_title[0]->settx(-0.1333+(((float)energy/(float)MAX_ENERGY)*0.067)/2.0);
        energy_title[0]->setsz(((float)energy/(float)MAX_ENERGY)*0.067);
    } //vege


    //a kigyok felmennek a dombon
    for (i=0; i<terrain.size(); i++)
        for (int j=0; j<20; j++)
        if (snakes[j]->gettx() > terrain[i]->gettx() - (terrain[i]->getsx()) / 2.0 &&
            snakes[j]->gettx() <= terrain[i]->gettx() + (terrain[i]->getsx()) / 2.0 &&
            snakes[j]->gettz() > terrain[i]->gettz() - (terrain[i]->getsz()) / 2.0 &&
            snakes[j]->gettz() <= terrain[i]->gettz() + (terrain[i]->getsz()) / 2.0)
            {
                if (snakes[j]->gettx() < terrain[i]->gettx() - (terrain[i]->getsx()*0.25) ||
                    snakes[j]->gettx() >= terrain[i]->gettx() + (terrain[i]->getsx()*0.25) ||
                    snakes[j]->gettz() < terrain[i]->gettz() - (terrain[i]->getsz()*0.25) ||
                    snakes[j]->gettz() >= terrain[i]->gettz() + (terrain[i]->getsz()*0.25))
                    {
                        float lamdax = fabs(snakes[j]->gettx()-terrain[i]->gettx());
                        float lamday = fabs(snakes[j]->gettz()-terrain[i]->gettz());

                        if (lamdax/terrain[i]->getsx() > lamday/terrain[i]->getsz())
                        {
                            lamdax = lamdax/terrain[i]->getsx()*0.25;
                            snakes[j]->setty(-0.15+terrain[i]->getsy()-terrain[i]->getsy()*lamdax*8);
                        }
                        else
                        {
                            lamday = lamday/terrain[i]->getsz()*0.25;
                            snakes[j]->setty(-0.15+terrain[i]->getsy()-terrain[i]->getsy()*lamday*8);
                        }

                    }

            }

    //a kamera koveti a domborzat felszinet
   for (int i=0; i<max_terrain; i++)
        if (-terrain[i]->getcx() > terrain[i]->gettx() - terrain[i]->getsx() / 2.0 &&
            -terrain[i]->getcx() <= terrain[i]->gettx() + terrain[i]->getsx() / 2.0 &&
            -terrain[i]->getcz() > terrain[i]->gettz() - terrain[i]->getsz() / 2.0 &&
            -terrain[i]->getcz() <= terrain[i]->gettz() + terrain[i]->getsz() / 2.0)
            {
                if (-terrain[i]->getcx() < terrain[i]->gettx() - terrain[i]->getsx()*0.25 ||
                -terrain[i]->getcx() >= terrain[i]->gettx() + terrain[i]->getsx()*0.25 ||
                -terrain[i]->getcz() < terrain[i]->gettz() - terrain[i]->getsz()*0.25 ||
                -terrain[i]->getcz() >= terrain[i]->gettz() + terrain[i]->getsz()*0.25)
                {
                    float lamdax = fabs(-terrain[i]->getcx()-terrain[i]->gettx());
                    float lamday = fabs(-terrain[i]->getcz()-terrain[i]->gettz());
                    int reverse=-1;
                    if (terrain[i]->getrx() == 180)
                        reverse = 1;

                    if (lamdax/terrain[i]->getsx() > lamday/terrain[i]->getsz())
                    {
                        lamdax = lamdax/terrain[i]->getsx()*0.25;
                        Object::setcy(reverse*(terrain[i]->getsy()-terrain[i]->getsy()*lamdax*8));
                    }
                    else
                    {
                        lamday = lamday/terrain[i]->getsz()*0.25;
                        Object::setcy(reverse*(terrain[i]->getsy()-terrain[i]->getsy()*lamday*8));
                    }
                }
            }
}

//az alma felvetele
void Jatek::apple_pickup(const int & x)
{
    if (x > -1)
    {
        pontok[x]++;
        kigyonoveles(x);

        diff = (pontok[0]-pontok[1])*0.001;
    }

    //alma lerakasa egy random helyre
    apple->settx((rand()%((int)MX*10))/10.0 - (MX/2));
    apple->settz((rand()%((int)MY*10))/10.0 - (MY/2)-1);

    //az alma koveti a domborzat felszinet
    bool dombon = false;
    for (int i=0; i<max_terrain; i++)
        if (apple->gettx() > terrain[i]->gettx() - (terrain[i]->getsx()) / 2.0 &&
            apple->gettx() <= terrain[i]->gettx() + (terrain[i]->getsx()) / 2.0 &&
            apple->gettz() > terrain[i]->gettz() - (terrain[i]->getsz()) / 2.0 &&
            apple->gettz() <= terrain[i]->gettz() + (terrain[i]->getsz()) / 2.0)
            {
                dombon = true;
                if (apple->gettx() < terrain[i]->gettx() - (terrain[i]->getsx()*0.25) ||
                    apple->gettx() >= terrain[i]->gettx() + (terrain[i]->getsx()*0.25) ||
                    apple->gettz() < terrain[i]->gettz() - (terrain[i]->getsz()*0.25) ||
                    apple->gettz() >= terrain[i]->gettz() + (terrain[i]->getsz()*0.25))
                    {
                        float lamdax = fabs(apple->gettx()-terrain[i]->gettx());
                        float lamday = fabs(apple->gettz()-terrain[i]->gettz());

                        if (lamdax/terrain[i]->getsx() > lamday/terrain[i]->getsz())
                        {
                            lamdax = lamdax/terrain[i]->getsx()*0.25;
                            apple->setty(-0.15+terrain[i]->getsy()-terrain[i]->getsy()*lamdax*8);
                        }
                        else
                        {
                            lamday = lamday/terrain[i]->getsz()*0.25;
                            apple->setty(-0.15+terrain[i]->getsy()-terrain[i]->getsy()*lamday*8);
                        }

                    }
                    else
                        apple->setty(-0.15+terrain[i]->getsy()/2);
            }

            if (!dombon)
                    apple->setty(-0.15);
}

//serules rendszer kezelese
void Jatek::damage(int & jatekresz)
{
    hp--;
    hang.play_sound(1);

    if (hp == 0)
        jatekresz = 2;
    else
    {
        for (int i=0; i<10; i++)
        {
            bal[i] = false;
            jobb[i] = false;
            kesleltet[i] = 0;
            kesleltet2[i] = 0;
            kesleltet3[i] = 0;
        }

        //kamera visszaallitasa
        Object::setcx(0);
        Object::setcy(0);
        Object::setcz(0);
        Object::setrcamera(0);

        for (int i=10; i<20; i++) //poziciod visszaallitasa
        {
            snakes[i]->settx(0.0);
            snakes[i]->setty(-0.15);
            snakes[i]->settz(0.0+(i-10)/12.0);
            snakes[i]->setrabsolute(0);
        }

        for (int i=0; i<10; i++) //ellenfel visszaallitasa
        {
            snakes[i]->settx(2.0);
            snakes[i]->setty(-0.15);
            snakes[i]->settz(0.0+i/12.0);
            snakes[i]->setrabsolute(0);
        }
    }
}

void Jatek::balgomb()
{
    int i;

    if (!bal[0])
    {
        bal[0] = true;
        kesleltet[0] = 5;
    }

    Object::rotate_camera(-2);

    snakes[10]->ajobbra();
}

void Jatek::jobbgomb()
{
    int i;

    if(!jobb[0])
    {
        jobb[0] = true;
        kesleltet2[0] = 5;
    }

    Object::rotate_camera(2);

    snakes[10]->abalra();
}

void Jatek::balgomb2()
{
    int i;

    if (kesleltet[0] == 0)
    {
        bal[0] = false;
        kesleltet[0] = -5;
    }
    else
    {
        Object::rotate_camera(-2);

        snakes[10]->ajobbra();
    }
}

void Jatek::jobbgomb2()
{
    int i;

    if (kesleltet2[0] == 0)
    {
        jobb[0] = false;
        kesleltet2[0] = -5;
    }
    else
    {
        Object::rotate_camera(2);

        snakes[10]->abalra();
    }
}

void Jatek::megjelenit(int & jatekresz)
{
    int i;

    for (i=0; i<terrain.size(); i++)
        terrain[i]->megjelenit();

    apple->megjelenit();

    //ellenfel kigyoja
    for (i=0; i<1+hossz[1]; i++)
        snakes[i]->megjelenit();

    //a te kigyod
    for (i=10; i<11+hossz[0]; i++)
        snakes[i]->megjelenit();

    for (i=0; i<game_objects.size(); i++)
        game_objects[i]->megjelenit();


    //feliratok
    char temp[5];
    sprintf(temp, "%d", pontok[0]);
    points_title[1]->gprintf(temp);
    sprintf(temp, "%d", pontok[1]);
    points_title[3]->gprintf(temp);
     sprintf(temp, "%d", hp);
    hp_title[1]->gprintf(temp);

    if (jatekresz == 2) //game over felirat
        game_over->megjelenit();

    if (jatekresz == 3)
       end_status->gprintf("gy/5zelem");

    if (jatekresz == 4)
       end_status->gprintf("vesztett/1l");

    energy_title[0]->megjelenit();
    energy_title[1]->megjelenit();
    points_title[0]->megjelenit();
    points_title[2]->megjelenit();
    hp_title[0]->megjelenit();

}


int Jatek::getkesleltet_0()
{
    return kesleltet[0];
}

int Jatek::getkesleltet2_0()
{
    return kesleltet2[0];
}

//gyorsulhatsz-e
bool Jatek::speedable()
{
    if (energy > 0 && !bal[9] && !bal[8] && !bal[7] && !bal[6] && !bal[5] && !bal[4] && !bal[3] && !bal[2] && !bal[1] && !bal[0] &&
       !jobb[9] && !jobb[8] && !jobb[7] && !jobb[6] && !jobb[5] && !jobb[4] && !jobb[3] && !jobb[2] && !jobb[1] && !jobb[0])
        return true;
    else
        return false;
}

bool Jatek::getbal_0()
{
    return bal[0];
}

bool Jatek::getjobb_0()
{
    return jobb[0];
}

void Jatek::kigyonoveles(const int & x)
{
    if (hossz[x] < 8)
        hossz[x]++;
}

void Jatek::zene(char * eleres)
{
    hang.play_music(eleres);
}

void Jatek::zene_stop()
{
    hang.stop();
}

void Jatek::reset()
{
    for (int i=0; i<10; i++)
    {
        bal[i] = false;
        jobb[i] = false;
        kesleltet[i] = 0;
        kesleltet2[i] = 0;
        kesleltet3[i] = 0;

    }

    hossz[0] = 0;
    hossz[1] = 0;
    pontok[0] = 0;
    pontok[1] = 0;
    hp = MAX_HP;
    energy = MAX_ENERGY;

    game_objects.clear();
    terrain.clear();

    max_objects=max_base_objects;

    //kamera visszaallitasa
    Object::setcx(0);
    Object::setcy(0);
    Object::setcz(0);
    Object::setrcamera(0);

    for (int i=10; i<20; i++) //poziciod visszaallitasa
    {
        snakes[i]->settx(0.0);
        snakes[i]->setty(-0.15);
        snakes[i]->settz(0.0+(i-10)/12.0);
        snakes[i]->setrabsolute(0);
    }

    for (int i=0; i<10; i++) //ellenfel visszaallitasa
    {
        snakes[i]->settx(2.0);
        snakes[i]->setty(-0.15);
        snakes[i]->settz(0.0+i/12.0);
        snakes[i]->setrabsolute(0);
    }
}

void Jatek::sethangok(bool * behang)
{
    vanhang = behang;
}

void Jatek::loadlevel(const int & level)
{
    char temp1[5] = {0};
    char temp2[20] = {0};
    char object[30];
    char texture[30];
    float x, y, z, sx, sy, sz;
    int type;
    int mozaik;
    int flag;
    int rx, ry, rz;
    FILE * file;

    sprintf(temp1, "%d", level);

    strcat(temp2, "Levels/level");
    strcat(temp2, temp1);
    strcat(temp2, ".txt");

    file = fopen(temp2, "r");

    /**Elem konstruktoranak utolso parameter ertekei:**/
    /*0: 3D objektum
      1: 2D objektum (DOOM/Duke Nukem-ben ismert animaciok)
      2: Skybox (A jatekter hattere)
      3: Megjelenites allando elemkent a kepernyon (pl: terkep, km ora, eletcsik)
      4: Szam kiiratasa stringben (itt csak a mappat kell megadni texturanak)
      5: Szoveg kiiratasa*/


    //az objects betoltes
    /**A jatekresz elemei:**/
    fscanf(file, "%s", temp1); //felesleg
    fscanf(file, "%s", temp1); //felesleg
    fscanf(file, "%s", texture); //a fold texturai
    fscanf(file, "%s", object); //a fal texturai!
    fscanf(file, "%f", &MX); //palya szelessege
    fscanf(file, "%f", &MY); // palya hossza
    fscanf(file, "%f", &x); // szine
    fscanf(file, "%f", &y);
    fscanf(file, "%f", &z);

    glClearColor(x, y, z, 0);
    glClearDepth(1);

    //0
    /*objects->hozzaad(Elem(0.0, -0.2, -1.0, //koordinatak
                        0, 0, 0, //elforgatas
                        MX, 1.0, MY, //atmeretezes
                        texture, 1, "negyzet", 0, 0));*/ //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag
    //1 (fal)
    game_objects.insert(new Object(MX/2.0, 0.05, -1.0, //koordinatak
                        0, 0, 270, //elforgatas
                        0.5, 0.05, MY, //atmeretezes
                        object, 3, "negyzet", 0, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //2 (fal)
    game_objects.insert(new Object(-MX/2.0, 0.05, -1.0, //koordinatak
                        0, 0, 270, //elforgatas
                        0.5, 0.05, MY, //atmeretezes
                        object, 3, "negyzet", 0, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag
    //3 (fal)
    game_objects.insert(new Object(0.0, 0.05, -(MY/2.0)-1, //koordinatak
                        0, 90, 270, //elforgatas
                        0.5, 0.05, MX, //atmeretezes
                        object, 3, "negyzet", 0, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag
    //4 (fal)
    game_objects.insert(new Object(0.0, 0.05, (MY/2.0)-1, //koordinatak
                        0, 90, 270, //elforgatas
                        0.5, 0.05, MX, //atmeretezes
                        object, 3, "negyzet", 0, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    textureidenity = (char**)malloc(sizeof(char*)*10);
    for (int i=0; i<10; i++)
    {
        textureidenity[i] = (char*)malloc(sizeof(char)*20);
        fscanf(file, "%s", textureidenity[i]);
    }

    max_terrain=0;

    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
        {
            int k;
            fscanf(file, "%d", &k);
            if (k != -1)
            {
                terrain.insert(new Object((float)i*2.22-10, -0.2, (float)j*2.22-10, //koordinatak
                                    0, 0, 0, //elforgatas
                                    2.22, 0.0, 2.22, //atmeretezes
                                    textureidenity[k], 0, "negyzet", 0, 0));

                max_terrain++;
            }

        }

        max_objects = max_base_objects;

    do
    {
        fscanf(file, "%s", object);

        if (object[0] != '*')
        {
            fscanf(file, "%s", texture);
            fscanf(file, "%f", &x);
            fscanf(file, "%f", &y);
            fscanf(file, "%f", &z);
            fscanf(file, "%f", &sx);
            fscanf(file, "%f", &sy);
            fscanf(file, "%f", &sz);

            int tempx = sx/2;
            int tempy = sy/2;
            terrain.insert(new Object(x*2.22+(tempx-1)*1.11-10, y+0.3, z*2.22+(tempy-1)*1.11-10, //koordinatak
                                0, 0, 0, //elforgatas
                                sx, sz, sy, //atmeretezes
                                texture, 0, object, 0, 0));

            max_terrain++;
            maxdomb++;
        }

    } while (object[0] != '*');

    do
    {
        fscanf(file, "%s", object);

        if (object[0] != '*')
        {
            fscanf(file, "%s", texture);
            fscanf(file, "%f", &x);
            fscanf(file, "%f", &y);
            fscanf(file, "%f", &z);
            fscanf(file, "%d", &rx);
            fscanf(file, "%d", &ry);
            fscanf(file, "%d", &rz);
            fscanf(file, "%f", &sx);
            fscanf(file, "%f", &sy);
            fscanf(file, "%f", &sz);
            fscanf(file, "%d", &type);
            fscanf(file, "%d", &mozaik);
            fscanf(file, "%d", &flag);

            /*if (!strcmp(object, "negyzet"))
                y = -0.22+sx/2;
            else
                y = -0.2;*/


            game_objects.insert(new Object(x, y, z, //koordinatak
                                rx, ry, rz, //elforgatas
                                sx, sy, sz, //atmeretezes
                                texture, mozaik, object, type, flag));

            max_objects++;
        }

    } while (object[0] != '*');

	fclose(file);

    apple_pickup(-1);
}

void Jatek::setspeed(float ujspeed)
{
    this->speed = ujspeed;
}

