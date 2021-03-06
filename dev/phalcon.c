
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

zend_class_entry *phalcon_dispatcher_class_entry;
zend_class_entry *phalcon_acl_class_entry;
zend_class_entry *phalcon_response_class_entry;
zend_class_entry *phalcon_request_class_entry;
zend_class_entry *phalcon_paginator_adapter_array_class_entry;
zend_class_entry *phalcon_paginator_adapter_model_class_entry;
zend_class_entry *phalcon_paginator_exception_class_entry;
zend_class_entry *phalcon_cache_class_entry;
zend_class_entry *phalcon_controller_front_class_entry;
zend_class_entry *phalcon_session_namespace_class_entry;
zend_class_entry *phalcon_view_class_entry;
zend_class_entry *phalcon_cache_frontend_output_class_entry;
zend_class_entry *phalcon_cache_backend_file_class_entry;
zend_class_entry *phalcon_cache_exception_class_entry;
zend_class_entry *phalcon_test_class_entry;
zend_class_entry *phalcon_utils_class_entry;
zend_class_entry *phalcon_db_class_entry;
zend_class_entry *phalcon_internal_test_class_entry;
zend_class_entry *phalcon_internal_testtemp_class_entry;
zend_class_entry *phalcon_internal_testdummy_class_entry;
zend_class_entry *phalcon_internal_testparent_class_entry;
zend_class_entry *phalcon_acl_adapter_memory_class_entry;
zend_class_entry *phalcon_acl_role_class_entry;
zend_class_entry *phalcon_acl_exception_class_entry;
zend_class_entry *phalcon_acl_resource_class_entry;
zend_class_entry *phalcon_tag_exception_class_entry;
zend_class_entry *phalcon_router_rewrite_class_entry;
zend_class_entry *phalcon_db_profiler_class_entry;
zend_class_entry *phalcon_db_adapter_mysql_class_entry;
zend_class_entry *phalcon_db_index_class_entry;
zend_class_entry *phalcon_db_reference_class_entry;
zend_class_entry *phalcon_db_profiler_item_class_entry;
zend_class_entry *phalcon_db_exception_class_entry;
zend_class_entry *phalcon_db_column_class_entry;
zend_class_entry *phalcon_db_pool_class_entry;
zend_class_entry *phalcon_db_dialect_mysql_class_entry;
zend_class_entry *phalcon_db_rawvalue_class_entry;
zend_class_entry *phalcon_flash_class_entry;
zend_class_entry *phalcon_paginator_class_entry;
zend_class_entry *phalcon_logger_class_entry;
zend_class_entry *phalcon_config_class_entry;
zend_class_entry *phalcon_filter_class_entry;
zend_class_entry *phalcon_loader_class_entry;
zend_class_entry *phalcon_exception_class_entry;
zend_class_entry *phalcon_logger_adapter_file_class_entry;
zend_class_entry *phalcon_logger_item_class_entry;
zend_class_entry *phalcon_logger_exception_class_entry;
zend_class_entry *phalcon_transaction_class_entry;
zend_class_entry *phalcon_transaction_failed_class_entry;
zend_class_entry *phalcon_transaction_manager_class_entry;
zend_class_entry *phalcon_session_class_entry;
zend_class_entry *phalcon_config_adapter_ini_class_entry;
zend_class_entry *phalcon_config_exception_class_entry;
zend_class_entry *phalcon_controller_class_entry;
zend_class_entry *phalcon_model_message_class_entry;
zend_class_entry *phalcon_model_manager_class_entry;
zend_class_entry *phalcon_model_metadata_class_entry;
zend_class_entry *phalcon_model_validator_class_entry;
zend_class_entry *phalcon_model_row_class_entry;
zend_class_entry *phalcon_model_base_class_entry;
zend_class_entry *phalcon_model_validator_uniqueness_class_entry;
zend_class_entry *phalcon_model_validator_regex_class_entry;
zend_class_entry *phalcon_model_validator_inclusionin_class_entry;
zend_class_entry *phalcon_model_validator_exclusionin_class_entry;
zend_class_entry *phalcon_model_validator_numericality_class_entry;
zend_class_entry *phalcon_model_validator_email_class_entry;
zend_class_entry *phalcon_model_metadata_memory_class_entry;
zend_class_entry *phalcon_model_resultset_class_entry;
zend_class_entry *phalcon_model_sanitize_class_entry;
zend_class_entry *phalcon_model_exception_class_entry;
zend_class_entry *phalcon_model_query_class_entry;
zend_class_entry *phalcon_view_exception_class_entry;
zend_class_entry *phalcon_tag_class_entry;

ZEND_DECLARE_MODULE_GLOBALS(phalcon)

PHP_MINIT_FUNCTION(phalcon){

	zend_class_entry ce00, ce01, ce02, ce03, ce04, ce05, ce06, ce07, ce08, ce09;
	zend_class_entry ce10, ce11, ce12, ce13, ce14, ce15, ce16, ce17, ce18, ce19;
	zend_class_entry ce20, ce21, ce22, ce23, ce24, ce25, ce26, ce27, ce28, ce29;
	zend_class_entry ce30, ce31, ce32, ce33, ce34, ce35, ce36, ce37, ce38, ce39;
	zend_class_entry ce40, ce41, ce42, ce43, ce44, ce45, ce46, ce47, ce48, ce49;
	zend_class_entry ce50, ce51, ce52, ce53, ce54, ce55, ce56, ce57, ce58, ce59;
	zend_class_entry ce60, ce61, ce62, ce63, ce64, ce65, ce66, ce67, ce68, ce69;
	zend_class_entry ce70, ce71, ce72, ce73, ce74, ce75, ce76;


	if(!zend_ce_iterator){
		fprintf(stderr, "Phalcon Error: Interface Iterator was not found");
		return FAILURE;
	}
	if(!spl_ce_SeekableIterator){
		fprintf(stderr, "Phalcon Error: Interface SeekableIterator was not found");
		return FAILURE;
	}
	if(!spl_ce_Countable){
		fprintf(stderr, "Phalcon Error: Interface Countable was not found");
		return FAILURE;
	}

	/** Init globals */
	ZEND_INIT_MODULE_GLOBALS(phalcon, php_phalcon_init_globals, NULL);

	INIT_CLASS_ENTRY(ce00, "Phalcon_Dispatcher", phalcon_dispatcher_functions);
	phalcon_dispatcher_class_entry = zend_register_internal_class(&ce00 TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_finished", sizeof("_finished")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_controllers", sizeof("_controllers")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_controllersDir", sizeof("_controllersDir")-1, "", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_basePath", sizeof("_basePath")-1, "", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_controllerName", sizeof("_controllerName")-1, "", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_actionName", sizeof("_actionName")-1, "", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_params", sizeof("_params")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_returnedValue", sizeof("_returnedValue")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_dispatcher_class_entry, "_lastController", sizeof("_lastController")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_defaultController", sizeof("_defaultController")-1, "index", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_dispatcher_class_entry, "_defaultAction", sizeof("_defaultAction")-1, "index", ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce01, "Phalcon_Acl", phalcon_acl_functions);
	phalcon_acl_class_entry = zend_register_internal_class(&ce01 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_class_entry, "_adapter", sizeof("_adapter")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_class_entry, "ALLOW", sizeof("ALLOW")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_acl_class_entry, "DENY", sizeof("DENY")-1, 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce02, "Phalcon_Response", phalcon_response_functions);
	phalcon_response_class_entry = zend_register_internal_class(&ce02 TSRMLS_CC);
	zend_declare_property_null(phalcon_response_class_entry, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_response_class_entry, "_content", sizeof("_content")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce03, "Phalcon_Request", phalcon_request_functions);
	phalcon_request_class_entry = zend_register_internal_class(&ce03 TSRMLS_CC);
	zend_declare_property_null(phalcon_request_class_entry, "_filter", sizeof("_filter")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_request_class_entry, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce04, "Phalcon_Paginator_Adapter_Array", phalcon_paginator_adapter_array_functions);
	phalcon_paginator_adapter_array_class_entry = zend_register_internal_class(&ce04 TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_class_entry, "_limitRows", sizeof("_limitRows")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_class_entry, "_config", sizeof("_config")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_array_class_entry, "_page", sizeof("_page")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce05, "Phalcon_Paginator_Adapter_Model", phalcon_paginator_adapter_model_functions);
	phalcon_paginator_adapter_model_class_entry = zend_register_internal_class(&ce05 TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_class_entry, "_limitRows", sizeof("_limitRows")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_class_entry, "_config", sizeof("_config")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_class_entry, "_page", sizeof("_page")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce06, "Phalcon_Cache", phalcon_cache_functions);
	phalcon_cache_class_entry = zend_register_internal_class(&ce06 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce07, "Phalcon_Controller_Front", phalcon_controller_front_functions);
	phalcon_controller_front_class_entry = zend_register_internal_class(&ce07 TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_instance", sizeof("_instance")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_controllersDir", sizeof("_controllersDir")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_modelsDir", sizeof("_modelsDir")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_viewsDir", sizeof("_viewsDir")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_basePath", sizeof("_basePath")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_baseUri", sizeof("_baseUri")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_dispatcher", sizeof("_dispatcher")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_model", sizeof("_model")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_view", sizeof("_view")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_request", sizeof("_request")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_front_class_entry, "_response", sizeof("_response")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce08, "Phalcon_Session_Namespace", phalcon_session_namespace_functions);
	phalcon_session_namespace_class_entry = zend_register_internal_class(&ce08 TSRMLS_CC);
	zend_declare_property_null(phalcon_session_namespace_class_entry, "_name", sizeof("_name")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_namespace_class_entry, "_data", sizeof("_data")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce09, "Phalcon_View", phalcon_view_functions);
	phalcon_view_class_entry = zend_register_internal_class(&ce09 TSRMLS_CC);
	zend_declare_property_string(phalcon_view_class_entry, "_content", sizeof("_content")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_view_class_entry, "_renderLevel", sizeof("_renderLevel")-1, 5, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_params", sizeof("_params")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_view_class_entry, "_layoutsDir", sizeof("_layoutsDir")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_templatesBefore", sizeof("_templatesBefore")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_templatesAfter", sizeof("_templatesAfter")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_controllerName", sizeof("_controllerName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_view_class_entry, "_actionName", sizeof("_actionName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_MAIN_LAYOUT", sizeof("LEVEL_MAIN_LAYOUT")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_AFTER_TEMPLATE", sizeof("LEVEL_AFTER_TEMPLATE")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_LAYOUT", sizeof("LEVEL_LAYOUT")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_BEFORE_TEMPLATE", sizeof("LEVEL_BEFORE_TEMPLATE")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_ACTION_VIEW", sizeof("LEVEL_ACTION_VIEW")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_view_class_entry, "LEVEL_NO_RENDER", sizeof("LEVEL_NO_RENDER")-1, 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce10, "Phalcon_Cache_Frontend_Output", phalcon_cache_frontend_output_functions);
	phalcon_cache_frontend_output_class_entry = zend_register_internal_class(&ce10 TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_frontend_output_class_entry, "_frontendOptions", sizeof("_frontendOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce11, "Phalcon_Cache_Backend_File", phalcon_cache_backend_file_functions);
	phalcon_cache_backend_file_class_entry = zend_register_internal_class(&ce11 TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_file_class_entry, "_frontendObject", sizeof("_frontendObject")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_cache_backend_file_class_entry, "_backendOptions", sizeof("_backendOptions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_cache_backend_file_class_entry, "_lastKey", sizeof("_lastKey")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce12, "Phalcon_Test", phalcon_test_functions);
	phalcon_test_class_entry = zend_register_internal_class(&ce12 TSRMLS_CC);
	zend_declare_property_null(phalcon_test_class_entry, "p", sizeof("p")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce13, "Phalcon_Utils", phalcon_utils_functions);
	phalcon_utils_class_entry = zend_register_internal_class(&ce13 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce14, "Phalcon_Db", phalcon_db_functions);
	phalcon_db_class_entry = zend_register_internal_class(&ce14 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_descriptor", sizeof("_descriptor")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_fetchMode", sizeof("_fetchMode")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_autoCommit", sizeof("_autoCommit")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_idConnection", sizeof("_idConnection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_underTransaction", sizeof("_underTransaction")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_logger", sizeof("_logger")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_profiler", sizeof("_profiler")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_ASSOC", sizeof("DB_ASSOC")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_BOTH", sizeof("DB_BOTH")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_NUM", sizeof("DB_NUM")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce15, "Phalcon_Internal_TestTemp", phalcon_internal_testtemp_functions);
	phalcon_internal_testtemp_class_entry = zend_register_internal_class(&ce15 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce16, "Phalcon_Internal_TestDummy", phalcon_internal_testdummy_functions);
	phalcon_internal_testdummy_class_entry = zend_register_internal_class(&ce16 TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_testdummy_class_entry, "_d1", sizeof("_d1")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce17, "Phalcon_Internal_TestParent", phalcon_internal_testparent_functions);
	phalcon_internal_testparent_class_entry = zend_register_internal_class(&ce17 TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_testparent_class_entry, "_pp0", sizeof("_pp0")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce18, "Phalcon_Acl_Adapter_Memory", phalcon_acl_adapter_memory_functions);
	phalcon_acl_adapter_memory_class_entry = zend_register_internal_class(&ce18 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_rolesNames", sizeof("_rolesNames")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_roles", sizeof("_roles")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_resources", sizeof("_resources")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_access", sizeof("_access")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_roleInherits", sizeof("_roleInherits")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_resourcesNames", sizeof("_resourcesNames")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_class_entry, "_accessList", sizeof("_accessList")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_acl_adapter_memory_class_entry, "_defaultAccess", sizeof("_defaultAccess")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce19, "Phalcon_Acl_Role", phalcon_acl_role_functions);
	phalcon_acl_role_class_entry = zend_register_internal_class(&ce19 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_role_class_entry, "_name", sizeof("_name")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_role_class_entry, "_description", sizeof("_description")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce20, "Phalcon_Acl_Resource", phalcon_acl_resource_functions);
	phalcon_acl_resource_class_entry = zend_register_internal_class(&ce20 TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_resource_class_entry, "_name", sizeof("_name")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_resource_class_entry, "_description", sizeof("_description")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce21, "Phalcon_Router_Rewrite", phalcon_router_rewrite_functions);
	phalcon_router_rewrite_class_entry = zend_register_internal_class(&ce21 TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_controller", sizeof("_controller")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_action", sizeof("_action")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_params", sizeof("_params")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_router_rewrite_class_entry, "_baseUri", sizeof("_baseUri")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce22, "Phalcon_Db_Profiler", phalcon_db_profiler_functions);
	phalcon_db_profiler_class_entry = zend_register_internal_class(&ce22 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_class_entry, "_allProfiles", sizeof("_allProfiles")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_class_entry, "_activeProfile", sizeof("_activeProfile")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_profiler_class_entry, "_totalSeconds", sizeof("_totalSeconds")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce23, "Phalcon_Db_Index", phalcon_db_index_functions);
	phalcon_db_index_class_entry = zend_register_internal_class(&ce23 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_index_class_entry, "_indexName", sizeof("_indexName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce24, "Phalcon_Db_Reference", phalcon_db_reference_functions);
	phalcon_db_reference_class_entry = zend_register_internal_class(&ce24 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_class_entry, "_referenceName", sizeof("_referenceName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_class_entry, "_referencedTable", sizeof("_referencedTable")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_class_entry, "_columns", sizeof("_columns")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_class_entry, "_referencedColumns", sizeof("_referencedColumns")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce25, "Phalcon_Db_Profiler_Item", phalcon_db_profiler_item_functions);
	phalcon_db_profiler_item_class_entry = zend_register_internal_class(&ce25 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_class_entry, "_sqlStatement", sizeof("_sqlStatement")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_class_entry, "_initialTime", sizeof("_initialTime")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_profiler_item_class_entry, "_finalTime", sizeof("_finalTime")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce26, "Phalcon_Db_Column", phalcon_db_column_functions);
	phalcon_db_column_class_entry = zend_register_internal_class(&ce26 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_class_entry, "_columnName", sizeof("_columnName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_class_entry, "_schemaName", sizeof("_schemaName")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_class_entry, "_type", sizeof("_type")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_class_entry, "_size", sizeof("_size")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_class_entry, "_scale", sizeof("_scale")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_class_entry, "_unsigned", sizeof("_unsigned")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_class_entry, "_notNull", sizeof("_notNull")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_class_entry, "_autoIncrement", sizeof("_autoIncrement")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_class_entry, "_first", sizeof("_first")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_class_entry, "_after", sizeof("_after")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_INTEGER", sizeof("TYPE_INTEGER")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_DATE", sizeof("TYPE_DATE")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_VARCHAR", sizeof("TYPE_VARCHAR")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_DECIMAL", sizeof("TYPE_DECIMAL")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_DATETIME", sizeof("TYPE_DATETIME")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_CHAR", sizeof("TYPE_CHAR")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_class_entry, "TYPE_TEXT", sizeof("TYPE_TEXT")-1, 6 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce27, "Phalcon_Db_Pool", phalcon_db_pool_functions);
	phalcon_db_pool_class_entry = zend_register_internal_class(&ce27 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce28, "Phalcon_Db_Dialect_Mysql", phalcon_db_dialect_mysql_functions);
	phalcon_db_dialect_mysql_class_entry = zend_register_internal_class(&ce28 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce29, "Phalcon_Db_RawValue", phalcon_db_rawvalue_functions);
	phalcon_db_rawvalue_class_entry = zend_register_internal_class(&ce29 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_rawvalue_class_entry, "_value", sizeof("_value")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce30, "Phalcon_Flash", phalcon_flash_functions);
	phalcon_flash_class_entry = zend_register_internal_class(&ce30 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce31, "Phalcon_Paginator", phalcon_paginator_functions);
	phalcon_paginator_class_entry = zend_register_internal_class(&ce31 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce32, "Phalcon_Logger", phalcon_logger_functions);
	phalcon_logger_class_entry = zend_register_internal_class(&ce32 TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_class_entry, "_adapter", sizeof("_adapter")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "SPECIAL", sizeof("SPECIAL")-1, 9 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "CUSTOM", sizeof("CUSTOM")-1, 8 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "DEBUG", sizeof("DEBUG")-1, 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "INFO", sizeof("INFO")-1, 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "NOTICE", sizeof("NOTICE")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "WARNING", sizeof("WARNING")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "ERROR", sizeof("ERROR")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "ALERT", sizeof("ALERT")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "CRITICAL", sizeof("CRITICAL")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_logger_class_entry, "EMERGENCE", sizeof("EMERGENCE")-1, 0 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce33, "Phalcon_Config", phalcon_config_functions);
	phalcon_config_class_entry = zend_register_internal_class(&ce33 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce34, "Phalcon_Filter", phalcon_filter_functions);
	phalcon_filter_class_entry = zend_register_internal_class(&ce34 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce35, "Phalcon_Loader", phalcon_loader_functions);
	phalcon_loader_class_entry = zend_register_internal_class(&ce35 TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_class_entry, "_namespaces", sizeof("_namespaces")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_loader_class_entry, "_directories", sizeof("_directories")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce36, "Phalcon_Logger_Adapter_File", phalcon_logger_adapter_file_functions);
	phalcon_logger_adapter_file_class_entry = zend_register_internal_class(&ce36 TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_class_entry, "_fileHandler", sizeof("_fileHandler")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_logger_adapter_file_class_entry, "_transaction", sizeof("_transaction")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_class_entry, "_quenue", sizeof("_quenue")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_class_entry, "_dateFormat", sizeof("_dateFormat")-1, "D, d M y H:i:s O", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_class_entry, "_format", sizeof("_format")-1, "[%date%][%type%] %message%", ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce37, "Phalcon_Logger_Item", phalcon_logger_item_functions);
	phalcon_logger_item_class_entry = zend_register_internal_class(&ce37 TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_class_entry, "_type", sizeof("_type")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_class_entry, "message", sizeof("message")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_item_class_entry, "_time", sizeof("_time")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce38, "Phalcon_Transaction", phalcon_transaction_functions);
	phalcon_transaction_class_entry = zend_register_internal_class(&ce38 TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_class_entry, "_connection", sizeof("_connection")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_class_entry, "_activeTransaction", sizeof("_activeTransaction")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_class_entry, "_isNewTransaction", sizeof("_isNewTransaction")-1, 1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_class_entry, "_rollbackOnAbort", sizeof("_rollbackOnAbort")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_class_entry, "_manager", sizeof("_manager")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_class_entry, "_pointer", sizeof("_pointer")-1, 255, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_class_entry, "_dependencies", sizeof("_dependencies")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_class_entry, "_messages", sizeof("_messages")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_class_entry, "_rollbackRecord", sizeof("_rollbackRecord")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce39, "Phalcon_Transaction_Manager", phalcon_transaction_manager_functions);
	phalcon_transaction_manager_class_entry = zend_register_internal_class(&ce39 TSRMLS_CC);
	zend_declare_property_bool(phalcon_transaction_manager_class_entry, "_initialized", sizeof("_initialized")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_transaction_manager_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce40, "Phalcon_Session", phalcon_session_functions);
	phalcon_session_class_entry = zend_register_internal_class(&ce40 TSRMLS_CC);
	zend_declare_property_null(phalcon_session_class_entry, "_uniqueId", sizeof("_uniqueId")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_session_class_entry, "_options", sizeof("_options")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce41, "Phalcon_Controller", phalcon_controller_functions);
	phalcon_controller_class_entry = zend_register_internal_class(&ce41 TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_class_entry, "_dispatcher", sizeof("_dispatcher")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_class_entry, "_view", sizeof("_view")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_class_entry, "request", sizeof("request")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_class_entry, "response", sizeof("response")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_controller_class_entry, "view", sizeof("view")-1, ZEND_ACC_PUBLIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce42, "Phalcon_Model_Message", phalcon_model_message_functions);
	phalcon_model_message_class_entry = zend_register_internal_class(&ce42 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_message_class_entry, "_type", sizeof("_type")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_message_class_entry, "_message", sizeof("_message")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce43, "Phalcon_Model_Manager", phalcon_model_manager_functions);
	phalcon_model_manager_class_entry = zend_register_internal_class(&ce43 TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_manager_class_entry, "_connection", sizeof("_connection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_metadata", sizeof("_metadata")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_modelsDir", sizeof("_modelsDir")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_models", sizeof("_models")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_hasMany", sizeof("_hasMany")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_hasOne", sizeof("_hasOne")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_belongsTo", sizeof("_belongsTo")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_manager_class_entry, "_sourceNames", sizeof("_sourceNames")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce44, "Phalcon_Model_MetaData", phalcon_model_metadata_functions);
	phalcon_model_metadata_class_entry = zend_register_internal_class(&ce44 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_ATTRIBUTES", sizeof("MODELS_ATTRIBUTES")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_PRIMARY_KEY", sizeof("MODELS_PRIMARY_KEY")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_NON_PRIMARY_KEY", sizeof("MODELS_NON_PRIMARY_KEY")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_NOT_NULL", sizeof("MODELS_NOT_NULL")-1, 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE", sizeof("MODELS_DATA_TYPE")-1, 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE_NUMERIC", sizeof("MODELS_DATA_TYPE_NUMERIC")-1, 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_DATE_AT", sizeof("MODELS_DATE_AT")-1, 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_metadata_class_entry, "MODELS_DATE_IN", sizeof("MODELS_DATE_IN")-1, 7 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce45, "Phalcon_Model_Validator", phalcon_model_validator_functions);
	phalcon_model_validator_class_entry = zend_register_internal_class(&ce45 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_record", sizeof("_record")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_fieldName", sizeof("_fieldName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_value", sizeof("_value")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_options", sizeof("_options")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_messages", sizeof("_messages")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce46, "Phalcon_Model_Row", phalcon_model_row_functions);
	phalcon_model_row_class_entry = zend_register_internal_class(&ce46 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_row_class_entry, "_connection", sizeof("_connection")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_model_row_class_entry, "_columns", sizeof("_columns")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce47, "Phalcon_Model_Base", phalcon_model_base_functions);
	phalcon_model_base_class_entry = zend_register_internal_class(&ce47 TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_initialized", sizeof("_initialized")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_uniqueKey", sizeof("_uniqueKey")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_connection", sizeof("_connection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_schema", sizeof("_schema")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_source", sizeof("_source")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_isView", sizeof("_isView")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_dumped", sizeof("_dumped")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_dumpLock", sizeof("_dumpLock")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_model_base_class_entry, "_errorMessages", sizeof("_errorMessages")-1, "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_class_entry, "_operationMade", sizeof("_operationMade")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_forceExists", sizeof("_forceExists")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_defaultConnection", sizeof("_defaultConnection")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_class_entry, "_connectionName", sizeof("_connectionName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_model_base_class_entry, "_refreshPersistance", sizeof("_refreshPersistance")-1, 1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_class_entry, "OP_CREATE", sizeof("OP_CREATE")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_class_entry, "OP_UPDATE", sizeof("OP_UPDATE")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_model_base_class_entry, "OP_DELETE", sizeof("OP_DELETE")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce48, "Phalcon_Model_MetaData_Memory", phalcon_model_metadata_memory_functions);
	phalcon_model_metadata_memory_class_entry = zend_register_internal_class(&ce48 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce49, "Phalcon_Model_Resultset", phalcon_model_resultset_functions);
	phalcon_model_resultset_class_entry = zend_register_internal_class(&ce49 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_model", sizeof("_model")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_resultResource", sizeof("_resultResource")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_model_resultset_class_entry, "_pointer", sizeof("_pointer")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_count", sizeof("_count")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_resultset_class_entry, "_activeRow", sizeof("_activeRow")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_class_implements(phalcon_model_resultset_class_entry TSRMLS_CC, 3, zend_ce_iterator, spl_ce_SeekableIterator, spl_ce_Countable);

	INIT_CLASS_ENTRY(ce50, "Phalcon_Model_Sanitize", phalcon_model_sanitize_functions);
	phalcon_model_sanitize_class_entry = zend_register_internal_class(&ce50 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce51, "Phalcon_Model_Query", phalcon_model_query_functions);
	phalcon_model_query_class_entry = zend_register_internal_class(&ce51 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_data", sizeof("_data")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_manager", sizeof("_manager")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_models", sizeof("_models")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_parameters", sizeof("_parameters")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_conditions", sizeof("_conditions")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_query_class_entry, "_limit", sizeof("_limit")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce52, "Phalcon_Tag", phalcon_tag_functions);
	phalcon_tag_class_entry = zend_register_internal_class(&ce52 TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_string(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	INIT_CLASS_ENTRY(ce53, "Phalcon_Exception", phalcon_exception_functions);
	phalcon_exception_class_entry = zend_register_internal_class_ex(&ce53, NULL, "exception" TSRMLS_CC);
	if(!phalcon_exception_class_entry){
		phalcon_inherit_not_found("Exception", "Phalcon_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce54, "Phalcon_Internal_TestParent", phalcon_internal_testparent_functions);
	phalcon_internal_testparent_class_entry = zend_register_internal_class(&ce54 TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_testparent_class_entry, "_pp0", sizeof("_pp0")-1, 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce55, "Phalcon_Db", phalcon_db_functions);
	phalcon_db_class_entry = zend_register_internal_class(&ce55 TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_descriptor", sizeof("_descriptor")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_class_entry, "_fetchMode", sizeof("_fetchMode")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_autoCommit", sizeof("_autoCommit")-1, 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_idConnection", sizeof("_idConnection")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_underTransaction", sizeof("_underTransaction")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_logger", sizeof("_logger")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_class_entry, "_profiler", sizeof("_profiler")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_ASSOC", sizeof("DB_ASSOC")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_BOTH", sizeof("DB_BOTH")-1, 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_class_entry, "DB_NUM", sizeof("DB_NUM")-1, 3 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce56, "Phalcon_Config", phalcon_config_functions);
	phalcon_config_class_entry = zend_register_internal_class(&ce56 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce57, "Phalcon_Model_Validator", phalcon_model_validator_functions);
	phalcon_model_validator_class_entry = zend_register_internal_class(&ce57 TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_record", sizeof("_record")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_fieldName", sizeof("_fieldName")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_value", sizeof("_value")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_options", sizeof("_options")-1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_model_validator_class_entry, "_messages", sizeof("_messages")-1, ZEND_ACC_PROTECTED TSRMLS_CC);

	INIT_CLASS_ENTRY(ce58, "Phalcon_Paginator_Exception", phalcon_paginator_exception_functions);
	phalcon_paginator_exception_class_entry = zend_register_internal_class_ex(&ce58, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_paginator_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Paginator_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce59, "Phalcon_Cache_Exception", phalcon_cache_exception_functions);
	phalcon_cache_exception_class_entry = zend_register_internal_class_ex(&ce59, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_cache_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Cache_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce60, "Phalcon_Internal_Test", phalcon_internal_test_functions);
	phalcon_internal_test_class_entry = zend_register_internal_class_ex(&ce60, NULL, "phalcon_internal_testparent" TSRMLS_CC);
	if(!phalcon_internal_test_class_entry){
		phalcon_inherit_not_found("Phalcon_Internal_TestParent", "Phalcon_Internal_Test");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_internal_test_class_entry, "_p0", sizeof("_p0")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_class_entry, "_p1", sizeof("_p1")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_class_entry, "_p2", sizeof("_p2")-1, "str", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_double(phalcon_internal_test_class_entry, "_p3", sizeof("_p3")-1, 4.12, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_class_entry, "_p4", sizeof("_p4")-1, 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_class_entry, "_p5", sizeof("_p5")-1, 1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_class_entry, "_p6", sizeof("_p6")-1, "12.01", ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_test_class_entry, "_p7", sizeof("_p7")-1, 128, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_class_entry, "_p8", sizeof("_p8")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_class_entry, "_p9", sizeof("_p9")-1, ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, "hello", ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_string(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, "11.20", ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_long(phalcon_internal_test_class_entry, "_sp4", sizeof("_sp4")-1, 128, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_class_entry, "_sp5", sizeof("_sp5")-1, 0, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_bool(phalcon_internal_test_class_entry, "_sp6", sizeof("_sp6")-1, 1, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_double(phalcon_internal_test_class_entry, "_sp7", sizeof("_sp7")-1, 3.1415, ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_internal_test_class_entry, "C1", sizeof("C1")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_double(phalcon_internal_test_class_entry, "C2", sizeof("C2")-1, 2.1 TSRMLS_CC);
	zend_declare_class_constant_bool(phalcon_internal_test_class_entry, "C3", sizeof("C3")-1, 0 TSRMLS_CC);
	zend_declare_class_constant_bool(phalcon_internal_test_class_entry, "C4", sizeof("C4")-1, 1 TSRMLS_CC);
	zend_declare_class_constant_null(phalcon_internal_test_class_entry, "C5", sizeof("C5")-1 TSRMLS_CC);
	zend_declare_class_constant_string(phalcon_internal_test_class_entry, "C6", sizeof("C6")-1, "str" TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_internal_test_class_entry, "C7", sizeof("C7")-1, -92 TSRMLS_CC);

	INIT_CLASS_ENTRY(ce61, "Phalcon_Acl_Exception", phalcon_acl_exception_functions);
	phalcon_acl_exception_class_entry = zend_register_internal_class_ex(&ce61, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_acl_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Acl_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce62, "Phalcon_Tag_Exception", phalcon_tag_exception_functions);
	phalcon_tag_exception_class_entry = zend_register_internal_class_ex(&ce62, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_tag_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Tag_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce63, "Phalcon_Db_Adapter_Mysql", phalcon_db_adapter_mysql_functions);
	phalcon_db_adapter_mysql_class_entry = zend_register_internal_class_ex(&ce63, NULL, "phalcon_db" TSRMLS_CC);
	if(!phalcon_db_adapter_mysql_class_entry){
		phalcon_inherit_not_found("Phalcon_Db", "Phalcon_Db_Adapter_Mysql");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce64, "Phalcon_Db_Exception", phalcon_db_exception_functions);
	phalcon_db_exception_class_entry = zend_register_internal_class_ex(&ce64, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_db_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Db_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce65, "Phalcon_Logger_Exception", phalcon_logger_exception_functions);
	phalcon_logger_exception_class_entry = zend_register_internal_class_ex(&ce65, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_logger_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Logger_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce66, "Phalcon_Transaction_Failed", phalcon_transaction_failed_functions);
	phalcon_transaction_failed_class_entry = zend_register_internal_class_ex(&ce66, NULL, "exception" TSRMLS_CC);
	if(!phalcon_transaction_failed_class_entry){
		phalcon_inherit_not_found("Exception", "Phalcon_Transaction_Failed");
		return FAILURE;
	}
	zend_declare_property_null(phalcon_transaction_failed_class_entry, "_record", sizeof("_record")-1, ZEND_ACC_PRIVATE TSRMLS_CC);

	INIT_CLASS_ENTRY(ce67, "Phalcon_Config_Adapter_Ini", phalcon_config_adapter_ini_functions);
	phalcon_config_adapter_ini_class_entry = zend_register_internal_class_ex(&ce67, NULL, "phalcon_config" TSRMLS_CC);
	if(!phalcon_config_adapter_ini_class_entry){
		phalcon_inherit_not_found("Phalcon_Config", "Phalcon_Config_Adapter_Ini");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce68, "Phalcon_Config_Exception", phalcon_config_exception_functions);
	phalcon_config_exception_class_entry = zend_register_internal_class_ex(&ce68, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_config_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Config_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce69, "Phalcon_Model_Validator_Uniqueness", phalcon_model_validator_uniqueness_functions);
	phalcon_model_validator_uniqueness_class_entry = zend_register_internal_class_ex(&ce69, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_uniqueness_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Uniqueness");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce70, "Phalcon_Model_Validator_Regex", phalcon_model_validator_regex_functions);
	phalcon_model_validator_regex_class_entry = zend_register_internal_class_ex(&ce70, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_regex_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Regex");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce71, "Phalcon_Model_Validator_Inclusionin", phalcon_model_validator_inclusionin_functions);
	phalcon_model_validator_inclusionin_class_entry = zend_register_internal_class_ex(&ce71, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_inclusionin_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Inclusionin");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce72, "Phalcon_Model_Validator_Exclusionin", phalcon_model_validator_exclusionin_functions);
	phalcon_model_validator_exclusionin_class_entry = zend_register_internal_class_ex(&ce72, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_exclusionin_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Exclusionin");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce73, "Phalcon_Model_Validator_Numericality", phalcon_model_validator_numericality_functions);
	phalcon_model_validator_numericality_class_entry = zend_register_internal_class_ex(&ce73, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_numericality_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Numericality");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce74, "Phalcon_Model_Validator_Email", phalcon_model_validator_email_functions);
	phalcon_model_validator_email_class_entry = zend_register_internal_class_ex(&ce74, NULL, "phalcon_model_validator" TSRMLS_CC);
	if(!phalcon_model_validator_email_class_entry){
		phalcon_inherit_not_found("Phalcon_Model_Validator", "Phalcon_Model_Validator_Email");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce75, "Phalcon_Model_Exception", phalcon_model_exception_functions);
	phalcon_model_exception_class_entry = zend_register_internal_class_ex(&ce75, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_model_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_Model_Exception");
		return FAILURE;
	}

	INIT_CLASS_ENTRY(ce76, "Phalcon_View_Exception", phalcon_view_exception_functions);
	phalcon_view_exception_class_entry = zend_register_internal_class_ex(&ce76, NULL, "phalcon_exception" TSRMLS_CC);
	if(!phalcon_view_exception_class_entry){
		phalcon_inherit_not_found("Phalcon_Exception", "Phalcon_View_Exception");
		return FAILURE;
	}
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(phalcon){
	return SUCCESS;
}

PHP_RINIT_FUNCTION(phalcon){
	
	/*return phalcon_init_fcall_cache();*/
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(phalcon){
	
	/*return phalcon_free_fcall_cache();*/
	return SUCCESS;
}

zend_module_entry phalcon_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	PHP_PHALCON_EXTNAME,
	NULL,
	PHP_MINIT(phalcon),
	PHP_MSHUTDOWN(phalcon),
	PHP_RINIT(phalcon),
	PHP_RSHUTDOWN(phalcon),
	NULL,
#if ZEND_MODULE_API_NO >= 20010901
	PHP_PHALCON_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PHALCON
ZEND_GET_MODULE(phalcon)
#endif

