/**
 * (c) 2015 Ruben Schmidmeister <ruby@fog.im>
 */

#include <node.h>
#include <v8.h>
#include <sys/utsname.h>

namespace bash
{
  using v8::Object;
  using v8::String;
  using v8::Number;
  using v8::Exception;
  using v8::FunctionTemplate;
  using v8::Isolate;
  using v8::Handle;
  using v8::HandleScope;
  using v8::Local;
  using v8::Value;
  using v8::FunctionCallbackInfo;

  void GetUname(const FunctionCallbackInfo<Value>& args)
  {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    struct utsname info;
    int code = uname(&info);

    if (code == -1) {
      isolate->ThrowException(Exception::Error(String::NewFromUtf8(isolate, "internal error calling `uname`")));
      return;
    }

    Handle<Object> Result = Object::New(isolate);

    Result->Set(String::NewFromUtf8(isolate, "sysname"), String::NewFromUtf8(isolate, info.sysname));
    Result->Set(String::NewFromUtf8(isolate, "nodename"), String::NewFromUtf8(isolate, info.nodename));
    Result->Set(String::NewFromUtf8(isolate, "release"), String::NewFromUtf8(isolate, info.release));
    Result->Set(String::NewFromUtf8(isolate, "version"), String::NewFromUtf8(isolate, info.version));
    Result->Set(String::NewFromUtf8(isolate, "machine"), String::NewFromUtf8(isolate, info.machine));

    #ifdef _GNU_SOURCE
    Result->Set(String::NewFromUtf8(isolate, "domainname"), String::NewFromUtf8(isolate, info.domainname));
    #endif

    args.GetReturnValue().Set(Result);
  }

  void Init(Handle<Object> exports)
  {
    Isolate* isolate = Isolate::GetCurrent();
    Local<FunctionTemplate> Template = FunctionTemplate::New(isolate, GetUname);

    exports->Set(String::NewFromUtf8(isolate, "uname"), Template->GetFunction());

  }

  NODE_MODULE(uname, Init)
}

