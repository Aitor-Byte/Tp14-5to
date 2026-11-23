#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Empleado {
protected:
    string nombre;
    double salarioBase;

public:
    Empleado(const string& nombre, double salarioBase)
        : nombre(nombre), salarioBase(max(0.0, salarioBase)) {}

    virtual double calcularSalario() const {
        return salarioBase;
    }

    virtual ~Empleado() = default;
};

class Gerente : public Empleado {
private:
    double bonoFijo;

public:
    Gerente(const string& nombre, double salarioBase, double bonoFijo)
        : Empleado(nombre, salarioBase), bonoFijo(max(0.0, bonoFijo)) {}

    double calcularSalario() const override {
        return salarioBase + bonoFijo;
    }
};

class Vendedor : public Empleado {
private:
    double totalVentas;
    double porcentajeComision;

public:
    Vendedor(const string& nombre, double salarioBase, double totalVentas, double porcentajeComision)
        : Empleado(nombre, salarioBase),
          totalVentas(max(0.0, totalVentas)),
          porcentajeComision(clamp(porcentajeComision, 0.0, 100.0)) {}

    double calcularSalario() const override {
        return salarioBase + (totalVentas * (porcentajeComision / 100.0));
    }
};

int main() {
    Gerente gerente("Ana", 2500.0, 800.0);
    Vendedor vendedor("Mateo", 1200.0, 15000.0, 10.0);

    vector<Empleado*> equipo = {&gerente, &vendedor};

    for (const Empleado* e : equipo) {
        cout << "Salario total: $" << e->calcularSalario() << "\n";
    }

    return 0;
}
