/**
 * @file UsrBuffer.c
 * @author vishalK
 * @brief Implentation file for the Circular buffer
 * @date 2020-12-26
 * 
 * 
 */

#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "UsrBuffer.h"

/**
 * @brief Function for initalizing circular buffer
 * 
 * @param me pointer to @ref sCircBuf_t struct , to be initalized
 * @return eStatus_t @ref eStatus_t
 * 
 * @note : The init function should always be called before using the buffer
 * 
 */
eStatus_t BufInit(sCircBuf_t* const me)
{
    assert(me);

    /// set buffer value to 0
    memset((me->buf),0,BUF_SIZE*sizeof(me->buf[0])) ;

    me->head = me->buf ;
    me->tail = me->buf ;
    me->NumElems = 0;

    return E_NOERR;
}

/**
 * @brief Helper function to check if buffer is full
 * 
 * @param me pointer to @ref sCircBuf_t struct, whose buffer is being checked
 * @return eStatus_t @ref eStatus_t
 * 
 */
static eStatus_t BufIsFull(sCircBuf_t* const me)
{
    assert(me);
    eStatus_t status = E_NOERR;

    if(me->NumElems >= BUF_SIZE )
    {
        status = E_BUF_FULL ;
    }

    return status;
}

/**
 * @brief Helper function to check if buffer is empty
 * 
 * @param me pointer to @ref sCircBuf_t struct, whose buffer is being checked
 * @return eStatus_t @ref eStatus_t
 * 
 */
static eStatus_t BufIsEmpty(sCircBuf_t* const me)
{
    assert(me);
    eStatus_t status = E_NOERR;

    if( me->NumElems <= 0)
    {
        status = E_BUF_EMPTY ;
    }

    return status;
}

/**
 * @brief Function to enqueue data into circular buffer
 * @param me pointer to @ref sCircBuf_t struct to which data is being enqueued
 * @param data data being enqueued
 * @return eStatus_t @ref eStatus_t
 */
eStatus_t BufEnqueue(sCircBuf_t* const me,int8_t data)
{
    assert(me);
    eStatus_t status = E_NOERR;

    /// If buffer is full indicate in status
    if( E_BUF_FULL ==  BufIsFull(me))
    {
        status = E_BUF_OVERWRITE ;
    }

    /// wrap buffer tail 
    if(me->tail >= me->buf + BUF_SIZE)
    {
        me->tail = me->buf ;
    }

    /// enqueue data and update number of elements
    *(me->tail++) = data ;
    me->NumElems++;

    /// set ceiling on number of elements
    if(me->NumElems > BUF_SIZE)
    {
        me->NumElems = BUF_SIZE ;
    }

    return status;
}

/**
 * @brief Function to dequeue data from circular buffer
 * 
 * @param me pointer to @ref sCircBuf_t struct to from data is being dequeued
 * @param pData data pointer to be filled by dequeue function 
 * @return eStatus_t @ref eStatus_t
 * 
 */
eStatus_t BufDequeue(sCircBuf_t* const me , int8_t* pData )
{
    assert(me);
    eStatus_t status = E_NOERR;

    /// If buffer is empty update status
    if( E_BUF_EMPTY ==  BufIsEmpty(me))
    {
        status = E_BUF_EMPTY ;
    }
    else
    {
        /// dequeue data and set to zero
        *pData = (*(me->head)) ;
        *(me->head) = 0 ;

        /// wrap buffer head
        if(me->head >= me->buf + BUF_SIZE)
        {
            me->head = me->buf ;
        }
        me->head++ ;
        me->NumElems-- ;
    }
    return status;
}

/**
 * @brief Function which is used to peek into the circular buffer
 * 
 * @param me pointer to @ref sCircBuf_t struct to from data is being peeked
 * @param data pointer to be filled by peek function 
 * @return eStatus_t @ref eStatus_t
 */
eStatus_t BufPeek(sCircBuf_t* const me , int8_t* data )
{
    assert(me);
    eStatus_t status = E_NOERR;

    if( E_BUF_EMPTY ==  BufIsEmpty(me))
    {
        status = E_BUF_EMPTY ;
    }
    else
    {
        *data = (*(me->head)) ;
        if(me->head >= me->buf + BUF_SIZE)
        {
            me->head = me->buf ;
        }
    }
    return status;
}