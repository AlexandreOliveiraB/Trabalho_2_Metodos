/**
*"Copyright 2025 <Alexandre>" 
*/
/**
 * \file testa_conta_palavras.cpp
 */
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_NO_POSIX_SIGNALS

#include "conta_palavras.hpp"
#include <string>
#include <fstream>
#include <map>
#include "catch.hpp"

// Testa a abertura de arquivo inexistente, tem que lancar uma excecao para esse teste passar
TEST_CASE("Arquivo inexistente") {
    REQUIRE_THROWS_AS(abrir_arquivo("nao.txt"), const std::ios_base::failure&);
}
// Testa a abertura de arquivo existente
TEST_CASE("Arquivo existente deve abrir com sucesso") {
    REQUIRE_NOTHROW(abrir_arquivo("exemplo.txt"));
}
// Testa a abertura de um arquivo vazio 
TEST_CASE("Arquivo vazio deve abrir com sucesso") {
    REQUIRE_NOTHROW(abrir_arquivo("arquivo_vazio.txt"));
}
// Testando a leitura de um arquivo que não existe 
TEST_CASE("Leitura de Arquivo inexistente") {
    REQUIRE_THROWS_AS(ler_arquivo("nao.txt"), const std::ios_base::failure&);
}
//Testando a funcao para ler um arquivo qualquer 
TEST_CASE("Teste da funcao de ler o conteudo de um arquivo") {
    REQUIRE_NOTHROW(ler_arquivo("exemploqualquer.txt"));
}
