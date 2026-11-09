/* FTDX10 CAT association helper regression test; hardware not required. */
#include <assert.h>
#include "../rigs/yaesu/ftdx10_cat_reply.h"

int main(void)
{
    assert(ftdx10_cat_query_reply_matches("RF0;", "RF06;"));
    assert(ftdx10_cat_query_reply_matches("CO00;", "CO000001;"));
    assert(ftdx10_cat_query_reply_matches("CO01;", "CO010800;"));
    assert(ftdx10_cat_query_reply_matches("EX030202;", "EX030202-12;"));
    assert(ftdx10_cat_query_reply_matches("EX030203;", "EX03020305;"));
    assert(ftdx10_cat_query_reply_matches("EX010415;", "EX0104151;"));
    assert(!ftdx10_cat_query_reply_matches("EX010415;", "EX0104181;"));
    assert(!ftdx10_cat_query_reply_matches("EX030202;", "EX03020305;"));
    assert(!ftdx10_cat_query_reply_matches("CO00;", "CO010800;"));
    assert(!ftdx10_cat_query_reply_matches("RF0;", "FA014074000;"));
    assert(!ftdx10_cat_query_reply_matches("EX030202;", "EX030202-12"));
    assert(!ftdx10_cat_query_reply_matches("EX030202;", "EX030202-12;EX030202-12;"));
    assert(!ftdx10_cat_query_reply_matches("EX030202;", "EX030202;"));
    assert(!ftdx10_cat_query_reply_matches("EX030202;", "FA014074000;"));
    assert(!ftdx10_cat_query_reply_matches(NULL, "RF06;"));
    assert(!ftdx10_cat_query_reply_matches("RF0;", NULL));
    return 0;
}
