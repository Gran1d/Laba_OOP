//
// Created by Артём Сиротин on 18.10.2023.
//

#ifndef LABA2_OOP_PROTEINSEQUENCE_H
#define LABA2_OOP_PROTEINSEQUENCE_H
#include "Transcription.h"
#include <string>
#include <iostream>

using namespace std;

class ProteinSequence : public Translation {
public:
    //Defoult
    ProteinSequence(){
        aminoAcids = "";
    }
    //init
    ProteinSequence(string _aminoAcids){
        if(_aminoAcids.find_first_not_of(TRUE_AMINOACIDS) == string::npos) {
            aminoAcids = _aminoAcids;
        }else{
            aminoAcids = "";
        }
    }
    //copy
    ProteinSequence(const ProteinSequence &ProteinSequencespointer){
        aminoAcids = ProteinSequencespointer.aminoAcids;

    }
    // сеттер
    void setAminoAcids(string _aminoAcids){
        if(_aminoAcids.find_first_not_of(TRUE_AMINOACIDS) == string::npos) {
            aminoAcids = _aminoAcids;
        }else{
            aminoAcids = "";
        }
    }
    //перегружаем сеттер чтобы можно было задавать цепочку любой длины
    void setNucleotide(string _nucleotide) override{
        if(_nucleotide.find_first_not_of(TRUE_NUCLEOTID) == string::npos) {
            nucleotide = _nucleotide;
        }else nucleotide = "";
    }
    //геттер
    string getAminoAcids() const{
        return aminoAcids;
    }
    //Переопределение метода трансляции
    string translation() override{
        for (int i = 0; i < size(nucleotide); ++i) {
            geneticCode+=nucleotide[i];
            if(size(geneticCode) == 3){
                aminoAcids += NucleotidsToAmino(geneticCode);
                geneticCode.clear();
            }
        }
        geneticCode.clear();

        return aminoAcids;
    }
    //функция идентификации класса
    bool isProteinSequence() override{
        return true;
    };
private:
    string aminoAcids;
    string TRUE_AMINOACIDS = "gavilpstcmdneqkrhfyw";
};


#endif //LABA2_OOP_PROTEINSEQUENCE_H
