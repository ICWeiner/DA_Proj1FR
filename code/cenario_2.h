//
// Created by rafael morgado on 10/04/2022.
//

#ifndef DA_PROJ1_CENARIO_2_H
#define DA_PROJ1_CENARIO_2_H

#include "data.h"
#include "dataReader.h"
#include <vector>
#include <algorithm>
#include <iostream>

class cenario_2 {
private:
    std::vector<estafeta> estafetas;
    std::vector<encomenda> encomendas;
    dataReader reader;
public:
    cenario_2();

    static bool compareFloatNum(double a, double b);

    static bool recompensaEncomendas(const encomenda &lhs, const encomenda &rhs);

    static bool custoEstafetas(const estafeta &lhs, const estafeta &rhs);

    void sort();

    int place();
};


#endif //DA_PROJ1_CENARIO_2_H
