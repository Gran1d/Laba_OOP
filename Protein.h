//
// Created by Артём Сиротин on 12.11.2023.
//

#ifndef LABA2_OOP_PROTEIN_H
#define LABA2_OOP_PROTEIN_H
#include "vector"

class Protein {
public:
    // defoult
    Protein() = default;
    //init
    Protein(ProteinSequence _protein){
        protein.push_back(_protein);
    }
    //copy
    Protein(Protein& protein) = default;
    //add aminoacid
    void add(ProteinSequence _protein){
        protein.push_back(_protein);
    }
    //delete
    void del(){
        protein.pop_back();
    }
    //геттер всего вектора
    vector <ProteinSequence> getPrtotein() const{
        return protein;
    }
    //addition (указываем позиции аминокислот, которые мы хотим сложить)
    string addition(int pos1, int pos2){
        int length = protein.size();
        if (pos1 > length || pos2 > length)
            return "incorrect position";
        string first = protein[pos1].getAminoAcids();
        string second = protein[pos2].getAminoAcids();
        if(first[first.size() - 1] == second[0])
            return first + second;
        else if(first[0] == second[second.size() - 1])
            return second + first;
        else
            return "";
    }
private:
    vector <ProteinSequence> protein;
};


#endif //LABA2_OOP_PROTEIN_H
