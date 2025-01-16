/**
 * \file conta_palavras.cpp
 * \brief Implementação das funções para contar e ordenar palavras de um arquivo.
 * 
 * Este arquivo contém a implementação de funções para abrir, ler e processar um arquivo de texto, 
 * contar as palavras, e ordenar as palavras por ordem alfabética sem considerar acentos.
 * 
 * \copyright 2025 Alexandre
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

/**
 * \brief Função para abrir um arquivo.
 * 
 * Esta função tenta abrir o arquivo especificado pelo nome. Se o arquivo não puder ser aberto, 
 * uma exceção será lançada.
 * 
 * \param nome_arquivo O nome do arquivo a ser aberto.
 * \throws std::ios_base::failure Se o arquivo não puder ser aberto.
 */
void abrir_arquivo(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        throw std::ios_base::failure("Nao foi possivel abrir o arquivo.");
    }
}

/**
 * \brief Função para ler o conteúdo de um arquivo.
 * 
 * Esta função lê todo o conteúdo de um arquivo e retorna como uma string.
 * 
 * \param nome_arquivo O nome do arquivo a ser lido.
 * \return Uma string contendo o conteúdo do arquivo.
 * \throws std::ios_base::failure Se o arquivo não puder ser aberto.
 */
std::string ler_arquivo(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        throw std::ios_base::failure("Não foi possível abrir o arquivo.");
    }
    std::stringstream conteudo;
    conteudo << arquivo.rdbuf();  // Lê todo o conteúdo do arquivo
    return conteudo.str();  // Retorna o conteúdo do arquivo como string
}

/**
 * \brief Função para separar o texto em palavras.
 * 
 * Esta função divide o texto em palavras usando espaços como delimitadores.
 * 
 * \param texto O texto a ser separado.
 * \return Um vetor de palavras (strings) extraídas do texto.
 */
std::vector<std::wstring> separar_palavras(const std::wstring& texto) {
    std::vector<std::wstring> palavras;
    std::wstring palavra;
    std::wstringstream stream(texto);

    while (stream >> palavra) {
        palavras.push_back(palavra);
    }

    return palavras;
}

/**
 * \brief Função para contar a ocorrência de cada palavra em um texto.
 * 
 * Esta função percorre o texto, converte as palavras para minúsculas e conta as ocorrências 
 * de cada palavra, armazenando em um mapa.
 * 
 * \param texto O texto no qual as palavras serão contadas.
 * \return Um mapa onde as chaves são as palavras e os valores são suas respectivas contagens.
 */
std::map<std::wstring, int> contar_palavras(const std::wstring& texto) {
    std::map<std::wstring, int> contagem;
    std::wstringstream stream(texto);
    std::wstring palavra;
    while (stream >> palavra) {
        // Converter para minúsculas
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::towlower);
        contagem[palavra]++;
    }
    return contagem;
}

/**
 * \brief Função para ordenar as palavras por ordem alfabética sem considerar acentos.
 * 
 * Esta função ordena as palavras de acordo com a versão sem acento de cada uma, mas preserva 
 * as palavras originais.
 * 
 * \param contagem O mapa que contém as palavras e suas contagens.
 * \return Um vetor com as palavras ordenadas de acordo com a versão sem acento.
 */
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

/**
 * \brief Função para remover acentos de uma palavra.
 * 
 * Esta função remove os acentos das letras de uma palavra, substituindo por suas versões sem acento.
 * 
 * \param palavra A palavra da qual os acentos serão removidos.
 * \return A palavra sem acento.
 */
std::wstring remover_acentos(const std::wstring& palavra) {
    std::wstring palavra_sem_acento;
    for (wchar_t c : palavra) {
        switch (c) {
            case L'à': case L'á': case L'â': case L'ã': case L'ä': c = L'a'; break;
            case L'è': case L'é': case L'ê': case L'ë': c = L'e'; break;
        }
        palavra_sem_acento += c;
    }
    return palavra_sem_acento;
}

/**
 * \brief Função para processar o conteúdo de um arquivo e exibir a contagem de palavras ordenadas.
 * 
 * Esta função abre o arquivo, lê seu conteúdo, conta as palavras e as ordena. Por fim, imprime as 
 * palavras e suas respectivas contagens.
 * 
 * \param nome_arquivo O nome do arquivo a ser processado.
 */
void processar_arquivo(const std::string& nome_arquivo) {
    abrir_arquivo(nome_arquivo);

    // Ler o arquivo
    std::string conteudo_arquivo = ler_arquivo(nome_arquivo);
    std::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
    std::wstring conteudo = convert.from_bytes(conteudo_arquivo);

    // Contar palavras
    std::map<std::wstring, int> contagem = contar_palavras(conteudo);

    // Ordenar palavras
    std::vector<std::wstring> palavras_ordenadas = ordenar_palavras(contagem);

    // Imprimir resultado
    for (const auto& palavra : palavras_ordenadas) {
        std::wcout << palavra << L": " << contagem[palavra] << std::endl;
    }
}
