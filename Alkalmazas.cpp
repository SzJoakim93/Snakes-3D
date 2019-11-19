#include "Alkalmazas.h"

Alkalmazas::Alkalmazas(char *frame_title, int bewidth, int beheight, int bedepth, char befullscreen)
{
    jatekresz = 0;

    //ctor
    this->width = bewidth;
    this->height = beheight;
    this->depth = bedepth;
    this->fullscreen = befullscreen;
    this->near=0.2;
    this->far=30.0;
    this->valtozas=false;
    this->setres=0;
    keystates = SDL_GetKeyState(NULL);
    SDL_Init(SDL_INIT_EVERYTHING);

    //a kepernyo beallitasa
	if (fullscreen)
	{
		SDL_SetVideoMode(width, height, depth,
						 SDL_OPENGL | SDL_FULLSCREEN);
	}
	else
	{
		SDL_SetVideoMode(width, height, depth,
						 SDL_OPENGL);
	}

	SDL_WM_SetCaption(frame_title, 0);

    FILE * file = fopen("settings.ini", "r");

    fscanf(file, "screen_width=%d\n", &width);
    fscanf(file, "screen_height=%d\n", &height);
    fscanf(file, "fullscreen=%d\n", &fullscreen);
	fscanf(file, "sound=%d\n", &hang);
	fscanf(file, "music=%d\n", &zene);


    menu = new Menu();
    jatek = new Jatek();

	jatek->sethangok(&hang);
	menu->sethangok(&hang, &zene, &fullscreen);

	fclose(file);

}

Alkalmazas::~Alkalmazas()
{
    if (valtozas)
    {
        FILE * file = fopen("settings.ini", "w");

        fprintf(file, "screen_width=%d\n", width);
        fprintf(file, "screen_height=%d\n", height);
        fprintf(file, "fullscreen=%d\n", fullscreen);
        fprintf(file, "sound=%d\n", hang);
        fprintf(file, "music=%d\n", zene);

        fclose(file);
    }

}

//a lataotavolsag megadasa
void Alkalmazas::eLoadProjectionMatrix(int width, int height, float near, float far)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float) width / (float) height, near, far);
}

void Alkalmazas::handleSDL2Events(bool & quit)
{
    while (SDL_PollEvent(&event))
    {
        if (keystates[SDLK_ESCAPE])
        {
            if (jatekresz == 0)
                quit = true;
            if (jatekresz > 0)
            {
                if (jatekresz > 0 && jatekresz < 5)
                    jatek->reset();
                jatekresz = 0;
                jatek->zene_stop();

                menu->setmaxcursor(3);
                menu->setcursor(0);
            }

        }

        if (event.type == SDL_KEYUP)
            if (event.key.keysym.sym == SDLK_RSHIFT)
                jatek->setspeed(0.02);


        if (jatekresz == 8 || jatekresz == 9)
        {
            if (keystates[SDLK_0] || keystates[SDLK_KP0])
                setres=setres*10;
            if (keystates[SDLK_1] || keystates[SDLK_KP1])
                setres=setres*10+1;
            if (keystates[SDLK_2] || keystates[SDLK_KP2])
                setres=setres*10+2;
            if (keystates[SDLK_3] || keystates[SDLK_KP3])
                setres=setres*10+3;
            if (keystates[SDLK_4] || keystates[SDLK_KP4])
                setres=setres*10+4;
            if (keystates[SDLK_5] || keystates[SDLK_KP5])
                setres=setres*10+5;
            if (keystates[SDLK_6] || keystates[SDLK_KP6])
                setres=setres*10+6;
            if (keystates[SDLK_7] || keystates[SDLK_KP7])
                setres=setres*10+7;
            if (keystates[SDLK_8] || keystates[SDLK_KP8])
                setres=setres*10+8;
            if (keystates[SDLK_9] || keystates[SDLK_KP9])
                setres=setres*10+9;

            if (keystates[SDLK_BACKSPACE] || keystates[SDLK_DELETE])
                setres=setres/10;
        }

        if (jatekresz == 0 || jatekresz > 4)
        {
            if (keystates[SDLK_UP])
            {
                menu->fel();
            }

            if (keystates[SDLK_DOWN])
            {
                menu->le();
            }

            if (jatekresz == 7 || jatekresz == 5)
            {
                if (keystates[SDLK_LEFT])
                {
                    menu->balra();
                }

                if (keystates[SDLK_RIGHT])
                {
                    menu->jobbra();
                }
            }

            if (keystates[SDLK_RETURN] || keystates[SDLK_SPACE])
            {
                menu->enter(jatekresz, quit,valtozas, width, height, setres, *jatek);
            }
        }
    }

    if (jatekresz == 1)
    {
        jatek->esemenyek(jatekresz);
        if (keystates[SDLK_LEFT] && jatek->getkesleltet_0() == 0)
        {
            jatek->balgomb();
        }
        else if (jatek->getbal_0())
        {
            jatek->balgomb2();
        }

        if (keystates[SDLK_RIGHT] && jatek->getkesleltet2_0() == 0)
        {
            jatek->jobbgomb();
        }
        else if (jatek->getjobb_0())
        {
            jatek->jobbgomb2();
        }

        if (keystates[SDLK_RSHIFT] || keystates[SDLK_LSHIFT])
        {
            if (jatek->speedable())
                    jatek->setspeed(0.035);
                else
                    jatek->setspeed(0.02);
        }
    }
}

void Alkalmazas::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    eLoadProjectionMatrix(width, height, near, far);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (jatekresz == 0 || jatekresz == 5 || jatekresz == 6 || jatekresz == 7)
        menu->megjelenit(jatekresz);
    if (jatekresz == 1 || jatekresz == 2 || jatekresz == 3 || jatekresz == 4)
        jatek->megjelenit(jatekresz);

    if (jatekresz == 8 || jatekresz == 9)
        menu->megjelenit_res(jatekresz, setres);

    glDisable(GL_BLEND);
    SDL_GL_SwapBuffers();

    SDL_Delay(20);
}

int Alkalmazas::getfar()
{
    return far;
}
