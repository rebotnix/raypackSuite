/*
 * Copyright 1993-2011 NVIDIA Corporation.  All rights reserved.
   Copyright 2015-2016  G. Hilgemann, All rights resserved.

	This file is part of Raypack Suite 
|
|    Unless you have obtained under a difference license,
|    this modified version is Raypack Suite|GPL.
|    Raypack Suite|GPL is free software; you can redistribute it and/or modify
|    it under the terms of the GNU General Public License as published by
|    the Free Software Foundation; either version 2, or (at your option)
|    any later version.
|
|    Bento4|GPL is distributed in the hope that it will be useful,
|    but WITHOUT ANY WARRANTY; without even the implied warranty of
|    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
|    GNU General Public License for more details.
|
 */

#ifndef cuda_profiler_H
#define cuda_profiler_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Profiler Output Modes
 */
/*DEVICE_BUILTIN*/
typedef enum CUoutput_mode_enum
{
    CU_OUT_KEY_VALUE_PAIR  = 0x00, /**< Output mode Key-Value pair format. */
    CU_OUT_CSV             = 0x01  /**< Output mode Comma separated values format. */
}CUoutput_mode;


/**
 * \ingroup CUDA_DRIVER
 * \defgroup CUDA_PROFILER Profiler Control 
 *
 * This section describes the profiler control functions of the low-level CUDA
 * driver application programming interface.
 *
 * @{
 */

/**
 * \brief Initialize the profiling.
 *
 * Using this API user can initialize the CUDA profiler by specifying
 * the configuration file, output file and output file format. This
 * API is generally used to profile different set of counters by
 * looping the kernel launch. The \p configFile parameter can be used
 * to select profiling options including profiler counters. Refer to
 * the "Compute Command Line Profiler User Guide" for supported
 * profiler options and counters.
 *
 * Limitation: The CUDA profiler cannot be initialized with this API
 * if another profiling tool is already active, as indicated by the
 * ::CUDA_ERROR_PROFILER_DISABLED return code.
 *
 * Typical usage of the profiling APIs is as follows: 
 *
 * for each set of counters/options\n
 * {\n
 *     cuProfilerInitialize(); //Initialize profiling, set the counters or options in the config file \n
 *     ...\n
 *     cuProfilerStart(); \n
 *     // code to be profiled \n
 *     cuProfilerStop(); \n
 *     ...\n
 *     cuProfilerStart(); \n
 *     // code to be profiled \n
 *     cuProfilerStop(); \n
 *     ...\n
 * }\n
 *
 * \param configFile - Name of the config file that lists the counters/options
 * for profiling.
 * \param outputFile - Name of the outputFile where the profiling results will
 * be stored.
 * \param outputMode - outputMode, can be ::CU_OUT_KEY_VALUE_PAIR or ::CU_OUT_CSV.
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_INVALID_CONTEXT,
 * ::CUDA_ERROR_INVALID_VALUE,
 * ::CUDA_ERROR_PROFILER_DISABLED
 * \notefnerr
 *
 * \sa ::cuProfilerStart, ::cuProfilerStop
 */
CUresult CUDAAPI cuProfilerInitialize(const char *configFile, const char *outputFile, CUoutput_mode outputMode);

/**
 * \brief Enable profiling.
 *
 * Enables profile collection by the active profiling tool. If
 * profiling is already enabled, then cuProfilerStart() has no
 * effect.
 *
 * cuProfilerStart and cuProfilerStop APIs are used to
 * programmatically control the profiling granularity by allowing
 * profiling to be done only on selective pieces of code.
 * 
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_INVALID_CONTEXT
 * \notefnerr
 *
 * \sa ::cuProfilerInitialize, ::cuProfilerStop
 */
CUresult CUDAAPI cuProfilerStart(void);

/**
 * \brief Disable profiling.
 *
 * Disables profile collection by the active profiling tool. If
 * profiling is already disabled, then cuProfilerStop() has no
 * effect.
 *
 * cuProfilerStart and cuProfilerStop APIs are used to
 * programmatically control the profiling granularity by allowing
 * profiling to be done only on selective pieces of code.
 *
 * \return
 * ::CUDA_SUCCESS,
 * ::CUDA_ERROR_INVALID_CONTEXT
 * \notefnerr
 *
 * \sa ::cuProfilerInitialize, ::cuProfilerStart
 */
CUresult CUDAAPI cuProfilerStop(void);

/** @} */ /* END CUDA_PROFILER */

#ifdef __cplusplus
};
#endif

#endif

