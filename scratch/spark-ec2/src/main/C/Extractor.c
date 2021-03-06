#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Extractor.h"
#include "sep.h"

JNIEXPORT jint JNICALL Java_Extractor_sep_1sum_1circle
  (JNIEnv *env, jobject obj, jbyteArray data, jbyteArray error, jbyteArray mask, jint dtype, jint edtype, jint mdtype, jint w, jint h, jdouble maskthresh, jdouble gain, jshort inflag, jdoubleArray x, jdoubleArray y, jdouble r, jint subpix, jdoubleArray sum, jdoubleArray sumerr, jdoubleArray area, jshortArray flag)
{
  jbyte *array = (jbyte *)(*env)->GetByteArrayElements(env, data, NULL);
  jbyte *e_array = NULL;
  if(error != NULL){
    e_array = (jbyte *)(*env)->GetByteArrayElements(env, error, NULL);
  }
  jbyte *m_array = NULL;
  if(mask != NULL){
    m_array = (jbyte *)(*env)->GetByteArrayElements(env, mask, NULL);
  }

  jdouble *xarray = (jdouble *)(*env)->GetDoubleArrayElements(env, x, 0);
  jdouble *yarray = (jdouble *)(*env)->GetDoubleArrayElements(env, y, 0);
  int len = (*env)->GetArrayLength(env, x);

  int status = 0;
  for(int i=0; i<len; i++){
    double dsum = 0.0;
    double dsumerr = 0.0;
    double darea = 0.0;
    short dflag = 0;
    
    status = sep_sum_circle(array, e_array, m_array, dtype, edtype, mdtype, w, h, maskthresh, gain, inflag, xarray[i], yarray[i], r, subpix, &dsum, &dsumerr, &darea, &dflag);

    (*env)->SetDoubleArrayRegion(env, sum, i, 1, &dsum);
    (*env)->SetDoubleArrayRegion(env, sumerr, i, 1, &dsumerr);
    (*env)->SetDoubleArrayRegion(env, area, i, 1, &darea);
    (*env)->SetShortArrayRegion(env, flag, i, 1, &dflag);
  }

  (*env)->ReleaseByteArrayElements(env, data, array, 0);
  (*env)->ReleaseDoubleArrayElements(env, x, xarray, 0);
  (*env)->ReleaseDoubleArrayElements(env, y, yarray, 0);
  if(e_array != NULL)
    (*env)->ReleaseByteArrayElements(env, error, e_array, 0);
  if(m_array != NULL)
    (*env)->ReleaseByteArrayElements(env, mask, m_array, 0);
  /*free(array);
  free(xarray);
  free(yarray);
  if(e_array != NULL)
    free(e_array);
  if(m_array != NULL)
  free(m_array);*/
  return status;
}

JNIEXPORT jint JNICALL Java_Extractor_sep_1sum_1circann
  (JNIEnv *env, jobject obj, jbyteArray data, jbyteArray error, jbyteArray mask, jint dtype, jint edtype, jint mdtype, jint w, jint h, jdouble maskthresh, jdouble gain, jshort inflag, jdoubleArray x, jdoubleArray y, jdouble rin, jdouble rout, jint subpix, jdoubleArray sum, jdoubleArray sumerr, jdoubleArray area, jshortArray flag)
{
  jbyte *array = (jbyte *)(*env)->GetByteArrayElements(env, data, NULL);
  jbyte *e_array = NULL;
  if(error != NULL){
    e_array = (jbyte *)(*env)->GetByteArrayElements(env, error, NULL);
  }
  jbyte *m_array = NULL;
  if(mask != NULL){
    m_array = (jbyte *)(*env)->GetByteArrayElements(env, mask, NULL);
  }

  jdouble *xarray = (jdouble *)(*env)->GetDoubleArrayElements(env, x, 0);
  jdouble *yarray = (jdouble *)(*env)->GetDoubleArrayElements(env, y, 0);
  int len = (*env)->GetArrayLength(env, x);

  int status = 0;
  for(int i=0; i<len; i++){
    double dsum = 0.0;
    double dsumerr = 0.0;
    double darea = 0.0;
    short dflag = 0;
    
    status = sep_sum_circann(array, e_array, m_array, dtype, edtype, mdtype, w, h, maskthresh, gain, inflag, xarray[i], yarray[i], rin, rout, subpix, &dsum, &dsumerr, &darea, &dflag);

    (*env)->SetDoubleArrayRegion(env, sum, i, 1, &dsum);
    (*env)->SetDoubleArrayRegion(env, sumerr, i, 1, &dsumerr);
    (*env)->SetDoubleArrayRegion(env, area, i, 1, &darea);
    (*env)->SetShortArrayRegion(env, flag, i, 1, &dflag);
  }

  (*env)->ReleaseByteArrayElements(env, data, array, 0);
  (*env)->ReleaseDoubleArrayElements(env, x, xarray, 0);
  (*env)->ReleaseDoubleArrayElements(env, y, yarray, 0);
  if(e_array != NULL)
    (*env)->ReleaseByteArrayElements(env, error, e_array, 0);
  if(m_array != NULL)
    (*env)->ReleaseByteArrayElements(env, mask, m_array, 0);

  /*free(array);
  free(xarray);
  free(yarray);
  if(e_array != NULL)
    free(e_array);
  if(m_array != NULL)
  free(m_array);*/

  return status;
}

JNIEXPORT jint JNICALL Java_Extractor_sep_1sum_1ellipse
  (JNIEnv *env, jobject obj, jbyteArray data, jbyteArray error, jbyteArray mask, jint dtype, jint edtype, jint mdtype, jint w, jint h, jdouble maskthresh, jdouble gain, jshort inflag, jdoubleArray x, jdoubleArray y, jdoubleArray a, jdoubleArray b, jdoubleArray theta, jdoubleArray r, jint subpix, jdoubleArray sum, jdoubleArray sumerr, jdoubleArray area, jshortArray flag)
{
  jbyte *array = (jbyte *)(*env)->GetByteArrayElements(env, data, NULL);
  jbyte *e_array = NULL;
  if(error != NULL){
    e_array = (jbyte *)(*env)->GetByteArrayElements(env, error, NULL);
  }
  jbyte *m_array = NULL;
  if(mask != NULL){
    m_array = (jbyte *)(*env)->GetByteArrayElements(env, mask, NULL);
  }

  jdouble *xarray = (jdouble *)(*env)->GetDoubleArrayElements(env, x, 0);
  jdouble *yarray = (jdouble *)(*env)->GetDoubleArrayElements(env, y, 0);
  jdouble *a_array = (jdouble *)(*env)->GetDoubleArrayElements(env, a, 0);
  jdouble *b_array = (jdouble *)(*env)->GetDoubleArrayElements(env, b, 0);
  jdouble *theta_array = (jdouble *)(*env)->GetDoubleArrayElements(env, theta, 0);
  jdouble *r_array = (jdouble *)(*env)->GetDoubleArrayElements(env, r, 0);
  int len = (*env)->GetArrayLength(env, x);
  int status = 0;

  for(int i=0; i<len; i++){
    double dsum = 1.0;
    double dsumerr = 1.0;
    double darea = 1.0;
    short dflag = 1;

    status = sep_sum_ellipse(array, e_array, m_array, dtype, edtype, mdtype, w, h, maskthresh, gain, inflag, xarray[i], yarray[i], a_array[i], b_array[i], theta_array[i], r_array[i], subpix, &dsum, &dsumerr, &darea, &dflag);
    //printf("C sep_sum_ellipse: dsum: %f\t dsumerr: %f\t darea: %f\t dflag: %d\n", dsum, dsumerr, darea, dflag);

    (*env)->SetDoubleArrayRegion(env, sum, i, 1, &dsum);
    (*env)->SetDoubleArrayRegion(env, sumerr, i, 1, &dsumerr);
    (*env)->SetDoubleArrayRegion(env, area, i, 1, &darea);
    (*env)->SetShortArrayRegion(env, flag, i, 1, &dflag);
  }


  (*env)->ReleaseByteArrayElements(env, data, array, 0);
  (*env)->ReleaseDoubleArrayElements(env, x, xarray, 0);
  (*env)->ReleaseDoubleArrayElements(env, y, yarray, 0);
  (*env)->ReleaseDoubleArrayElements(env, a, a_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, b, b_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, theta, theta_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, r, r_array, 0);
  if(e_array != NULL)
    (*env)->ReleaseByteArrayElements(env, error, e_array, 0);
  if(m_array != NULL)
    (*env)->ReleaseByteArrayElements(env, mask, m_array, 0);

  /*free(array);
  free(xarray);
  free(yarray);
  free(a_array);
  free(b_array);
  free(theta_array);
  free(r_array);
  if(e_array != NULL)
    free(e_array);
  if(m_array != NULL)
  free(m_array);*/

  return status;
}

JNIEXPORT jint JNICALL Java_Extractor_sep_1sum_1ellipann
  (JNIEnv *env, jobject obj, jbyteArray data, jbyteArray error, jbyteArray mask, jint dtype, jint edtype, jint mdtype, jint w, jint h, jdouble maskthresh, jdouble gain, jshort inflag, jdoubleArray x, jdoubleArray y, jdoubleArray a, jdoubleArray b, jdoubleArray theta, jdouble rin, jdouble rout, jint subpix, jdoubleArray sum, jdoubleArray sumerr, jdoubleArray area, jshortArray flag)
{
  jbyte *array = (jbyte *)(*env)->GetByteArrayElements(env, data, NULL);

  jbyte *e_array = NULL;
  if(error != NULL){
    e_array = (jbyte *)(*env)->GetByteArrayElements(env, error, NULL);
  }
  jbyte *m_array = NULL;
  if(mask != NULL){
    m_array = (jbyte *)(*env)->GetByteArrayElements(env, mask, NULL);
  }

  jdouble *xarray = (jdouble *)(*env)->GetDoubleArrayElements(env, x, 0);
  jdouble *yarray = (jdouble *)(*env)->GetDoubleArrayElements(env, y, 0);
  jdouble *a_array = (jdouble *)(*env)->GetDoubleArrayElements(env, a, 0);
  jdouble *b_array = (jdouble *)(*env)->GetDoubleArrayElements(env, b, 0);
  jdouble *thetaarray = (jdouble *)(*env)->GetDoubleArrayElements(env, theta, 0);
  int len = (*env)->GetArrayLength(env, x);
  int status = 0;

  for(int i=0; i<len; i++){
    double dsum = 1.0;
    double dsumerr = 1.0;
    double darea = 1.0;
    short dflag = 1;

    status = sep_sum_ellipann(array, e_array, m_array, dtype, edtype, mdtype, w, h, maskthresh, gain, inflag, xarray[i], yarray[i], a_array[i], b_array[i], thetaarray[i], rin, rout, subpix, &dsum, &dsumerr, &darea, &dflag);
    //printf("C sep_sum_ellipse: dsum: %f\t dsumerr: %f\t darea: %f\t dflag: %d\n", dsum, dsumerr, darea, dflag);

    (*env)->SetDoubleArrayRegion(env, sum, i, 1, &dsum);
    (*env)->SetDoubleArrayRegion(env, sumerr, i, 1, &dsumerr);
    (*env)->SetDoubleArrayRegion(env, area, i, 1, &darea);
    (*env)->SetShortArrayRegion(env, flag, i, 1, &dflag);
  }

  (*env)->ReleaseByteArrayElements(env, data, array, 0);
  (*env)->ReleaseDoubleArrayElements(env, x, xarray, 0);
  (*env)->ReleaseDoubleArrayElements(env, y, yarray, 0);
  (*env)->ReleaseDoubleArrayElements(env, a, a_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, b, b_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, theta, thetaarray, 0);
  if(e_array != NULL)
    (*env)->ReleaseByteArrayElements(env, error, e_array, 0);
  if(m_array != NULL)
    (*env)->ReleaseByteArrayElements(env, mask, m_array, 0);


  /*free(array);
  free(xarray);
  free(yarray);
  free(a_array);
  free(b_array);
  free(thetaarray);
  if(e_array != NULL)
    free(e_array);
  if(m_array != NULL)
  free(m_array);*/

  return status;
}

JNIEXPORT jint JNICALL Java_Extractor_sep_1extract
  (JNIEnv *env, jobject obj, jbyteArray data, jbyteArray nstream, jint dtype, jint ndtype, jshort noise_flag, jint w, jint h, jfloat thresh, jint minarea, jbyteArray cstream, jint convw, jint convh, jint deblend_nthresh, jdouble deblend_cont, jboolean clean_flag, jdouble clean_param, jobjectArray objects, jint nobj)
{
  jbyte *marray = (jbyte *)(*env)->GetByteArrayElements(env, data, NULL);  
 
  
  jfloat *conv = NULL;
  jbyte *carray = NULL;
  //printf("C sep_extract: convw: %d, convh: %d\n", convw, convh);
  if(convw !=0 && convh != 0)
  { 
    carray = (jbyte *)(*env)->GetByteArrayElements(env, cstream, NULL);  
    conv = (jfloat *)malloc(sizeof(float)*convw*convh);
    double *dp = (double *)carray;
    for(int i=0; i<convw*convh; i++){
      conv[i] = *(dp++);
      //printf("conv[%d]: %f\n", i, conv[i]);
    }
  }

  jbyte *narray = NULL;
  if(nstream != NULL){
    //printf("C sep_extract: nstream is not null\n");
    narray = (jbyte *)(*env)->GetByteArrayElements(env, nstream, NULL);
  }

  sepobj *objs;

  int status = sep_extract(marray, narray, dtype, ndtype, noise_flag, w, h, thresh, minarea, conv, convw, convh, deblend_nthresh, deblend_cont, clean_flag, clean_param, &objs, &nobj);
  //printf("C sep_extract: status: %d\n", status);

  /*for(int i=0; i<nobj; i++)
    printf("Number: %d\t X_IMAGE: %f\t Y_IMAGE: %f\n", i, objs[i].x, objs[i].y);*/

  jclass cls = (*env)->GetObjectClass(env, obj);
  assert(cls != NULL);
  jmethodID consID = (*env)->GetMethodID(env, cls, "init_obj", "(DIIIIIIDDDDDFFFFFFFFFFIIIISI)LSepobj;");
  assert(consID != NULL);

  for(int i=0; i<nobj; i++){
    jobject sepobj = (*env)->CallObjectMethod(env, obj, consID, objs[i].thresh, objs[i].npix, objs[i].tnpix, objs[i].xmin, objs[i].xmax, objs[i].ymin, objs[i].ymax, objs[i].x, objs[i].y, objs[i].x2, objs[i].y2, objs[i].xy, objs[i].a, objs[i].b, objs[i].theta, objs[i].cxx, objs[i].cyy, objs[i].cxy, objs[i].cflux, objs[i].flux, objs[i].cpeak, objs[i].peak, objs[i].xcpeak, objs[i].ycpeak, objs[i].xpeak, objs[i].ypeak, objs[i].flag);
    (*env)->SetObjectArrayElement(env, objects, i, sepobj);
  }

  (*env)->ReleaseByteArrayElements(env, data, marray, 0);
  //free(marray);
  if(conv != NULL)
    free(conv);
  if(carray != NULL)
    (*env)->ReleaseByteArrayElements(env, cstream, carray, 0);
  //free(carray);
  if(narray != NULL)
    (*env)->ReleaseByteArrayElements(env, nstream, narray, 0);
  //free(narray);
  return nobj;
}

JNIEXPORT void JNICALL Java_Extractor_sep_1ellipse_1coeffs
  (JNIEnv *env, jobject obj, jdoubleArray a, jdoubleArray b, jdoubleArray theta, jdoubleArray cxx, jdoubleArray cyy, jdoubleArray cxy)
{
  int len = (*env)->GetArrayLength(env, a);
  jdouble *a_array = (jdouble *)(*env)->GetDoubleArrayElements(env, a, 0);
  jdouble *b_array = (jdouble *)(*env)->GetDoubleArrayElements(env, b, 0);
  jdouble *theta_array = (jdouble *)(*env)->GetDoubleArrayElements(env, theta, 0);

  jdouble *cxx_array = malloc(sizeof(double)*len);
  jdouble *cyy_array = malloc(sizeof(double)*len);
  jdouble *cxy_array = malloc(sizeof(double)*len);
  for(int i=0; i<len; i++){
    sep_ellipse_coeffs(a_array[i], b_array[i], theta_array[i], &cxx_array[i], &cyy_array[i], &cxy_array[i]);
  }
  (*env)->SetDoubleArrayRegion(env, cxx, 0, len, cxx_array);
  (*env)->SetDoubleArrayRegion(env, cyy, 0, len, cyy_array);
  (*env)->SetDoubleArrayRegion(env, cxy, 0, len, cxy_array);

  (*env)->ReleaseDoubleArrayElements(env, a, a_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, b, b_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, theta, theta_array, 0);
  /*free(a_array);
  free(b_array);
  free(theta_array);*/
  free(cxx_array);
  free(cyy_array);
  free(cxy_array);
}

JNIEXPORT void JNICALL Java_Extractor_sep_1ellipse_1axes
  (JNIEnv *env, jobject obj, jdoubleArray cxx, jdoubleArray cyy, jdoubleArray cxy, jdoubleArray a, jdoubleArray b, jdoubleArray theta)
{
  int len = (*env)->GetArrayLength(env, cxx);
  jdouble *cxx_array = (jdouble *)(*env)->GetDoubleArrayElements(env, cxx, 0);
  jdouble *cyy_array = (jdouble *)(*env)->GetDoubleArrayElements(env, cyy, 0);
  jdouble *cxy_array = (jdouble *)(*env)->GetDoubleArrayElements(env, cxy, 0);

  jdouble *a_array = malloc(sizeof(double)*len);
  jdouble *b_array = malloc(sizeof(double)*len);
  jdouble *theta_array = malloc(sizeof(double)*len);
  for(int i=0; i<len; i++){
    sep_ellipse_axes(cxx_array[i], cyy_array[i], cxy_array[i], &a_array[i], &b_array[i], &theta_array[i]);
  }
  (*env)->SetDoubleArrayRegion(env, a, 0, len, a_array);
  (*env)->SetDoubleArrayRegion(env, b, 0, len, b_array);
  (*env)->SetDoubleArrayRegion(env, theta, 0, len, theta_array);

  (*env)->ReleaseDoubleArrayElements(env, cxx, cxx_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, cyy, cyy_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, cxy, cxy_array, 0);
  free(a_array);
  free(b_array);
  free(theta_array);
}

JNIEXPORT void JNICALL Java_Extractor_sep_1kron_1radius
  (JNIEnv *env, jobject obj, jbyteArray data, jbyteArray mstream, jint dtype, jint mdtype, jint w, jint h, jdouble maskthresh, jdoubleArray x, jdoubleArray y, jdoubleArray cxx, jdoubleArray cyy, jdoubleArray cxy, jdoubleArray r, jdoubleArray kr, jshortArray flag)
{
  jbyte *array = (jbyte *)(*env)->GetByteArrayElements(env, data, NULL);  

  jbyte *marray = NULL;
  if(mstream != NULL){
    jbyte *marray = (jbyte *)(*env)->GetByteArrayElements(env, mstream, NULL);  
  }

  int len = (*env)->GetArrayLength(env, cxx);
  jdouble *x_array = (jdouble *)(*env)->GetDoubleArrayElements(env, x, 0);
  jdouble *y_array = (jdouble *)(*env)->GetDoubleArrayElements(env, y, 0);
  jdouble *cxx_array = (jdouble *)(*env)->GetDoubleArrayElements(env, cxx, 0);
  jdouble *cyy_array = (jdouble *)(*env)->GetDoubleArrayElements(env, cyy, 0);
  jdouble *cxy_array = (jdouble *)(*env)->GetDoubleArrayElements(env, cxy, 0);  
  jdouble *r_array = (jdouble *)(*env)->GetDoubleArrayElements(env, r, 0);

  jdouble *kr_array = (jdouble *)malloc(sizeof(double)*len);
  jshort *flag_array = (jshort *)malloc(sizeof(short)*len);
  for(int i=0; i<len; i++){
    sep_kron_radius(array, marray, dtype, mdtype, w, h, maskthresh, x_array[i], y_array[i], cxx_array[i], cyy_array[i], cxy_array[i], r_array[i], &kr_array[i], &flag_array[i]);
  }
    
  (*env)->SetDoubleArrayRegion(env, kr, 0, len, kr_array);
  (*env)->SetShortArrayRegion(env, flag, 0, len, flag_array);

  (*env)->ReleaseByteArrayElements(env, data, array, 0);
  if(marray != NULL)
      (*env)->ReleaseByteArrayElements(env, mstream, marray, 0);
  (*env)->ReleaseDoubleArrayElements(env, x, x_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, y, y_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, cxx, cxx_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, cyy, cyy_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, cxy, cxy_array, 0);
  (*env)->ReleaseDoubleArrayElements(env, r, r_array, 0);

  /*free(array);
  free(x_array);
  free(y_array);
  free(cxx_array);
  free(cyy_array);
  free(cxy_array);
  free(r_array);*/
  free(kr_array);
  free(flag_array);
}  

JNIEXPORT void JNICALL Java_Extractor_sep_1set_1ellipse
  (JNIEnv *env, jobject obj, jbyteArray data, jint w, jint h, jdoubleArray x, jdoubleArray y, jdoubleArray cxx, jdoubleArray cyy, jdoubleArray cxy, jdoubleArray r, jbyte value)
{
  jbyte *array = (jbyte *)(*env)->GetByteArrayElements(env, data, NULL);  
  int len = (*env)->GetArrayLength(env, x);
  jdouble *x_array = (jdouble *)(*env)->GetDoubleArrayElements(env, x, 0);
  jdouble *y_array = (jdouble *)(*env)->GetDoubleArrayElements(env, y, 0);
  jdouble *cxx_array = (jdouble *)(*env)->GetDoubleArrayElements(env, cxx, 0);
  jdouble *cyy_array = (jdouble *)(*env)->GetDoubleArrayElements(env, cyy, 0);
  jdouble *cxy_array = (jdouble *)(*env)->GetDoubleArrayElements(env, cxy, 0);  
  jdouble *r_array = (jdouble *)(*env)->GetDoubleArrayElements(env, r, 0);

  for(int i=0; i<len; i++){
    sep_set_ellipse((unsigned char *)array, w, h, x_array[i], y_array[i], cxx_array[i], cyy_array[i], cxy_array[i], r_array[i], value);
    //sep_set_ellipse((unsigned char *)array, 20, 20, 10.0, 10.0, 1.0, 1.0, 0.0, 1.001, 1);
  }

  int alen = (*env)->GetArrayLength(env, data);
  (*env)->SetByteArrayRegion(env, data, 0, alen, array);
}  
