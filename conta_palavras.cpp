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
    return conteudo.str(); // Retorna o conteúdo do arquivo como string
}
/*
std::vector<std::string> separar_palavras(const std::string& texto) {
    std::vector<std::string> palavras;
    std::istringstream stream(texto);
    std::string palavra;
    while (stream >> palavra) {
        palavras.push_back(palavra);
    }
    return palavras;
}*/
std::vector<std::wstring> separar_palavras(const std::wstring& texto) {
    std::vector<std::wstring> palavras;
    std::wstring palavra;
    std::wstringstream stream(texto);
    
    while (stream >> palavra) {
        palavras.push_back(palavra);
    }
    
    return palavras;
}
std::map<std::string, int> contar_palavras(const std::string& texto) {
    std::map<std::string, int> contagem;
    std::istringstream stream(texto);
    std::string palavra;
    while (stream >> palavra) {
        contagem[palavra]++;
    }
    return contagem;
}
