#ifndef MENU_H
#define MENU_H

#include "vector"
#include "Jatek.h"

class Menu
{
    public:
        Menu();
        void fel(); //kurzor elmozditasa felfele
        void le(); //kurzor elmozditasa lefele
        void balra(); //kurzor elmozditasa balra
        void jobbra(); //kurzor elmozditasa jobbra
        void megjelenit(int & jatekresz); //menu elemeinek megjelenitese
        void megjelenit_res(int & jatekresz, int & setres); //menu elemeinek megjelenitese
        int getcursor();
        void setmaxcursor(int becursor);
        void setcursor(int becursor);
        void setcursor();
        void sethangok(bool * behang, bool * bezene, bool * befullscreen);
        void enter(int & jatekresz, bool & quit, bool & valtozas, int & width, int & height, int & setres, Jatek & jatek);
    protected:
    private:
        int cursor; //kurzor hanyadik menuponton van 0-tol kezdve
        int maxcursor; //maximum hany menupont van
        vector<Object*> menu_objects;
        int DB;
        bool * hang;
        bool * zene;
        bool * fullscreen;
        char zenelista[30][18];
        char palyalista[30][18];
        int maxpalya;
};

#endif // MENU_H
