
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"



/**** BEGIN PROCEDURE _int_range ****/

errcode _int_range(ret_1, ret_2)
CLUREF *ret_1;
CLUREF *ret_2;
    {
    errcode err;
    errcode ecode2;
    enter_proc(2);

  LINE(5);
    {
    {
    ret_1->num = -1073741824;
    }
    {
    ret_2->num = 1073741823;
    }
    {signal (ERR_ok);}}
    goto end_0;
    ex_0:
        {
            if (err == ERR_failure) {signal(ERR_failure);}
            elist[0] = _pclu_erstr(err);
            {signal(ERR_failure);}
        }
    end_0: elist[0].str = no_return_values_STRING;
        {signal(ERR_failure);}
    }

/**** END PROCEDURE _int_range ****/

