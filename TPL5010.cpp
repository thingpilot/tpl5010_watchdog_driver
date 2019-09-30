/**
  * @file    TPL5010.cpp
  * @version 1.0.0
  * @author  Adam Mitchell
  * @brief   C++ file of the TPL5010 watchdog timer driver module
  */

/** Includes
 */
#include "TPL5010.h"

/** Constructor. Create an interface to the watchdog chip with the specified uC pin
 *  connected to the DONE pin on the TPL5010
 * 
 * @param done GPIO to reset the watchdog timer
 */
TPL5010::TPL5010(PinName done) :
                 _done(done, 0)
{

}

/** Destructor. Will set _done to logic low
 */
TPL5010::~TPL5010()
{
    _done = 0;
}

/** Kick the watchdog by asserting _done for 2 microseconds. The minimum pulse width
 *  that the TPL5010 will detect is ~ 100 nanoseconds
 */
void TPL5010::kick()
{
    _done = 1;

    wait_us(2);

    _done = 0;
}