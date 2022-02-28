#include "Organizm.h"

bool* Organizm::Mozliwosci() {
	bool* mozliwosci = new bool[8];
	for (int i = 0; i < 8; i++) {
		mozliwosci[i] = true;
	}
	if (this->x - 1 < 0) {
		mozliwosci[0] = false;
		mozliwosci[7] = false;
		mozliwosci[6] = false;
	}
	else if (this->x + 1 == this->swiat->GetN()) {
		mozliwosci[2] = false;
		mozliwosci[3] = false;
		mozliwosci[4] = false;
	}
	if (this->y - 1 < 0) {
		mozliwosci[4] = false;
		mozliwosci[5] = false;
		mozliwosci[6] = false;
	}
	else if (this->y + 1 == this->swiat->GetN()) {
		mozliwosci[0] = false;
		mozliwosci[1] = false;
		mozliwosci[2] = false;
	}
	return mozliwosci;
}

int Organizm::GetDojrzalosc() {
	return dojrzalosc;
}

bool Organizm::GetMoc() {
	return moc;
}

int Organizm::GetOdliczanie() {
	return odliczanie;
}

void Organizm::SetMoc(bool nowaMoc) {
	moc = nowaMoc;
}

void Organizm::SetOdliczanie( int noweOdliczanie) {
	odliczanie = noweOdliczanie;
}



int Organizm::GetX() {
	return x;
}

int Organizm::GetY() {
	return y;
}

Organizm::Organizm(Swiat* swiat, int x, int y) : swiat(swiat) , x(x), y(y), pre(nullptr), nxt(nullptr){
	inicjatywa = 0;
	dojrzalosc = 0;
	sila = 0;
	moc = false;
	odliczanie = 0;
}

Organizm::Organizm(Swiat* swiat, int x, int y, Organizm* pre) : swiat(swiat), x(x), y(y), pre(pre), nxt(nullptr) {
	inicjatywa = 0;
	dojrzalosc = 0;
	sila = 0;
	moc = false;
	odliczanie = 0;
}

Organizm::Organizm(Swiat* swiat, int x, int y, Organizm* pre, Organizm* nxt) : swiat(swiat), x(x), y(y), pre(pre), nxt(nxt) {
	inicjatywa = 0;
	dojrzalosc = 0;
	sila = 0;
	moc = false;
	odliczanie = 0;
}

Organizm* Organizm::GetPre() {
	return pre;
}

Organizm* Organizm::GetNxt() {
	return nxt;
}

void Organizm::SetX(int newX) {
	x = newX;
}

void Organizm::SetY(int newY) {
	y = newY;
}

void Organizm::SetPre(Organizm* nowyPre) {
	pre = nowyPre;
}

void Organizm::SetNxt(Organizm* nowyNxt) {
	nxt = nowyNxt;
}

int Organizm::GetInicjatywa() {
	return inicjatywa;
}

void Organizm::SetInicjatywa(int nowaInicjatywa) {
	this->inicjatywa = nowaInicjatywa;
}

int Organizm::GetSila() {
	return sila;
}

void Organizm::SetSila(int nowaSila) {
	this->sila = nowaSila;
}

void Organizm::Rosnij() {
	if (dojrzalosc != 0) {
		dojrzalosc--;
	}
}

Organizm::~Organizm() {
	if (this == this->swiat->GetOrganizmy()) {
		if (this->nxt) {
			this->swiat->SetOrganizmy(this->nxt);
			this->nxt->pre = nullptr;
		}
		else {
			this->swiat->SetOrganizmy(nullptr);
		}
	}
	else {
		if (pre) {
			pre->nxt = nxt;
		}
		if (nxt) {
			nxt->pre = pre;
		}
	}
}