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
