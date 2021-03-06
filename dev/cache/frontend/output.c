
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Cache_Frontend_Output
 *
 * Allows to cache output fragments using a file backend
 *
 */

/**
 * Phalcon_Cache_Frontend_Output constructor
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, __construct){

	zval *a0 = NULL;
	zval *v0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_cache_frontend_output_class_entry, this_ptr, "_frontendOptions", strlen("_frontendOptions"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_frontendOptions", strlen("_frontendOptions"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns cache lifetime
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getLifetime){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_frontendOptions", sizeof("_frontendOptions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v0, t0);
	eval_int = phalcon_array_isset_string(v0, "lifetime", strlen("lifetime")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v0, "lifetime", strlen("lifetime"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Starts output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, start){


	PHALCON_MM_GROW();
	PHALCON_CALL_FUNC_NORETURN("ob_start", 0x011);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getContent){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "ob_get_contents", 0x012);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, stop){


	PHALCON_MM_GROW();
	PHALCON_CALL_FUNC_NORETURN("ob_end_clean", 0x014);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

