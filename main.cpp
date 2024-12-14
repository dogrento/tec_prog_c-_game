#include <iostream>
// #include <SFML/Graphics.hpp>
#include "Gerenciador_Logs.hpp"
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
        if (argumento == "DEBUG") {
            nivel = GerenciadorLog::DEBUG;
        } else if (argumento == "INFO") {
            nivel = GerenciadorLog::INFO;
        } else if (argumento == "WARN") {
            nivel = GerenciadorLog::WARN;
        } else if (argumento == "ERROR") {
            nivel = GerenciadorLog::ERROR;
        } else {
            std::cerr << "Nível de log inválido! Usando INFO como padrão." << std::endl;
        }
    }

    // Configura o gerenciador de log com o nível especificado
    GerenciadorLog* log = GerenciadorLog::getInstancia();
    log->setNivel(nivel);

    // Testes de log
    log->debug("Mensagem de depuração (DEBUG).");
    log->info("Mensagem informativa (INFO).");
    log->aviso("Mensagem de aviso (WARN).");
    log->erro("Mensagem de erro (ERROR).");
    Jogo jogo;
    jogo.exec();
    return 0;
}
