#include "izraz.hpp"

#include <iostream>
#include <cstdio>

double Broj::interpretacija() const{
    return _br;
}

double Promenljiva::interpretacija() const{
    auto vrednost = Promenljive.find(_ime);
    if (vrednost == Promenljive.end()) {
        std::cerr << "Nepostojeca promenljiva: " << _ime << std::endl; return 0.0;
        return 0.0;
    } else return vrednost->second;
}

double Unos::interpretacija() const{
    double x;
    std::cin >> x;
    return x;
}

double Sabiranje::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi + desni;
}

double Oduzimanje::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi - desni;
}

double Mnozenje::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi * desni;
}

double Deljenje::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi / desni;
}

double Manje::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi < desni;
}

double Vece::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi > desni;
}

double Jednako::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi == desni;
}

double Razlicito::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi != desni;
}

double LogickoI::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi && desni;
}

double LogickoIli::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi + desni;
}

double UnMinus::interpretacija() const {
	double levi = _levi->interpretacija();
	double desni = _desni->interpretacija();
	return levi * desni;
}

double Negacija::interpretacija() const {
	double operand = _i->interpretacija();
	return !operand;
}
