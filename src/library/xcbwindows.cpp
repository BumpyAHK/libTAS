/*
    Copyright 2015-2020 Clément Gallet <clement.gallet@ens-lyon.org>

    This file is part of libTAS.

    libTAS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libTAS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libTAS.  If not, see <http://www.gnu.org/licenses/>.
 */

// #include "config.h"
#include "xcbwindows.h"
// #include "xevents.h"
#include "hook.h"
#include "logging.h"
#include "../shared/sockethelpers.h"
#include "../shared/messages.h"
#include "ScreenCapture.h"
// #include "WindowTitle.h"
// #include "encoding/AVEncoder.h"
// #include "backtrace.h"
// #include "inputs/xinput.h"
// #include "xatom.h"
// #include "../external/mwm.h"
// #include "XlibEventQueueList.h"

// #ifdef LIBTAS_HAS_XRANDR
// #include <X11/extensions/Xrandr.h>
// #endif

namespace libtas {

DEFINE_ORIG_POINTER(xcb_create_window_checked);
DEFINE_ORIG_POINTER(xcb_create_window);
DEFINE_ORIG_POINTER(xcb_create_window_aux_checked);
DEFINE_ORIG_POINTER(xcb_create_window_aux);
DEFINE_ORIG_POINTER(xcb_destroy_window_checked);
DEFINE_ORIG_POINTER(xcb_destroy_window);

DEFINE_ORIG_POINTER(xcb_map_window_checked);
DEFINE_ORIG_POINTER(xcb_map_window);
DEFINE_ORIG_POINTER(xcb_unmap_window_checked);
DEFINE_ORIG_POINTER(xcb_unmap_window);

OVERRIDE xcb_void_cookie_t
xcb_create_window_checked (xcb_connection_t *c,
                           uint8_t           depth,
                           xcb_window_t      wid,
                           xcb_window_t      parent,
                           int16_t           x,
                           int16_t           y,
                           uint16_t          width,
                           uint16_t          height,
                           uint16_t          border_width,
                           uint16_t          _class,
                           xcb_visualid_t    visual,
                           uint32_t          value_mask,
                           const void       *value_list)
{
    debuglog(LCF_WINDOW, __func__, " call with id ", wid, " and dimensions ", width, "x", height);
    LINK_NAMESPACE_GLOBAL(xcb_create_window_checked);
    xcb_void_cookie_t ret = orig::xcb_create_window_checked(c, depth, wid, parent, x, y, width, height, border_width, _class, visual, value_mask, value_list);

    debuglog(LCF_KEYBOARD, "   selecting xcb keyboard events");
    debuglog(LCF_MOUSE, "   selecting xcb mouse events");
    game_info.keyboard |= GameInfo::XCBEVENTS;
    game_info.mouse |= GameInfo::XCBEVENTS;
    game_info.tosend = true;

    /* Only save the Window identifier for top-level windows */
    xcb_screen_t *s = xcb_setup_roots_iterator (xcb_get_setup (c)).data;

    if (s->root == parent) {
        /* Saving top-level window */
        if (gameXWindows.empty())
            debuglog(LCF_WINDOW, "   set game window to ", wid);
        gameXWindows.push_back(wid);
    }

    return ret;
}

OVERRIDE xcb_void_cookie_t
xcb_create_window (xcb_connection_t *c,
                   uint8_t           depth,
                   xcb_window_t      wid,
                   xcb_window_t      parent,
                   int16_t           x,
                   int16_t           y,
                   uint16_t          width,
                   uint16_t          height,
                   uint16_t          border_width,
                   uint16_t          _class,
                   xcb_visualid_t    visual,
                   uint32_t          value_mask,
                   const void       *value_list)
{
    debuglog(LCF_WINDOW, __func__, " call with id ", wid, " and dimensions ", width, "x", height);
    LINK_NAMESPACE_GLOBAL(xcb_create_window);
    xcb_void_cookie_t ret = orig::xcb_create_window(c, depth, wid, parent, x, y, width, height, border_width, _class, visual, value_mask, value_list);

    debuglog(LCF_KEYBOARD, "   selecting xcb keyboard events");
    debuglog(LCF_MOUSE, "   selecting xcb mouse events");
    game_info.keyboard |= GameInfo::XCBEVENTS;
    game_info.mouse |= GameInfo::XCBEVENTS;
    game_info.tosend = true;

    /* Only save the Window identifier for top-level windows */
    xcb_screen_t *s = xcb_setup_roots_iterator (xcb_get_setup (c)).data;

    if (s->root == parent) {
        /* Saving top-level window */
        if (gameXWindows.empty())
            debuglog(LCF_WINDOW, "   set game window to ", wid);
        gameXWindows.push_back(wid);
    }

    return ret;
}


OVERRIDE xcb_void_cookie_t
xcb_create_window_aux_checked (xcb_connection_t                     *c,
                               uint8_t                               depth,
                               xcb_window_t                          wid,
                               xcb_window_t                          parent,
                               int16_t                               x,
                               int16_t                               y,
                               uint16_t                              width,
                               uint16_t                              height,
                               uint16_t                              border_width,
                               uint16_t                              _class,
                               xcb_visualid_t                        visual,
                               uint32_t                              value_mask,
                               const xcb_create_window_value_list_t *value_list)
{
    debuglog(LCF_WINDOW, __func__, " call with id ", wid, " and dimensions ", width, "x", height);
    LINK_NAMESPACE_GLOBAL(xcb_create_window_aux_checked);
    xcb_void_cookie_t ret = orig::xcb_create_window_aux_checked(c, depth, wid, parent, x, y, width, height, border_width, _class, visual, value_mask, value_list);

    debuglog(LCF_KEYBOARD, "   selecting xcb keyboard events");
    debuglog(LCF_MOUSE, "   selecting xcb mouse events");
    game_info.keyboard |= GameInfo::XCBEVENTS;
    game_info.mouse |= GameInfo::XCBEVENTS;
    game_info.tosend = true;

    /* Only save the Window identifier for top-level windows */
    xcb_screen_t *s = xcb_setup_roots_iterator (xcb_get_setup (c)).data;

    if (s->root == parent) {
        /* Saving top-level window */
        if (gameXWindows.empty())
            debuglog(LCF_WINDOW, "   set game window to ", wid);
        gameXWindows.push_back(wid);
    }

    return ret;
}

OVERRIDE xcb_void_cookie_t
xcb_create_window_aux (xcb_connection_t                     *c,
                       uint8_t                               depth,
                       xcb_window_t                          wid,
                       xcb_window_t                          parent,
                       int16_t                               x,
                       int16_t                               y,
                       uint16_t                              width,
                       uint16_t                              height,
                       uint16_t                              border_width,
                       uint16_t                              _class,
                       xcb_visualid_t                        visual,
                       uint32_t                              value_mask,
                       const xcb_create_window_value_list_t *value_list)
{
    debuglog(LCF_WINDOW, __func__, " call with id ", wid, " and dimensions ", width, "x", height);
    LINK_NAMESPACE_GLOBAL(xcb_create_window_aux);
    xcb_void_cookie_t ret = orig::xcb_create_window_aux(c, depth, wid, parent, x, y, width, height, border_width, _class, visual, value_mask, value_list);

    debuglog(LCF_KEYBOARD, "   selecting xcb keyboard events");
    debuglog(LCF_MOUSE, "   selecting xcb mouse events");
    game_info.keyboard |= GameInfo::XCBEVENTS;
    game_info.mouse |= GameInfo::XCBEVENTS;
    game_info.tosend = true;

    /* Only save the Window identifier for top-level windows */
    xcb_screen_t *s = xcb_setup_roots_iterator (xcb_get_setup (c)).data;

    if (s->root == parent) {
        /* Saving top-level window */
        if (gameXWindows.empty())
            debuglog(LCF_WINDOW, "   set game window to ", wid);
        gameXWindows.push_back(wid);
    }

    return ret;
}

static void sendXWindow(Window w)
{
    uint32_t i = (uint32_t)w;
    sendMessage(MSGB_WINDOW_ID);
    sendData(&i, sizeof(i));
    debuglog(LCF_WINDOW, "Sent X11 window id ", w);
}

xcb_void_cookie_t xcb_destroy_window_checked (xcb_connection_t *c, xcb_window_t window)
{
    debuglog(LCF_WINDOW, __func__, " called with window ", window);
    LINK_NAMESPACE_GLOBAL(xcb_destroy_window_checked);

    /* If current game window, switch to another one on the list */
    if (!gameXWindows.empty() && window == gameXWindows.front()) {
        ScreenCapture::fini();

        gameXWindows.pop_front();
        if (gameXWindows.empty()) {
            /* Tells the program we don't have a window anymore to gather inputs */
            sendXWindow(0);
        }
        else {
            /* Switch to the next game window */
            debuglog(LCF_WINDOW, "   set game window to ", gameXWindows.front());
            sendXWindow(gameXWindows.front());
            ScreenCapture::init();
        }
    }
    else {
        /* If another game window, remove it from the list */
        for (auto iter = gameXWindows.begin(); iter != gameXWindows.end(); iter++) {
            if (window == *iter) {
                gameXWindows.erase(iter);
                break;
            }
        }
    }

    return orig::xcb_destroy_window_checked(c, window);
}

xcb_void_cookie_t xcb_destroy_window (xcb_connection_t *c, xcb_window_t window)
{
    debuglog(LCF_WINDOW, __func__, " called with window ", window);
    LINK_NAMESPACE_GLOBAL(xcb_destroy_window);

    /* If current game window, switch to another one on the list */
    if (!gameXWindows.empty() && window == gameXWindows.front()) {
        ScreenCapture::fini();

        gameXWindows.pop_front();
        if (gameXWindows.empty()) {
            /* Tells the program we don't have a window anymore to gather inputs */
            sendXWindow(0);
        }
        else {
            /* Switch to the next game window */
            debuglog(LCF_WINDOW, "   set game window to ", gameXWindows.front());
            sendXWindow(gameXWindows.front());
            ScreenCapture::init();
        }
    }
    else {
        /* If another game window, remove it from the list */
        for (auto iter = gameXWindows.begin(); iter != gameXWindows.end(); iter++) {
            if (window == *iter) {
                gameXWindows.erase(iter);
                break;
            }
        }
    }

    return orig::xcb_destroy_window(c, window);
}

xcb_void_cookie_t xcb_map_window_checked (xcb_connection_t *c, xcb_window_t window)
{
    debuglog(LCF_WINDOW, __func__, " called with window ", window);
    LINK_NAMESPACE_GLOBAL(xcb_map_window_checked);
    xcb_void_cookie_t ret = orig::xcb_map_window_checked(c, window);

    /* We must wait until the window is mapped to send it to the program.
     * We are checking the content of gameXWindows to see if we must send it */
    for (auto iter = gameXWindows.begin(); iter != gameXWindows.end(); iter++) {
        if (window == *iter) {
            gameXWindows.erase(iter);
            gameXWindows.push_front(window);
            sendXWindow(window);
            break;
        }
    }

    return ret;
}

xcb_void_cookie_t xcb_map_window (xcb_connection_t *c, xcb_window_t window)
{
    debuglog(LCF_WINDOW, __func__, " called with window ", window);
    LINK_NAMESPACE_GLOBAL(xcb_map_window);
    xcb_void_cookie_t ret = orig::xcb_map_window(c, window);

    /* We must wait until the window is mapped to send it to the program.
     * We are checking the content of gameXWindows to see if we must send it */
    for (auto iter = gameXWindows.begin(); iter != gameXWindows.end(); iter++) {
        if (window == *iter) {
            gameXWindows.erase(iter);
            gameXWindows.push_front(window);
            sendXWindow(window);
            break;
        }
    }

    return ret;
}

xcb_void_cookie_t xcb_unmap_window_checked (xcb_connection_t *c, xcb_window_t window)
{
    debuglog(LCF_WINDOW, __func__, " called with window ", window);
    LINK_NAMESPACE_GLOBAL(xcb_unmap_window_checked);
    xcb_void_cookie_t ret = orig::xcb_unmap_window_checked(c, window);
    return ret;
}

xcb_void_cookie_t xcb_unmap_window (xcb_connection_t *c, xcb_window_t window)
{
    debuglog(LCF_WINDOW, __func__, " called with window ", window);
    LINK_NAMESPACE_GLOBAL(xcb_unmap_window);
    xcb_void_cookie_t ret = orig::xcb_unmap_window(c, window);
    return ret;
}


}
