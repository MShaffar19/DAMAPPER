/*******************************************************************************************
 *
 *  Filter interface for the dazzler.
 *
 *  Author:  Gene Myers
 *  Date  :  July 2013
 *
 ********************************************************************************************/

#ifndef _FILTER

#define _FILTER

#include "DB.h"
#include "align.h"

extern int    BIASED;
extern int    VERBOSE;
extern int    PROFILE;
extern int    SPACING;
extern double BEST_TIE;

extern uint64 MEM_LIMIT;
extern uint64 MEM_PHYSICAL;

int Set_Filter_Params(int kmer, int suppress, int nthreads); 

void *Sort_Kmers(HITS_DB *block, int *len);

void Match_Filter(HITS_DB *ablock, HITS_DB *bblock,
                  void *atable, int alen, void *btable, int blen, int comp, int start);

#define FLAG_DOA    0x1
#define FLAG_DOB    0x2

void Reporter(char *aname, HITS_DB *ablock, char *bname, HITS_DB *bblock,
              Align_Spec *asettings, int mflag);

#endif
