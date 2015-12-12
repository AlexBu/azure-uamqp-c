// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdlib.h>
#ifdef _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
#include <string.h>
#include "sasl_mssbcbs.h"
#include "amqpalloc.h"

typedef struct SASL_MSSBCBS_INSTANCE_TAG
{
	unsigned char dummy : 1;
} SASL_MSSBCBS_INSTANCE;

static const SASL_MECHANISM_INTERFACE_DESCRIPTION saslmssbcbs_interface =
{
	saslmssbcbs_create,
	saslmssbcbs_destroy,
	saslmssbcbs_get_init_bytes,
	saslmssbcbs_get_mechanism_name,
	saslmssbcbs_challenge
};

CONCRETE_SASL_MECHANISM_HANDLE saslmssbcbs_create(void* config)
{
	return amqpalloc_malloc(sizeof(SASL_MSSBCBS_INSTANCE));
}

void saslmssbcbs_destroy(CONCRETE_SASL_MECHANISM_HANDLE sasl_mechanism_concrete_handle)
{
	if (sasl_mechanism_concrete_handle != NULL)
	{
		amqpalloc_free(sasl_mechanism_concrete_handle);
	}
}

int saslmssbcbs_get_init_bytes(CONCRETE_SASL_MECHANISM_HANDLE sasl_mechanism_concrete_handle, SASL_MECHANISM_BYTES* init_bytes)
{
	int result;

	if (sasl_mechanism_concrete_handle == NULL)
	{
		result = __LINE__;
	}
	else
	{
		init_bytes->bytes = NULL;
		init_bytes->length = 0;

		result = 0;
	}

	return result;
}

const char* saslmssbcbs_get_mechanism_name(CONCRETE_SASL_MECHANISM_HANDLE sasl_mechanism)
{
	const char* result;

	if (sasl_mechanism == NULL)
	{
		result = NULL;
	}
	else
	{
		result = "MSSBCBS";
	}

	return result;
}

int saslmssbcbs_challenge(CONCRETE_SASL_MECHANISM_HANDLE concrete_sasl_mechanism, const SASL_MECHANISM_BYTES* challenge_bytes, SASL_MECHANISM_BYTES* response_bytes)
{
	return 0;
}

const SASL_MECHANISM_INTERFACE_DESCRIPTION* saslmssbcbs_get_interface(void)
{
	return &saslmssbcbs_interface;
}
