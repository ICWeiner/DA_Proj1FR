//
// Created by username on 07/04/22.
//

#ifndef DA_PROJ1_CENARIO_1_H
#define DA_PROJ1_CENARIO_1_H

#include "dataReader.h"
#include <algorithm>

/** @brief Class used for scenery nº1 <br>
 * In this scenario we are minimizing the number of couriers for the delivery of all orders or the largest number in one day. <br>
 * To achieve this we used a greedy algorithms based on the bin packing problem <br>
 * @author Diogo Almeida, Diogo Nunes
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
    /** dataReader object to read data from txt files
    */
    dataReader reader;

public:
    /** Contains: <br>
     *  A constructor from dataReader.h and two vectors. <br>
     *  One vector contains all instances of "encomendas" and the other one all instances of "estafetas". <br>
    */
    cenario_1();
    /**
     * Boolean to determine if "encomenda" lhs's "peso" is bigger than "encomenda" rhs's. <br>
     * If both objects contain the same "peso" then they are sorted by "volume". <br>
     * @param lhs left side value
     * @param rhs right side value
     * @return true if lhs is bigger than rhs or false if its smaller
     */
    static bool pesoEncomendas(const encomenda& lhs, const encomenda& rhs);
    /**
     * Boolean to determine if "estafeta" lhs's "pesoMax" is bigger than "estafeta" rhs's. <br>
     * If both objects contain the same "pesoMax" then they are sorted by "volMax". <br>
     * @param lhs left side value
     * @param rhs right side value
     * @return true if lhs is bigger than rhs or false if its smaller
     */
    static bool pesoEstafetas(const estafeta& lhs, const estafeta& rhs);
    /**
     * Member function to sort each vector according to the previously defined boolean functions given.
     */
    void sort();
    /**
     * Member function to return the number of "estafetas" that will take all the "encomendas" to take from the company to deliver.
     */
    int place();
};

#endif //DA_PROJ1_CENARIO_1_H
