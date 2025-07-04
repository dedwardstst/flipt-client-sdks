#include <jni.h>
#include "include/flipt_engine.h"
#include <stdlib.h>
#include <string.h>

jlong JNICALL Java_io_flipt_client_CLibrary_initializeEngine(
        JNIEnv *env, jobject obj, jstring opts) {
    const char *opts_c = (*env)->GetStringUTFChars(env, opts, 0);

    void *engine = initialize_engine(opts_c);

    (*env)->ReleaseStringUTFChars(env, opts, opts_c);

    return (jlong) engine; // Cast to jlong to safely pass the pointer
}

jstring JNICALL Java_io_flipt_client_CLibrary_getSnapshot(
        JNIEnv *env, jobject obj, jlong enginePtr) {
    const char *result = get_snapshot((void *) enginePtr);

    jstring result_j = (*env)->NewStringUTF(env, result);
    destroy_string((char *) result); // Free the result string

    return result_j;
}

jstring JNICALL Java_io_flipt_client_CLibrary_evaluateVariant(
        JNIEnv *env, jobject obj, jlong enginePtr, jstring evaluationRequest) {
    const char *eval_request_c = (*env)->GetStringUTFChars(env, evaluationRequest, 0);

    const char *result = evaluate_variant((void *) enginePtr, eval_request_c);

    (*env)->ReleaseStringUTFChars(env, evaluationRequest, eval_request_c);

    jstring result_j = (*env)->NewStringUTF(env, result);
    destroy_string((char *) result); // Free the result string

    return result_j;
}

jstring JNICALL Java_io_flipt_client_CLibrary_evaluateBoolean(
        JNIEnv *env, jobject obj, jlong enginePtr, jstring evaluationRequest) {
    const char *eval_request_c = (*env)->GetStringUTFChars(env, evaluationRequest, 0);

    const char *result = evaluate_boolean((void *) enginePtr, eval_request_c);

    (*env)->ReleaseStringUTFChars(env, evaluationRequest, eval_request_c);

    jstring result_j = (*env)->NewStringUTF(env, result);
    destroy_string((char *) result); // Free the result string

    return result_j;
}

jstring JNICALL Java_io_flipt_client_CLibrary_evaluateBatch(
        JNIEnv *env, jobject obj, jlong enginePtr, jstring batchEvaluationRequest) {
    const char *batch_request_c = (*env)->GetStringUTFChars(env, batchEvaluationRequest, 0);

    const char *result = evaluate_batch((void *) enginePtr, batch_request_c);

    (*env)->ReleaseStringUTFChars(env, batchEvaluationRequest, batch_request_c);

    jstring result_j = (*env)->NewStringUTF(env, result);
    destroy_string((char *) result); // Free the result string

    return result_j;
}

jstring JNICALL Java_io_flipt_client_CLibrary_listFlags(
        JNIEnv *env, jobject obj, jlong enginePtr) {
    const char *result = list_flags((void *) enginePtr);

    jstring result_j = (*env)->NewStringUTF(env, result);
    destroy_string((char *) result); // Free the result string

    return result_j;
}

void JNICALL Java_io_flipt_client_CLibrary_destroyEngine(
        JNIEnv *env, jobject obj, jlong enginePtr) {
    destroy_engine((void *) enginePtr);
}