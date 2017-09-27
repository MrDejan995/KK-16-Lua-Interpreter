#include "naredba.hpp"
#include <iostream>

void Dodela::interpretacija() {
    Promenljive[_ime] = _izraz->interpretacija();
}

void Ispis::interpretacija() {
    std::cout << _izraz->interpretacija() << std::endl;
}

void Blok::interpretacija() {
    for (auto & n : _naredbe)
        n->interpretacija();
}

void NaredbaIzraz::interpretacija() {
    std::cout << _i->interpretacija() << std::endl;
}

void IfThenElse::interpretacija() {
    double uslov = _uslov->interpretacija();
    if (uslov)
        _thenNaredba->interpretacija();
    else if (_elseNaredba != nullptr)
        _elseNaredba->interpretacija();
}

void While::interpretacija() {
    double uslov = _uslov->interpretacija();
    while (uslov) {
        _telo->interpretacija();
        uslov = _uslov->interpretacija();
    }
}

void PraznaNaredba::interpretacija() {
	
}