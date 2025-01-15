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
#include <cwctype>
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
    // Vetor auxiliar para armazenar pares (sem acento, original)
    std::vector<std::pair<std::wstring, std::wstring>> palavras_aux;

    // Preencher o vetor auxiliar com versões sem acentos e originais
    for (const auto& par : contagem) {
        palavras_aux.emplace_back(remover_acentos(par.first), par.first);
    }

    // Ordenar com base na versão sem acentos
    std::sort(palavras_aux.begin(), palavras_aux.end());

    // Restaurar a lista ordenada com as palavras originais
    std::vector<std::wstring> palavras_ordenadas;
    for (const auto& par : palavras_aux) {
        palavras_ordenadas.push_back(par.second);
    }

    return palavras_ordenadas;
}
std::wstring remover_acentos(const std::wstring& palavra) {
    std::wstring palavra_sem_acento;
    for (wchar_t c : palavra) {
        switch (c) {
            case L'à': case L'á': case L'â': case L'ã': case L'ä': c = L'a'; break;
            case L'è': case L'é': case L'ê': case L'ë': c = L'e'; break;
            case L'ì': case L'í': case L'î': case L'ï': c = L'i'; break;
            case L'ò': case L'ó': case L'ô': case L'õ': case L'ö': c = L'o'; break;
            case L'ù': case L'ú': case L'û': case L'ü': c = L'u'; break;
            case L'ç': c = L'c'; break;
            case L'À': case L'Á': case L'Â': case L'Ã': case L'Ä': c = L'A'; break;
            case L'È': case L'É': case L'Ê': case L'Ë': c = L'E'; break;
            case L'Ì': case L'Í': case L'Î': case L'Ï': c = L'I'; break;
            case L'Ò': case L'Ó': case L'Ô': case L'Õ': case L'Ö': c = L'O'; break;
            case L'Ù': case L'Ú': case L'Û': case L'Ü': c = L'U'; break;
            case L'Ç': c = L'C'; break;
        }
        palavra_sem_acento += c;
    }
    return palavra_sem_acento;
}
