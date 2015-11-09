//=============================================================================================================
/**
* @file     gusbampproducer.h
* @author   Viktor Klüber <viktor.klueber@tu-ilmenau.de>;
*           Lorenz Esch <lorenz.esch@tu-ilmenau.de>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>;
* @version  1.0
* @date     November, 2015
*
* @section  LICENSE
*
* Copyright (C) 2015, Viktor Klüber, Lorenz Esch and Matti Hamalainen. All rights reserved.
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of MNE-CPP authors nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief    Contains the declaration of the GUSBAmpProducer class.
*
*/

#ifndef GUSBAMPPRODUCER_H
#define GUSBAMPPRODUCER_H


//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include <generics/circularbuffer.h>


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QThread>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE GUSBAmpPlugin
//=============================================================================================================

namespace GUSBAmpPlugin
{


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace IOBuffer;


//*************************************************************************************************************
//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================

class GUSBAmp;
class GUSBAmpDriver;


//=============================================================================================================
/**
* DECLARE CLASS EEGProducer
*
* @brief The EEGProducer class provides a EEG data producer for a given sampling rate.
*/
class GUSBAmpProducer : public QThread
{
public:
    //=========================================================================================================
    /**
    * Constructs a GUSBAmpProducer.
    *
    * @param [in] pGUSBAmp a pointer to the corresponding GUSBAmp class.
    */
    GUSBAmpProducer(GUSBAmp* pGUSBAmp);

    //=========================================================================================================
    /**
    * Destroys the GUSBAmpProducer.
    */
    ~GUSBAmpProducer();

    //=========================================================================================================
    /**
    * Starts the GUSBAmpProducer by starting the producer's thread and initialising the device.
    * @param [in] iNumberOfChannels The number of channels defined by the user via the GUI.
    * @param [in] iSamplingFrequency The sampling frequency defined by the user via the GUI (in Hertz).
    * @param [in] iSamplesPerBlock The samples per block defined by the user via the GUI.
    * @param [in] bUseChExponent Flag for using the channels exponent. Defined by the user via the GUI.
    * @param [in] bUseUnitGain Flag for using the channels unit gain. Defined by the user via the GUI.
    * @param [in] sOutpuFilePath Holds the path for the output file. Defined by the user via the GUI.
    * @param [in] bWriteDriverDebugToFile Flag for writing the received samples to a file. Defined by the user via the GUI.
    * @param [in] bUseUnitOffset Flag for using the channels unit offset. Defined by the user via the GUI.
    */
    virtual void start(int iNumberOfChannels,
                       int iSamplingFrequency,
                       int iSamplesPerBlock,
                       bool bUseChExponent,
                       bool bUseUnitGain,
                       bool bUseUnitOffset,
                       bool bWriteDriverDebugToFile,
                       QString sOutputFilePath);

    //=========================================================================================================
    /**
    * Stops the GUSBAmpProducer by stopping the producer's thread.
    */
    void stop();

protected:
    //=========================================================================================================
    /**
    * The starting point for the thread. After calling start(), the newly created thread calls this function.
    * Returning from this method will end the execution of the thread.
    * Pure virtual method inherited by QThread.
    */
    virtual void run();

private:
    GUSBAmp*                       m_pGUSBAmp;            /**< A pointer to the corresponding GUSBAmp class.*/
    QSharedPointer<GUSBAmpDriver>  m_pGUSBAmpDriver;      /**< A pointer to the corresponding GUSBAmp driver class.*/

    bool                        m_bIsRunning;       /**< Whether GUSBAmpProducer is running.*/

};

} // NAMESPACE

#endif // GUSBAMPPRODUCER_H