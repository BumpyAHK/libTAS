if BUILD32LIBONLY
bin_PROGRAMS =
else
bin_PROGRAMS = libtas.so
endif

libtas_so_SOURCES = \
    backtrace.cpp \
    BusyLoopDetection.cpp \
    DeterministicTimer.cpp \
    dlhook.cpp \
    frame.cpp \
    glibwrappers.cpp \
    global.cpp \
    GlobalState.cpp \
    hook.cpp \
    hookpatch.cpp \
    localewrappers.cpp \
    logging.cpp \
    main.cpp \
    mallocwrappers.cpp \
    NonDeterministicTimer.cpp \
    openglwrappers.cpp \
    pthreadwrappers.cpp \
    randomwrappers.cpp \
    ScreenCapture.cpp \
    SDLEventQueue.cpp \
    sdldisplay.cpp \
    sdldynapi.cpp \
    sdlevents.cpp \
    sdlmain.cpp \
    sdlmutex.cpp \
    sdlrender.cpp \
    sdlthreads.cpp \
    sdltimer.cpp \
    sdlversion.cpp \
    sdlwindows.cpp \
    signalwrappers.cpp \
    sleepwrappers.cpp \
    Stack.cpp \
    TimeHolder.cpp \
    timewrappers.cpp \
    tlswrappers.cpp \
    Utils.cpp \
    waitwrappers.cpp \
    WindowTitle.cpp \
    XlibEventQueue.cpp \
    XlibEventQueueList.cpp \
    XcbEventQueue.cpp \
    XcbEventQueueList.cpp \
    xatom.cpp \
    xcbconnection.cpp \
    xcbevents.cpp \
    xcbwindows.cpp \
    xdisplay.cpp \
    xevents.cpp \
    xf86vidmode.cpp \
    xinerama.cpp \
    xrandr.cpp \
    xwindows.cpp \
    audio/AudioBuffer.cpp \
    audio/AudioContext.cpp \
    audio/AudioPlayer.cpp \
    audio/AudioSource.cpp \
    audio/DecoderMSADPCM.cpp \
    audio/alsa/control.cpp \
    audio/alsa/pcm.cpp \
    audio/fluidsynth/fluidsynth.cpp \
    audio/fmod/fmod.cpp \
    audio/openal/al.cpp \
    audio/openal/alc.cpp \
    audio/openal/efx.cpp \
    audio/sdl/sdlaudio.cpp \
    checkpoint/AltStack.cpp \
    checkpoint/Checkpoint.cpp \
    checkpoint/ProcMapsArea.cpp \
    checkpoint/ProcSelfMaps.cpp \
    checkpoint/ReservedMemory.cpp \
    checkpoint/SaveState.cpp \
    checkpoint/SaveStateManager.cpp \
    checkpoint/ThreadLocalStorage.cpp \
    checkpoint/ThreadManager.cpp \
    checkpoint/ThreadSync.cpp \
    encoding/AVEncoder.cpp \
    encoding/NutMuxer.cpp \
    fileio/FileHandleList.cpp \
    fileio/generaliowrappers.cpp \
    fileio/posixiowrappers.cpp \
    fileio/SaveFile.cpp \
    fileio/SaveFileList.cpp \
    fileio/stdiowrappers.cpp \
    fileio/URandom.cpp \
    inputs/evdev.cpp \
    inputs/inputevents.cpp \
    inputs/inputs.cpp \
    inputs/ioctl_joy.cpp \
    inputs/jsdev.cpp \
    inputs/keyboard_helper.cpp \
    inputs/sdlgamecontroller.cpp \
    inputs/sdlhaptic.cpp \
    inputs/sdljoystick.cpp \
    inputs/sdlkeyboard.cpp \
    inputs/sdlkeyboardlayout.cpp \
    inputs/sdlpointer.cpp \
    inputs/sdltextinput.cpp \
    inputs/udevwrappers.cpp \
    inputs/winekeyboardlayout.cpp \
    inputs/xcbkeyboard.cpp \
    inputs/xcbpointer.cpp \
    inputs/xkeyboard.cpp \
    inputs/xkeyboardlayout.cpp \
    inputs/xinput.cpp \
    inputs/xpointer.cpp \
    renderhud/RenderHUD_GL.cpp \
    renderhud/RenderHUD_SDL1.cpp \
    renderhud/RenderHUD_SDL2_renderer.cpp \
    renderhud/RenderHUD_SDL2_surface.cpp \
    renderhud/RenderHUD.cpp \
    renderhud/sdl_ttf.cpp \
    renderhud/SurfaceARGB.cpp \
    steam/isteamapps.cpp \
    steam/isteamclient.cpp \
    steam/isteamcontroller.cpp \
    steam/isteamfriends.cpp \
    steam/isteamgamecoordinator.cpp \
    steam/isteamhttp.cpp \
    steam/isteammatchmaking.cpp \
    steam/isteamremotestorage/isteamremotestorage.cpp \
    steam/isteamremotestorage/isteamremotestorage001.cpp \
    steam/isteamremotestorage/isteamremotestorage012.cpp \
    steam/isteamremotestorage/isteamremotestorage013.cpp \
    steam/isteamremotestorage/isteamremotestorage014.cpp \
    steam/isteamscreenshots.cpp \
    steam/isteamugc.cpp \
    steam/isteamuser.cpp \
    steam/isteamuserstats.cpp \
    steam/isteamutils.cpp \
    steam/steamapi.cpp \
    steam/steamapiinternal.cpp \
    wine/winehook.cpp \
    wine/wined3d.cpp \
    wine/user32.cpp \
    wine/kernel32.cpp \
    ../shared/AllInputs.cpp \
    ../shared/SingleInput.cpp \
    ../shared/sockethelpers.cpp

libtas_so_CXXFLAGS = $(LIBSWRESAMPLE_CFLAGS) -fPIC -shared -fvisibility=hidden -Wall -fno-stack-protector
libtas_so_LDFLAGS = -shared
libtas_so_LDADD = $(LIBRARY_LIBS)

if BUILD32LIB
bin_PROGRAMS += libtas32.so
libtas32_so_SOURCES = $(libtas_so_SOURCES)
libtas32_so_CXXFLAGS = -m32 $(libtas_so_CXXFLAGS)
libtas32_so_LDFLAGS = $(libtas_so_LDFLAGS)
libtas32_so_LDADD = $(libtas_so_LDADD)
endif
