/*
 * Copyright 2022 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OSSL_INTERNAL_AUDIT_H
# define OSSL_INTERNAL_AUDIT_H
# pragma once

# define AUDIT_CONTEXT_SIZE (8)

# include <sys/sdt.h>

# define AUDIT_PUSH_CONTEXT(context_ptr, parent_ptr) \
	DTRACE_PROBE3(audit, push_context, context_ptr, parent_ptr, AUDIT_CONTEXT_SIZE)
# define AUDIT_POP_CONTEXT(context_ptr) \
	DTRACE_PROBE2(audit, pop_context, context_ptr, AUDIT_CONTEXT_SIZE)
# define AUDIT_WORD_DATA(context_ptr, key_ptr, value_ptr) \
	DTRACE_PROBE3(audit, word_data, context_ptr, key_ptr, value_ptr)
# define AUDIT_STRING_DATA(context_ptr, key_ptr, value_ptr) \
	DTRACE_PROBE3(audit, string_data, context_ptr, key_ptr, value_ptr)
# define AUDIT_BLOB_DATA(key_ptr, context_ptr, value_ptr, value_size) \
	DTRACE_PROBE4(audit, blob_data, context_ptr, key_ptr, value_ptr, value_size)

#endif /* !defined(OSSL_INTERNAL_AUDIT_H) */
