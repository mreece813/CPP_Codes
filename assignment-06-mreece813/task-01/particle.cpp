#include <cmath>

#include "particle.h"

particle::particle(double x, double y):
    position({x, y})
{}


void particle::compute_acceleration(const particle &o)
{
    double dx = o.position[0] - position[0];
    double dy = o.position[1] - position[1];
    compute_acceleration(dx, dy, o.mass);
}

void particle::compute_acceleration(double dx, double dy, double omass)
{
    double r = std::hypot(dx, dy);
    double f = G * mass * omass / (r * r);
    double t = std::atan2(dy, dx);

    acceleration[0] += f * std::cos(t) / mass;
    acceleration[1] += f * std::sin(t) / mass;
}

void particle::update(double dt)
{
    position[0] += velocity[0] * dt + 0.5 * acceleration[0] * dt * dt;
    position[1] += velocity[1] * dt + 0.5 * acceleration[1] * dt * dt;
    velocity[0] += dt * acceleration[0];
    velocity[1] += dt * acceleration[1];
    acceleration[0] = 0.0;
    acceleration[1] = 0.0;
}