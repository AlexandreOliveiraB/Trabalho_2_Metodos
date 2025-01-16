/**
 * \file testa_conta_palavras.cpp
 * \brief Arquivo de testes para as funções de processamento de palavras.
 * 
 * Este arquivo contém os testes das funções do programa `conta_palavras.cpp`. Ele utiliza o framework Catch2 
 * para testar as funcionalidades como abertura de arquivos, leitura de conteúdo, separação de palavras, 
 * contagem de palavras, e ordenação das palavras.
 * 
 * \copyright 2025 Alexandre
 */

#define CATCH_CONFIG_MAIN  ///< Definindo a configuração principal do Catch2 para gerar o main.
#define CATCH_CONFIG_NO_POSIX_SIGNALS  ///< Desativa o tratamento de sinais POSIX.

#include "conta_palavras.hpp"
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include "catch.hpp"

/**
 * \brief Testa a abertura de arquivo inexistente.
 * 
 * Verifica se a função `abrir_arquivo` lança uma exceção quando o arquivo não existe.
 */
TEST_CASE("Arquivo inexistente") {
    REQUIRE_THROWS_AS(abrir_arquivo("nao.txt"), const std::ios_base::failure&);
}

/**
 * \brief Testa a abertura de arquivo existente.
 * 
 * Verifica se a função `abrir_arquivo` não lança exceções ao tentar abrir um arquivo existente.
 */
TEST_CASE("Arquivo existente deve abrir com sucesso") {
    REQUIRE_NOTHROW(abrir_arquivo("exemplo.txt"));
}

/**
 * \brief Testa a abertura de um arquivo vazio.
 * 
 * Verifica se a função `abrir_arquivo` não lança exceções ao tentar abrir um arquivo vazio.
 */
TEST_CASE("Arquivo vazio deve abrir com sucesso") {
    REQUIRE_NOTHROW(abrir_arquivo("arquivo_vazio.txt"));
}

/**
 * \brief Testa a leitura de um arquivo inexistente.
 * 
 * Verifica se a função `ler_arquivo` lança uma exceção quando o arquivo não existe.
 */
TEST_CASE("Leitura de Arquivo inexistente") {
    REQUIRE_THROWS_AS(ler_arquivo("nao.txt"), const std::ios_base::failure&);
}

/**
 * \brief Testa a leitura de um arquivo qualquer.
 * 
 * Verifica se a função `ler_arquivo` não lança exceções ao ler um arquivo existente.
 */
TEST_CASE("Teste da funcao de ler o conteudo de um arquivo") {
    REQUIRE_NOTHROW(ler_arquivo("exemploqualquer.txt"));
}

/**
 * \brief Testa a leitura de um arquivo existente no diretório.
 * 
 * Verifica se o conteúdo de um arquivo é lido corretamente.
 */
TEST_CASE("Teste de leitura de conteudo de arquivo ja existente") {
        const std::string nome_arquivo = "exemplo.txt";
        std::string conteudo = ler_arquivo(nome_arquivo);
        REQUIRE(conteudo == "exemplo.\n");  // O conteúdo deve ser o mesmo
}

/**
 * \brief Testa a leitura de um arquivo criado pelo próprio programa.
 * 
 * Testa a função `ler_arquivo` ao ler um arquivo recém-criado pelo programa.
 */
TEST_CASE("Teste de leitura de conteudo de arquivo criado do zero") {
        // Criando um arquivo de teste com conteudo
        std::ofstream arquivo("exemplocriado.txt");
        arquivo << "Conteudo do arquivo de teste." << std::endl;
        arquivo.close();
        // Testando a função ler_arquivo
        ler_arquivo("exemplocriado.txt");  // Não deve lançar exceção
        // Verificando o conteúdo lido
        std::string conteudo = ler_arquivo("exemplocriado.txt");
        REQUIRE(conteudo == "Conteudo do arquivo de teste.\n");
}

/**
 * \brief Testa a separação de palavras por espaço.
 * 
 * Verifica se a função `separar_palavras` divide corretamente o texto em palavras separadas por espaços.
 */
TEST_CASE("Separação de palavras por espaço", "[separar_palavras]") {
    std::wstring texto = L"Esta é uma frase de teste.";
    std::vector<std::wstring> resultado_esperado = {L"Esta", L"é", L"uma", L"frase", L"de", L"teste."};
    REQUIRE(separar_palavras(texto) == resultado_esperado);
}

/**
 * \brief Testa a separação de palavras por quebra de linha.
 * 
 * Verifica se a função `separar_palavras` lida corretamente com quebras de linha.
 */
TEST_CASE("Separação de palavras por quebra de linha", "[separar_palavras]") {
    std::wstring texto = L"Esta é uma\nfrase de teste.";
    std::vector<std::wstring> resultado_esperado = {L"Esta", L"é", L"uma", L"frase", L"de", L"teste."};
    REQUIRE(separar_palavras(texto) == resultado_esperado);
}

/**
 * \brief Testa a separação de palavras com múltiplos espaços.
 * 
 * Verifica se a função `separar_palavras` lida corretamente com múltiplos espaços consecutivos.
 */
TEST_CASE("Separação de palavras com múltiplos espaços", "[separar_palavras]") {
    std::wstring texto = L"Esta  é   uma    frase    de        teste.";
    std::vector<std::wstring> resultado_esperado = {L"Esta", L"é", L"uma", L"frase", L"de", L"teste."};
    REQUIRE(separar_palavras(texto) == resultado_esperado);
}

/**
 * \brief Testa a separação de palavras com espaços e quebras de linha.
 * 
 * Verifica se a função `separar_palavras` lida corretamente com espaços e quebras de linha simultaneamente.
 */
TEST_CASE("Separação de palavras com espaços e quebras de linha", "[separar_palavras]") {
    std::wstring texto = L"Esta            é uma\nfrase de teste.";
    std::vector<std::wstring> resultado_esperado = {L"Esta", L"é", L"uma", L"frase", L"de", L"teste."};
    REQUIRE(separar_palavras(texto) == resultado_esperado);
}

/**
 * \brief Testa a separação de palavras em texto vazio.
 * 
 * Verifica se a função `separar_palavras` retorna um vetor vazio quando o texto está vazio.
 */
TEST_CASE("Separação de palavras em texto vazio", "[separar_palavras]") {
    std::wstring texto = L"";
    std::vector<std::wstring> resultado_esperado = {};
    REQUIRE(separar_palavras(texto) == resultado_esperado);
}

/**
 * \brief Testa a contagem de palavras diferentes (case-insensitive).
 * 
 * Verifica se a função `contar_palavras` conta as palavras corretamente, independentemente de maiúsculas ou minúsculas.
 */
TEST_CASE("Contagem de palavras diferentes (case-insensitive)", "[contar_palavras]") {
    std::wstring texto = L"Esta é uma frase de teste. Esta é uma frase de Teste.";
    std::map<std::wstring, int> resultado_esperado = {
        {L"esta", 2},
        {L"é", 2},
        {L"uma", 2},
        {L"frase", 2},
        {L"de", 2},
        {L"teste.", 2}
    };
    REQUIRE(contar_palavras(texto) == resultado_esperado);
}

/**
 * \brief Testa a contagem de palavras em texto vazio.
 * 
 * Verifica se a função `contar_palavras` retorna um mapa vazio quando o texto está vazio.
 */
TEST_CASE("Contagem de palavras em texto vazio", "[contar_palavras]") {
    std::wstring texto = L"";
    std::map<std::wstring, int> resultado_esperado = {};
    REQUIRE(contar_palavras(texto) == resultado_esperado);
}

/**
 * \brief Testa a ordenação de palavras.
 * 
 * Verifica se a função `ordenar_palavras` ordena corretamente um conjunto de palavras.
 */
TEST_CASE("Ordenar palavras - ordenação comum", "[ordenar_palavras]") {
    std::map<std::wstring, int> contagem = {
        {L"banana", 1},
        {L"abacaxi", 1},
        {L"laranja", 1}
    };
    std::vector<std::wstring> resultado = ordenar_palavras(contagem);
    std::vector<std::wstring> esperado = {L"abacaxi", L"banana", L"laranja"};
    REQUIRE_THAT(resultado, Catch::Matchers::Equals(esperado));
}

/**
 * \brief Testa a ordenação de palavras com entrada vazia.
 * 
 * Verifica se a função `ordenar_palavras` lida corretamente com um mapa vazio.
 */
TEST_CASE("Ordenar palavras - entrada vazia", "[ordenar_palavras]") {
    std::map<std::wstring, int> contagem;
    std::vector<std::wstring> resultado = ordenar_palavras(contagem);
    REQUIRE(resultado.empty());
}

/**
 * \brief Testa as funções de contagem e ordenação de palavras com leitura de arquivo existente.
 * 
 * Verifica se as funções de contagem e ordenação funcionam corretamente com um arquivo existente.
 */
TEST_CASE("Testa funções de contagem e ordenação de palavras com leitura de arquivo existente e case-insensitive") {
    std::locale::global(std::locale("en_US.UTF-8"));

    const std::string nome_arquivo = "arquivo.txt";

    SECTION("Leitura e processamento de um arquivo simples") {
        // Configurar a saída para capturar std::wcout
        std::wstringstream saida_capturada;
        std::wstreambuf* cout_buffer_original = std::wcout.rdbuf();
        std::wcout.rdbuf(saida_capturada.rdbuf());

        // Processar o arquivo
        processar_arquivo(nome_arquivo);

        // Restaurar o buffer original de std::wcout
        std::wcout.rdbuf(cout_buffer_original);

        // Verificar saída capturada
        std::wstring resultado_esperado =
            L"é: 1\n"
            L"este: 1\n"
            L"o: 1\n"
            L"que: 1\n"
            L"será: 1\n"
            L"texto: 2\n"
            L"utilizado: 1\n";

        REQUIRE(saida_capturada.str() == resultado_esperado);
    }
}
