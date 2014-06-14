FILESEXTRAPATHS_prepend := "${THISDIR}/weston:"

SRC_URI += "file://disable-tests.patch  \
            file://fixup-egl-gles-versions.patch \
           "

# Remove DRM backend as it seems to lock up on the RPi
PACKAGECONFIG = "${@bb.utils.contains('DISTRO_FEATURES', 'wayland', 'fbdev wayland rpi', '', d)} \
                   ${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'x11', '', d)} \
                   ${@bb.utils.contains('DISTRO_FEATURES', 'pam', 'launch', '', d)} \
                   ${@bb.utils.contains('DISTRO_FEATURES', 'maynard', 'launch wayland rpi', 'pam', d)} \
                  "
#
# Compositor choices
#
# Weston on RPI
PACKAGECONFIG[rpi] = "--enable-rpi-compositor WESTON_NATIVE_BACKEND='rpi-backend.so', \
                      --disable-rpi-compositor	,udev virtual/mesa virtual/libgles2 virtual/libgl virtual/egl \
                     "
