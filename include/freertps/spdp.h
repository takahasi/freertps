#ifndef FREERTPS_SPDP_H
#define FREERTPS_SPDP_H

#include "freertps/id.h"
extern const fr_eid_t g_spdp_writer_id, g_spdp_reader_id;

void fr_spdp_init();
void fr_spdp_start();
void fr_spdp_tick();
void fr_spdp_fini();

void fr_spdp_bcast();

#endif
