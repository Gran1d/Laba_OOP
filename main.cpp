//
// Created by Артём Сиротин on 25.09.2023.
//

//#include "Transcription.h"
#include "ProteinSequence.h"

int main(){
    Translation defoultTranscription;
    assert(defoultTranscription.getNucleotide() == "");
    assert(defoultTranscription.isProteinSequence() == false);
    cout << "Test for default constructor passed" << endl;

    Translation initedTranscription("AUG");
    assert(initedTranscription.getNucleotide() == "AUG");
    assert(initedTranscription.translation() == "m");
    assert(initedTranscription.isProteinSequence() == false);
    //Должен вернуть пустую строку так как мы передаем не триплет а последовательность из триплетов
    Translation initedTranscription1("AUGGGG");
    assert(initedTranscription1.getNucleotide() == "");
    assert(initedTranscription1.translation() == "");
    assert(initedTranscription1.isProteinSequence() == false);
    cout << "Test for initialization constructor passed" << endl;

    Translation copiedTranscription = Translation(initedTranscription);
    assert(copiedTranscription.getNucleotide() == "AUG");
    assert(copiedTranscription.translation() == "m");
    assert(copiedTranscription.isProteinSequence() == false);
    cout << "Test for copy constructor passed" << endl;
    // Передаем в родительский класс цепь длинее чем 3 возвращает пустую строку
    defoultTranscription.setNucleotide("AUUAUU");
    assert(defoultTranscription.getNucleotide() == "");
    assert(defoultTranscription.translation() == "");
    assert(defoultTranscription.isProteinSequence() == false);
    defoultTranscription.setNucleotide("AUU");
    assert(defoultTranscription.getNucleotide() == "AUU");
    assert(defoultTranscription.translation() == "i");
    assert(defoultTranscription.isProteinSequence() == false);
    cout << "Test for getters and setters passed" << endl;
    // в наследуемом классе мы можем передавать цепь любой длины
    ProteinSequence defoltProteinSequence;
    // дефолт
    assert(defoltProteinSequence.getNucleotide() == "");
    assert(defoltProteinSequence.getAminoAcids() == "");
    assert(defoltProteinSequence.isProteinSequence() == true);
    cout << "Test for default constructor passed" << endl;
    // инициализация
    ProteinSequence initedProteinSequence("agwwagg");
    assert(initedProteinSequence.getAminoAcids() == "agwwagg");
    assert(initedProteinSequence.getNucleotide() == "");
    assert(initedProteinSequence.isProteinSequence() == true);
    assert(initedProteinSequence.translation() == "agwwagg");
    cout << "Test for initialization constructor passed" << endl;
    //копирование
    ProteinSequence copyProteinSequnce(initedProteinSequence);
    assert(copyProteinSequnce.getAminoAcids() == "agwwagg");
    assert(copyProteinSequnce.getNucleotide() == "");
    assert(copyProteinSequnce.isProteinSequence() == true);
    assert(copyProteinSequnce.translation() == "agwwagg");
    cout << "Test for copy constructor passed" << endl;
    //Проверка геттеров и сеттеров в наследуемом классе
    defoltProteinSequence.setNucleotide("UGGUAU");
    assert(defoltProteinSequence.getNucleotide() == "UGGUAU");
    assert(defoltProteinSequence.translation() == "wy");
    assert(defoltProteinSequence.getAminoAcids() == "wy");
    assert(defoltProteinSequence.isProteinSequence() == true);
    defoltProteinSequence.setAminoAcids("z");
    assert(defoltProteinSequence.getAminoAcids() == "");
    defoltProteinSequence.setNucleotide("UGGUAU");
    defoltProteinSequence.setAminoAcids("ay");
    assert(defoltProteinSequence.getNucleotide() == "UGGUAU");
    assert(defoltProteinSequence.getAminoAcids() == "ay");
    assert(defoltProteinSequence.translation() == "aywy");
    cout << "Test for getters and setters passed" << endl;

    return 0;
}