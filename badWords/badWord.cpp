/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** badWord
*/

#include "badWord.hpp"

BadWord::BadWord() : _word("empty")
{}

BadWord::~BadWord()
{}

void BadWord::print()
{
    std::cout << _word << std::endl;
}

void BadWord::setWord(std::string word)
{
    _word = word;
}

std::string BadWord::getWord()
{
    return _word;
}