#pragma once

#include "DicoGenerator_Classes.h"

#include <set>

std::string returnFirstWord(std::string& word) {
    std::string w = word;

    for (char &e : w) {
        e = returnGoodLetter(e);
    }

    return w;
}

std::string returnFirstWord_second(std::string& word) {
    std::string w = word;

    for (char &e : w) {
        e = returnGoodLetter_second(e);
    }

    return w;
}

std::vector<std::string> genererListeDeMot_char_par_char(const std::string& mot) {
    std::vector<std::string> listeMots;
    std::set<std::string> motsDejaVus;
    motsDejaVus.insert(mot);

    for (size_t i = 0; i < mot.length(); i++) {
        std::string motModifie = mot;
        motModifie[i] = returnGoodLetter(motModifie[i]);

        if (motsDejaVus.find(motModifie) == motsDejaVus.end()) {
            listeMots.push_back(motModifie);
            motsDejaVus.insert(motModifie);
        }
    }

    return listeMots;
}

std::vector<std::vector<std::string>> assemblerMotsUnParUn(const std::vector<std::string>& motsModifies) {
    std::vector<std::vector<std::string>> listeMots;
    listeMots.reserve(motsModifies.size());
    for (const auto & motsModifie : motsModifies) {
        listeMots.push_back(genererListeDeMot_char_par_char(motsModifie));
    }
    return listeMots;
}

std::vector<std::string> assemblerMotsUnParUn_2(const std::string& mot, const std::vector<std::string>& motsModifies) {
    std::vector<std::string> listeMots;
    listeMots.reserve(motsModifies.size());
    listeMots.push_back(mot); // Ajouter le mot original à la liste

    for (const auto& motModifie : motsModifies) {
        for (size_t i = 1; i < mot.length(); i++) {
            std::string motSuivant = motModifie;
            for (size_t j = i; j < mot.length(); j++) {
                motSuivant[j] = returnGoodLetter(motSuivant[j]);
            }

            listeMots.push_back(motSuivant);
        }
    }

    return listeMots;
}

std::vector<std::string> assembleNumberWord(const std::vector<std::string>& list) {
    std::vector<std::string> listeMots;

    for (const auto& motModifie : list) {
        for (int i = 1; i <= 1000; i++) {
            std::string motSuivant = std::to_string(i) + motModifie;
            std::string motSuivant2 = motModifie + std::to_string(i);
            listeMots.push_back(motSuivant);
            listeMots.push_back(motSuivant2);
        }
    }

    return listeMots;
}

std::vector<std::string> assembleTiretsToWord(const std::vector<std::string>& list) {
    std::vector<std::string> listeMots;

    for (const auto& motModifie : list) {
        std::string motSuivant = "-" + motModifie;
        std::string motSuivant2 = motModifie + "-";
        listeMots.push_back(motSuivant);
        listeMots.push_back(motSuivant2);

        motSuivant = "--" + motModifie;
        motSuivant2 = motModifie + "--";
        listeMots.push_back(motSuivant);
        listeMots.push_back(motSuivant2);

        motSuivant = "---" + motModifie;
        motSuivant2 = motModifie + "---";
        listeMots.push_back(motSuivant);
        listeMots.push_back(motSuivant2);

        motSuivant = "----" + motModifie;
        motSuivant2 = motModifie + "----";
        listeMots.push_back(motSuivant);
        listeMots.push_back(motSuivant2);
    }

    return listeMots;
}

