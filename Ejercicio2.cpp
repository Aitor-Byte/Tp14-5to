#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    virtual void hacerSonido() const {
        cout << "El animal emite un sonido.\n";
    }

    virtual ~Animal() = default;
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        cout << "Guau guau!\n";
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        cout << "Miau!\n";
    }
};

class Pato : public Animal {
public:
    void hacerSonido() const override {
        cout << "Cuac cuac!\n";
    }
};

int main() {
    Perro perro;
    Gato gato;
    Pato pato;

    vector<Animal*> animales = {&perro, &gato, &pato};

    for (const Animal* a : animales) {
        a->hacerSonido();
    }

    return 0;
}
