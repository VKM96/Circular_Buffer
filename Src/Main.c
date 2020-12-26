/**
 * @file Main.c
 * @author vishalK
 * @brief 
 * @version @ref VERSION
 * @date 2020-12-20
 * @bug No known bugs at the time of development
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include "UsrBuffer.h"



/**
 * @brief Function entry point, Initialization, enqueuing and dequeing demonstrated
 * 
 * 
 * @return int 
 */
int main()
{
    sCircBuf_t CircBuf;
    sCircBuf_t* psCircBuf_t = &CircBuf;
    
    /// Initialize buffer
    /// @ref BufInit
    BufInit(psCircBuf_t);
    
    for(size_t i = 0 ; i < BUF_SIZE ; i++)
    {
        /// Enqueue buffer
        /// @ref BufEnqueue
        BufEnqueue(psCircBuf_t,i);
    }

    int8_t temp = 0;
    eStatus_t status;

    do
    {
        /// Dequeue buffer
        /// @ref BufDequeue
        status = BufDequeue(psCircBuf_t,&temp);
        printf("\n%d",temp);
        
    } while (E_NOERR == status );

    return 0;

}





