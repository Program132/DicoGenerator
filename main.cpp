#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "DicoGenerator_Classes.h"
#include "DicoGenerator_bases_func.h"

int main() {
    int amount_words = 0;

    std::string selected_word;
    std::cout << "Give me a word: ";
    std::cin >> selected_word;
    std::cout << std::endl;

    std::string first_word = selected_word;
    std::string nice_word_basic_analyze = returnFirstWord(selected_word);
    std::string worst_word_basic_analyze = returnFirstWord_second(selected_word);
    amount_words += 1;
    std::cout << amount_words << ":" << first_word << std::endl;
    amount_words += 1;
    std::cout << amount_words << ":" << nice_word_basic_analyze << std::endl;
    amount_words += 1;
    std::cout << amount_words << ":" << worst_word_basic_analyze << std::endl;

    std::vector<std::string> generated_base = genererListeDeMot_char_par_char(selected_word);
    std::vector<std::vector<std::string>> generated_second = assemblerMotsUnParUn(generated_base);
    std::vector<std::string> generated_third = assemblerMotsUnParUn_2(selected_word, generated_base);

    for (auto const& e : generated_second) {
        for (auto const& a : e) {
            amount_words += 1;
            std::cout << amount_words << ":" << a << std::endl;
        }
    }

    for (auto const& e : generated_third) {
        amount_words += 1;
        std::cout << amount_words << ":" << e << std::endl;
    }

    return 0;
}
