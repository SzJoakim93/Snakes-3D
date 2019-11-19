#ifndef OBJECT_H
#define OBJECT_H

#include "GL/gl.h"
#include "SDL/SDL.h"
#include "gl/glu.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>

typedef struct eCoord3f
{
    float x;
    float y;
    float z;
} eCoord3f;

typedef struct eVertex
{
    eCoord3f coord;
    eCoord3f normal;
} eVertex;

typedef struct eFace
{
    eVertex a, b, c;
} eFace;

typedef struct eMesh
{
    int max_face_num;
    int current_face_num;
    eFace *faces;
} eMesh;

typedef struct eVertexList
{
    int max_vertex_num;
    int current_vertex_num;
    eVertex *vertices;
} eVertexList;

class Object
{
    public:
        Object(float betx, float bety, float betz,
             int berx, int bery, int berz,
             float besx, float besy, float besz,
             char* betexture, int bemozaik, char* betype, int beapp, int beflag);
        ~Object();
        void megjelenit(); //Object parameter nelkuli megjelenitese (kep eseten)
        void gprintf(char * title); //Object megjelenitese szovegkent
        static void cHorizontal(const float & x); //kamera mozgasa elore
        void aelore(const float & x); //Object mozgasa elore
        void ahatra(const float & x); //Object mozgasa hatra
        static void rotate_camera(const int & x); //kamera forgatasa jobbra
        void abalra(); //Object mozgasa balra
        void ajobbra(); //Object mozgasa jobbra
        void afel(const float & x);
        void ale(const float & x);
        bool collision(Object *& other, const int & space);
        void follow(Object *& other);
        //setterek:
        void settx(const float & x);
        void setty(const float & y);
        void settz(const float & z);
        void setsx(const float & x);
        void setsy(const float & y);
        void setsz(const float & z);
        static void setcx(const float & x);
        static void setcy(const float & y);
        static void setcz(const float & z);
        void setrabsolute(int be);
        static void setrcamera(const int & x);
        //getterek:
        float gettx();
        float getty();
        float gettz();
        float getcx();
        float getcy();
        float getcz();
        float getsx();
        float getsy();
        float getsz();
        int getrx();
        int getry();
        int getrz();
        int getrabsolute();
        int getflag();
    protected:
    private:
        //terep textura koordinatai
        static const float terrain_vertices[90];
        static const float rect_vertices[18];
        float * rect_texcoords;
        //Object koordinatai:
        float tx;
        float ty;
        float tz;
        //kamera eltolas:
        static float cx;
        static float cy;
        static float cz;
         //Object elforgatasa:
        int rx;
        int ry;
        int rz;
         //kamera koruli forgatas
        static int rcamera;
        //Object iranya (jelen esetben az ellenfel merre forduljon)
        int rabsolute;
        //Object atmeretezese:
        float sx;
        float sy;
        float sz;
        //blender file betoltese eseten az obj file elerese, negyzet eseten a "negyzet" szo
        char objname[32];
        //textura elerese, szoveg kiirasa eseten csak a mappa nevet kell megadni
        char texture[32];
        //megjelenes tipusa
        int appear;
        //mozaik texturazas: 0: nyujtja a texturat 1: a texturazas mozaikokkal torteneik 2: csak vizszintesen nyujtja 3: csak fuggolegesen nyujtja,
        int mozaik;
        //textura azonositoi
        GLuint * textureid;
        //tetszoleges flag
        int flag;
        eMesh mesh;

        //ez a 3 mar ismeros :D
        char eCreateTextureFromSDLSurface(SDL_Surface *surf, GLuint & textureid);
        void eLoadBMPTexture(char *filename, GLuint & textureid);
        void square(); //beepitett negyzet kirajzolasa
        void rise(const char & x);
        void eRenderMesh(eMesh *m);
        void eLoadMeshFromOBJ(eMesh *mesh, char *file);
        void eInitVertexList(eVertexList *vl);
        void eAddFaceToMesh(eMesh *mesh, eFace *face);
        void eAddVertexToVertexList(eVertexList *vl, eVertex *vertex);
        void eInitMesh(eMesh *mesh);
};

#endif // OBJECT_H
