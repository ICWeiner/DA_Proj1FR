//
// Created by Diogo Nunes on 3/4/22.
//
#include "dataReader.h"
#include <sstream>
#include <iostream>

dataReader::dataReader() {

}

std::vector<estafeta> dataReader::readEstafetas() {
    file.open("../input/carrinhas.txt");
    std::vector<estafeta> vector;
    std::string line;

    while (std::getline(file,line)){
        int vol, peso, custo;
        std::stringstream lineStream(line);

        while (lineStream >> vol >> peso >> custo){
            //std::cout << vol << " " << peso << " " << custo <<  "\n";
            estafeta estafetaData;

            estafetaData.volMax = vol;
            estafetaData.pesoMax = peso;
            estafetaData.custo = custo;
            estafetaData.custoKG = (float ) custo / (float )peso;
            estafetaData.custoVol = (float ) custo/ (float )vol;

            vector.push_back(estafetaData);
        }
    }

    file.close();

    return vector;
}

std::vector<encomenda> dataReader::readEncomendas() {
    file.open("../input/encomendas.txt");
    std::vector<encomenda> vector;
    std::string line;


    while (std::getline(file,line)){
        int vol, peso, recompensa, duracao;
        std::stringstream lineStream(line);

        while (lineStream >> vol >> peso >> recompensa >> duracao){
            //std::cout << vol << " " << peso << " " << recompensa<< " " << duracao <<  "\n";
            encomenda encomendaData;

            encomendaData.vol = vol;
            encomendaData.peso = peso;
            encomendaData.recompensa = recompensa;
            encomendaData.duracao = duracao;
            encomendaData.recompensaKG = (float ) recompensa / (float ) peso;
            encomendaData.recompensaVol = (float ) recompensa / (float ) vol;

            vector.push_back(encomendaData);
            //std::cout << vector.end()->vol << " " << vector.end()->peso << " " << vector.end()->recompensa<< " " << vector.end()->duracao <<  "\n";
        }
    }

    file.close();

    return vector;
}