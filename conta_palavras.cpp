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
#include <locale>
#include <codecvt>
#include "catch.hpp"
void abrir_arquivo(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        throw std::ios_base::failure("Nao foi possivel abrir o arquivo.");
    }
}
std::string ler_arquivo(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        throw std::ios_base::failure("Não foi possível abrir o arquivo.");
    }
    std::stringstream conteudo;
    conteudo << arquivo.rdbuf(); // Lê todo o conteúdo do arquivo
    return conteudo.str(); // Retorna o conteúdo do arquivo como string
}
std::vector<std::wstring> separar_palavras(const std::wstring& texto) {
    std::vector<std::wstring> palavras;
    std::wstring palavra;
    std::wstringstream stream(texto);
    
    while (stream >> palavra) {
        palavras.push_back(palavra);
    }
    
    return palavras;
}
std::map<std::wstring, int> contar_palavras(const std::wstring& texto) {
    std::map<std::wstring, int> contagem;
    std::wstringstream stream(texto);
    std::wstring palavra;
    while (stream >> palavra) {
        contagem[palavra]++;
    }
    return contagem;
}
std::vector<std::wstring> ordenar_palavras(const std::map<std::wstring, int>& contagem) {
    std::vector<std::wstring> palavras;
    for (const auto& par : contagem) {
        palavras.push_back(par.first);
    }
    std::sort(palavras.begin(), palavras.end());
    return palavras;
}
