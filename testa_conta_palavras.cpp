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
//Testando a leitura de um arquivo que existe no diretorio 
TEST_CASE("Teste de leitura de conteudo de arquivo ja existente") {
        const std::string nome_arquivo = "exemplo.txt";
        std::string conteudo = ler_arquivo(nome_arquivo);
         REQUIRE(conteudo == "exemplo.\n"); // O conteúdo deve ser o mesmo
}
//Testando a funcao para ler um arquivo criado pelo proprio programa 
TEST_CASE("Teste de leitura de conteudo de arquivo criado do zero") { 
        //Criando um arquivo de teste com conteudo
        std::ofstream arquivo("exemplocriado.txt");
        arquivo << "Conteudo do arquivo de teste." << std::endl;
        arquivo.close();
        //Testando a função ler_arquivo
        ler_arquivo("exemplocriado.txt"); // Não deve lançar exceção
        // Verificando o conteúdo lido
        std::string conteudo = ler_arquivo("exemplocriado.txt");
        REQUIRE(conteudo == "Conteudo do arquivo de teste.\n"); // O conteúdo deve ser o mesmo
}
// Separação de palavras por espaço
TEST_CASE("Separação de palavras por espaço", "[separar_palavras]") { 
    std::wstring texto = L"Esta é uma frase de teste.";
    std::vector<std::wstring> resultado_esperado = {L"Esta", L"é", L"uma", L"frase", L"de", L"teste."};
    REQUIRE(separar_palavras(texto) == resultado_esperado);
}

// Separação de palavras por quebra de linha
TEST_CASE("Separação de palavras por quebra de linha", "[separar_palavras]") { 
    std::wstring texto = L"Esta é uma\nfrase de teste.";
    std::vector<std::wstring> resultado_esperado = {L"Esta", L"é", L"uma", L"frase", L"de", L"teste."};
    REQUIRE(separar_palavras(texto) == resultado_esperado);
}

// Separação de palavras com múltiplos espaços
TEST_CASE("Separação de palavras com múltiplos espaços", "[separar_palavras]") { 
    std::wstring texto = L"Esta  é   uma    frase    de        teste.";
    std::vector<std::wstring> resultado_esperado = {L"Esta", L"é", L"uma", L"frase", L"de", L"teste."};
    REQUIRE(separar_palavras(texto) == resultado_esperado);
}

// Separação de palavras com espaços e quebras de linha
TEST_CASE("Separação de palavras com espaços e quebras de linha", "[separar_palavras]") { 
    std::wstring texto = L"Esta            é uma\nfrase de teste.";
    std::vector<std::wstring> resultado_esperado = {L"Esta", L"é", L"uma", L"frase", L"de", L"teste."};
    REQUIRE(separar_palavras(texto) == resultado_esperado);
}

// Separação de palavras em texto vazio
TEST_CASE("Separação de palavras em texto vazio", "[separar_palavras]") { 
    std::wstring texto = L"";
    std::vector<std::wstring> resultado_esperado = {};
    REQUIRE(separar_palavras(texto) == resultado_esperado);
}
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
//Contagem de palavras em texto vazio
TEST_CASE("Contagem de palavras em texto vazio", "[contar_palavras]") {
    std::wstring texto = L"";
    std::map<std::wstring, int> resultado_esperado = {};
   REQUIRE(contar_palavras(texto) == resultado_esperado);
}
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

TEST_CASE("Ordenar palavras - entrada vazia", "[ordenar_palavras]") {
    std::map<std::wstring, int> contagem;
    std::vector<std::wstring> resultado = ordenar_palavras(contagem);
    REQUIRE(resultado.empty());
}
TEST_CASE("Testa funções de contagem e ordenação de palavras com leitura de arquivo existente e case-insensitive") {
    std::locale::global(std::locale("en_US.UTF-8"));

    const std::string nome_arquivo = "arquivo.txt";

    SECTION("Leitura e processamento de um arquivo simples") {
        // Configurar a saída para capturar std::wcout
        std::wstringstream saida_capturada;
        std::wstreambuf* cout_buffer_original = std::wcout.rdbuf(); // Salvar buffer original
        std::wcout.rdbuf(saida_capturada.rdbuf()); // Redirecionar std::wcout para o stringstream

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
