#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class GerenciadorLog {
public:
    // Enum para os níveis de log
    enum NivelLog {
        DEBUG = 0,  // Menor prioridade (logar tudo)
        INFO = 1,   // Logar informações gerais
        WARN = 2,   // Logar avisos e erros
        ERROR = 3   // Maior prioridade (apenas erros)
    };

private:
    static GerenciadorLog* instancia; // Singleton
    std::ofstream arquivoLog;        // Arquivo de log
    NivelLog nivelAtual;             // Nível atual de log

    // Construtor privado
    GerenciadorLog(NivelLog nivel = DEBUG)
        : nivelAtual(nivel) {
        arquivoLog.open("log.txt", std::ios::out | std::ios::app); // Abre o arquivo de log
        if (!arquivoLog.is_open()) {
            std::cerr << "Erro ao abrir o arquivo de log!" << std::endl;
        }
    }

    // Impede cópia ou atribuição
    GerenciadorLog(const GerenciadorLog&) = delete;
    GerenciadorLog& operator=(const GerenciadorLog&) = delete;

    // Converte o nível de log em string
    std::string nivelParaString(NivelLog nivel) const {
        static std::map<NivelLog, std::string> niveis = {
            {DEBUG, "DEBUG"},
            {INFO, "INFO"},
            {WARN, "WARN"},
            {ERROR, "ERROR"}
        };
        return niveis[nivel];
    }

public:
    // Destrutor
    ~GerenciadorLog() {
        if (arquivoLog.is_open()) {
            arquivoLog.close();
        }
    }

    // Acesso à instância única
    static GerenciadorLog* getInstancia(NivelLog nivel = DEBUG) {
        if (instancia == nullptr) {
            instancia = new GerenciadorLog(nivel);
        }
        return instancia;
    }

    // Configura o nível atual de log
    void setNivel(NivelLog nivel) {
        nivelAtual = nivel;
    }

    // Registra uma mensagem no log
    void escrever(NivelLog nivel, const std::string& mensagem) {
        if (nivel >= nivelAtual) { // Apenas loga mensagens com nível maior ou igual ao atual
            if (arquivoLog.is_open()) {
                arquivoLog << "[" << nivelParaString(nivel) << "] " << mensagem << std::endl;
            } else {
                std::cerr << "Erro: arquivo de log não está aberto!" << std::endl;
            }
        }
    }

    // Método para registrar apenas mensagens de erro diretamente
    void erro(const std::string& mensagem) {
        escrever(ERROR, mensagem);
    }

    // Método para registrar avisos diretamente
    void aviso(const std::string& mensagem) {
        escrever(WARN, mensagem);
    }

    // Método para registrar informações diretamente
    void info(const std::string& mensagem) {
        escrever(INFO, mensagem);
    }

    // Método para registrar depurações diretamente
    void debug(const std::string& mensagem) {
        escrever(DEBUG, mensagem);
    }
};

// Inicialização do Singleton
GerenciadorLog* GerenciadorLog::instancia = nullptr;