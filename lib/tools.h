/*
 *  megatools - Mega.nz client library and tools
 *  Copyright (C) 2013  Ondřej Jirman <megous@megous.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __TOOLS_H
#define __TOOLS_H

#include <glib.h>
#include <glib/gstdio.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <utime.h>
#include "mega.h"
#include "alloc.h"

typedef enum {
  TOOL_SESSION_OPEN = 1
} ToolSessionFlags;

typedef enum {
  TOOL_INIT_AUTH = 1
} ToolInitFlags;

void            tool_init             (gint* ac, gchar*** av, const gchar* tool_name, GOptionEntry* tool_entries, ToolInitFlags flags);
mega_session*   tool_start_session    (ToolSessionFlags flags);
void            tool_fini             (mega_session* s);

void            tool_show_progress    (const gchar* file, const mega_status_data *data);
gchar*          tool_convert_filename (const gchar* path, gboolean local);

#ifdef G_OS_WIN32
#define ESC_CLREOL ""
#define ESC_WHITE ""
#define ESC_GREEN ""
#define ESC_YELLOW ""
#define ESC_BLUE ""
#define ESC_GRAY ""
#define ESC_NORMAL ""
#else
#define ESC_CLREOL "\x1b[0K"
#define ESC_WHITE "\x1b[37;1m"
#define ESC_GREEN "\x1b[32;1m"
#define ESC_YELLOW "\x1b[33;1m"
#define ESC_BLUE "\x1b[34;1m"
#define ESC_GRAY "\x1b[30;1m"
#define ESC_NORMAL "\x1b[0m"
#endif

#endif
