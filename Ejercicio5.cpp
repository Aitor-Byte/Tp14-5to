#include <iostream>
#include <vector>

using namespace std;

class InstrumentoMusical {
public:
    virtual void tocar() const {
        cout << "Tocando un instrumento musical.\n";
    }

    virtual ~InstrumentoMusical() = default;
};

class Piano : public InstrumentoMusical {
public:
    void tocar() const override {
        cout << "Presionando teclas del piano: plin-plon armonico.\n";
    }
};

class Guitarra : public InstrumentoMusical {
public:
    void tocar() const override {
        cout << "Rasgueando las cuerdas de la guitarra: rasg-rasg.\n";
    }
};

class Flauta : public InstrumentoMusical {
public:
    void tocar() const override {
        cout << "Soplando la boquilla de la flauta: fliu-fliu.\n";
    }
};

int main() {
    Piano piano;
    Guitarra guitarra;
    Flauta flauta;

    vector<InstrumentoMusical*> orquesta = {&piano, &guitarra, &flauta};

    for (const InstrumentoMusical* inst : orquesta) {
        inst->tocar();
    }

    return 0;
}
