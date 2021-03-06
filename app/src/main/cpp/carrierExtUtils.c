/*
 * Copyright (c) 2020 Elastos Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "carrierExtUtils.h"

#include "utils.h"
#include "log.h"

int newJavaTurnServerInfo(JNIEnv *env, jstring jserver, jstring jusername,
                          jstring jpassword, jstring jrealm, jint jport, jobject *jsinfo)
{
    const char* clazzName = "org/elastos/carrier/CarrierExtension$TurnServerInfo";
    jclass clazz = (*env)->FindClass(env, clazzName);
    if (!clazz) {
        logE("Java class 'CarrierExtension$TurnServerInfo' not found");
        return 0;
    }

    jmethodID contor = (*env)->GetMethodID(env, clazz, "<init>",
                                           "("_J("String;")_J("String;")
                                           _J("String;")_J("String;I)V"));
    if (!contor) {
        (*env)->DeleteLocalRef(env, clazz);
        logE("constructor method: 'CarrierExtension$TurnServerInfo()' mismatched");
        return 0;
    }

    jobject jobj = (*env)->NewObject(env, clazz, contor, jserver, jusername,
                                     jpassword, jrealm, jport);
    (*env)->DeleteLocalRef(env, clazz);
    if (!jobj) {
        logE("New class CarrierExtension$TurnServerInfo object error");
        return 0;
    }

    *jsinfo = jobj;
    return 1;
}

