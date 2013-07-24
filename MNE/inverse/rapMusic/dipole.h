//=============================================================================================================
/**
* @file     dipole.h
* @author   Christoph Dinh <christoph.dinh@tu-ilmenau.de>;
* @version  1.0
* @date     March, 2011
*
* @section  LICENSE
*
* Copyright (C) 2013 Christoph Dinh. All rights reserved.
*
* No part of this program may be photocopied, reproduced,
* or translated to another program language without the
* prior written consent of the author.
*
*
* @brief    ToDo Documentation...
*
*/

#ifndef DIPOLE_H
#define DIPOLE_H

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================


//*************************************************************************************************************
//=============================================================================================================
// STL INCLUDES
//=============================================================================================================

#include <iostream>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE INVERSELIB
//=============================================================================================================

namespace INVERSELIB
{


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================


//*************************************************************************************************************
//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================
template<typename T>
class Dipole;


//=============================================================================================================
/**
* Declares a DipolePair structure consisting of two correlated dipoles which are the result of the RAP MUSIC
* searching algorithm.
*/
template<typename T>
struct DipolePair
{
    int m_iIdx1;            /**< Index of dipole one. */
    Dipole<T> m_Dipole1;    /**< Dipole one. */

    int m_iIdx2;            /**< Index of dipole two. */
    Dipole<T> m_Dipole2;    /**< Dipole two. */

    T m_vCorrelation;     /**< Correlation of the dipole pair. */
};




//=============================================================================================================
/**
* DECLARE CLASS Dipoles
*
* @brief ToDo
*/
template<class T>
class Dipole
{
//typedef Eigen::Matrix<T, 3, 1> Point3D;

public:

    //=========================================================================================================
    /**
    * Default constructor
    */
    Dipole();

    //=========================================================================================================
    /**
    * ctor
    *
    * @param p_sDataPath the path to the directory which contains the data folder.
    */
    /*	Dipole();*/


    //=========================================================================================================
    /**
    * dtor
    * Do garbage collecting
    */
    virtual ~Dipole();


    inline T& x() { return m_pPosition[0] ; }
    inline T& y() { return m_pPosition[1] ; }
    inline T& z() { return m_pPosition[2] ; }
    inline T x() const { return m_pPosition[0] ; }
    inline T y() const { return m_pPosition[1] ; }
    inline T z() const { return m_pPosition[2] ; }

    inline T& phi_x() { return m_pDirection[0] ; }
    inline T& phi_y() { return m_pDirection[1] ; }
    inline T& phi_z() { return m_pDirection[2] ; }
    inline T phi_x() const { return m_pDirection[0] ; }
    inline T phi_y() const { return m_pDirection[1] ; }
    inline T phi_z() const { return m_pDirection[2] ; }


    //=========================================================================================================
    /**
    * clean
    */
    void clean();

protected:

private:

    T* m_pPosition;
    T* m_pDirection;

    double  m_dLength;
    double  m_dFrequency;

    //TGreensFunction* green;

};

} // NAMESPACE

//TypeDefs
typedef INVERSELIB::Dipole<int>     Dipole_INT;
typedef INVERSELIB::Dipole<float>   Dipole_FLOAT;
typedef INVERSELIB::Dipole<double>  Dipole_DOUBLE;

//Make the template definition visible to compiler in the first point of instantiation
#include "dipole.cpp"

#endif // DIPOLE_H