#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
using namespace std;

class Ding {
public:
    unsigned int n;
    double x, y, z;
    double v_x, v_y, v_z;

    Ding(unsigned int set_n = 0, double set_x = 0.0, double set_y = 0.0, double set_z = 0.0,
         double set_v_x = 0.0, double set_v_y = 0.0, double set_v_z = 0.0) :
         n{set_n}, x{set_x}, y{set_y}, z{set_z}, v_x{set_v_x}, v_y{set_v_y}, v_z{set_v_z} {}

    void Gehe_Zeitschritt(double dt, double max_x, double max_y, double max_z, double gamma);
};

inline void Ding::Gehe_Zeitschritt(double dt, double max_x, double max_y, double max_z, double gamma) {
    x += v_x * dt;
    y += v_y * dt;

    if (x < 0) x += max_x;
    if (x >= max_x) x -= max_x;
    if (y < 0) y += max_y;
    if (y >= max_y) y -= max_y;

    v_x *= (1.0 - gamma * dt);
    v_y *= (1.0 - gamma * dt);
}

int main() {
    double kiste_x = 40.0;
    double kiste_y = 40.0;
    unsigned int Anz_Teilchen = 70;

    double t;
    double dt = 0.05;
    unsigned int Anz_tSchritte = 500;
    double gamma = 0.1;  // Reibungskoeffizient

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> pos_dist(0.0, 40.0);
    uniform_real_distribution<> vel_dist(-5.0, 5.0);

    vector<Ding> Kiste_Teilchen;

    for (unsigned int n = 0; n < Anz_Teilchen; ++n) {
        Kiste_Teilchen.push_back(Ding{n, pos_dist(gen), pos_dist(gen), 0.0, vel_dist(gen), vel_dist(gen), 0.0});
    }

    cout << "t";
    for (unsigned int n = 0; n < Anz_Teilchen; ++n) {
        cout << ",x" << n << ",y" << n;
    }
    cout << endl;

    for (unsigned int i = 0; i < Anz_tSchritte; ++i) {
        t = i * dt;
        cout << fixed << setprecision(5) << t;

        for (auto& teilchen : Kiste_Teilchen) {
            cout << "," << teilchen.x << "," << teilchen.y;
            teilchen.Gehe_Zeitschritt(dt, kiste_x, kiste_y, 0.0, gamma);
        }

        cout << endl;
    }

    return 0;
}
