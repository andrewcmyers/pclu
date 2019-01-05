
/* This file was automatically generated by pclu.*/

#include "pclu_err.h"
#include "pclu_sys.h"


extern errcode arrayOPnew();
extern errcode intOPfrom_to();
extern errcode intOPadd();
extern errcode stringOPsize();
extern errcode stringOPfetch();
extern errcode charOPequal();
extern errcode boolOPnot();
extern errcode arrayOPempty();
extern errcode arrayOPaddh();
extern errcode stringOPac2s();
extern errcode arrayOPtrim();
static int parse_line_own_init = 0;
CLUREF parse_lineOPaccum;

/**** BEGIN PROCEDURE parse_line ****/

errcode parse_line(s, ret_1)
CLUREF s;
CLUREF *ret_1;
    {
    errcode err;
    errcode ecode2;
    CLUREF parts;
    CLUREF pos;
    CLUREF c;
        if (parse_line_own_init == 0) {
        parse_line_own_init = 1;
        {
            {CLUREF T_0_1;
            err = arrayOPnew(&T_0_1);
            if (err != ERR_ok) goto ex_0;
            parse_lineOPaccum.num = T_0_1.num;
            }
            }
    }
    enter_proc(8);

  LINE(10);
    {
        {CLUREF T_1_1;
        err = arrayOPnew(&T_1_1);
        if (err != ERR_ok) goto ex_0;
        parts.num = T_1_1.num;
        }
        }

  LINE(11);
    {
    CLUREF T_1_1;
    CLUREF T_1_2;
    CLUREF T_1_3;
    CLUREF T_1_4;
        err = stringOPsize(s, &T_1_1);
        if (err != ERR_ok) goto ex_0;
        T_1_2.num = T_1_1.num + 1;
         if ((T_1_2.num > 0 && T_1_1.num < 0 && 1 < 0) || 
             (T_1_2.num < 0 && T_1_1.num > 0 && 1 > 0)) {
            err = ERR_overflow;
            goto ex_0;}
        T_1_4.num = T_1_2.num;
        for (T_1_3.num = 1; T_1_3.num <= T_1_4.num; T_1_3.num++) {
            pos.num = T_1_3.num;

  LINE(12);
            {
                {CLUREF T_3_1;
                err = stringOPfetch(s, pos, &T_3_1);
                if (err != ERR_ok) goto ex_1;
                c.num = T_3_1.num;
                }
                }
                goto end_1;
                ex_1:
                    if ((err == ERR_bounds)) {

  LINE(13);
                        {
                        CLUREF T_3_1;
                        T_3_1.ch = ' ';
                        c.num = T_3_1.num;
                        }
                    }
                    else {
                        goto ex_0;
                    }
                end_1:;

  LINE(14);
            {
            CLUREF T_2_1;
            CLUREF T_2_2;
            CLUREF T_2_3;
            CLUREF T_2_4;
            CLUREF T_2_5;
            CLUREF T_2_6;
            CLUREF T_2_7;
            CLUREF T_2_8;
            T_2_3.ch = ' ';
            T_2_4.num = (c.ch == T_2_3.ch)? true : false;
            T_2_2.num = T_2_4.num;
            if (!T_2_4.num) {
                T_2_5.ch = '\t';
                T_2_6.num = (c.ch == T_2_5.ch)? true : false;
                T_2_2.num = T_2_6.num;
            }
            T_2_1.num = T_2_2.num;
            if (!T_2_2.num) {
                T_2_7.ch = ',';
                T_2_8.num = (c.ch == T_2_7.ch)? true : false;
                T_2_1.num = T_2_8.num;
            }
            if (T_2_1.num == true) {

  LINE(15);
                {
                CLUREF T_3_1;
                CLUREF T_3_2;
                T_3_1.num = (parse_lineOPaccum.array->ext_size == 0)? true : false;
                T_3_2.num = T_3_1.num ^ 1;
                if (T_3_2.num == true) {

  LINE(16);
                    {
                    CLUREF T_4_1;
                    err = stringOPac2s(parse_lineOPaccum, &T_4_1);
                    if (err != ERR_ok) goto ex_0;
                    {
                    if ((parts.array->int_low + parts.array->ext_size + 1) < parts.array->int_size) {
                        parts.array->store->data[parts.array->int_low + parts.array->ext_size] = T_4_1.num;
                        parts.array->ext_size++; parts.array->ext_high++;}
                    else {
                        err = arrayOPaddh(parts, T_4_1);
                        if (err != ERR_ok) goto ex_0;}
                    }
                    }

  LINE(17);
                    {
                    err = arrayOPtrim(parse_lineOPaccum, CLU_1, CLU_0);
                    if (err != ERR_ok) goto ex_0;
                    }
                    }
                    }/* end if */
                }
            else {

  LINE(19);
                {
                {
                if ((parse_lineOPaccum.array->int_low + parse_lineOPaccum.array->ext_size + 1) < parse_lineOPaccum.array->int_size) {
                    parse_lineOPaccum.array->store->data[parse_lineOPaccum.array->int_low + parse_lineOPaccum.array->ext_size] = c.num;
                    parse_lineOPaccum.array->ext_size++; parse_lineOPaccum.array->ext_high++;}
                else {
                    err = arrayOPaddh(parse_lineOPaccum, c);
                    if (err != ERR_ok) goto ex_0;}
                }
                }
                }}/* end if */
        }
    }
    end_inline_for_1:;

  LINE(22);
    {
    {
    ret_1->num = parts.num;
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

/**** END PROCEDURE parse_line ****/

