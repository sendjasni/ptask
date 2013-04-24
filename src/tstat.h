#ifndef __WCET_H__
#define __WCET_H__

#include <ptime.h>

/**
   This module provides simple utilities for measuring the average and
   worst case execution time of a task.

   The tstat_init() and tstat_record() are called by the ptask module to 
   automatically measure the wcet of a task.

   The tstat_get... are called by the client that wishes to obtain
   information on the task execution. 
   No synchronisation mechanism is used to protect the data structure 
   that holds the data. Hence, if the tstat_get... functions are called 
   while the task executes, the result may be incorrect. 

   The module is based on the CLOCK_THREAD_CPUTIME_ID specified by  
   POSIX , so the precision of the results depend on the OS and 
   on the internal functioning of this timer. 
*/
void tstat_init(int i);           /*< init the internal data struct. */
void tstat_record(int i);         /*< record data                    */

tspec_t tstat_getwcet(int i);     /*< returns the task wcet          */
tspec_t tstat_getavg(int i);      /*< returns the task av. exec time */
int tstat_getnuminstances(int i); /*< returns the number of inst.    */
tspec_t tstat_gettotal(int i);    /*< returns the total exec time    */

#endif
