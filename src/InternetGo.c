/* gtkgo 0.0.10 (InternetGo.c) - 05/17/99
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

#include "InternetGo.h"

void CloseSocket (void)
{
  inet = 0;
  /* Well... ReceiveData will now remove the internetwindow */
  /* and close the sockfd.                                   */
}

void ToggleWrap (GtkWidget *checkbutton, GtkWidget *text)
{
  gtk_text_set_word_wrap (GTK_TEXT (text), GTK_TOGGLE_BUTTON
    (checkbutton)->active);
}

struct in_addr *atoaddr (char *address)
{
  struct hostent *host;
  static struct in_addr saddr;

  saddr.s_addr = inet_addr (address);
  if (saddr.s_addr != -1)
  {
    return (&saddr);
  }
  host = gethostbyname (address);
  if (host != NULL)
  {
    return ((struct in_addr *) *host->h_addr_list);
  }
  saddr.s_addr = inet_addr ("666.666.666.666");
  return (&saddr);
}

void InternetGo (void)
{
  if ((ifilestuff == 0) && (inet == 0))
  {
    shost = gtk_entry_get_text (GTK_ENTRY (connectentry1));
    theaddress = atoaddr (shost);
    iport = atoi (gtk_entry_get_text (GTK_ENTRY (connectentry2)));

    gtk_widget_destroy (connectwindow);
    iyesno = 0;

    bzero ((char *) &host_addr, sizeof (host_addr));
    host_addr.sin_family = AF_INET;
    host_addr.sin_addr.s_addr = inet_addr (inet_ntoa (*theaddress));
    host_addr.sin_port = htons (iport);

    if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    {
      Message ("Unable to open socket.", 3, 0);
    }
    itheerror = connect (sockfd, (struct sockaddr *) &host_addr, sizeof
      (host_addr));
    if (itheerror < 0)
    {
      sprintf (serrortemp, "Unable to connect to host (%s).", strerror
        (errno));
      Message (serrortemp, 3, 0);
    }
    else
    {
      fcntl (sockfd, F_SETFL, O_NONBLOCK);
      biscomputer = 0;
      sprintf (bplayername, "%s", "unknown");
      wiscomputer = 0;
      sprintf (wplayername, "%s", "unknown");
      StatusBar ();

      if (ichangestuff == 0)
      {
        Play ("open.mp3", 0);
      }

      internetwindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
      gtk_window_set_title (GTK_WINDOW (internetwindow), "Internet window");
      gtk_signal_connect (GTK_OBJECT (internetwindow), "delete_event",
        GTK_SIGNAL_FUNC (CloseSocket), NULL);
      gtk_window_set_policy (GTK_WINDOW (internetwindow), 0, 0, 1);
      gtk_container_border_width (GTK_CONTAINER (internetwindow), 0);
      gtk_widget_realize (internetwindow);

      internetbox1 = gtk_vbox_new (FALSE, 0);
      gtk_container_border_width (GTK_CONTAINER (internetbox1), 0);
      gtk_container_add (GTK_CONTAINER (internetwindow), internetbox1);
      gtk_widget_show (internetbox1);
      internetbox2 = gtk_hbox_new (FALSE, 0);
      gtk_container_border_width (GTK_CONTAINER (internetbox2), 0);
      gtk_box_pack_start (GTK_BOX (internetbox1), internetbox2, TRUE, TRUE, 5);
      gtk_widget_show (internetbox2);
      internetbox3 = gtk_vbox_new (FALSE, 0);
      gtk_container_border_width (GTK_CONTAINER (internetbox3), 0);
      gtk_box_pack_start (GTK_BOX (internetbox2), internetbox3, TRUE, TRUE, 0);
      gtk_widget_show (internetbox3);
      internettable1 = gtk_table_new (2, 1, FALSE);
      gtk_widget_show (internettable1);
      gtk_box_pack_start (GTK_BOX (internetbox3), internettable1, TRUE, TRUE,
        0);
      internettable2 = gtk_table_new (2, 3, FALSE);
      gtk_widget_show (internettable2);
      gtk_box_pack_start (GTK_BOX (internetbox3), internettable2, TRUE, TRUE,
        0);

      text = gtk_text_new (NULL, NULL);
      gtk_widget_set_usize (text, 535, 266);
      gtk_text_set_editable (GTK_TEXT (text), FALSE);
      gtk_table_attach (GTK_TABLE (internettable1), text, 0, 1, 0, 1,
        GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 5, 0);
      gtk_widget_show (text);

      vscrollbar = gtk_vscrollbar_new (GTK_TEXT (text)->vadj);
      adj = (GTK_TEXT (text))->vadj;
      gtk_table_attach (GTK_TABLE (internettable1), vscrollbar, 1, 2, 0, 1,
        GTK_FILL, GTK_EXPAND  | GTK_FILL, 5, 0);
      gtk_widget_show (vscrollbar);

      cmap = gdk_colormap_get_system ();
      color.red = 0xffff;
      color.green = 0;
      color.blue = 0;
      if (!gdk_color_alloc (cmap, &color))
      {
        Message ("Could not allocate color.", 3, 0);
      }

      gtk_widget_realize (text);

      wrapcheck = gtk_check_button_new_with_label ("wrap");
      gtk_table_attach (GTK_TABLE (internettable2), wrapcheck, 0, 1, 0, 1,
        GTK_FILL, GTK_FILL, 5, 10);
      gtk_signal_connect (GTK_OBJECT (wrapcheck), "toggled",
        GTK_SIGNAL_FUNC (ToggleWrap), text);
      gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (wrapcheck), FALSE);
      gtk_widget_show (wrapcheck);

      internetentry = gtk_entry_new_with_max_length (50);
      gtk_signal_connect (GTK_OBJECT (internetentry), "activate",
        GTK_SIGNAL_FUNC (SendData), NULL);
      gtk_table_attach (GTK_TABLE (internettable2), internetentry, 1, 2, 0, 1,
        GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 5, 10);
      gtk_widget_grab_focus (internetentry);
      gtk_widget_show (internetentry);

      inetsep = gtk_hseparator_new ();
      gtk_table_attach (GTK_TABLE (internettable2), inetsep, 0, 2, 1, 2,
        GTK_EXPAND | GTK_FILL, GTK_FILL, 0, 0);
      gtk_widget_show (inetsep);

      inetbutton = gtk_button_new_with_label ("Disconnect");
      gtk_signal_connect (GTK_OBJECT (inetbutton), "clicked",
        GTK_SIGNAL_FUNC (CloseSocket), NULL);
      GTK_WIDGET_SET_FLAGS (inetbutton, GTK_CAN_DEFAULT);
      gtk_window_set_default (GTK_WINDOW (internetwindow), inetbutton);
      gtk_table_attach (GTK_TABLE (internettable2), inetbutton, 0, 2, 2, 3,
        GTK_EXPAND | GTK_FILL, GTK_FILL, 2, 2);
      gtk_widget_show (inetbutton);

      gtk_widget_show (internetwindow);
      inet = 1;
      ReceiveData ();
    }
  }
}
