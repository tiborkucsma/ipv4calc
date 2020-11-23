#include "ipv4utils.h"

#include "ipv4types.h"
#include "ipv4math.h"

#include <stdlib.h>
#include <inttypes.h>

int ipv4_subnet(subnet_list_t *sl, subnet_list_create_info_t *create_info)
{
    sl->data = NULL;
    sl->n_sn = 0;

    uint32_t subnet_mask_n_bits;
    
    if (create_info->n_subnets && !create_info->n_hosts)
    {
        uint32_t n_sn_bits = 0;
        for (uint32_t i = 1; i < create_info->n_subnets && n_sn_bits < 32; i *= 2, n_sn_bits++);

        subnet_mask_n_bits = ipv4_mask_bits(create_info->st_mask) + n_sn_bits;
        if (subnet_mask_n_bits > 30)
        {
            return subnet_mask_n_bits;
        }
    } else if (!create_info->n_subnets && create_info->n_hosts)
    {
        uint32_t n_host_bits = 0;
        for (uint32_t i = 1; i < (create_info->n_hosts + 2) && n_host_bits < 32; i *= 2, n_host_bits++);

        subnet_mask_n_bits = 32 - n_host_bits;
        if (subnet_mask_n_bits < ipv4_mask_bits(create_info->st_mask))
        {
            return subnet_mask_n_bits;
        }
    } else
    {
        return 1;
    }
    
    ipv4_addr_t st_addr = create_info->st_addr & create_info->st_mask;
    ipv4_mask_t st_mask = ipv4_mask_generate(subnet_mask_n_bits);

    sl->data = (subnet_t *) malloc(sizeof(subnet_t) * create_info->n_subnets_to_include);
    sl->n_sn = create_info->n_subnets_to_include;
    for (uint32_t i = 0; i < create_info->n_subnets_to_include; i++)
    {
        ipv4_addr_t csn_addr = st_addr | (i << (32 - subnet_mask_n_bits));
        sl->data[i].addr = csn_addr;
        sl->data[i].mask = st_mask;
    }

    return 0;
}

void ipv4_destroy_subnet_list(subnet_list_t *sl)
{
    if (sl->data != NULL)
    {
        free(sl->data);
        sl->data = NULL;
        sl->n_sn = 0;
    }
}
