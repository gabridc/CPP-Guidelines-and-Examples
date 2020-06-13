#ifndef AMISTAD_H
#define AMISTAD_H

#include "Clases.hpp"
#include <iostream>
#include <vector>

class GestorClientes
{


public:
    void darAlta(const Cliente& cliente);
    Cliente* buscarPorNif(const std::string &nif);

private:
    std::vector<Cliente> clientes;  


};

#endif