//
// Created by Артём Сиротин on 25.09.2023.
//

//#include "Transcription.h"
#include "ProteinSequence.h"
#include "Protein.h"

int main(){
    Translation defoultTranscription;
    assert(defoultTranscription.getNucleotide() == "");
    assert(defoultTranscription.identify() == "Transcription");
    cout << "Test for default constructor passed" << endl;

    Translation initedTranscription("AUG");
    assert(initedTranscription.getNucleotide() == "AUG");
    assert(initedTranscription.translation() == "m");
    assert(initedTranscription.identify() == "Transcription");
    //Должен вернуть пустую строку так как мы передаем не триплет а последовательность из триплетов
    Translation initedTranscription1("AUGGGG");
    assert(initedTranscription1.getNucleotide() == "");
    assert(initedTranscription1.translation() == "");
    assert(initedTranscription1.identify() == "Transcription");
    cout << "Test for initialization constructor passed" << endl;

    Translation copiedTranscription = Translation(initedTranscription);
    assert(copiedTranscription.getNucleotide() == "AUG");
    assert(copiedTranscription.translation() == "m");
    assert(copiedTranscription.identify() == "Transcription");
    cout << "Test for copy constructor passed" << endl;
    // Передаем в родительский класс цепь длинее чем 3 возвращает пустую строку
    defoultTranscription.setNucleotide("AUUAUU");
    assert(defoultTranscription.getNucleotide() == "");
    assert(defoultTranscription.translation() == "");
    assert(defoultTranscription.identify() == "Transcription");
    defoultTranscription.setNucleotide("AUU");
    assert(defoultTranscription.getNucleotide() == "AUU");
    assert(defoultTranscription.translation() == "i");
    assert(defoultTranscription.identify() == "Transcription");
    cout << "Test for getters and setters passed" << endl;
    // в наследуемом классе мы можем передавать цепь любой длины
    ProteinSequence defoltProteinSequence;
    // дефолт
    assert(defoltProteinSequence.getNucleotide() == "");
    assert(defoltProteinSequence.getAminoAcids() == "");
    assert(defoltProteinSequence.identify() == "ProteinSequence");
    cout << "Test for default constructor passed" << endl;
    // инициализация
    ProteinSequence initedProteinSequence("agwwagg");
    assert(initedProteinSequence.getAminoAcids() == "agwwagg");
    assert(initedProteinSequence.getNucleotide() == "");
    assert(initedProteinSequence.identify() == "ProteinSequence");
    assert(initedProteinSequence.translation() == "agwwagg");
    cout << "Test for initialization constructor passed" << endl;
    //копирование
    ProteinSequence copyProteinSequnce(initedProteinSequence);
    assert(copyProteinSequnce.getAminoAcids() == "agwwagg");
    assert(copyProteinSequnce.getNucleotide() == "");
    assert(copyProteinSequnce.identify() == "ProteinSequence");
    assert(copyProteinSequnce.translation() == "agwwagg");
    cout << "Test for copy constructor passed" << endl;
    //Проверка геттеров и сеттеров в наследуемом классе
    defoltProteinSequence.setNucleotide("UGGUAU");
    assert(defoltProteinSequence.getNucleotide() == "UGGUAU");
    assert(defoltProteinSequence.translation() == "wy");
    assert(defoltProteinSequence.getAminoAcids() == "wy");
    assert(defoltProteinSequence.identify() == "ProteinSequence");
    defoltProteinSequence.setAminoAcids("z");
    assert(defoltProteinSequence.getAminoAcids() == "");
    defoltProteinSequence.setNucleotide("UGGUAU");
    defoltProteinSequence.setAminoAcids("ay");
    assert(defoltProteinSequence.getNucleotide() == "UGGUAU");
    assert(defoltProteinSequence.getAminoAcids() == "ay");
    assert(defoltProteinSequence.translation() == "aywy");
    cout << "Test for getters and setters passed" << endl;
    ProteinSequence ps;
    Translation *t = &ps;
    assert(t->identify() == "ProteinSequence");
    cout << "Test for inter-class interaction" << endl;
// Test Protein
    ProteinSequence test("gavilpstcmdneqkrhfyw");
    ProteinSequence test2("gavi");
    ProteinSequence test3("ivlps");
    ProteinSequence test4;
    test4.setNucleotide("UGGUAU");
    test4.translation();

    Protein defoultProtein;
    assert(defoultProtein.addition(0,1) == "incorrect position");
    defoultProtein.add(test2);
    defoultProtein.add(test3);
    assert(defoultProtein.addition(0,1) == "gaviivlps");
    Protein initedProtein(test);
    initedProtein.add(test4);
    assert(initedProtein.addition(0,1) == "gavilpstcmdneqkrhfywwy");
    Protein copyProtein(initedProtein);
    assert(copyProtein.addition(0,1) == "gavilpstcmdneqkrhfywwy");

    Protein multiple_lines;
    multiple_lines.add(test);
    multiple_lines.add(test2);
    multiple_lines.add(test3);
    multiple_lines.add(test4);
    assert(multiple_lines.addition(0,1) == "");
    assert(multiple_lines.addition(0,3) == "gavilpstcmdneqkrhfywwy");
    assert(multiple_lines.addition(1,2) == "gaviivlps");
    cout << "all test pass" << endl;
    //Вывод всех значений которые хранятся в векторе
    for(auto i: multiple_lines.getPrtotein())
        cout << i.getAminoAcids() << endl;
    //Вывод зачения после удаления
    multiple_lines.del();
    for(auto i: multiple_lines.getPrtotein())
        cout << i.getAminoAcids() << endl;
    return 0;
}