/* -*- c++ -*- */
/*
 * Copyright 2018 Ahmet Inan, Ron Economos.
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


#ifndef INCLUDED_DVBS2RXX_LDPC_DECODER_CB_H
#define INCLUDED_DVBS2RXX_LDPC_DECODER_CB_H

#include <gnuradio/block.h>
#include <dvbs2rxx/api.h>
#include <dvbs2rxx/dvb_config.h>

namespace gr {
  namespace dvbs2rxx {

    /*!
     * \brief <+description of block+>
     * \ingroup dvbs2rxx
     *
     */
    class DVBS2RXX_API ldpc_decoder_cb : virtual public gr::block
    {
  public:
      typedef std::shared_ptr<ldpc_decoder_cb> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of dvbs2rxx::ldpc_decoder_cb.
       *
       * To avoid accidental use of raw pointers, dvbs2rxx::ldpc_decoder_cb's
       * constructor is in a private implementation
       * class. dvbs2rxx::ldpc_decoder_cb::make is the public interface for
       * creating new instances.
       */
      static sptr
      make(dvb_standard_t standard,
           dvb_framesize_t framesize,
           dvb_code_rate_t rate,
           dvb_constellation_t constellation,
           dvb_outputmode_t outputmode,
           dvb_infomode_t infomode);
    };

  } // namespace dvbs2rxx
} // namespace gr

#endif /* INCLUDED_DVBS2RXX_LDPC_DECODER_CB_H */
