/**
*"Copyright 2025 <Alexandre>" 
*/
/**
 * \file  conta_palavras.cpp
 */
#include "conta_palavras.hpp"
#include "catch.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

void abrir_arquivo(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        throw std::ios_base::failure("Nao foi possivel abrir o arquivo.");
    }
}
