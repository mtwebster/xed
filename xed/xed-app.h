/*
 * xed-app.h
 * This file is part of xed
 *
 * Copyright (C) 2005 - Paolo Maggi 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA 02110-1301, USA.
 */
 
/*
 * Modified by the xed Team, 2005. See the AUTHORS file for a 
 * list of people on the xed Team.  
 * See the ChangeLog files for a list of changes. 
 *
 * $Id$
 */

#ifndef __XED_APP_H__
#define __XED_APP_H__

#include <gtk/gtk.h>

#include <xed/xed-window.h>

G_BEGIN_DECLS

/*
 * Type checking and casting macros
 */
#define XED_TYPE_APP              (xed_app_get_type())
#define XED_APP(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj), XED_TYPE_APP, XedApp))
#define XED_APP_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass), XED_TYPE_APP, XedAppClass))
#define XED_IS_APP(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj), XED_TYPE_APP))
#define XED_IS_APP_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), XED_TYPE_APP))
#define XED_APP_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj), XED_TYPE_APP, XedAppClass))

/* Private structure type */
typedef struct _XedAppPrivate XedAppPrivate;

/*
 * Main object structure
 */
typedef struct _XedApp XedApp;

struct _XedApp 
{
	GObject object;

	/*< private > */
	XedAppPrivate *priv;
};

/*
 * Class definition
 */
typedef struct _XedAppClass XedAppClass;

struct _XedAppClass 
{
	GObjectClass parent_class;
};

/*
 * Public methods
 */
GType 		 xed_app_get_type 			(void) G_GNUC_CONST;

XedApp 	*xed_app_get_default			(void);

XedWindow	*xed_app_create_window		(XedApp  *app,
							 GdkScreen *screen);

const GList	*xed_app_get_windows			(XedApp *app);
XedWindow	*xed_app_get_active_window		(XedApp *app);

/* Returns a newly allocated list with all the documents */
GList		*xed_app_get_documents		(XedApp *app);

/* Returns a newly allocated list with all the views */
GList		*xed_app_get_views			(XedApp *app);

/*
 * Non exported functions
 */
XedWindow	*_xed_app_restore_window		(XedApp    *app,
							 const gchar *role);
XedWindow	*_xed_app_get_window_in_viewport	(XedApp     *app,
							 GdkScreen    *screen,
							 gint          workspace,
							 gint          viewport_x,
							 gint          viewport_y);

/* global print config */
GtkPageSetup		*_xed_app_get_default_page_setup	(XedApp         *app);
void			 _xed_app_set_default_page_setup	(XedApp         *app,
								 GtkPageSetup     *page_setup);
GtkPrintSettings	*_xed_app_get_default_print_settings	(XedApp         *app);
void			 _xed_app_set_default_print_settings	(XedApp         *app,
								 GtkPrintSettings *settings);

G_END_DECLS

#endif  /* __XED_APP_H__  */
