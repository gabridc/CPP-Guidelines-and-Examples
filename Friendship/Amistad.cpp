#include "Amistad.hpp"

void GestorClientes::darAlta(const Cliente &cliente)
{
    
    //Al ser const el parametro puedo ver cualquier funcion definida como const
    //en la clase cliente (getNombre)
    std::cout << cliente.getNombre() << std::endl;

    //Para acceder a otros metodos o atributos no constantes en la clase cliente
    //se puede usar 'Amistad'
    cliente.apellidos;
    cliente.mostarCliente();


    clientes.push_back(cliente);
}

Cliente *GestorClientes::buscarPorNif(const std::string &nif)
{
    Cliente *cliente = new Cliente();

    for (int i = 0; i < clientes.size(); i++)
    {
        if(clientes[i].nif == nif)
        {
            //No llamo al constructor copia porque el objeto destio ya ha sido creado
            std::cout << "buscarPorNif" << std::endl;
            *cliente = clientes[i];
        }
    }

    return cliente;
}