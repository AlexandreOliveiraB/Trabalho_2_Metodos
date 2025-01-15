/**
*"Copyright 2025 <Alexandre>" 
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

void abrir_arquivo(const std::string& nome_arquivo);
std::string ler_arquivo(const std::string& nome_arquivo);
std::vector<std::wstring> separar_palavras(const std::wstring& texto);
std::map<std::wstring, int> contar_palavras(const std::wstring& texto);
std::vector<std::wstring> ordenar_palavras(const std::map<std::wstring, int>& contagem);
#endif  // CONTA_PALAVRAS_HPP_
