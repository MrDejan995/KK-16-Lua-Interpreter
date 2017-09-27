#ifndef IZRAZ_HPP
#define IZRAZ_HPP

#include <string>
#include <map>

#define JEDNAKOJEDNAKO 300
#define NIJEJEDNAKO 301

extern std::map<std::string, double> Promenljive;

class Izraz {
public:
	virtual double interpretacija() const = 0;
	virtual ~Izraz() {}
};

class Broj : public Izraz {
public:
    Broj(double br)
        : _br(br)
    {}
    double interpretacija() const;

private:
    double _br;
};

class Promenljiva : public Izraz {
public:
    Promenljiva(std::string ime)
        : _ime(ime)
    {}
    double interpretacija() const;

private:
    std::string _ime;
};

class Unos : public Izraz {
public:
    Unos () {}
    double interpretacija() const;
};

class BinarniOperator : public Izraz {
public:
    BinarniOperator(Izraz* levi, Izraz* desni)
        :_levi(levi), _desni(desni)
    {}
    ~BinarniOperator() {
        delete _levi;
        delete _desni;
    }

protected:
    Izraz* _levi;
    Izraz* _desni;
};

class Sabiranje : public BinarniOperator {
public:
	Sabiranje(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class Oduzimanje : public BinarniOperator {
public:
	Oduzimanje(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class Mnozenje : public BinarniOperator {
public:
	Mnozenje(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class Deljenje : public BinarniOperator {
public:
	Deljenje(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class Vece : public BinarniOperator {
public:
	Vece(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class Manje : public BinarniOperator {
public:
	Manje(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class Jednako : public BinarniOperator {
public:
	Jednako(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class Razlicito : public BinarniOperator {
public:
	Razlicito(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class UnMinus : public BinarniOperator {
public:
	UnMinus(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class LogickoI : public BinarniOperator {
public:
	LogickoI(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class LogickoIli : public BinarniOperator {
public:
	LogickoIli(Izraz* levi, Izraz* desni)
	: BinarniOperator(levi, desni)
	{}
	double interpretacija() const;
};

class Negacija : public Izraz {
public:
	Negacija(Izraz* i)
	: _i(i)
	{}
	~Negacija() {
		delete _i;
	}
	double interpretacija() const;
private:
	Izraz* _i;
};

class StrLength : public Izraz {
public:
	StrLength(std::string str)
	: _str(str)
	{}
	double interpretacija() const;
private:
	std::string _str;
};
#endif 
