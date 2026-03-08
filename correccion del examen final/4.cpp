#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const double PI = 3.1416;
class Sensor {
protected:
    char id[20];
    double* pos;
public:
    Sensor(const char* id, double x, double y) {
        strcpy(this->id, id);
        pos = new double[2]{x, y};
    }
    Sensor(const Sensor& o) : Sensor(o.id, o.pos[0], o.pos[1]) {}
    virtual ~Sensor() { delete[] pos; }
    virtual double areaCobertura()             const = 0;
    virtual bool   detecta(double x, double y) const = 0;
    virtual void   imprimir()                  const = 0;
    const char* getId() const { return id; }
};
class SensorCircular : public Sensor {
    double radio;
public:
    SensorCircular(const char* id, double x, double y, double r)
        : Sensor(id, x, y), radio(r) {}
    double areaCobertura() const override { return PI * radio * radio; }
    bool detecta(double x, double y) const override {
        double dx = x - pos[0], dy = y - pos[1];
        return (dx*dx + dy*dy) <= radio*radio;
    }
    void imprimir() const override {
        cout << "[CIRCULAR]    ID:" << id
             << " pos:(" << pos[0] << "," << pos[1] << ")"
             << " radio:" << radio
             << " area:"  << areaCobertura() << endl;
    }
};
class SensorRectangular : public Sensor {
    double ancho, alto;
public:
    SensorRectangular(const char* id, double x, double y, double a, double h)
        : Sensor(id, x, y), ancho(a), alto(h) {}
    double areaCobertura() const override { return ancho * alto; }
    bool detecta(double x, double y) const override {
        return x >= pos[0]-ancho/2 && x <= pos[0]+ancho/2 &&
               y >= pos[1]-alto/2  && y <= pos[1]+alto/2;
    }
    void imprimir() const override {
        cout << "[RECTANGULAR] ID:" << id
             << " pos:(" << pos[0] << "," << pos[1] << ")"
             << " ancho:" << ancho << " alto:" << alto
             << " area:"  << areaCobertura() << endl;
    }
};
class SistemaSensores {
    Sensor** s;
    int cantidad, capacidad;
public:
    SistemaSensores() : cantidad(0), capacidad(4) { s = new Sensor*[4]; }
    ~SistemaSensores() {
        for (int i = 0; i < cantidad; i++) delete s[i];
        delete[] s;
    }
    void agregar(Sensor* nuevo) {
        if (cantidad == capacidad) {
            capacidad *= 2;
            Sensor** tmp = new Sensor*[capacidad];
            for (int i = 0; i < cantidad; i++) tmp[i] = s[i];
            delete[] s; s = tmp;
        }
        s[cantidad++] = nuevo;
        cout << "Sensor '" << nuevo->getId() << "' agregado." << endl;
    }
    void mostrar() const {
        if (!cantidad) { cout << "Sin sensores." << endl; return; }
        for (int i = 0; i < cantidad; i++) s[i]->imprimir();
    }
    double areaTotal() const {
        double t = 0;
        for (int i = 0; i < cantidad; i++) t += s[i]->areaCobertura();
        return t;
    }
    int cuantosDetectan(double x, double y) const {
        int c = 0;
        for (int i = 0; i < cantidad; i++) if (s[i]->detecta(x, y)) c++;
        return c;
    }
    Sensor* mayorCobertura() const {
        if (!cantidad) return nullptr;
        Sensor* m = s[0];
        for (int i = 1; i < cantidad; i++)
            if (s[i]->areaCobertura() > m->areaCobertura()) m = s[i];
        return m;
    }
};
int main() {
    SistemaSensores sys;
    int op;
    do {
        cout << "\n1.Circular 2.Rectangular 3.Mostrar "
             << "4.AreaTotal 5.Detectan 6.Mayor 0.Salir\nOpcion: ";
        cin >> op;
        if (op == 1) {
            char id[20]; double x, y, r;
            cout << "ID x y radio: "; cin >> id >> x >> y >> r;
            sys.agregar(new SensorCircular(id, x, y, r));
        } else if (op == 2) {
            char id[20]; double x, y, a, h;
            cout << "ID x y ancho alto: "; cin >> id >> x >> y >> a >> h;
            sys.agregar(new SensorRectangular(id, x, y, a, h));
        } else if (op == 3) {
            sys.mostrar();
        } else if (op == 4) {
            cout << "Area total: " << sys.areaTotal() << endl;
        } else if (op == 5) {
            double x, y;
            cout << "x y: "; cin >> x >> y;
            cout << "Detectan: " << sys.cuantosDetectan(x, y) << endl;
        } else if (op == 6) {
            Sensor* m = sys.mayorCobertura();
            if (m) m->imprimir();
            else cout << "Sin sensores." << endl;
        }
    } while (op != 0);
    return 0;
}