#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Figura {
public:
    virtual double calcularArea() const {
        return 0.0;
    }

    virtual ~Figura() = default;
};

class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(double base, double altura)
        : base(max(0.0, base)), altura(max(0.0, altura)) {}

    double calcularArea() const override {
        return base * altura;
    }
};

class Circulo : public Figura {
private:
    double radio;
    static constexpr double PI = 3.141592653589793;

public:
    explicit Circulo(double radio) : radio(max(0.0, radio)) {}

    double calcularArea() const override {
        return PI * radio * radio;
    }
};

int main() {
    Rectangulo r(5.0, 3.0);
    Circulo c(4.0);

    vector<Figura*> figuras = {&r, &c};

    for (const Figura* f : figuras) {
        cout << "Area: " << f->calcularArea() << "\n";
    }

    return 0;
}
