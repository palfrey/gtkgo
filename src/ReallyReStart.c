/* gtkgo 0.0.10 (ReallyReStart.c) - 05/17/99
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

#include "ReallyReStart.h"

gfloat lprogress (gfloat pvalue)
{
  pvalue += 0.00277;
  gtk_progress_bar_update (GTK_PROGRESS_BAR (lbar), pvalue);
  while (gtk_events_pending ())
  {
    gtk_main_iteration ();
  }
  return (pvalue);
}

void ReallyReStart (GtkWidget *rrw, GtkFileSelection *rrfs)
{
  gfloat pvalue = 0;
  if ((ihistory > 0) && (isave == 1))
  {
    JudgeBoard ('w');
    Save ();
  }
  if (isavemes == 1)
  {
    Message (ssavemes, 2, 1);
  }

  x = 0;
  y = 0;
  iCapturedW = 0;
  iCapturedB = 0;
  ilimit = 0;
  ijustundo = 0;
  ifilestuff = 0;
  iduh = 0;
  iother = 0;
  isave = 1;
  iquit = 0;
  isavemes = 0;
  iiamblack = 0;
  ihistory = 0;
  imoves = 0;
  ilastmoveb = 1000;
  ilastmovew = 1000;
  StatusBar ();

  for (iPlace = 1; iPlace <= 361; iPlace++)
  {
    sprintf (Board[iPlace], "%s", "mme");
  }
  sprintf (Board[1], "%s", "lte");
  for (iPlace = 2; iPlace <= 18; iPlace++)
  {
    sprintf (Board[iPlace], "%s", "mte");
  }
  sprintf (Board[19], "%s", "rte");
  sprintf (Board[20], "%s", "lme");
  sprintf (Board[38], "%s", "rme");
  sprintf (Board[39], "%s", "lme");
  sprintf (Board[57], "%s", "rme");
  sprintf (Board[58], "%s", "lme");
  sprintf (Board[61], "%s", "mms");
  sprintf (Board[67], "%s", "mms");
  sprintf (Board[73], "%s", "mms");
  sprintf (Board[76], "%s", "rme");
  sprintf (Board[77], "%s", "lme");
  sprintf (Board[95], "%s", "rme");
  sprintf (Board[96], "%s", "lme");
  sprintf (Board[114], "%s", "rme");
  sprintf (Board[115], "%s", "lme");
  sprintf (Board[133], "%s", "rme");
  sprintf (Board[134], "%s", "lme");
  sprintf (Board[152], "%s", "rme");
  sprintf (Board[153], "%s", "lme");
  sprintf (Board[171], "%s", "rme");
  sprintf (Board[172], "%s", "lme");
  sprintf (Board[175], "%s", "mms");
  sprintf (Board[181], "%s", "mms");
  sprintf (Board[187], "%s", "mms");
  sprintf (Board[190], "%s", "rme");
  sprintf (Board[191], "%s", "lme");
  sprintf (Board[209], "%s", "rme");
  sprintf (Board[210], "%s", "lme");
  sprintf (Board[228], "%s", "rme");
  sprintf (Board[229], "%s", "lme");
  sprintf (Board[247], "%s", "rme");
  sprintf (Board[248], "%s", "lme");
  sprintf (Board[266], "%s", "rme");
  sprintf (Board[267], "%s", "lme");
  sprintf (Board[285], "%s", "rme");
  sprintf (Board[286], "%s", "lme");
  sprintf (Board[289], "%s", "mms");
  sprintf (Board[295], "%s", "mms");
  sprintf (Board[301], "%s", "mms");
  sprintf (Board[304], "%s", "rme");
  sprintf (Board[305], "%s", "lme");
  sprintf (Board[323], "%s", "rme");
  sprintf (Board[324], "%s", "lme");
  sprintf (Board[342], "%s", "rme");
  sprintf (Board[343], "%s", "lue");
  for (iPlace = 344; iPlace <= 360; iPlace++)
  {
    sprintf (Board[iPlace], "%s", "mue");
  }
  sprintf (Board[361], "%s", "rue");

  DoHandicap ();

  for (ibuttonrr = 1; ibuttonrr <= 361; ibuttonrr++)
  {
    sprintf (History[ihistory][ibuttonrr], "%s", Board[ibuttonrr]);
  }
  gtk_widget_hide (window1);

  loadingw = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_position (GTK_WINDOW (loadingw), GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (loadingw), "loading...");
  gtk_signal_connect (GTK_OBJECT (loadingw), "delete_event",
    GTK_SIGNAL_FUNC (Quit), NULL);
  gtk_window_set_policy (GTK_WINDOW (loadingw), 0, 0, 1);
  gtk_container_border_width (GTK_CONTAINER (loadingw), 0);
  gtk_widget_realize (loadingw);

  lbox1 = gtk_vbox_new (FALSE, 0);
  gtk_container_border_width (GTK_CONTAINER (lbox1), 0);
  gtk_container_add (GTK_CONTAINER (loadingw), lbox1);
  gtk_widget_show (lbox1);
  lbox2 = gtk_hbox_new (FALSE, 0);
  gtk_container_border_width (GTK_CONTAINER (lbox2), 0);
  gtk_box_pack_start (GTK_BOX (lbox1), lbox2, FALSE, FALSE, 0);
  gtk_widget_show (lbox2);
  ltable1 = gtk_table_new (1, 2, FALSE);
  gtk_box_pack_start (GTK_BOX (lbox2), ltable1, TRUE, TRUE, 0);
  gtk_widget_show (ltable1);

#ifdef USE_GNOME
  im9 = gdk_imlib_load_image (PKGDATADIR"pix/gologog.png");
#else
  im9 = gdk_imlib_load_image (PKGDATADIR"pix/gologo.png");
#endif
  w9 = im9->rgb_width;
  h9 = im9->rgb_height;
  gdk_imlib_render (im9, w9, h9);
  lpixmap = gdk_imlib_move_image (im9);
  lpixmapwid = gtk_pixmap_new (lpixmap, NULL);
  gtk_table_attach (GTK_TABLE (ltable1), lpixmapwid, 0, 1, 0, 1,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_widget_show (lpixmapwid);
  gdk_flush ();

  lbar = gtk_progress_bar_new ();
  gtk_table_attach (GTK_TABLE (ltable1), lbar, 0, 1, 1, 2,
    GTK_FILL, GTK_FILL, 0, 0);
  gtk_widget_show (lbar);

  gtk_widget_show (loadingw);
  while (gtk_events_pending ())
  {
    gtk_main_iteration ();
  }

  for (ibuttonrr = 1; ibuttonrr <= 361; ibuttonrr++)
  {
    PixmapOnButton (ibuttonrr);
    pvalue = lprogress (pvalue);
  }
  gtk_widget_destroy (loadingw);
  if (itooltips == 0)
  {
    itooltips = 1;
    Tooltips ();
  }
  gtk_widget_show (window1);
}
