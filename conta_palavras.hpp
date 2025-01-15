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

void abrir_arquivo(const std::string& nome_arquivo);
std::string ler_arquivo(const std::string& nome_arquivo);
//std::vector<std::string> separar_palavras(const std::string& texto);
std::vector<std::wstring> separar_palavras(const std::wstring& texto);
std::map<std::string, int> contar_palavras(const std::string& texto);
#endif  // CONTA_PALAVRAS_HPP_
