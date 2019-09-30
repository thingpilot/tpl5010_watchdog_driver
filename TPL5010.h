/**
  * @file    TPL5010.h
  * @version 1.0.0
  * @author  Adam Mitchell
  * @brief   Header file of the TPL5010 watchdog timer driver module
  */

/** Define to prevent recursive inclusion
 */
#pragma once

/** Includes 
 */
#include <mbed.h>

/** Base class for the TPL5010 series watchdog timer
 */ 
class TPL5010
{

    public:

        /** Constructor. Create an interface to the watchdog chip with the specified uC pin
         *  connected to the DONE pin on the TPL5010
         * 
         * @param done GPIO to reset the watchdog timer
         */
        TPL5010(PinName done);

        /** Destructor. Will set _done to logic low
         */
        ~TPL5010();

        /** Kick the watchdog by asserting _done for 2 microseconds. The minimum pulse width
         *  that the TPL5010 will detect is ~ 100 nanoseconds
         */
        void kick();

    private:

        DigitalOut _done;
};