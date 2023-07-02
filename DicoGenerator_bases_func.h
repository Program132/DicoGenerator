#pragma once

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

    std::string motActuel = mot;

    for (const auto& motModifie : motsModifies) {
        for (size_t i = 1; i < mot.length(); i++) {
            std::string motSuivant = motModifie;
            for (size_t j = i; j < mot.length(); j++) {
                motSuivant[j] = returnGoodLetter(motSuivant[j]);
            }

            listeMots.push_back(motSuivant);
            motActuel = motSuivant;
        }
    }

    return listeMots;
}


