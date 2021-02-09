#include <memory>
#include <string>
#include <iostream>
#include <vector>
using String = std::string; // using instead of typedef

class Planet
{

public:
    Planet() = default;
    explicit Planet(String name) : name_(name){};
    ~Planet() { std::cout << "Planet Destructor: " << name_ << std::endl; };

    std::string name_ = "Courusant";
    void setName(std::string name) noexcept
    {
        name_ = name;
    };
};
using UpPlanet = std::unique_ptr<Planet>;
using SpPlanet = std::shared_ptr<Planet>;
void printPlanet(std::unique_ptr<Planet> planet);
void printPlanetObserver(SpPlanet planet);

int main(void)
{

    auto planet = std::make_unique<Planet>(Planet()); // Se crea un planeta, se asigna a un unique_ptr y se elimina el planeta

    //printPlanet(planet);                             // ERROR. unique_ptr(const unique_ptr&) = delete;
    std::cout << "Llamada a la funcion printPlanetObserver. Al hacer std::move el objeto planet se invalida,"
              << "\n ownership tranferido al shared_ptr que se eliminara al salir de la funcion" << std::endl
              << std::endl;

    planet.get()->name_ = "Zefos";
    printPlanetObserver(std::move(planet)); // Ownership transfered
    //std::cout <<   planet.get()->name_  << std::endl;  // No permitido planet ya no es valido al perder ownership
    printPlanet(std::make_unique<Planet>(Planet())); //Good.

    planet = std::make_unique<Planet>(Planet());
    std::vector<UpPlanet> planets{};
    //planets.push_back(std::move(planet)); // ERROR. unique_ptr(const unique_ptr&) = delete;
    planets.push_back(std::make_unique<Planet>(Planet("Tatooine")));   // Se crea un planeta, se asigna a un unique_ptr y se elimina el planeta
    planets.push_back(std::make_unique<Planet>(Planet("Dathomir")));   // Se crea un planeta, se asigna a un unique_ptr y se elimina el planeta
    planets.push_back(std::make_unique<Planet>(Planet("Naboo")));      // Se crea un planeta, se asigna a un unique_ptr y se elimina el planeta
    planets.push_back(std::make_unique<Planet>(Planet("Endor Moon"))); // Se crea un planeta, se asigna a un unique_ptr y se elimina el planeta
    for (uint8_t i = 0U; i < planets.size(); i++)
    {
        std::cout << planets[i].get()->name_ << std::endl;
    }

    return 0;
}

void printPlanet(std::unique_ptr<Planet> planet)
{
    std::cout << "Planet Name: " << planet.get()->name_ << std::endl;
}

// Planet Observer
void printPlanetObserver(std::shared_ptr<Planet> planet)
{
    std::cout << "[Observer Function] Planet Name: " << planet.get()->name_ << std::endl;
    std::cout << "[Observer Function] Planet Count: " << planet.use_count() << std::endl;
}