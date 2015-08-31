![SDR Angel banner](/doc/img/sdrangel_banner.png)

**SDRangel** is an Open Source Qt5/OpenGL SDR and signal analyzer frontend to various hardware. 

Although it keeps the same look and feel as its parent application **SDRangelove** it is a major redesign from it hitting more than half the lines of the code. Therefore the code base cannot be kept in sync anymore with its parent. It also contains enhancements and major differences. So it should now fly with its own wings and with its own name: **SDRangel**

<h1>Source code</h1>

<h2>Repository branches</h2>

- master: the "production" branch
- legacy: the modified code from the parent application [hexameron rtl-sdrangelove](https://github.com/hexameron/rtl-sdrangelove) before a major redeisign of the code was carried out and sync was lost.

<h2>Unsupported plugins</h2>

These plugins come from the parent code base and are still present in the source tree but are not part of the build:

- Channels:
  - tetra 
- Sample sources:
  - gnuradio
  - osmosdr
  - v4l-msi
  - v4l-rtl

<h1>Supported hardware</h1>

<h2>BladeRF</h2>

BladeRF is supported through the libbladerf library that should be installed in your system for proper build of the software and operation support.

If you use your own location for libbladeRF install directory you need to specify library and include locations. Example with `/opt/install/libbladerf` with the following defines on `cmake` command line:

`-DLIBBLADERF_LIBRARIES=/opt/install/libbladeRF/lib/libbladeRF.so -DLIBBLADERF_INCLUDE_DIR=/opt/install/libbladeRF/include`

<h2>Funcube Dongle</h2>

Only the original Funcube Dongle Pro is supported. Funcube Dongle Pro+ will come later.

The interface is built in the software and do not require additional libraries other than USB support with libusb. 

<h2>RTL-SDR</h2>

RTL-SDR based dongles are supported through the librtlsdr library that should be installed in your system for proper build of the software and operation support.

If you use your own location for librtlsdr install directory you need to specify library and include locations. Example with `/opt/install/librtlsdr` with the following defines on `cmake` command line:

`-DLIBRTLSDR_LIBRARIES=/opt/install/librtlsdr/lib/librtlsdr.so -DLIBRTLSDR_INCLUDE_DIR=/opt/install/librtlsdr/include`

<h1>Software build</h1>

<h2>For Ubuntu</h2>

`sudo apt-get install libqt5multimedia5-plugins qtmultimedia5-dev qttools5-dev qttools5-dev-tools libqt5opengl5-dev qtbase5-dev libusb-1.0 librtlsdr-dev libboost-all-dev`

`mkdir build && cd build && cmake ../ && make`

`librtlsdr-dev` is in the `universe` repo. (utopic 14.10 amd64.)

Use `cmake ../ -DV4L-RTL=ON` to build the Linux kernel driver for RTL-SDR (Experimental). Needs a recent kernel and libv4l2. Will need extra work to support SDRPlay. Needs `cp KERNEL_SOURCE/include/linux/compiler.h /usr/include/linux/` and `cp KERNEL_SOURCE/include/uapi/linux/videodev2.h /usr/include/uapi/linux/` and package `libv4l-dev`.

The Gnuradio plugin source needs extra packages, including `liblog4cpp-dev libboost-system-dev gnuradio-dev libosmosdr-dev`

For non standard installations of RTL-SDR library, the GNU Radio runtime and gr.osmocom drivers use the following variables in the cmake command line. The paths specified are just examples:

  - For GNU Radio runtime:
    - Includes: `-DGNURADIO_RUNTIME_INCLUDE_DIRS=/opt/install/gnuradio-3.7.5.1/include`
    - Library: `-DGNURADIO_RUNTIME_LIBRARIES=/opt/install/gnuradio-3.7.5.1/lib/libgnuradio-runtime.so`
  - For gr.osmocom:
    - Includes: `-DGNURADIO_OSMOSDR_INCLUDE_DIRS=/opt/install/gr-osmosdr/include`
    - Library: `-DGNURADIO_OSMOSDR_LIBRARIES=/opt/install/gr-osmosdr/lib/libgnuradio-osmosdr.so`
  - For RTL-SDR library:
    - Includes: `-DLIBRTLSDR_INCLUDE_DIR=/opt/install/rtlsdr/include`
    - Library: `-DLIBRTLSDR_LIBRARIES=/opt/install/rtlsdr/lib/librtlsdr.so`
    
There is no installation procedure the executable is at the root of the build directory

<h2>For Debian</h2>

For any version of Debian you will need Qt5.

Debian 7 "wheezy" uses Qt4. Qt5 is available from the "wheezy-backports" repo, but this will remove Qt4. Debian 8 "jessie" uses Qt5. 

Assuming Debian Jessie is used:

`sudo apt-get install cmake g++ pkg-config libfftw3-dev libusb-1.0-0-dev libusb-dev qt5-default qtbase5-dev qtchooser libqt5multimedia5-plugins qtmultimedia5-dev qttools5-dev qttools5-dev-tools libqt5opengl5-dev qtbase5-dev librtlsdr-dev libboost-all-dev`

`mkdir build && cd build && cmake ../ && make`

Then the same remarks as for Ubuntu apply...

<h1>Known Issues</h1>

  - You will need to stop input before changing preset then start again
  - The message queuing model supports a n:1 connection to an object (on its input queue) and a 1:1 connection from an object (on its output queue). Assuming a different model can cause insidious disruptions.
  - As the objects input and output queues can be publicly accessed there is no strict control of which objects post messages on these queues. The correct assumption is that messages can be popped from the input queue only by its holder and that messages can be pushed on the output queue only by its holder.

<h1>Changes from SDRangelove</h1>

<h2>New features, enhancements and fixes</h2>

  - Added ppm correction for the LO of RTL-SDR. This uses the corresponding function in the librtlsdr interface (range -99..99 ppm)
  - Added a preset update button (the diskette with the yellow corner) to be able to save the current settings on an existing preset
  - Added variable decimation in log2 increments from 2^0=1 to 2^4=16 allowing to see the full 2048 kHz of spectrum if so you wish
  - Better handling of rtlsdr GUI display when settings change (initial load, load of presets)
  - Added display and precise control of the shift frequency from center frequency of the NFM receivers.
  - Removed useless spectrum visualizer in NFM receivers. Created a null sink class to fit corresponding parameter in NFMDemod class constructor.
  - Added display and precise control of the shift frequency from center frequency of the SSB receivers.
  - SSB filter bounds are tunable so that filter can be set off from center frequency allowing aural decoding of CW
  - Make the sidebands appear correctly on SSB channel overlay. Limit to +/- 6 kHz to fit channel spectrum analyzer window
  - SSB bandwidth can now be tuned in steps of 100 Hz
  - NFM and SSB receiver in focus trigger the display of the central frequency line on the spectrum frequency scale thus facilitating its identification
  - Added AM demod so now you can listen to air traffic!
  - Added the possibility to change the brightness and/or color of the grid.
  - Make the low cutoff frequency of the SSB filter variable so it can be used for CW also.
  - NFM demodulation without using atan and smooth squelch with AGC suppressing most clicks on low level signals and hiss on carrier tails. Only useful modulation comes through.
  - Added working WFM demodulation. Optimized for no atan2.
  - OsmoSDR and GNURadio plugins removed from the build as they have too many bugs that are too difficult to correct
  - New plugin for BladeRF interfacing libbladeRF directly
  - Corrected the nasty audio band resampling bug preventing use of sample rates that are not power of 2 multiples of 48kHz. This was because the resampling ratio was calculated with an integer division instead of a float division. 
  - As a consequence of the above added more interesting values for the available sampling rates of the BladeRF plugin
  - Variable span for the SSB demod down to 1.5 kHz
  - Filter out CTCSS tones for audio and full CTCSS support in NFMDemod
  - Enhancement of the NFM squelch mimicking professional analog squelch circuits (based on balance between two AF filters)
  - Added a channel analyzer plugin focusing on measurement (DSA/DSO functionnality). Basic functions.
  - Added a scope widget in the channel analyzer plugin
  - Channel analyzer bandwidth up to half the available RF (IF) bandwidth (was 48k fixed)
  - Enhanced scope display and controls: scale display, better X (time) and Y scales control, grid fit to scale, effectively implementing triggers, trigger on magnitude and phase, properly handling time shift, ...
  - Enhanced spectrum display: Histogram: wider decay range, make stroke and late holdoff adjustable. Added option to show live spectrum (had only max hold before).
  - Enhanced channel analyzer: enhanced scope and spectrum displays as mentioned above, make the spectrum display synchronous to scope (hence triggerable a la E4406A).
  - Sort channel plugins by delta frequency and type before saving to preset
  - Implemented scope pre-trigger delay
  - Implemented variable scope memory depth
  - Implemented trigger delay
  - Trigger on both edges
  - Spectrum histogram clear
  - Trigger line display for all trigger modes
  - Coarse and fine trigger level sliders
  - Minimalist recording (no file choice)
  - File sample source plugin (recording reader) not working
  
<h2>Major redesign</h2>

  - Make the DSP engine global static simplifying access to it
  - Fixed startup initialization sequence. New initialization phase in DSP engine and new ready state
  - Synchronous messaging class to push message to thread and wait for completion relieving the message queuing mechanism from this role
  - Message queuing and handling redesign. Still not completely satisfactory
  - Objects have their own input and output message queues
  - Dedicated message queue to communicate to the GUI for objects coupled with a GUI
  - Many other little things...
    
<h1>To Do</h1>

  - Level calibration
  - Enhance presets management (Edit, Move, Import/Export from/to human readable format like JSON)  
  - Tx channels for Rx/Tx boards like BladeRF
  - Enhance WFM (stereo, RDS?)
  - Even more demods ...
  - Support for Airspy and Funcube Dongle Pro+
  
