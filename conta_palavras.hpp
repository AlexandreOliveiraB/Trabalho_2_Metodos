/**
 * \file conta_palavras.hpp
 * \brief Definições das funções para contar e ordenar palavras de um arquivo.
 * 
 * Este arquivo contém as declarações das funções que permitem abrir, ler e processar um arquivo de 
 * texto, contar as palavras presentes no arquivo e ordená-las por ordem alfabética, desconsiderando acentos.
 * 
 * \copyright 2025 Alexandre
 */

#ifndef CONTA_PALAVRAS_HPP_
#define CONTA_PALAVRAS_HPP_

#include <string>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <locale>
#include <codecvt>

/**
 * \brief Função para abrir um arquivo.
 * 
 * Tenta abrir o arquivo especificado pelo nome. Caso o arquivo não possa ser aberto, uma exceção 
 * será lançada.
 * 
 * \param nome_arquivo O nome do arquivo a ser aberto.
 * \throws std::ios_base::failure Se o arquivo não puder ser aberto.
 */
void abrir_arquivo(const std::string& nome_arquivo);

/**
 * \brief Função para ler o conteúdo de um arquivo.
 * 
 * Lê todo o conteúdo de um arquivo e retorna como uma string.
 * 
 * \param nome_arquivo O nome do arquivo a ser lido.
 * \return Uma string contendo o conteúdo do arquivo.
 * \throws std::ios_base::failure Se o arquivo não puder ser aberto.
 */
std::string ler_arquivo(const std::string& nome_arquivo);

/**
 * \brief Função para separar o texto em palavras.
 * 
 * Divide o texto em palavras usando espaços como delimitadores e retorna um vetor com as palavras.
 * 
 * \param texto O texto a ser separado em palavras.
 * \return Um vetor de palavras (strings) extraídas do texto.
 */
std::vector<std::wstring> separar_palavras(const std::wstring& texto);

/**
 * \brief Função para contar as ocorrências de cada palavra no texto.
 * 
 * Conta as ocorrências de cada palavra no texto, convertendo-as para minúsculas e armazenando 
 * as contagens em um mapa.
 * 
 * \param texto O texto onde as palavras serão contadas.
 * \return Um mapa contendo as palavras e suas respectivas contagens.
 */
std::map<std::wstring, int> contar_palavras(const std::wstring& texto);

/**
 * \brief Função para ordenar as palavras por ordem alfabética, desconsiderando os acentos.
 * 
 * Ordena as palavras de acordo com suas versões sem acento, mas preservando as palavras originais.
 * 
 * \param contagem O mapa contendo as palavras e suas contagens.
 * \return Um vetor com as palavras ordenadas sem considerar acentos.
 */
std::vector<std::wstring> ordenar_palavras(const std::map<std::wstring, int>& contagem);

/**
 * \brief Função para remover os acentos de uma palavra.
 * 
 * Remove os acentos das letras de uma palavra, substituindo por suas versões sem acento.
 * 
 * \param palavra A palavra da qual os acentos serão removidos.
 * \return A palavra sem acento.
 */
std::wstring remover_acentos(const std::wstring& palavra);

/**
 * \brief Função para processar o conteúdo de um arquivo e exibir a contagem das palavras ordenadas.
 * 
 * Abre o arquivo, lê seu conteúdo, conta as palavras, ordena-as e exibe as palavras ordenadas 
 * com suas respectivas contagens.
 * 
 * \param nome_arquivo O nome do arquivo a ser processado.
 */
void processar_arquivo(const std::string& nome_arquivo);

#endif  // CONTA_PALAVRAS_HPP_
