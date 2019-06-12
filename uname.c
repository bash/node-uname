#define NAPI_VERSION 4

#include <assert.h>
#include <sys/utsname.h>
#include <node_api.h>

#define NODE_UNAME_FUNCTION "uname"
#define ASSERT_OK(status) assert(status == napi_ok)

void node_uname_set_string_property(napi_env env, napi_value target, const char *property, const char *value)
{
    napi_value value_as_napi_value;

    ASSERT_OK(napi_create_string_utf8(env, value, NAPI_AUTO_LENGTH, &value_as_napi_value));
    ASSERT_OK(napi_set_named_property(env, target, property, value_as_napi_value));
}

napi_value node_uname_get_uname_info(napi_env env, napi_callback_info _info)
{
    struct utsname info;
    if (uname(&info) == -1)
    {
        napi_throw_error(env, NULL, "internal error calling `uname`");
    }

    napi_value result;
    ASSERT_OK(napi_create_object(env, &result));

    node_uname_set_string_property(env, result, "sysname", info.sysname);
    node_uname_set_string_property(env, result, "nodename", info.nodename);
    node_uname_set_string_property(env, result, "release", info.release);
    node_uname_set_string_property(env, result, "version", info.version);
    node_uname_set_string_property(env, result, "machine", info.machine);

    return result;
}

napi_value node_uname_init(napi_env env, napi_value exports)
{
    napi_value fn;
    ASSERT_OK(napi_create_function(env, NODE_UNAME_FUNCTION, NAPI_AUTO_LENGTH, node_uname_get_uname_info, NULL, &fn));
    ASSERT_OK(napi_set_named_property(env, exports, NODE_UNAME_FUNCTION, fn));
    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, node_uname_init)
