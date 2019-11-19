#include "Menu.h"

Menu::Menu()
{
    cursor = 0;
    maxcursor = 3;

    int i=0;

    bool van=true;
    while (van)
    {
        FILE * file;
        char temp1[30] = {0};
        char temp2[30] = {0};
        sprintf(temp1, "%d", i+1);

        strcat(temp2, "Levels/level");
        strcat(temp2, temp1);
        strcat(temp2, ".txt");

        if (fopen(temp2, "r") != 0)
        {
            file = fopen(temp2, "r");
            fscanf(file, "%s", palyalista[i]);
            fscanf(file, "%s", zenelista[i]);
            fclose(file);
            i++;
        }
        else
            van = false;
    }

    Object * new_object;
    /**A menu elemei:**/
    //0 (menupont)
    menu_objects.insert(new Object(-0.095, 0.0, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

   //1 (menupont)
    menu_objects.insert(new Object(-0.095, -0.04, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //2 (menupont)
    menu_objects.insert(new Object(-0.095, -0.02, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //3 (menupont)
    menu_objects.insert(new Object(-0.095, -0.06, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //4 (menupont)
    menu_objects.insert(new Object(-0.095, -0.08, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //5 (menupont)
    menu_objects.insert(new Object(-0.095, 0.02, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag
    //6 (menupont)
    menu_objects.insert(new Object(-0.095, 0.04, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //7 (menupont)
    menu_objects.insert(new Object(-0.095, 0.06, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //8 (menupont)
    menu_objects.insert(new Object(-0.095, 0.08, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //9 (menupont)
    menu_objects.insert(new Object(0.03, 0.08, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //10 (menupont)
    menu_objects.insert(new Object(0.03, 0.06, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //11 (menupont)
    menu_objects.insert(new Object(0.03, 0.04, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //12 (menupont)
    menu_objects.insert(new Object(0.03, 0.02, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //13 (menupont)
    menu_objects.insert(new Object(0.03, 0.00, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //14 (menupont)
    menu_objects.insert(new Object(0.03, -0.02, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //15 (menupont)
    menu_objects.insert(new Object(0.03, -0.04, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //16 (menupont)
    menu_objects.insert(new Object(0.03, -0.06, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //17 (menupont)
    menu_objects.insert(new Object(0.03, -0.08, 0.0, //koordinatak
                            0, 90, 90, //elforgatas
                            0.0125, 1.0, 0.0075, //atmeretezes
                            "Textures/letters1", 0, "negyzet", 4, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag


    //18 (kurzor)
    menu_objects.insert(new Object(-0.11, 0.00, 0.0, //koordinatak
                            0, 0, 0, //elforgatas
                            0.01, 1.0, 0.01, //atmeretezes
                            "Textures/head.bmp", 0, "negyzet", 3, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    //19 (felirat)
   menu_objects.insert(new Object(-0.062, 0.05, 0.0, //koordinatak
                            0, 0, 0, //elforgatas
                            0.17, 1.0, 0.17, //atmeretezes
                            "Textures/title.bmp", 0, "negyzet", 3, 0)); //textura, mozaik legyen-e, modell, megjelenes tipusa, tetszoleges flag

    maxpalya = i;


}

void Menu::fel()
{
    cursor--;
    if (cursor < 0)
        cursor = maxcursor - 1;

    setcursor();
}

void Menu::le()
{
    cursor++;
    if (cursor >= maxcursor)
        cursor = 0;

    setcursor();
}

void Menu::balra()
{
    cursor-=9;
    if (cursor < 0)
        cursor = 0;

    setcursor();
}

void Menu::jobbra()
{
    cursor+=9;
    if (cursor >= maxcursor)
        cursor = maxcursor - 1;

    setcursor();
}

int Menu::getcursor()
{
    return cursor;
}

void Menu::setmaxcursor(int becursor)
{
    maxcursor = becursor;
}

void Menu::setcursor(int becursor)
{
    cursor = becursor;
    setcursor();

}

void Menu::setcursor()
{

    if  (maxcursor > 9)
    {
        menu_objects[18]->settx(-0.11+(cursor/9)*(0.125));
        menu_objects[18]->setty((cursor%9)*(-0.02)+0.08);
    }
    else if  (maxcursor == 9)
        menu_objects[18]->setty(cursor*(-0.02)+0.08);
    else if (maxcursor == 8)
        menu_objects[18]->setty(cursor*(-0.02)+0.06);
    else if  (maxcursor == 7)
        menu_objects[18]->setty(cursor*(-0.02)+0.04);
    else if  (maxcursor == 6)
        menu_objects[18]->setty(cursor*(-0.02)+0.02);
    else
        menu_objects[18]->setty(cursor*(-0.02));
}

void Menu::megjelenit(int & jatekresz)
{
    menu_objects[18]->megjelenit();

    if (jatekresz == 0)
    {

        menu_objects[0]->gprintf("start");
        menu_objects[2]->gprintf("be/0ll/2t/0s");
        menu_objects[1]->gprintf("kil/1p");

        menu_objects[19]->megjelenit();
    }

    if (jatekresz == 5)
    {
        if (maxpalya < 6)
        {
            menu_objects[0]->gprintf(palyalista[0]);
            menu_objects[2]->gprintf(palyalista[1]);
            menu_objects[1]->gprintf(palyalista[2]);
            if (maxpalya > 3)
                menu_objects[3]->gprintf(palyalista[3]);
            if (maxpalya > 4)
                menu_objects[4]->gprintf(palyalista[4]);
        }
        else if (maxpalya == 6)
        {
            menu_objects[5]->gprintf(palyalista[0]);
            menu_objects[0]->gprintf(palyalista[1]);
            menu_objects[2]->gprintf(palyalista[2]);
            menu_objects[1]->gprintf(palyalista[3]);
            menu_objects[3]->gprintf(palyalista[4]);
            menu_objects[4]->gprintf(palyalista[5]);
        }
        else if (maxpalya == 7)
        {
            menu_objects[6]->gprintf(palyalista[0]);
            menu_objects[5]->gprintf(palyalista[1]);
            menu_objects[0]->gprintf(palyalista[2]);
            menu_objects[2]->gprintf(palyalista[3]);
            menu_objects[1]->gprintf(palyalista[4]);
            menu_objects[3]->gprintf(palyalista[5]);
            menu_objects[4]->gprintf(palyalista[6]);
        }
        else if (maxpalya == 8)
        {
            menu_objects[7]->gprintf(palyalista[0]);
            menu_objects[6]->gprintf(palyalista[1]);
            menu_objects[5]->gprintf(palyalista[2]);
            menu_objects[0]->gprintf(palyalista[3]);
            menu_objects[2]->gprintf(palyalista[4]);
            menu_objects[1]->gprintf(palyalista[5]);
            menu_objects[3]->gprintf(palyalista[6]);
            menu_objects[4]->gprintf(palyalista[7]);
        }
        else
        {
            menu_objects[8]->gprintf(palyalista[0]);
            menu_objects[7]->gprintf(palyalista[1]);
            menu_objects[6]->gprintf(palyalista[2]);
            menu_objects[5]->gprintf(palyalista[3]);
            menu_objects[0]->gprintf(palyalista[4]);
            menu_objects[2]->gprintf(palyalista[5]);
            menu_objects[1]->gprintf(palyalista[6]);
            menu_objects[3]->gprintf(palyalista[7]);
            menu_objects[4]->gprintf(palyalista[8]);

            for (int i=9; i<maxpalya; i++)
                menu_objects[9]->gprintf(palyalista[9]);
        }
    }

    if (jatekresz == 6)
    {
        if (*hang)
            menu_objects[0]->gprintf("hang be");
        else
            menu_objects[0]->gprintf("hang ki");

        if (*zene)
            menu_objects[2]->gprintf("zene be");
        else
            menu_objects[2]->gprintf("zene ki");

        if (*fullscreen)
            menu_objects[1]->gprintf("teljes k/1perny/5 be");
        else
            menu_objects[1]->gprintf("teljes k/1perny/5 ki");

        menu_objects[3]->gprintf("felbont/0s");
    }

    if (jatekresz == 7)
    {
        menu_objects[8]->gprintf("320x200");
        menu_objects[7]->gprintf("320x240");
        menu_objects[6]->gprintf("400x225");
        menu_objects[5]->gprintf("400x250");
        menu_objects[0]->gprintf("400x300");
        menu_objects[2]->gprintf("640x480");
        menu_objects[1]->gprintf("800x450");
        menu_objects[3]->gprintf("800x500");
        menu_objects[4]->gprintf("800x600");
        menu_objects[9]->gprintf("1024x768");
        menu_objects[10]->gprintf("1152x864");
        menu_objects[11]->gprintf("1280x720");
        menu_objects[12]->gprintf("1280x800");
        menu_objects[13]->gprintf("1280x1024");
        menu_objects[14]->gprintf("egy/1ni");
    }

}

void Menu::megjelenit_res(int & jatekresz, int & setres)
{
    char temp[30];

    if (jatekresz == 8)
        menu_objects[0]->gprintf("sz/1less/1g");
    else if (jatekresz == 9)
        menu_objects[0]->gprintf("magass/0g");
    sprintf(temp, "%d", setres);
    menu_objects[2]->gprintf(temp);
}

void Menu::sethangok(bool * behang, bool * bezene, bool * befullscreen)
{
    hang = behang;
    zene = bezene;
    fullscreen = befullscreen;
}

void Menu::enter(int & jatekresz, bool & quit, bool & valtozas, int & width, int & height, int & setres, Jatek & jatek)
{
    switch (jatekresz)
                {
                    case 0: //fomenu
                    {
                        if (cursor == 0)
                        {
                            jatekresz = 5;
                            maxcursor = maxpalya;
                            setcursor(0);
                        }


                        if (cursor == 1)
                        {
                            jatekresz = 6;
                            maxcursor = 4;
                            setcursor(0);
                        }


                        if (cursor == 2)
                            quit = true;

                        break;
                    }
                    case 5: //palya menu
                    {
                        jatek.loadlevel(cursor+1);

                        if (*zene)
                            jatek.zene(zenelista[cursor]);

                        jatekresz = 1;
                        break;
                    }
                    case 6: //beallitasok
                    {
                        valtozas = true;

                        if (cursor == 0)
                        {
                            if (*hang)
                                *hang = false;
                            else
                                *hang = true;
                        }

                        if (cursor == 1)
                        {
                            if (*zene)
                                *zene = false;
                            else
                                *zene = true;

                        }

                        if (cursor == 2)
                        {
                            if (*fullscreen)
                                *fullscreen = false;
                            else
                                *fullscreen = true;

                        }

                        if (cursor == 3)
                        {
                            jatekresz = 7;
                            maxcursor = 15;
                            setcursor(0);
                        }


                        break;
                    }
                    case 7: //felbontas
                    {
                        if (cursor == 0)
                        {
                            width = 320;
                            height = 200;
                        }

                        if (cursor == 1)
                        {
                            width = 320;
                            height = 240;
                        }

                        if (cursor == 2)
                        {
                            width = 400;
                            height = 225;
                        }

                        if (cursor == 3)
                        {
                            width = 400;
                            height = 250;
                        }

                        if (cursor == 4)
                        {
                            width = 400;
                            height = 300;
                        }

                        if (cursor == 5)
                        {
                            width = 640;
                            height = 480;
                        }

                        if (cursor == 6)
                        {
                            width = 800;
                            height = 450;
                        }

                        if (cursor == 7)
                        {
                            width = 800;
                            height = 500;
                        }

                        if (cursor == 8)
                        {
                            width = 800;
                            height = 600;
                        }

                        if (cursor == 9)
                        {
                            width = 1024;
                            height = 768;
                        }

                        if (cursor == 10)
                        {
                            width = 1152;
                            height = 864;
                        }

                        if (cursor == 11)
                        {
                            width = 1280;
                            height = 720;
                        }

                        if (cursor == 12)
                        {
                            width = 1280;
                            height = 800;
                        }

                        if (cursor == 13)
                        {
                            width = 1280;
                            height = 1024;
                        }

                        if (cursor == 14)
                        {
                            jatekresz = 8;
                            setres = 0;
                        }

                        if (cursor < 14)
                            jatekresz = 6;

                        maxcursor = 4;
                        setcursor(0);

                        break;
                    }

                    case 8:
                    {
                        width = setres;
                        setres = 0;
                        jatekresz = 9;
                        break;
                    }

                    case 9:
                    {
                        height = setres;
                        setres = 0;
                        jatekresz = 6;
                        break;
                    }
                }
}
