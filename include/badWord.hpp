/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-raytracer-thomas.laprie
** File description:
** badWord
*/

#pragma once

#include <iostream>

class BadWord {
    public:
        BadWord();
        ~BadWord();
        void print();
        void setWord(std::string word);
        std::string getWord();
    private:
        std::string _word;

};

