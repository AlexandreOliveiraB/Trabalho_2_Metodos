/**
*"Copyright 2025 <Alexandre>" 
*/
/**
 * \file  conta_palavras.cpp
 */
#include "conta_palavras.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include "catch.hpp"
void abrir_arquivo(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        throw std::ios_base::failure("Nao foi possivel abrir o arquivo.");
    }
}

std::string ler_arquivo(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    
    // Se não conseguir abrir o arquivo, lança uma exceção
    if (!arquivo.is_open()) {
        throw std::ios_base::failure("Não foi possível abrir o arquivo.");
    }

    std::stringstream conteudo;
    conteudo << arquivo.rdbuf(); // Lê todo o conteúdo do arquivo

    return "Conteudo incorreto"; // Retorna o conteúdo do arquivo como string
}
