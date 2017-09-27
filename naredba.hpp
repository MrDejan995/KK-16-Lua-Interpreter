#ifndef NAREDBA_HPP
#define NAREDBA_HPP

#include <string>
#include <map>
#include <vector>
#include "izraz.hpp"

extern std::map<std::string, double> Promenljive;

class Naredba {
public:
    virtual ~Naredba() {}
    virtual void interpretacija() = 0;
};

class Dodela : public Naredba {
public:
    Dodela(std::string imePromenljive, Izraz* izraz)
        : _ime(imePromenljive), _izraz(izraz)
    {}
    ~Dodela() {
        delete _izraz;
    }
    void interpretacija();

private:
    std::string _ime;
    Izraz* _izraz;
};

class Blok : public Naredba {
public:
    Blok(std::vector<Naredba*> naredbe)
        : _naredbe(naredbe)
    {}
    ~Blok() {
        for (auto & n : _naredbe)
            delete n;
    }
    void interpretacija();

private:
    std::vector<Naredba*> _naredbe;
};

class Ispis : public Naredba {
public:
    Ispis(Izraz* i)
        : _izraz(i)
    {}
    ~Ispis() {
        delete _izraz;
    }
    void interpretacija();

private:
    Izraz* _izraz;
};

class NaredbaIzraz : public Naredba {
public:
    NaredbaIzraz(Izraz* i)
        : _i(i)
    {}
    ~NaredbaIzraz() {
        delete _i;
    }
    void interpretacija();

private:
    Izraz* _i;
};

class IfThenElse : public Naredba {
public:
    IfThenElse(Izraz* uslov, Blok* thenNaredba, Blok* elseNaredba)
        : _uslov(uslov), _thenNaredba(thenNaredba), _elseNaredba(elseNaredba)
    {}
    ~IfThenElse() {
        delete _uslov;
        delete _thenNaredba;
        delete _elseNaredba;
    }
    void interpretacija();

private:
    Izraz* _uslov;
    Blok* _thenNaredba;
    Blok* _elseNaredba;
};

class While : public Naredba {
public:
    While(Izraz* uslov, Blok* telo)
        : _uslov(uslov), _telo(telo)
    {}
    ~While() {
        delete _uslov;
        delete _telo;
    }
    void interpretacija();

private:
    Izraz* _uslov;
    Blok* _telo;
};

class PraznaNaredba : public Naredba {
public:
	void interpretacija();
};
#endif 
