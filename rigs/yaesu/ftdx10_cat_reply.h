/*
 * Yaesu FTDX10 command/response association guard.
 *
 * Query responses have no transaction sequence number. For EX menu slots,
 * Contour CO subcommands and Roofing RF selectors, the first two characters
 * are insufficient: an old reply from a different slot has the same prefix.
 *
 * This rejects wrong-slot, malformed and partial replies in the native CAT
 * parser. A delayed response with an *identical* complete prefix cannot be
 * distinguished from a current response without a device transaction ID.
 */
#ifndef HAMLIB_FTDX10_CAT_REPLY_H
#define HAMLIB_FTDX10_CAT_REPLY_H

#include <stddef.h>
#include <string.h>

static inline int ftdx10_cat_query_reply_matches(const char *query, const char *reply)
{
    size_t query_length, reply_length, discriminator_length;
    if (!query || !reply) return 0;
    query_length = strlen(query);
    reply_length = strlen(reply);
    if (query_length < 3 || reply_length <= query_length
        || query[query_length - 1] != ';'
        || reply[reply_length - 1] != ';') return 0;

    discriminator_length = 2;
    if (strncmp(query, "EX", 2) == 0 || strncmp(query, "CO", 2) == 0
        || strncmp(query, "RF", 2) == 0) {
        discriminator_length = query_length - 1;
    }
    return strncmp(reply, query, discriminator_length) == 0;
}

#endif /* HAMLIB_FTDX10_CAT_REPLY_H */
