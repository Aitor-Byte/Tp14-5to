#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Vehiculo {
protected:
    double velocidad;

public:
    explicit Vehiculo(double velocidadInicial = 0.0)
        : velocidad(max(0.0, velocidadInicial)) {}

    virtual void acelerar() {
        velocidad += 10.0;
        cout << "Vehiculo acelerando. Velocidad actual: " << velocidad << " km/h\n";
    }

    virtual ~Vehiculo() = default;
};

class Coche : public Vehiculo {
public:
    explicit Coche(double velocidadInicial = 0.0) : Vehiculo(velocidadInicial) {}

    void acelerar() override {
        velocidad += 20.0;
        cout << "Coche acelerando con marcha suave. Velocidad actual: " << velocidad << " km/h\n";
    }
};

class Moto : public Vehiculo {
public:
    explicit Moto(double velocidadInicial = 0.0) : Vehiculo(velocidadInicial) {}

    void acelerar() override {
        velocidad += 30.0;
        cout << "Moto acelerando con respuesta rapida. Velocidad actual: " << velocidad << " km/h\n";
    }
};

int main() {
    Coche coche(40.0);
    Moto moto(50.0);

    vector<Vehiculo*> vehiculos = {&coche, &moto};

    for (Vehiculo* v : vehiculos) {
        v->acelerar();
    }

    return 0;
}
