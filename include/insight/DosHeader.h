#pragma once

#include "insight_export.h"
#include <cstdint>

#pragma pack(push,1)
struct INSIGHT_EXPORT DosHeader {
  char signature[2];
  int16_t lastsize;
  int16_t nblocks;
  int16_t nreloc;
  int16_t hdrsize;
  int16_t minalloc;
  int16_t maxalloc;
  uint16_t ss;
  uint16_t sp;
  int16_t checksum;
  uint16_t ip;
  uint16_t cs;
  int16_t relocpos;
  int16_t nooverlay;
  int16_t reserved1[4];
  int16_t oem_id;
  int16_t oem_info;
  int16_t reserved2[10];
  uint32_t e_lfanew;
};
#pragma pack(pop)