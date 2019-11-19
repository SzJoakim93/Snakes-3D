#include "Elem_tarolo.h"

Elem_tarolo::Elem_tarolo()
{
    //ctor
    elemszam = 0;
}

Elem_tarolo::~Elem_tarolo()
{
    //dtor
    if (elemszam > 0)
        delete [] elemek;
}

void Elem_tarolo::hozzaad(Object ujelem)
{

    Object * temp = new Object[elemszam+1];

    for (int i=0; i<elemszam; i++)
        temp[i] = elemek[i];

    temp[elemszam] = ujelem;

    if (elemszam > 0)
        delete [] elemek;

    elemszam++;

    elemek = temp;
}

void Elem_tarolo::torol()
{
    if (elemszam > 0)
        delete [] elemek;

    elemszam = 0;
}

Object & Elem_tarolo::operator [] (int i)
{
    return elemek[i];
}

bool Elem_tarolo::utkozes(const int & e1, const int & e2, const int & space)
{
    if (other->getry() == 0 || other->getry() == 180)
    {
        if (elemek[e1].gettx() + elemek[e1].getsx() / 2.0 > other->gettx() - (other->getsy()*(space/100.0)) / 2.0 &&
        elemek[e1].gettx() - elemek[e1].getsx() / 2.0 <= other->gettx() + (other->getsy()*(space/100.0)) / 2.0 &&
        elemek[e1].gettz() + elemek[e1].getsz() / 2.0 > other->gettz() - (other->getsz()*(space/100.0)) / 2.0 &&
        elemek[e1].gettz() - elemek[e1].getsz() / 2.0 <= other->gettz() + (other->getsz()*(space/100.0)) / 2.0)
            return true;
        else
            return false;
    }
    else
    {
        if (elemek[e1].gettx() + elemek[e1].getsx() / 2.0 > other->gettx() - (other->getsz()*(space/100.0)) / 2.0 &&
        elemek[e1].gettx() - elemek[e1].getsx() / 2.0 <= other->gettx() + (other->getsz()*(space/100.0)) / 2.0 &&
        elemek[e1].gettz() + elemek[e1].getsz() / 2.0 > other->gettz() - (other->getsy()*(space/100.0)) / 2.0 &&
        elemek[e1].gettz() - elemek[e1].getsz() / 2.0 <= other->gettz() + (other->getsy()*(space/100.0)) / 2.0)
            return true;
        else
            return false;
    }

}

void Elem_tarolo::kovet(const int & e1, const int & e2)
{
    if (elemek[e1].gettx() > other->gettx() + 0.1)
    {
        elemek[e1].setrabsolute(270);
    }
    else if (elemek[e1].gettx() < other->gettx() - 0.1)
    {
        elemek[e1].setrabsolute(90);
    }
    else if (elemek[e1].gettz() > other->gettz())
    {
        elemek[e1].setrabsolute(0);
    }
    else if (elemek[e1].gettz() < other->gettz())
    {
        elemek[e1].setrabsolute(180);
    }
}

int & Elem_tarolo::getelemszam()
{
    return elemszam;
}

void Elem_tarolo::camera_elore(const float & x)
{
    for (int i=0; i<elemszam; i++)
        elemek[i].celore(x);
}

void Elem_tarolo::camera_hatra(const float & x)
{
    for (int i=0; i<elemszam; i++)
        elemek[i].chatra(x);
}

void Elem_tarolo::setCameraY(const float & x)
{
    for (int i=0; i<elemszam; i++)
        elemek[i].setcy(x);
}
