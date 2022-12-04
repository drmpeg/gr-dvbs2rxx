# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT dvbs2rxx_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT dvbs2rxx_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND dvbs2rxx_python_files
    bbdeheader_bb_python.cc
    bbdescrambler_bb_python.cc
    bch_decoder_bb_python.cc
    ldpc_decoder_cb_python.cc
    dvb_config_python.cc
    dvbs2_config_python.cc
    dvbt2_config_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(dvbs2rxx
   ../..
   gr::dvbs2rxx
   "${dvbs2rxx_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(TARGET dvbs2rxx_python POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dvbs2rxx_python>
    ${CMAKE_BINARY_DIR}/test_modules/dvbs2rxx/
)

install(TARGETS dvbs2rxx_python DESTINATION ${GR_PYTHON_DIR}/dvbs2rxx COMPONENT pythonapi)
