/**
*"Copyright 2025 <Alexandre>" 
*/
/**
 * \file testa_conta_palavras.cpp
 */

#include "conta_palavras.hpp"

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#include "catch.hpp"

#include <fstream>
#include <string>
#include <map>

// Testa a abertura de arquivo inexistente 
TEST_CASE("Arquivo inexistente deve falhar") {
    REQUIRE_THROWS_AS(abrir_arquivo("inexistente.txt"), const std::ios_base::failure&); //Aqui eh para falhar, ele testa se nao abre nada
}
// Testa a abertura de arquivo existente 
TEST_CASE("Arquivo existente deve abrir com sucesso") {
    REQUIRE_NOTHROW(abrir_arquivo("exemplo.txt"));  
}