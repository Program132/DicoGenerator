#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <fstream>
#include <sstream>

#include "DicoGenerator_bases_func.h"

std::vector<std::string> splitStringBySpace(const std::string& input) {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}


void addToFinalList(std::vector<std::string>& final, std::set<std::string>& motsdejavue, std::vector<std::string>& currentL) {
    for (auto const& element : currentL) {
        if (motsdejavue.find(element) == motsdejavue.end()) {
            final.push_back(element);
            motsdejavue.insert(element);
        }
    }
}

void executeForOneWord(std::vector<std::string>& finalList, std::set<std::string>& motsDejaVus_finalLists, std::string word) {
    std::string selected_word = word;
    motsDejaVus_finalLists.insert(selected_word);
    std::string first_word = selected_word;
    std::string second_word = returnFirstWord(selected_word);
    std::string third_word = returnFirstWord_second(selected_word);
    std::vector<std::string> generated_base = genererListeDeMot_char_par_char(selected_word);
    std::vector<std::vector<std::string>> generated_second = assemblerMotsUnParUn(generated_base);
    std::vector<std::string> generated_third = assemblerMotsUnParUn_2(selected_word, generated_base);

    finalList.push_back(selected_word);
    finalList.push_back(third_word);
    finalList.push_back(second_word);
    addToFinalList(finalList, motsDejaVus_finalLists, generated_base);
    for (auto e : generated_second) {
        addToFinalList(finalList, motsDejaVus_finalLists, e);
    }
    addToFinalList(finalList, motsDejaVus_finalLists, generated_third);
    std::vector<std::string> generatedNumber_Word = assembleNumberWord(finalList);
    addToFinalList(finalList, motsDejaVus_finalLists, generatedNumber_Word);
    std::vector<std::string> generateTiretsWord = assembleTiretsToWord(finalList);
    addToFinalList(finalList, motsDejaVus_finalLists, generateTiretsWord);

    int i = 1;
    for (std::string_view e : finalList) {
        std::cout << i << ":" << e << std::endl;
        i++;
    }
}

int main() {
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "----------------------- Dico Generator -----------------------" << std::endl;
    std::cout << "--------------------------- Program --------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "---------------- https://github.com/Program132 ----------------" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;

    std::vector<std::string> finalList;
    std::set<std::string> motsDejaVus_finalLists;

    std::ifstream file {"listes_mots.txt"};
    std::ofstream save_file {"best_dico.txt"};

    std::string FileCode((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    std::vector<std::string> words = splitStringBySpace(FileCode);

    for (auto const& e : words) {
        executeForOneWord(finalList, motsDejaVus_finalLists, e);
    }

    if (save_file && save_file.is_open()) {
        for (std::string_view e : finalList) {
            save_file << e;
        }
        save_file.close();
    }

    return 0;
}
