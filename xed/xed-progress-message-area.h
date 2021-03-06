/*
 * xed-progress-message-area.h
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

#ifndef __XED_PROGRESS_MESSAGE_AREA_H__
#define __XED_PROGRESS_MESSAGE_AREA_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

/*
 * Type checking and casting macros
 */
#define XED_TYPE_PROGRESS_MESSAGE_AREA              (xed_progress_message_area_get_type())
#define XED_PROGRESS_MESSAGE_AREA(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj), XED_TYPE_PROGRESS_MESSAGE_AREA, XedProgressMessageArea))
#define XED_PROGRESS_MESSAGE_AREA_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass), XED_TYPE_PROGRESS_MESSAGE_AREA, XedProgressMessageAreaClass))
#define XED_IS_PROGRESS_MESSAGE_AREA(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj), XED_TYPE_PROGRESS_MESSAGE_AREA))
#define XED_IS_PROGRESS_MESSAGE_AREA_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), XED_TYPE_PROGRESS_MESSAGE_AREA))
#define XED_PROGRESS_MESSAGE_AREA_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj), XED_TYPE_PROGRESS_MESSAGE_AREA, XedProgressMessageAreaClass))

/* Private structure type */
typedef struct _XedProgressMessageAreaPrivate XedProgressMessageAreaPrivate;

/*
 * Main object structure
 */
typedef struct _XedProgressMessageArea XedProgressMessageArea;

struct _XedProgressMessageArea 
{
	GtkInfoBar parent;

	/*< private > */
	XedProgressMessageAreaPrivate *priv;
};

/*
 * Class definition
 */
typedef struct _XedProgressMessageAreaClass XedProgressMessageAreaClass;

struct _XedProgressMessageAreaClass 
{
	GtkInfoBarClass parent_class;
};

/*
 * Public methods
 */
GType 		 xed_progress_message_area_get_type 		(void) G_GNUC_CONST;

GtkWidget	*xed_progress_message_area_new      		(const gchar              *stock_id,
								 const gchar              *markup,
								 gboolean                  has_cancel);

void		 xed_progress_message_area_set_stock_image	(XedProgressMessageArea *area,
								 const gchar              *stock_id);

void		 xed_progress_message_area_set_markup		(XedProgressMessageArea *area,
								 const gchar              *markup);

void		 xed_progress_message_area_set_text		(XedProgressMessageArea *area,
								 const gchar              *text);

void		 xed_progress_message_area_set_fraction	(XedProgressMessageArea *area,
								 gdouble                   fraction);

void		 xed_progress_message_area_pulse		(XedProgressMessageArea *area);
								 

G_END_DECLS

#endif  /* __XED_PROGRESS_MESSAGE_AREA_H__  */
