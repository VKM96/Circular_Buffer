/**
 * @file UsrBuffer.h
 * @author vishalK
 * @brief This is the interface file for the circular buffer
 * @date 2020-12-26
 * 
 * 
 */

#ifndef USRBUFFER
#define USRBUFFER

#include <stdint.h>
#include <stddef.h>

const size_t BUF_SIZE = 16 ; /*> Buffer size to be updated based on application needs*/

/**
 * @brief status enum
 * 
 */
typedef enum
{
    E_NOERR = 0,        /**< No error */
    E_BUF_FULL ,        /**< Buffer full */
    E_BUF_EMPTY,        /**< Buffer empty */
    E_BUF_OVERWRITE     /**< Buffer overwritten */
}eStatus_t;

/**
 * @brief Circular buffer structure used by the application program
 * 
 */
typedef struct 
{
    int8_t buf[BUF_SIZE];   /**< Buffer used by circular buffer */
    int8_t* head;           /**< head pointer, data will be read from here */
    int8_t* tail;           /**< head pointer, data will be inserted from here */
    size_t NumElems;        /**< Number of elements currently in the circular buffer  */
}sCircBuf_t;

eStatus_t BufInit(sCircBuf_t* const me);
eStatus_t BufEnqueue(sCircBuf_t* const me,int8_t data);
eStatus_t BufDequeue(sCircBuf_t* const me , int8_t* data );
eStatus_t BufPeek(sCircBuf_t* const me , int8_t* data );

#endif