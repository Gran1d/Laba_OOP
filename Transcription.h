//
// Created by Артём Сиротин on 25.09.2023.
//

#ifndef LABA1_OOP_TRANSCRIPTION_H
#define LABA1_OOP_TRANSCRIPTION_H
#include <iostream>
#include <string>
using namespace std;

class Translation {
public:
// Конструктор по умолчанию
    Translation(){
        nucleotide = "";
//        aminoAcids = "";
    }
// Инициализация (Если убрать второе условие можно задать цепочку любой длины)
    Translation(string _nucleotide){
        if(_nucleotide.find_first_not_of(TRUE_NUCLEOTID) == string::npos && size(_nucleotide) == 3) {
            nucleotide = _nucleotide;
        }else{
            nucleotide = "";
        }
    }
    // копирование
    Translation(const Translation &Translationpointer){
        nucleotide = Translationpointer.nucleotide;

    }
    // геттер и сеттер
    string getNucleotide() const{
        return nucleotide;
    }
    //(Если убрать второе условие можно задать цепочку любой длины)
    virtual void setNucleotide(string _nucleotide){
        if(_nucleotide.find_first_not_of(TRUE_NUCLEOTID) == string::npos && size(_nucleotide) == 3) {
            nucleotide = _nucleotide;
        }else nucleotide = "";
    }
//    string getAminoAcids() const{
//        return aminoAcids;
//    }
// Преобразование триплетов в аминокислоту
    virtual string translation(){
    string aminoAcids;
//        if (size(nucleotide) != 3){
//            return "is not a triplet";
//        }
        for (int i = 0; i < size(nucleotide); ++i) {
            geneticCode+=nucleotide[i];
            if(size(geneticCode) == 3){
                aminoAcids = NucleotidsToAmino(geneticCode);
                geneticCode.clear();
                break;
            }
        }
        geneticCode.clear();
        return aminoAcids;
    }

    //Ф-ция идентификатор,
    virtual bool isProteinSequence(){
        return false;
    };

protected:
    string nucleotide;
    string geneticCode;
//    string aminoAcids;
// Ограничение должно быть, потому что мы не можем работать со сторокой которая содержить не нуклеотиды,
// это будет являться неверными входными данными
    string TRUE_NUCLEOTID = "AGCU";
//    string Amino;
    // трансляция
    string NucleotidsToAmino(string geneticCode){
        if (geneticCode == "GGU" || geneticCode == "GGC" || geneticCode == "GGA" || geneticCode == "GGG"){
            return "g";
        }else if (geneticCode == "GCU" || geneticCode == "GCC" || geneticCode == "GCA" || geneticCode == "GCG"){
            return "a";
        }else if (geneticCode == "GUU" || geneticCode == "GUC" || geneticCode == "GUA" || geneticCode == "GUG"){
            return "v";
        }else if(geneticCode == "AUU" || geneticCode == "AUC" || geneticCode == "AUA"){
            return "i";
        }else if(geneticCode == "UUA" || geneticCode == "UUG" || geneticCode == "CUU" || geneticCode == "CUC" \
 || geneticCode == "CUA" || geneticCode == "CUG"){
            return "l";
        }else if(geneticCode == "CCU" || geneticCode == "CCC" || geneticCode == "CCA" || geneticCode == "CCG"){
            return "p";
        }else if(geneticCode == "UCU" || geneticCode == "UCC" || geneticCode == "UCA" || geneticCode == "UCG" \
 || geneticCode == "AGU" || geneticCode == "AGC"){
            return "s";
        }else if(geneticCode == "ACU" || geneticCode == "ACC" || geneticCode == "ACA" || geneticCode == "ACG"){
            return "t";
        }else if(geneticCode == "UGU" || geneticCode == "UGC"){
            return "c";
        }else if(geneticCode == "AUG"){
            return "m";
        }else if(geneticCode == "GAU" || geneticCode == "GAC"){
            return "d";
        }else if(geneticCode == "AAU" || geneticCode == "AAC"){
            return "n";
        }else if(geneticCode == "GAA" || geneticCode == "GAG"){
            return "e";
        }else if(geneticCode == "CAA" || geneticCode == "CAG"){
            return "q";
        }else if(geneticCode == "AAA" || geneticCode == "AAG"){
            return "k";
        }else if(geneticCode == "CGU" || geneticCode == "CGC" || geneticCode == "CGA" || geneticCode == "CGG" \
 || geneticCode == "AGA" || geneticCode == "AGG"){
            return "r";
        }else if(geneticCode == "CAU" || geneticCode == "CAC"){
            return "h";
        }else if(geneticCode == "UUU" || geneticCode == "UUC"){
            return "f";
        }else if(geneticCode == "UAU" || geneticCode == "UAC"){
            return "y";
        }else if(geneticCode == "UGG"){
            return "w";
        } else return "";
    }

};


#endif //LABA1_OOP_TRANSCRIPTION_H
