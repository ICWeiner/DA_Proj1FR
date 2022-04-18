//
// Created by username on 07/04/22.
//

#ifndef DA_PROJ1_CENARIO_1_H
#define DA_PROJ1_CENARIO_1_H

#include "dataReader.h"
#include <algorithm>

/** @brief Class used for scenery nº1 <br>
 * In this scenery we are minimizing the number of couriers for the delivery of all orders or the largest number in one day. <br>
 * To do it we will use the greedy algorithm to determine the smallest number. <br>
 * @author Diogo Almeida
 * @date April 2022
 */
class cenario_1{
private:
    /** Vector containing all "estafetas" read from dataReader
    */
    std::vector<estafeta> estafetas;
    /** Vector containing all "encomendas" read from dataReader
    */
    std::vector<encomenda> encomendas;
    /** Constructor from dataReader.h
    */
    dataReader reader;

public:
    /** Contains: <br>
     *  A constructor from dataReader.h and two vectors. <br>
     *  One vector contains the number of "encomendas" another one contains "estafetas". <br>
    */
    cenario_1();
    /**
     * Boolean to determine if "encomenda" lhs's "peso" is bigger than "encomenda" rhs's. <br>
     * If both objects contain the same "peso" then the second topic to sort it's going to be the "volume". <br>
     * @param encomenda lhs
     * @param encomenda rhs
     * @return true if lhs is bigger than rhs or false if its smaller
     */
    static bool pesoEncomendas(const encomenda& lhs, const encomenda& rhs);
    /**
     * Boolean to determine if "estafeta" lhs's "pesoMax" is bigger than "estafeta" rhs's. <br>
     * If both objects contain the same "pesoMax" then the second topic to sort it's going to be the "volMax". <br>
     * @param encomenda lhs
     * @param encomenda rhs
     * @return true if lhs is bigger than rhs or false if its smaller
     */
    static bool pesoEstafetas(const estafeta& lhs, const estafeta& rhs);
    /**
     * Function to sort each vector according to the static booleans given.
     */
    void sort();
    /**
     * Function to return the number of "estafestas" that will take all the "encomendas" to take from the company to deliver.
     */
    int place();
};

#endif //DA_PROJ1_CENARIO_1_H
