#ifndef PROJ_TRANSPORTATIONLOCALREG_H
#define PROJ_TRANSPORTATIONLOCALREG_H

#include "../Header/bst.h"
#include "../Header/TransportationLocal.h"

class TransportationLocalReg {
private:
    BST<TransportationLocal *> transportationLocals;

public:
    TransportationLocalReg();
    /**
     *
     * @return BST of transportation locals
     */

    const BST<TransportationLocal *> &getTransportationLocals() const;
    /**
     * @brief adds transportationLocal to BST of transportationLocals
     * @param transportationLocal
     */

    void addTransportationLocal(TransportationLocal *transportationLocal);
    /**
     *
     * @param transportationLocalId
     * @param distanceToAirport
     * @param transportationType
     * @param airport
     * @return true if transportationLocal with parameters was added to BST
     */

    bool addTransportationLocal(int transportationLocalId, float distanceToAirport, string transportationType, Airport* airport);

    /**
     *
     * @param transportationLocalId
     * @param time
     * @return true if time was added sucefully to transportationLocal  with transportationLocalId
     */
    bool addTransportationLocalTimeTable(int transportationLocalId, string time);
    /**
     *
     * @param transportationLocalId
     * @param time
     * @return true if time was removed from transportationLocal with transportationLocalId
     */

    bool remTransportationLocalTimeTable(int transportationLocalId, string time);
    /**
     * @brief lists all times of transportationLocal with transportationLocalId
     * @param transportationLocalId
     */

    void listTransportationLocalTimeTable(int transportationLocalId);
    /**
     * @brief lists all transportationLocals
     */

    void listTransportationLocals();
    /**
     *
     * @param transportationLocalId
     * @return true if transportationLocal  with transportationLocalId was removed
     */
    bool remTransportationLocal(int transportationLocalId);
    /**
     *
     * @param transportationLocalId
     * @return true if transportationLocal with transportationLocalId was found
     */

    bool findTransportationLocal(int transportationLocalId);
    /**
     *
     * @param transportationLocalId
     * @return transportationLocal with transportationLocalId
     */

    TransportationLocal *getTransportationLocalById(int transportationLocalId);

    /**
     * @brief removes a transport associated with the airport whose name is local
     * @param local
     */
    void remTransportationLocal(string local);
};


#endif //PROJ_TRANSPORTATIONLOCALREG_H
