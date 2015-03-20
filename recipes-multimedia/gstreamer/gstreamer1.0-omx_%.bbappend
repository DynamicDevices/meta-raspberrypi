EXTRA_OECONF_append_rpi = " CPPFLAGS='-I${STAGING_DIR_TARGET}/usr/include/interface/vcos/pthreads \
                                   -I${STAGING_DIR_TARGET}/usr/include/interface/vmcs_host/linux \
                                   -I${STAGING_DIR_TARGET}/usr/include/IL' \
                                  "
GSTREAMER_1_0_OMX_TARGET_rpi= "rpi"
GSTREAMER_1_0_OMX_CORE_NAME_rpi = "${libdir}/libopenmaxil.so"
