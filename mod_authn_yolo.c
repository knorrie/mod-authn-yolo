/* Copyright 2018 Hans van Kranenburg <hans@knorrie.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mod_auth.h"
#include "ap_provider.h"
#include "http_request.h"

static authn_status authn_yolo(request_rec *r, const char* user,
			       const char* password)
{
	return AUTH_GRANTED;
}

static const authn_provider authn_yolo_provider =
{
	&authn_yolo,
	NULL
};

static void register_hooks(apr_pool_t *p)
{
	ap_register_auth_provider(p, AUTHN_PROVIDER_GROUP, "yolo",
				  AUTHN_PROVIDER_VERSION,
				  &authn_yolo_provider,
				  AP_AUTH_INTERNAL_PER_CONF);
}

module AP_MODULE_DECLARE_DATA authn_yolo_module =
{
	STANDARD20_MODULE_STUFF,
	NULL,		/* Per-directory configuration handler */
	NULL,		/* Merge handler for per-directory configurations */
	NULL,		/* Per-server configuration handler */
	NULL,		/* Merge handler for per-server configurations */
	NULL,		/* Any directives we may have for httpd */
	register_hooks	/* Our hook registering function */
};
