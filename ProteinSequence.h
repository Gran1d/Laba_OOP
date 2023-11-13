//
// Created by Артём Сиротин on 18.10.2023.
//

#ifndef LABA2_OOP_PROTEINSEQUENCE_H
#define LABA2_OOP_PROTEINSEQUENCE_H
#include "Transcription.h"
//#include <string>
//#include <iostream>

using namespace std;

class ProteinSequence : public Translation {
public:
    //Defoult
    ProteinSequence(): Translation(){
        aminoAcids = "";
    }
    //Конструктор инициализации(Мы не обращаемся к конструктору в родительский класс, так как там есть ограничения
    //Поэтому для того чтобы задать строку мы используем перегруженный сеттер, в котором нет ограничения
    ProteinSequence(string _aminoAcids){
        if(_aminoAcids.find_first_not_of(TRUE_AMINOACIDS) == string::npos) {
            aminoAcids = _aminoAcids;
        }else{
            aminoAcids = "";
        }
    }
    //copy
    ProteinSequence(const ProteinSequence &ProteinSequencespointer): Translation(ProteinSequencespointer){
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
    //Здесь этот метод преобразует цепочку из нуклеотидов в аминокислоты и конкатенирут с аминокислотами, которые уже были переданы
    string translation() override{
        string geneticCode;
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
    //функция идентификации класса(этот класс является белковой последовательностью)
    string identify() const override{
        return "ProteinSequence";
    };
private:
    string aminoAcids;
    //Задаем алфавит, так как строку содержащую другие символы будет некорректно вводить
    string TRUE_AMINOACIDS = "gavilpstcmdneqkrhfyw";
};


#endif //LABA2_OOP_PROTEINSEQUENCE_H
