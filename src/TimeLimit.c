/* gtkgo 0.0.10 (TimeLimit.c) - 05/17/99
 * Copyright (C) 1998, 1999  Norbert de Jonge
 * (hack@altavista.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this game; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#include "TimeLimit.h"

void DestroyTime (void)
{
  gtk_widget_destroy (timewindow);
  iyesno = 0;
}

void TimeLimit (void)
{
  if ((ifilestuff == 0) && ((biscomputer == 0) || (wiscomputer == 0))
    && (iyesno == 0) && (inet == 0))
  {
    timewindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (timewindow), "time limit");
    gtk_signal_connect (GTK_OBJECT (timewindow), "delete_event",
      GTK_SIGNAL_FUNC (DestroyTime), NULL);
    gtk_window_set_policy (GTK_WINDOW (timewindow), 0, 0, 1);
    gtk_container_border_width (GTK_CONTAINER (timewindow), 0);
    gtk_widget_realize (timewindow);

    timebox1 = gtk_vbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (timebox1), 0);
    gtk_container_add (GTK_CONTAINER (timewindow), timebox1);
    gtk_widget_show (timebox1);
    timebox2 = gtk_hbox_new (FALSE, 0);
    gtk_container_border_width (GTK_CONTAINER (timebox2), 0);
    gtk_box_pack_start (GTK_BOX (timebox1), timebox2, FALSE, FALSE, 0);
    gtk_widget_show (timebox2);
    timetable1 = gtk_table_new (1, 4, FALSE);
    gtk_box_pack_start (GTK_BOX (timebox2), timetable1, TRUE, TRUE, 0);
    gtk_widget_show (timetable1);

    timelabel = gtk_label_new ("Enter time limit in <m> or <h:m>.");
    gtk_label_set (GTK_LABEL (timelabel), "Enter time limit in <m> or <h:m>.");
    gtk_label_set_justify (GTK_LABEL (timelabel), GTK_JUSTIFY_CENTER);
    gtk_table_attach (GTK_TABLE (timetable1), timelabel, 0, 1, 0, 1,
      GTK_FILL, GTK_FILL, 10, 10);
    gtk_widget_show (timelabel);

    itimemm = itimelimit;
    if (itimemm > 59)
    {
      itimehh = 0;
      do
      {
        itimemm -= 60;
        itimehh++;
      } while (itimemm >= 60);
      if (itimemm < 10)
      {
        sprintf (sthetime, "%i:0%i", itimehh, itimemm);
      }
      else
      {
        sprintf (sthetime, "%i:%i", itimehh, itimemm);
      }
    }
    else
    {
      if (itimemm < 10)
      {
        sprintf (sthetime, "0%i", itimemm);
      }
      else
      {
        sprintf (sthetime, "%i", itimemm);
      }
    }

    timeentry1 = gtk_entry_new_with_max_length (6);
    gtk_signal_connect (GTK_OBJECT (timeentry1), "activate",
      GTK_SIGNAL_FUNC (SetTimeLimit), NULL);
    gtk_entry_set_text (GTK_ENTRY (timeentry1), sthetime);
    gtk_entry_select_region (GTK_ENTRY (timeentry1), 0,
      GTK_ENTRY (timeentry1)->text_length);
    gtk_table_attach (GTK_TABLE (timetable1), timeentry1, 0, 1, 1, 2,
      GTK_EXPAND, GTK_EXPAND, 0, 10);
    gtk_widget_grab_focus (timeentry1);
    gtk_widget_show (timeentry1);

    timesep = gtk_hseparator_new ();
    gtk_table_attach (GTK_TABLE (timetable1), timesep, 0, 1, 2, 3,
      GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show (timesep);

#ifdef USE_GNOME
    timebutton = gnome_stock_button (GNOME_STOCK_BUTTON_OK);
#else
    timebutton = gtk_button_new_with_label ("OK");
#endif
    gtk_signal_connect (GTK_OBJECT (timebutton), "clicked",
    GTK_SIGNAL_FUNC (SetTimeLimit), NULL);
    GTK_WIDGET_SET_FLAGS (timebutton, GTK_CAN_DEFAULT);
    gtk_window_set_default (GTK_WINDOW (timewindow), timebutton);
    gtk_table_attach (GTK_TABLE (timetable1), timebutton, 0, 1, 3, 4,
      GTK_FILL, GTK_FILL, 2, 2);
    gtk_widget_show (timebutton);

    gtk_widget_show (timewindow);
    iyesno = 1;
  }
}
