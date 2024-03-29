// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef JOTOCOIN_JOTOCOINCONSENSUS_H
#define JOTOCOIN_JOTOCOINCONSENSUS_H

#if defined(BUILD_JOTOCOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/jotocoin-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBJOTOCOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define JOTOCOINCONSENSUS_API_VER 0

typedef enum jotocoinconsensus_error_t
{
    jotocoinconsensus_ERR_OK = 0,
    jotocoinconsensus_ERR_TX_INDEX,
    jotocoinconsensus_ERR_TX_SIZE_MISMATCH,
    jotocoinconsensus_ERR_TX_DESERIALIZE,
} jotocoinconsensus_error;

/** Script verification flags */
enum
{
    jotocoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    jotocoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    jotocoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    jotocoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not NULL, err will contain an error/success code for the operation
EXPORT_SYMBOL int jotocoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, jotocoinconsensus_error* err);

EXPORT_SYMBOL unsigned int jotocoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // JOTOCOIN_JOTOCOINCONSENSUS_H
