DESCRIPTION = "This repository contains the source code for the ARM side \
libraries used on Raspberry Pi. These typically are installed in /opt/vc/lib \
and includes source for the ARM side code to interface to: EGL, mmal, GLESv2,\
vcos, openmaxil, vchiq_arm, bcm_host, WFC, OpenVG."
LICENSE = "Broadcom"
LIC_FILES_CHKSUM = "file://LICENCE;md5=957f6640d5e2d2acfce73a36a56cb32f"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

PROVIDES = "virtual/libgles2 \
            virtual/egl"
COMPATIBLE_MACHINE = "raspberrypi"

SRCBRANCH ?= "master"
SRCFORK ?= "raspberrypi"
SRCREV ?= "8181677fc08814cd5fcd1475ab73046f89f8dc80"

SRC_URI = "git://github.com/${SRCFORK}/userland.git;protocol=git;branch=${SRCBRANCH} \
           file://egl.pc \
           file://glesv2.pc \
	   file://bcm_host.pc \
	  "

S = "${WORKDIR}/git"

inherit cmake

EXTRA_OECMAKE = "-DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS='-Wl,--no-as-needed'"

# The compiled binaries don't provide sonames.
SOLIBS = "${SOLIBSDEV}"

do_install_append() {
    mkdir -p ${D}/${prefix}
    mv ${D}/opt/vc/* ${D}/${prefix}
    rm -rf ${D}/opt
    install -d ${D}${libdir}/pkgconfig
    install -m 0644 ${WORKDIR}/*.pc ${D}${libdir}/pkgconfig/
}

pkgconfigdir = "${libdir}/pkgconfig"

FILES_${PN} += "${libdir}/*${SOLIBS}"
FILES_${PN}-dev = "${includedir} \
                   ${prefix}/src \
                   ${pkgconfigdir}/*.pc \
                "
FILES_${PN}-doc += "${datadir}/install"

PACKAGE_ARCH = "${MACHINE_ARCH}"
