#include <iostream>
#include <string>
#include <vector>
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


void addToFinalList(std::vector<std::string>& final, std::set<std::string>& motsdejavue, std::vector<std::string>& currentL, std::ofstream &save_file, int &total_words) {
    for (auto const& element : currentL) {
        if (motsdejavue.find(element) == motsdejavue.end()) {
            std::cout << total_words << ":" << element << std::endl;

            final.push_back(element);
            motsdejavue.insert(element);
            save_file << element << "\n";
            total_words += 1;
        }
    }
}

void executeForOneWord(std::vector<std::string>& finalList, std::set<std::string>& motsDejaVus_finalLists, std::string word, std::ofstream &save_file, int &total_words) {
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
    total_words += 3;
    addToFinalList(finalList, motsDejaVus_finalLists, generated_base, save_file, total_words);
    for (auto e : generated_second) {
        addToFinalList(finalList, motsDejaVus_finalLists, e, save_file, total_words);
    }
    addToFinalList(finalList, motsDejaVus_finalLists, generated_third, save_file, total_words);
    std::vector<std::string> generatedNumber_Word = assembleNumberWord(finalList);
    addToFinalList(finalList, motsDejaVus_finalLists, generatedNumber_Word, save_file, total_words);
    std::vector<std::string> generateTiretsWord = assembleTiretsToWord(finalList);
    addToFinalList(finalList, motsDejaVus_finalLists, generateTiretsWord, save_file, total_words);
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

    std::ifstream file {"listes_mots.txt"};
    std::ofstream save_file {"best_dico.txt"};

    if (!file || !save_file) {
        std::cout << "\n" << std::endl;
        std::cout << "'listes_mots.txt' and 'best_dico.txt' are not in the folder." << std::endl;
        std::cout << "\n" << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;
        std::cout << "----------------------- Dico Generator -----------------------" << std::endl;
        std::cout << "--------------------------- Program --------------------------" << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;
        std::cout << "---------------- https://github.com/Program132 ----------------" << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;
        return -1;
    }

    int total_words = 1;

    std::vector<std::string> finalList;
    std::set<std::string> motsDejaVus_finalLists;

    std::string FileCode((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    std::vector<std::string> words = splitStringBySpace(FileCode);

    for (auto const& e : words) {
        executeForOneWord(finalList, motsDejaVus_finalLists, e, save_file, total_words);
        finalList.clear();
    }

    save_file.close();

    std::cout << "\n" << std::endl;
    std::cout << "You have " << total_words << " in your 'best_dico.txt' file" << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "----------------------- Dico Generator -----------------------" << std::endl;
    std::cout << "--------------------------- Program --------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "---------------- https://github.com/Program132 ----------------" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;

    return 0;
}
