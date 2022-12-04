/* -*- c++ -*- */
/*
 * Copyright 2018 Ron Economos.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_DVBS2RXX_BBDESCRAMBLER_BB_IMPL_H
#define INCLUDED_DVBS2RXX_BBDESCRAMBLER_BB_IMPL_H

#include "dvb_defines.h"
#include <dvbs2rxx/bbdescrambler_bb.h>

namespace gr {
  namespace dvbs2rxx {

    class bbdescrambler_bb_impl : public bbdescrambler_bb
    {
  private:
      unsigned int kbch;
      unsigned char bb_derandomise[FRAME_SIZE_NORMAL];
      void
      init_bb_derandomiser(void);

  public:
      bbdescrambler_bb_impl(dvb_standard_t standard,
                            dvb_framesize_t framesize,
                            dvb_code_rate_t rate);
      ~bbdescrambler_bb_impl();

      int
      work(int noutput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace dvbs2rxx
} // namespace gr

#endif /* INCLUDED_DVBS2RXX_BBDESCRAMBLER_BB_IMPL_H */
