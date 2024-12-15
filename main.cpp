#include <iostream>
// #include <SFML/Graphics.hpp>
#include "Gerenciadores/Gerenciador_Logs.hpp"
#include "include/Jogo.h"
using namespace std;

int main(int argc, char* argv[])
{
        // Define o nível padrão como INFO
    GerenciadorLog::NivelLog nivel = GerenciadorLog::INFO;

    // Verifica se um argumento foi passado
    if (argc > 1) {
        std::string argumento = argv[1];
        
        // Mapeia os argumentos para os níveis de log
        if (argumento == "DEBUG" || argumento == "d") {
            nivel = GerenciadorLog::DEBUG;
        } else if (argumento == "INFO" || argumento == "i") {
            nivel = GerenciadorLog::INFO;
        } else if (argumento == "WARN" || argumento == "w") {
            nivel = GerenciadorLog::WARN;
        } else if (argumento == "ERROR" || argumento == "e") {
            nivel = GerenciadorLog::ERROR;
        } else {
            std::cerr << "Nível de log inválido! Usando INFO como padrão." << std::endl;
        }
    }

    // Configura o gerenciador de log com o nível especificado
    GerenciadorLog* logger = GerenciadorLog::getInstancia();
    logger->setNivel(nivel);

    // Testes de logger
    logger->info("Iniciando Jogo.");
    Jogo jogo;
    jogo.exec();
    return 0;
}
