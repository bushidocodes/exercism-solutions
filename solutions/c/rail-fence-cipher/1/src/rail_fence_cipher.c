#include <assert.h>
#include <stdbool.h>
#include <stdio.h> /* temp */
#include <stdlib.h>
#include <string.h>

#include "rail_fence_cipher.h"

char *encode(char *text, size_t rails)
{
    assert(text != NULL);
    assert(rails > 0);

    size_t text_len = strlen(text);
    char *ciphertext = calloc(text_len + 1, sizeof(char));
    size_t ciphertext_idx = 0;

    if (text_len == 0 || rails == 1 || text_len < rails)
    {
        strncpy(ciphertext, text, text_len);
        return ciphertext;
    }

    /* 
     * Every rail has a total "gap" of 2(rails - 1) chars
     * This "gap" is split between ascending and descending parts
     * But top or bottom rows are missing one of these parts
     * 
     * Additionally, the initial "gap" starts at 0 and increments by 1
     * i.e. 4 rails => 2(4 - 1) => 6
     * 
     * 0 => c => 6 => c => 6 => c
     * 1 => c => 4 => c => 2 => c
     * 2 => c => 2 => c => 4 => c
     * 3 => c => 6 => c => 6 => c
    */
    int total_gap = 2 * (rails - 1);
    int start_pos = 0;

    for (int desc_gap = total_gap; desc_gap >= 0; desc_gap -= 2)
    {
        int asc_gap = total_gap - desc_gap;

        size_t src = start_pos++;
        bool is_desc = true;
        while (src < text_len)
        {
            ciphertext[ciphertext_idx++] = text[src];
            if (desc_gap == 0) /* Top rail */
            {
                src += asc_gap;
                is_desc = false;
            }
            else if (asc_gap == 0) /* Bottom rail */
            {
                src += desc_gap;
                is_desc = true;
            }
            else /* Intermediate rails */
            {
                src += is_desc ? desc_gap : asc_gap;
                is_desc = !is_desc;
            }
        }
    }

    return ciphertext;
}

char *decode(char *ciphertext, size_t rails)
{
    assert(ciphertext != NULL);
    assert(rails > 0);

    const size_t ciphertext_len = strlen(ciphertext);
    char *text = calloc(ciphertext_len + 1, sizeof(char));

    if (ciphertext_len == 0 || rails == 1)
    {
        strncpy(text, ciphertext, ciphertext_len);
        return text;
    }

    /* Calculate the Length of each Rail */
    size_t rail_len[rails];
    for (size_t current_rail = 0; current_rail < rails; current_rail++)
    {
        rail_len[current_rail] = 0;
    }

    for (size_t i = 0; i < ciphertext_len;)
    {
        for (size_t current_rail = 0; current_rail < rails && i < ciphertext_len; current_rail++, i++)
        {
            rail_len[current_rail]++;
        }
        for (size_t current_rail = rails - 2; current_rail > 0 && i < ciphertext_len; current_rail--, i++)
        {
            rail_len[current_rail]++;
        }
    }

    /* Calculate the start idx of each rail */
    size_t rail_start[rails];
    rail_start[0] = 0;

    for (size_t i = 1; i < rails; i++)
    {
        rail_start[i] = rail_start[i - 1] + rail_len[i - 1];
    }

    /* Track the idx within each rail */
    size_t rail_idx[rails];
    for (size_t i = 0; i < rails; i++)
    {
        rail_idx[i] = 0;
    }

    /* "Ping pong" through the rails, reassembling the message */
    size_t i = 0;
    while (i < ciphertext_len)
    {
        for (size_t current_rail = 0; current_rail < rails && i < ciphertext_len; current_rail++, i++)
        {
            size_t src_idx = rail_start[current_rail] + rail_idx[current_rail]++;
            text[i] = ciphertext[src_idx];
        }
        for (size_t current_rail = rails - 2; current_rail > 0 && i < ciphertext_len; current_rail--, i++)
        {
            size_t src_idx = rail_start[current_rail] + rail_idx[current_rail]++;
            text[i] = ciphertext[src_idx];
        }
    }
    text[i++] = '\0';

    return text;
}
