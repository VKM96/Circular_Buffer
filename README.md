Circular buffer                      {#mainpage}
============
    Circular buffer implementation for use in embedded systems

**Code Structure**

1. Source files are present in @ref Src
2. Interface files are present in @ref inc
3. PLease refer doxygen generated HTML documentation in the Doc/html subfolder for implementation details
4. The function entry point is @ref Main.c

**Usage**

1. Initialization of the circularBuffer is achieved through @ref BufInit in @ref UsrBuffer.h
2. Applications using the buffer, inputs data through @ref BufEnqueue
3. @ref BufDequeue is used for extracting buffer data 

**Modification**

1. BUffer size can be changed by changing @ref BUF_SIZE in file @ref UsrBuffer.h

**Permissions**

1. Please refer to the LICENSE file 
