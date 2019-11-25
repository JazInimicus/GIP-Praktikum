#pragma once
#include <iostream>
#include <string>

void parse_gesamtausdruck(std::string& input, int& pos);
void parse_ausdruck(std::string& input, int& pos);
void parse_term(std::string& input, int& pos);
void parse_operand(std::string& input, int& pos);
void parse_number(std::string& input, int& pos);
void match(char c, std::string& input, int& pos);
bool expect(char c, std::string& input, int pos);
