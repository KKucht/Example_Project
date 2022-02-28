#include "Czlowiek.h"
#include <string>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32

Organizm* Czlowiek::NowyOrganizm(int newX, int newY) {
    Organizm* nowy = new Czlowiek(this->swiat, newX, newY, this);
    this->swiat->SetOrganizmZPlanszy(newX,newY, nowy);
    return nowy;
}

void Czlowiek::TarczaAlzura(int newX, int newY, std::string& opis) {
    opis += " ma na sobie Tarcze Alzura.";
    Organizm* tmp = this->swiat->GetOrganizmZPlanszy(newX, newY);
    this->swiat->SetOrganizmZPlanszy(newX, newY, nullptr);
    newX = this->x;
    newY = this->y;
    bool* mozliwosci = Mozliwosci();
    int dX, dY;
    while (true) {
        dX = rand() % 3 - 1;
        dY = rand() % 3 - 1;
        if (dX != 0 || dY != 0) {
            if (mozliwosci[0]) {
                if (dX == -1 && dY == 1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x+dX, y+dY))) {
                        newX = x + dX;
                        newY = y + dY;
                        break;
                    }
                    else {
                        mozliwosci[0] = false;
                    }
                }
            }
            if (mozliwosci[1]) {
                if (dX == 0 && dY == 1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                        newX = x + dX;
                        newY = y + dY;
                        break;
                    }
                    else {
                        mozliwosci[1] = false;
                    }
                }
            }
            if (mozliwosci[2]) {
                if (dX == 1 && dY == 1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                        newX = x + dX;
                        newY = y + dY;
                        break;
                    }
                    else {
                        mozliwosci[2] = false;
                    }
                }
            }
            if (mozliwosci[7]) {
                if (dX == -1 && dY == 0) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                        newX = x + dX;
                        newY = y + dY;
                        break;
                    }
                    else {
                        mozliwosci[7] = false;
                    }
                }
            }
            if (mozliwosci[3]) {
                if (dX == 1 && dY == 0) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                        newX = x + dX;
                        newY = y + dY;
                        break;
                    }
                    else {
                        mozliwosci[3] = false;
                    }
                }
            }
            if (mozliwosci[6]) {
                if (dX == -1 && dY == -1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                        newX = x + dX;
                        newY = y + dY;
                        break;
                    }
                    else {
                        mozliwosci[6] = false;
                    }
                }
            }
            if (mozliwosci[5]) {
                if (dX == 0 && dY == -1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                        newX = x + dX;
                        newY = y + dY;
                        break;
                    }
                    else {
                        mozliwosci[5] = false;
                    }
                }
            }
            if (mozliwosci[4]) {
                if (dX == 1 && dY == -1) {
                    if (!(this->swiat->GetOrganizmZPlanszy(x + dX, y + dY))) {
                        newX = x + dX;
                        newY = y + dY;
                        break;
                    }
                    else {
                        mozliwosci[4] = false;
                    }
                }
            }
            bool koniec = true;
            for (int i = 0; i < 8; i++) {
                if (mozliwosci[i]) {
                    koniec = false;
                    break;
                }
            }
            if (koniec) {
                opis += "wystapil, jakis blad!!!";
                delete[] mozliwosci;
                return;
            }
        }
    }
    this->swiat->SetOrganizmZPlanszy(newX, newY, tmp);
    tmp->SetX(newX);
    tmp->SetY(newY);
    opis += " Zwierze zostalo odbite na (" + std::to_string(newX) + "," + std::to_string(newY) + ").";
    delete[] mozliwosci;
}

void Czlowiek::Nazwa(std::string& opis) {
    opis += "Czlowiek";
}

Czlowiek::Czlowiek(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y) {
    moc = false;
    odliczanie = 0;
    this->sila = 5;
    this->inicjatywa = 4;
}

Czlowiek::Czlowiek(Swiat* swiat, int x, int y, Organizm* pre) : Zwierze(swiat, x, y, pre) {
    moc = false;
    odliczanie = 0;
    this->sila = 5;
    this->inicjatywa = 4;
}

Czlowiek::Czlowiek(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : Zwierze(swiat, x, y, pre, nxt) {
    moc = false;
    odliczanie = 0;
    this->sila = 5;
    this->inicjatywa = 4;
}

Czlowiek::Czlowiek(Swiat* swiat, int x, int y, int rundyMlodosci) : Zwierze(swiat, x, y, rundyMlodosci) {
    this->sila = 5;
    this->inicjatywa = 4;
    moc = false;
    odliczanie = 0;
}

Czlowiek::Czlowiek(Swiat* swiat, int x, int y, Organizm* pre, int rundyMlodosci) : Zwierze(swiat, x, y, pre, rundyMlodosci) {
    this->sila = 5;
    this->inicjatywa = 4;
    moc = false;
    odliczanie = 0;
}

Czlowiek::Czlowiek(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt, int rundyMlodosci) : Zwierze(swiat, x, y, pre, nxt, rundyMlodosci) {
    this->sila = 5;
    this->inicjatywa = 4;
    moc = false;
    odliczanie = 0;
}

char Czlowiek::Rysowanie() {
    if (dojrzalosc == 0) {
        return 'C';
    }
    else {
        return 'c';
    }
}

bool Czlowiek::Obrona(int newX, int newY, std::string& opis) {
    Nazwa(opis);
    if (moc) {
        TarczaAlzura(newX, newY, opis);
        return false;
    }
    else {
        if (this->sila > this->swiat->GetOrganizmZPlanszy(newX, newY)->GetSila()) {
            opis += " wybronil sie.";
            return false;
        }
        else {
            opis += " umarl.";
            this->inicjatywa = -1;
            this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
            return true;
        }
    }
}

void Czlowiek::Akcja(std::string& opis) {
    Nazwa(opis);
    opis = opis + "(" + std::to_string(x) + "," + std::to_string(y) + ") z sila " + std::to_string(sila);
    int newX = this->x, newY = this->y;
    int instrukcja = this->swiat->GetButton();
    if (instrukcja == KEY_SPACE) {
        if (!moc && odliczanie == 0) {
            opis += " wlaczyl Tarcze Alzura. ";
            moc = 1;
            odliczanie = 4;
        }
    }
    else if (instrukcja == KEY_LEFT) {
        if (x - 1 != -1) {
            newX--;
        }
    }
    else if (instrukcja == KEY_RIGHT) {
        if (x + 1 != this->swiat->GetN()) {
            newX++;
        }
    }
    else if (instrukcja == KEY_UP) {
        if (y - 1 != -1) {
            newY--;
        }
    }
    else if (instrukcja == KEY_DOWN) {
        if (y + 1 != this->swiat->GetM()) {
            newY++;
        }
    }
    if (newX != this->x || newY !=this->y) {
        if (!(this->swiat->GetOrganizmZPlanszy(newX, newY))) {
            opis += " wszedl na (" + std::to_string(newX) + "," + std::to_string(newY) + ").";
            this->swiat->SetOrganizmZPlanszy(this->x, this->y, nullptr);
            this->x = newX;
            this->y = newY;
            this->swiat->SetOrganizmZPlanszy(this->x, this->y, this);
        }
        else {
            Kolizja(newX, newY, opis);
        }
    }
    if (inicjatywa != -1) {
        if (!moc) {
            if (odliczanie != 0) {
                odliczanie--;
            }
            if (odliczanie != 0) {
                opis += " Moc bedzie dzialac za " + std::to_string(odliczanie) + " tur.";
            }
            else {
                opis += " Moc gotowa do uzycia.";
            }
        }
        else {
            if (odliczanie != 0) {
                opis += " Moc dziala jeszcze prze " + std::to_string(odliczanie) + " tury.";
                odliczanie--;
                if (odliczanie == 0) {
                    odliczanie = 6;
                    moc = 0;
                }
            }
        }
    }
}