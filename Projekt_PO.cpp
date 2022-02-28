#include <iostream>
#include "Swiat.h"
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_Q 113
#define KEY_SPACE 32
#define KEY_L 108
#define KEY_S 115


int main()
{
    srand(time(NULL));
    Swiat* swiat = new Swiat();
    swiat->rysujSwiat();

    int input = 0;
    bool koncz = 0;
    bool pomin = 0;
    while (true) {
        input = 0;
        switch ((input = _getch())) {
        case KEY_UP:
            swiat->SetButton(KEY_UP);
            break;
        case KEY_DOWN:
            swiat->SetButton(KEY_DOWN);
            break;
        case KEY_LEFT:
            swiat->SetButton(KEY_LEFT);
            break;
        case KEY_RIGHT:
            swiat->SetButton(KEY_RIGHT);
            break;
        case KEY_Q:
            koncz = true;
            break;
        case KEY_SPACE:
            swiat->SetButton(KEY_SPACE);
            break;
        case KEY_L:
            pomin = 1;
            swiat->LoadSwiat();
            break;
        case KEY_S:
            pomin = 1;
            swiat->SaveSwiat();
            break;
        case 224:
            pomin = 1;
            break;
        default:
            swiat->SetButton(0);
            break;
        }
        if (koncz) {
            break;
        }
        else if (!pomin) {
            swiat->wykonajTure();
            swiat->rysujSwiat();
        }
        else {
            pomin = 0;
        }
    }
    delete swiat;
    return 0;
}