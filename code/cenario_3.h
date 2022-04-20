//
// Created by rafael morgado on 14/04/2022.
//

#ifndef DA_PROJ1_CENARIO_3_H
#define DA_PROJ1_CENARIO_3_H

#include "dataReader.h"

/** @brief Class used for scenery nº3 <br>
 * In this scenario we are maximizing the number of successful deliveries that can be achieved in a day between 9:00am and 5:00 pm. <br>
 * To achieve this, a greedy algorithm was applied to an ordered vector. <br>
 * @author Rafael Morgado
 * @date April 2022
 */
class cenario_3{
private:
    /** Vector containing all "encomendas" read from dataReader
     */
    std::vector<encomenda> encomendas;
    /** Constructor from dataReader.h
     */
    dataReader reader;

public:
    /** Contains: <br>
      *  A constructor from dataReader.h and one vectors. <br>
      *  The vector contains the number of "encomendas". <br>
      */
    cenario_3();
    /**
     * Boolean to determine if "encomenda" lhs's "duracao" is bigger than "encomenda" rhs's. <br>
     * If both objects contain the same "duracao" then the second topic to sort it's going to be the "volume". <br>
     * @param encomenda lhs
     * @param encomenda rhs
     * @return true if lhs is bigger than rhs or false if its smaller
     */
    static bool pesoEncomendas(const encomenda& lhs, const encomenda& rhs);
    /**
     * Function to sort the vector according to the static boolean's value.
     */
    void sort();
    /**
     * Function to return the number of "encomendas" that will be successfully delivered between 9:00am and 5:00pm.
     */
    int place();
};

#endif //DA_PROJ1_CENARIO_3_H
