/* gtkgo 0.0.10 (SendData.c) - 05/17/99
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

#include "SendData.h"

void SendData (int istype, char *ssenddata)
{
  if (istype == 1)
  {
    sprintf (sendline, "%s\n", ssenddata);
  }
  else
  {
    sprintf (sendline, "%s\n", gtk_entry_get_text (GTK_ENTRY (internetentry)));
    gtk_entry_set_text (GTK_ENTRY (internetentry), "");
  }
  n = strlen (sendline);
  if (send (sockfd, sendline, n, 0) != n)
  {
    Message ("A send error has occured.", 3, 0);
  }
  gtk_text_freeze (GTK_TEXT (text));
  gtk_text_insert (GTK_TEXT (text), fixed_font, &color, NULL,
    sendline, -1);
  gtk_text_thaw (GTK_TEXT (text));
  gtk_adjustment_set_value (adj, adj->upper - adj->lower - adj->page_size);
}
