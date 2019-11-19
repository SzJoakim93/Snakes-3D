#include "Object.h"

float Object::cx = 0.0;
float Object::cy = 0.0;
float Object::cz = 0.0;
int Object::rcamera = 0;

const float Object::rect_vertices[18] = {    -0.5, 0, -0.5,
                            0.5, 0, 0.5,
                            0.5, 0, -0.5,

                            -0.5, 0, -0.5,
                            -0.5, 0, 0.5,
                            0.5, 0, 0.5
                       };

const float Object::terrain_vertices[90] = {-0.5, -0.25, 0.5, // positive z
                                            0.5, -0.25, 0.5,
                                            0.25, 0.25, 0.25,

                                            -0.5, -0.25, 0.5,
                                            0.25, 0.25, 0.25,
                                            -0.25, 0.25, 0.25,

                                            -0.5, -0.25, -0.5, // negative z
                                            0.5, -0.25, -0.5,
                                            0.25, 0.25, -0.25,

                                            -0.5, -0.25, -0.5,
                                            0.25, 0.25, -0.25,
                                            -0.25, 0.25, -0.25,

                                            -0.25, 0.25, -0.25, // positive y
                                            0.25, 0.25, -0.25,
                                            0.25, 0.25, 0.25,

                                            -0.25, 0.25, -0.25,
                                            0.25, 0.25, 0.25,
                                            -0.25, 0.25, 0.25,

                                            0.5, -0.25, -0.5, // positive x
                                            0.25, 0.25, -0.25,
                                            0.25, 0.25, 0.25,

                                            0.5, -0.25, -0.5,
                                            0.25, 0.25, 0.25,
                                            0.5, -0.25, 0.5,

                                            -0.5, -0.25, -0.5, // negative x
                                            -0.25, 0.25, -0.25,
                                            -0.25, 0.25, 0.25,

                                            -0.5, -0.25, -0.5,
                                            -0.25, 0.25, 0.25,
                                            -0.5, -0.25, 0.5
                                        };

Object::Object(float betx, float bety, float betz, int berx, int bery, int berz, float besx, float besy, float besz, char* betexture, int bemozaik, char* beobjname, int beapp, int beflag)
{
    //ctor
    this->tx = betx;
    this->ty = bety;
    this->tz = betz;
    this->cx = 0;
    this->cy = 0;
    this->cz = 0;
    this->rx = berx;
    this->ry = bery;
    this->rz = berz;
    this->sx = besx;
    this->sy = besy;
    this->sz = besz;
    this->rcamera = 0;
    this->rabsolute = 0;
    this->appear = beapp;
    this->mozaik = bemozaik;
    this->flag = beflag;
    strcpy(texture, betexture);

    if (appear < 4)
    {
        textureid = new GLuint;
        glGenTextures(1, textureid);
        eLoadBMPTexture(texture, textureid[0]);
    }

    if (appear == 4)
    {
        textureid = new GLuint [45];
        glGenTextures(45, textureid);
        for (int i=0; i<26; i++)
        {

            char temp[30];
            strcpy(temp, texture);
            strcat(temp, "/");
            char temp2[2]={'A'+i, 0};
            strcat(temp, temp2);
            strcat(temp, ".bmp");
            eLoadBMPTexture(temp, textureid[i]);
        }

        for (int i=0; i<10; i++)
        {
            char temp[30];
            strcpy(temp, texture);
            strcat(temp, "/");
            char temp2[2]={'0'+i, 0};
            strcat(temp, temp2);
            strcat(temp, ".bmp");
            eLoadBMPTexture(temp, textureid[26+i]);
        }

        for (int i=0; i<9; i++)
        {
            char temp[30];
            strcpy(temp, texture);
            strcat(temp, "/_");
            char temp2[2]={'0'+i, 0};
            strcat(temp, temp2);
            strcat(temp, ".bmp");
            eLoadBMPTexture(temp, textureid[36+i]);
        }
    }
    eInitMesh(&mesh);
    strcpy(this->objname, beobjname);

    if (!strncmp(objname, "rise", 4))
    {
        rect_texcoords = new float [60];
        for (int i=0; i<60; i++)
        {
            if (i == 2 || i == 4 || i == 5 || i == 8 || i == 9 || i == 11 || i == 14 || i == 16 || i == 17 || i == 20 || i == 21 || i == 23 ||
                i == 38 || i == 40 || i == 41 || i == 44 || i == 45 || i == 47 || i == 50 || i == 52 || i == 53 || i == 56 || i == 57 || i == 59)
                rect_texcoords[i] = sx;
            else if (i == 26 || i == 28 || i == 29 || i == 32 || i == 33 || i == 35)
                rect_texcoords[i] = sz;
            else
                rect_texcoords[i] = 0;
        }
    }
    else if (!strcmp(objname, "negyzet"))
    {
        rect_texcoords = new float [12];
        for (int i=0; i<12; i++)
            if (i==0 || i==1 || i ==4 || i==6 || i==7 || i==9)
                rect_texcoords[i] = 0;
            else
                rect_texcoords[i] = 1;

        if (mozaik)
        {
            for (int i=0; i<12; i++)
                if (i==0 || i==1 || i ==4 || i==6 || i==7 || i==9)
                    rect_texcoords[i] = 0;
                else if (mozaik != 2 && (i==2 || i==8 || i ==10))
                    rect_texcoords[i] = sz;
                else if (mozaik != 3)
                    rect_texcoords[i] = sx;
        }
    }
    else if (strcmp(objname, "negyzet"))
        eLoadMeshFromOBJ(&mesh, objname);
    //eCalcMeshNormals(&mesh);
}

Object::~Object()
{
    if (strcmp(objname, "negyzet"))
        delete [] mesh.faces;
    else
        delete [] rect_texcoords;

    if (appear < 4)
        glDeleteTextures(1, textureid);
    else
        glDeleteTextures(45, textureid);

    delete [] textureid;
}

void Object::megjelenit()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureid[0]);
    glPushMatrix();

    if (appear < 2)
    {
        glRotatef(20, 1, 0, 0); //alap elforgatas a kameranezetnek megfeleloen

        //az Object elforgatasa a kamerahoz kepest

        glTranslatef(0, -0.25, -0.85); //a kulso nezet miatti eltolas (belso nezet eseten ez nem kell)

        glRotatef(rcamera, 0, 1, 0);

        glTranslatef(tx, ty, tz); //eltolas az abszolut helyre
        glTranslatef(cx, cy, cz); //kamera eltolas

        if (appear == 1)
            glRotatef(-rcamera, 0, 1, 0);

        //az Object elforgatasa az abszolut helyzetetehez kepest
        glRotatef(rx, 1, 0, 0);
        glRotatef(ry, 0, 1, 0);
        glRotatef(rz, 0, 0, 1);

        /*if (sy == 0.0) //szamitasi egyszerusites miatt a 0 osszenyomast is 1-nek vesszuk
            glScalef(sx, 1.0, sz);
        else*/
        glScalef(sx, sy, sz); //nagyitas/kicsinyites
    }
    else if (appear == 2)
    {
        glTranslatef(0, 2, tz);
        glRotatef(90, 1, 0, 0);
        glScalef(sx, 1.0, sz);
    }
    else if (appear == 3)
    {
        glTranslatef(tx, ty, -0.25);
        glRotatef(-90, 1, 0, 0);
        glRotatef(90, 0, 1, 0);
        glScalef(sx, sy, sz);
    }

    if (!strcmp(objname, "negyzet"))
        square();
    else if (!strncmp(objname, "rise", 4))
        rise(objname[4]);
    else
        eRenderMesh(&mesh);

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void Object::gprintf(char * title)
{
    int i=0;
    int j=0;

    while (title[i] != 0)
    {

        if (title[i] != ' ')
        {
            glEnable(GL_TEXTURE_2D);

            if (title[i] == '/')
            {
                i++;
                j++;
                glBindTexture(GL_TEXTURE_2D, textureid[36+title[i]-'0']);
            }
            else if (title[i] < 'a')
                glBindTexture(GL_TEXTURE_2D, textureid[26+title[i]-'0']);
            else
                glBindTexture(GL_TEXTURE_2D, textureid[title[i]-'a']);


            glPushMatrix();

            glTranslatef(tx+(i-j)*sx, ty, -0.25);
            glRotatef(-90, 1, 0, 0);
            glRotatef(90, 0, 1, 0);
            glScalef(sx, sy, sz);

            if (!strcmp(objname, "negyzet"))
                square();
            /*else
                eRenderMesh(&mesh);*/

            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
        }
        i++;
    }

}

char Object::eCreateTextureFromSDLSurface(SDL_Surface *surf, GLuint & textureid)
{
    glGetError();

    glBindTexture(GL_TEXTURE_2D, textureid);

    int pixels = surf->w * surf->h * 4;
    unsigned char *surfacedata = (unsigned char*) surf->pixels;
    unsigned char *data = (unsigned char*) malloc(sizeof(unsigned char) * pixels);
    int i;

    for (i = 0; i < pixels; i += 4)
    {
        data[i + 0] = surfacedata[i + 2];
        data[i + 1] = surfacedata[i + 1];
        data[i + 2] = surfacedata[i + 0];
        data[i + 3] = surfacedata[i + 3];
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // ezt a ket sort rakd vissza kommentbe es probald ki, hogy mit csinal
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    free(data);

    return 0;
}


void Object::eLoadBMPTexture(char *filename, GLuint & textureid)
{
    char error = 1;

    if (textureid)
    {
        SDL_Surface *image = SDL_LoadBMP(filename);
        if (!image)
            image = SDL_LoadBMP("error.bmp");
        SDL_Surface *optimized = NULL;
        if (image)
        {
            optimized = SDL_DisplayFormat(image);

            SDL_Flip (optimized);
            SDL_FreeSurface(image);

            if (optimized)
            {
                if (!eCreateTextureFromSDLSurface(optimized, textureid))
                {
                    error = 0;
                }
                SDL_FreeSurface(optimized);
            }
        }
    }

    if (error)
    {
        fprintf(stderr, "Error during loading texture: %s\n", filename);
    }
}

void Object::square()
{
    glVertexPointer(3, GL_FLOAT, 0, rect_vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, rect_texcoords);

    glEnableClientState(GL_VERTEX_ARRAY);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, sizeof(rect_vertices) / sizeof(float) / 3);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Object::rise(const char & x)
{
    float lejtes = x - '0';

    glVertexPointer(3, GL_FLOAT, 0, terrain_vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, rect_texcoords);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glDrawArrays(GL_TRIANGLES, 0, sizeof(terrain_vertices) / sizeof(float) / 3);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Object::eAddFaceToMesh(eMesh *mesh, eFace *face)
{
    if (mesh->current_face_num >= mesh->max_face_num)
    {
        int incsize = mesh->max_face_num * 2 + 1;
        eFace *tmp = (eFace*) malloc(sizeof(eFace) * incsize);

        memcpy(tmp, mesh->faces, mesh->max_face_num * sizeof(eFace));
        mesh->max_face_num = incsize;

        if (mesh->faces)
        {
            free(mesh->faces);
        }
        mesh->faces = tmp;
    }

    mesh->faces[mesh->current_face_num++] = *face;
}

void Object::eInitVertexList(eVertexList *vl)
{
    vl->vertices = 0;
    vl->max_vertex_num = 0;
    vl->current_vertex_num = 0;
}

void Object::eLoadMeshFromOBJ(eMesh *mesh, char *file)
{
    FILE *fd = fopen(file, "rb");

    eVertexList vertexlist;
    eInitVertexList(&vertexlist);

    if (fd)
    {
        while (!feof(fd))
        {
            char str[256];
            fscanf(fd, "%s", str);
            if (feof(fd))
            {
                break;
            }

            if (!strcmp(str, "f"))
            {
                int a, b, c;

                fscanf(fd, "%d %d %d", &a, &b, &c);
                if (feof(fd))
                {
                    break;
                }
                a--;
                b--;
                c--;

                eFace face;

                face.a = vertexlist.vertices[a];
                face.b = vertexlist.vertices[b];
                face.c = vertexlist.vertices[c];
                eAddFaceToMesh(mesh, &face);
                b = c;

                while (!feof(fd))
                {
                    char str[256];
                    fscanf(fd, "%s", str);
                    if (feof(fd))
                    {
                        break;
                    }

                    if (!strcmp(str, "f"))
                    {
                        int offset = -strlen(str);
                        fseek(fd, offset, SEEK_CUR);
                        break;
                    }
                    else
                    {
                        sscanf(str, "%d", &c);
                        c--;

                        face.a = vertexlist.vertices[a];
                        face.b = vertexlist.vertices[b];
                        face.c = vertexlist.vertices[c];
                        eAddFaceToMesh(mesh, &face);
                        b = c;
                    }
                }
            }
            else if (!strcmp(str, "v"))
            {
                eVertex v;
                fscanf(fd, "%f %f %f", &v.coord.x, &v.coord.y, &v.coord.z);
                if (feof(fd))
                {
                    break;
                }

                eAddVertexToVertexList(&vertexlist, &v);
            }
        }

        fclose(fd);
    }

    if (vertexlist.vertices)
    {
        free(vertexlist.vertices);
    }
}

void Object::eAddVertexToVertexList(eVertexList *vl, eVertex *vertex)
{
    if (vl->current_vertex_num >= vl->max_vertex_num)
    {
        int incsize = vl->max_vertex_num * 2 + 1;
        eVertex *tmp = (eVertex*) malloc(sizeof(eVertex) * incsize);

        memcpy(tmp, vl->vertices, vl->max_vertex_num * sizeof(eVertex));
        vl->max_vertex_num = incsize;

        if (vl->vertices)
        {
            free(vl->vertices);
        }
        vl->vertices = tmp;
    }

    vl->vertices[vl->current_vertex_num++] = *vertex;
}

void Object::eRenderMesh(eMesh *m)
{

    float * texcoords = (float*)malloc(sizeof(float) * m->max_face_num * 12);

    for (int i=0; i<m->max_face_num*12; i+=12)
    {
        texcoords[i] = 0;
        texcoords[i+1] = 0;
        texcoords[i+2] = 1;
        texcoords[i+3] = 0;
        texcoords[i+4] = 1;
        texcoords[i+5] = 1;
        texcoords[i+6] = 0;
        texcoords[i+7] = 0;
        texcoords[i+8] = 1;
        texcoords[i+9] = 1;
        texcoords[i+10] = 0;
        texcoords[i+11] = 1;
    }

    if (mozaik)
    {
        int i;
        for (i=0; i<12; i++)
            if (i==0 || i==1 || i ==4 || i==6 || i==7 || i==9)
                texcoords[i] = 0;
            else if (mozaik != 2 && (i==2 || i==8 || i ==10))
                texcoords[i] = sz;
            else if (mozaik != 3)
                texcoords[i] = sx;
    }


    glVertexPointer(3, GL_FLOAT, sizeof(eVertex), &m->faces->a.coord.x);
    //glNormalPointer(GL_FLOAT, sizeof(eVertex), &m->faces->a.normal.x);
    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

    glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glDrawArrays(GL_TRIANGLES, 0, m->current_face_num * 3);

    glDisableClientState(GL_VERTEX_ARRAY);
    //glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    free(texcoords);
}

void Object::eInitMesh(eMesh *mesh)
{
    mesh->faces = 0;
    mesh->current_face_num = 0;
    mesh->max_face_num = 0;
}

void Object::settx(const float & x)
{
    this->tx = x;
}

void Object::setty(const float & y)
{
    this->ty = y;
}

void Object::settz(const float & z)
{
    this->tz = z;
}

void Object::setsx(const float & x)
{
    this->sx = x;
}

void Object::setsy(const float & y)
{
    this->sy = y;
}

void Object::setsz(const float & z)
{
    this->sz = z;
}

void Object::setcx(const float & x)
{
    cx = x;
}

void Object::setcy(const float & y)
{
    cy = y;
}

void Object::setcz(const float & z)
{
    cz = z;
}

void Object::setrabsolute(int be)
{
    this->rabsolute = be;
}

void Object::setrcamera(const int & x)
{
    rcamera = x;
}

float Object::gettx()
{
    return tx;
}

float Object::getty()
{
    return ty;
}

float Object::gettz()
{
    return tz;
}

float Object::getcx()
{
    return cx;
}

float Object::getcy()
{
    return cy;
}

float Object::getcz()
{
    return cz;
}

float Object::getsx()
{
    return sx;
}

float Object::getsy()
{
    return sy;
}

float Object::getsz()
{
    return sz;
}

int Object::getrx()
{
    return rx;
}

int Object::getry()
{
    return ry;
}

int Object::getrz()
{
    return rz;
}

void Object::cHorizontal(const float & x)
{
    cz +=cos(rcamera*3.1415/180)*x;
    cx -=sin(rcamera*3.1415/180)*x;
}

void Object::aelore(const float & x)
{
    tz -=cos(rabsolute*3.1415/180)*x;
    tx +=sin(rabsolute*3.1415/180)*x;
}

void Object::ahatra(const float & x)
{
    tz +=cos(rabsolute*3.1415/180)*x;
    tx -=sin(rabsolute*3.1415/180)*x;
}

void Object::rotate_camera(const int & x)
{
    rcamera+=x;
    if (rcamera < 0)
        rcamera = 358;
}

void Object::abalra()
{
    rabsolute+=2;
    if (rabsolute > 358)
        rabsolute = 0;
}

void Object::ajobbra()
{
    rabsolute-=2;
    if (rcamera < 0)
        rabsolute = 358;
}

void Object::afel(const float & x)
{
    ty+=x;
}

void Object::ale(const float & x)
{
    ty-=x;
}

int Object::getrabsolute()
{
    return rabsolute;
}

int Object::getflag()
{
    return flag;
}

bool Object::collision(Object *& other, const int & space)
{
    //if (other->getrz() )
    if (other->getry() == 0 || other->getry() == 180)
    {
        if (tx + 0.05 > other->gettx() - (other->getsy()*(space/100.0)) / 2.0 &&
        tx - 0.05 <= other->gettx() + (other->getsy()*(space/100.0)) / 2.0 &&
        tz + 0.05 > other->gettz() - (other->getsz()*(space/100.0)) / 2.0 &&
        tz - 0.05 <= other->gettz() + (other->getsz()*(space/100.0)) / 2.0)
            return true;
        else
            return false;
    }
    else
    {
        if (tx + 0.05 > other->gettx() - (other->getsz()*(space/100.0)) / 2.0 &&
        tx - 0.05 <= other->gettx() + (other->getsz()*(space/100.0)) / 2.0 &&
        tz + 0.05 > other->gettz() - (other->getsy()*(space/100.0)) / 2.0 &&
        tz - 0.05 <= other->gettz() + (other->getsy()*(space/100.0)) / 2.0)
            return true;
        else
            return false;
    }

}

void Object::follow(Object *& other)
{
    if (tx > other->gettx() + 0.1)
    {
        rabsolute = 270;
    }
    else if (tx < other->gettx() - 0.1)
    {
        rabsolute = 90;
    }
    else if (tz > other->gettz())
    {
        rabsolute = 0;
    }
    else if (tz < other->gettz())
    {
        rabsolute = 180;
    }
}
