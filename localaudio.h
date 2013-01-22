/**
 * @file localaudio.h
 *
 * @brief Routines for recording and playing sounds on the local host.
 */
#ifndef LOCALAUDIO_H
#define LOCALAUDIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <portaudio.h>

typedef int LaError_t;

enum LA_ERRORCODE {
  LA_OK = 0,
  LA_ERROR
};

enum LA_RECORDTYPE {
  LA_REC_ONCE = 0,  /**< Record until buffer is full then stop. */
  LA_REC_CONT       /**< Record continuously. */
};

LaError_t  LA_init();
LaError_t  LA_terminate();
void       LA_print_last_error(FILE* const stream);

int        LA_is_recording(void);
void       LA_stop_recording();
LaError_t  LA_record(void* const buffer, const unsigned long bufsize, const unsigned samprate, int rectype);

int        LA_is_playing(void);
LaError_t  LA_play(const void* const buffer, const unsigned long bufsize, const unsigned samprate);


#endif
