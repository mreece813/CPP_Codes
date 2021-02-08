#include<cmath>
#include<random>
#include<vector>
#include<ruc-sci-comp/animate.hpp>
#include "particle.h"

using namespace std;

int main()
{
    constexpr int N = 250;
    vector<particle> particles;
    particles.reserve(N);
    mt19937_64 eng(1337);
    uniform_real_distribution<double> dis(-500.0, 500.0);
    particles.emplace_back(0.0, 0.0);
    particles.back().mass = 5.0e13;

    for (int i = 0; i < N - 1; i++)
    {
        particles.emplace_back(dis(eng), dis(eng));
    }

    vector<vector<double>> all_data_x;
    vector<vector<double>> all_data_y;
    double time = 0.0;
    double dt = 0.2;

    while (time < 100.0)
    {
        for (auto &p1 : particles)
        {
            for (auto &p2 :particles)
            {
                if (&p1 == &p2)
                {
                    continue;
                }
                p1.compute_acceleration(p2);
            }
        }
        all_data_x.emplace_back();
        all_data_y.emplace_back();
        for (auto &p : particles)
        {
            p.update(dt);
            all_data_x.back().push_back(p.position[0]);
            all_data_y.back().push_back(p.position[1]);
        }
        time += dt;
    }
    animate(all_data_x, all_data_y, {-1000.0, 1000.0}, {-1000.0, 1000.0});


}